#include "unity.h"
#include "button.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

extern STATIC Button_ModuleState_t Button_gMoudleState;
extern Buttons_state_t ga_buttons_state[NUM_OF_BTNS];

void setUp(void)
{
    Button_gMoudleState = BTN_INT;
}


void tearDown(void)
{
    Button_gMoudleState = BTN_IDLE;

}

/************************************Button_init Test***************************************/

/** Doxygen Test Case Description **/
void test_button_init_should_returnNoError_when_calledFirstTime()
{
    /*!
		  * @par Given : module in UNINT state
		  * @par When  : Button_init() is called
		  * @par Then  : init function should return ok 
	*/

    /* Expected moudle is not init */    
    /* Act call init function*/
    /* Assert OK  returned*/
    Button_gMoudleState = BTN_IDLE;
    TEST_ASSERT_EQUAL_INT(OK,button_init());
}


/** Doxygen Test Case Description **/
void test_button_init_should_return_multiInitError_when_initaitedMultipleTimes(void)
{
    /*!
		  * @par Given : module is already inited
		  * @par When  : Button_init() is called
		  * @par Then  : init function should return MULTIPLE_INIT error
	*/

    /* Expected moudle is inited from setup function*/    
    /* Act call init again*/
    /* Assert MULTIPLE_INIT error returned*/
    TEST_ASSERT_EQUAL_INT(MULTIPLE_INIT_ERR,button_init());
    TEST_ASSERT_EQUAL_INT(MULTIPLE_INIT_ERR,button_init());
}

/** Doxygen Test Case Description **/
void test_button_init_should_initalizeBtnStateToRelased(void)
{

    /*!
		  * @par Given : All buttons are in  in unknown state
		  * @par When  : Button_init() is called
		  * @par Then  : All buttons are in BTN_RELEASED state
	*/

    /*  Expected 
    *   module state is uninit
    *   BTNS   state is unkown
    */
    Button_gMoudleState = BTN_IDLE;
    
    for(int i = 0 ; i < NUM_OF_BTNS ; i++)
        ga_buttons_state[i] = BTN_PRESSED;

    /* Act*/
    TEST_ASSERT_EQUAL_INT(OK,button_init());
	
    /* Assert */
    for(int i = 0 ; i < NUM_OF_BTNS ; i++)
        TEST_ASSERT_EQUAL_INT(BTN_RELEASED,ga_buttons_state[i]);

}

/************************************button_getState Test***************************************/

/** Doxygen Test Case Description **/
void test_Button_getState_should_returnTheStateOFGivenButton(void)
{
       /*!
		  * @par Given : module inited and all three buttons are in different setted states
		  * @par When  : button_getState() is called
		  * @par Then  : return should be the expected setted state
	    */

       for(int i = 0 ; i < NUM_OF_BTNS ; i++)
       {
            /*  Expected */
            ga_buttons_state[i] = i%4; /*the state of the buttons are 4 states from 0 to 3*/
            Buttons_state_t button_expected_state = i%4;
            
            /*Act*/
            Buttons_state_t button_actual_state =  button_getState(i);

            /*Assert*/
            TEST_ASSERT_EQUAL_INT(button_expected_state,button_actual_state);
       }
}

/** Doxygen Test Case Description **/
void test_Button_getState_should_return_PARAM_OUT_OF_RANG_when_passed_OFR_PARM(void)
{

      /*!
		  * @par Given : module inited 
		  * @par When  : button_getState() is called with out of range button numbers 
          *              Tested Values ==> {INT16_MIN,-1,NUM_OF_BTNS,INT16_MAX}
		  * @par Then  : return should be PARAM_OUT_OF_RANG_ERR
	    */

        int arr[] = {INT16_MIN,-1,NUM_OF_BTNS,INT16_MAX};

        
        for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++)
        {
            /*Expect*/
            ERR_t exp_button_err = PARAM_OUT_OF_RANG_ERR;
            /*Act*/     
            ERR_t act_button_err =  button_getState(arr[i]);
             /*Assert*/
            TEST_ASSERT_EQUAL_INT(exp_button_err,act_button_err);

        }
}


/************************************button_updateState Test***************************************/
uint8_t updatedataFromFile(char * fileName,Buttons_state_t *Exp_buttonState,unsigned char *Exp_button_P_presstime)
{
    static char fristTime =1;
     // Declare the file pointer
    static FILE *filePointer ;

    // Declare the variable for the data to be read from file
    char dataToBeRead[INPUT_LINE_LEGHT];

    if(fristTime)
    {
        // Open the existing file using fopen()
        // in read mode using "r" attribute
        filePointer = fopen(fileName, "r") ;

        // Check if this filePointer is null
        // which maybe if the file does not exist
        if ( filePointer == NULL )
        {
            printf( "%s file failed to open.",fileName ) ;
            
            return 0;
        }
        fgets ( dataToBeRead, INPUT_LINE_LEGHT, filePointer ); //get the header line and ignore it

        fristTime = 0;
    }

    if( fgets ( dataToBeRead, INPUT_LINE_LEGHT, filePointer ) != NULL )
    {

        
        char * pch = strtok (dataToBeRead,"    ");
        char counter = 0 ;  /*the counter tracks the variable to be updated from the sheet*/ 
        while (pch != NULL)
        {
            
            if(strcmp(pch,"BTN_PREPRESSED") == 0) 
                Exp_buttonState[counter] = BTN_PREPRESSED;
            else if (strcmp(pch,"BTN_PRESSED") == 0)
                Exp_buttonState[counter] = BTN_PRESSED;
            else if (strcmp(pch,"BTN_PRERELEASED") == 0)
                Exp_buttonState[counter] = BTN_PRERELEASED;
            else if (strcmp(pch,"BTN_RELEASED") == 0)
                Exp_buttonState[counter] = BTN_RELEASED;
            else if(pch[0] >= '0' && pch[0] <= '9')
                *Exp_button_P_presstime = atoi(pch);
            else
                printf("Incorrect test data\n");
            
            counter++;
            pch = strtok (NULL, "    ");
        }
        return 1;

    }
    else
    {
        // Closing the file using fclose()
        fclose(filePointer) ;
        return 0;
    }
}
/** Doxygen Test Case Description **/
void test_Button_updateState_should_return_OK_when_moduleIsInited(void)
{
        /*!
		  * @par Given : module inited 
		  * @par When  : button_updateState() is called 
		  * @par Then  : returned value should be OK
	    */
           
        /*Expect*/
        ERR_t exp_button_err = OK;

    
        /*Act*/  
        unsigned char testNum = 1;   
        ERR_t act_button_err =  button_updateState(testNum);
        /*Assert*/
        TEST_ASSERT_EQUAL_INT(exp_button_err,act_button_err);
}  


/** Doxygen Test Case Description **/
void test_Button_updateState_should_return_MODUL_IS_IDLE_when_moduleIsNotInited(void)
{
        /*!
		  * @par Given : module inited 
		  * @par When  : button_updateState() is called 
		  * @par Then  : all btns state should be updated from file
	    */

        /*Setup*/
        Button_gMoudleState = BTN_IDLE;   
        /*Expect*/
        ERR_t exp_button_err = MODULE_IS_IDLE_ERR;

    
        /*Act*/     
        unsigned char testNum = 1;
        ERR_t act_button_err =  button_updateState(testNum);
        /*Assert*/
        TEST_ASSERT_EQUAL_INT(exp_button_err,act_button_err);
}  

/** Doxygen Test Case Description **/
void test_Button_updateState_should_update_buttonsState(void)
{
        /*!
		  * @par Given : module inited 
		  * @par When  : button_updateState() is called 
		  * @par Then  : all btns state should be updated from file
	    */
        
        /*Expect*/
        ERR_t exp_button_err = OK;

        Buttons_state_t Expected_buttonsState[NUM_OF_BTNS];
        unsigned char   Expected_p_pressedTime = -1;
        unsigned char   testNum = 1;
        while(updatedataFromFile(INPUT_FILE_ABS_PATH,Expected_buttonsState,&Expected_p_pressedTime))
        {
            /*for each test case we setup the state of each button as an out of range to make sure it is being set */
            /*setup*/
            for(int i =0  ; i < NUM_OF_BTNS ; i++)
                ga_buttons_state[i] = -1;
            
            p_pressedTime = -1;
            
            
            /*Act*/     
            ERR_t act_button_err =  button_updateState(testNum);
            testNum++;
            
            /*Assert*/
            TEST_ASSERT_EQUAL_INT(exp_button_err,act_button_err);

            for(int i = 0 ; i < NUM_OF_BTNS ; i++)
                TEST_ASSERT_EQUAL_INT(Expected_buttonsState[i],ga_buttons_state[i]);

            TEST_ASSERT_EQUAL_INT(Expected_p_pressedTime,p_pressedTime);
        }
}  