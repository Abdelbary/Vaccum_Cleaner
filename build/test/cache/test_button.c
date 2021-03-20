#include "build/temp/_test_button.c"
#include "src/button.h"
#include "C:/Ruby27-x64/lib/ruby/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"






extern Button_ModuleState_t Button_gMoudleState;

extern Buttons_state_t ga_buttons_state[3];



void setUp(void)

{

    Button_gMoudleState = BTN_INT;

}





void tearDown(void)

{

    Button_gMoudleState = BTN_IDLE;



}









void test_button_init_should_returnNoError_when_calledFirstTime()

{

    Button_gMoudleState = BTN_IDLE;

    UnityAssertEqualNumber((UNITY_INT)((OK)), (UNITY_INT)((button_init())), (

   ((void *)0)

   ), (UNITY_UINT)(37), UNITY_DISPLAY_STYLE_INT);

}







void test_button_init_should_return_multiInitError_when_initaitedMultipleTimes(void)

{

    UnityAssertEqualNumber((UNITY_INT)((MULTIPLE_INIT_ERR)), (UNITY_INT)((button_init())), (

   ((void *)0)

   ), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((MULTIPLE_INIT_ERR)), (UNITY_INT)((button_init())), (

   ((void *)0)

   ), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);

}





void test_button_init_should_initalizeBtnStateToRelased(void)

{

    Button_gMoudleState = BTN_IDLE;



    for(int i = 0 ; i < 3 ; i++)

        ga_buttons_state[i] = BTN_PRESSED;





    UnityAssertEqualNumber((UNITY_INT)((OK)), (UNITY_INT)((button_init())), (

   ((void *)0)

   ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);





    for(int i = 0 ; i < 3 ; i++)

        UnityAssertEqualNumber((UNITY_INT)((BTN_RELEASED)), (UNITY_INT)((ga_buttons_state[i])), (

       ((void *)0)

       ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_INT);



}









void test_Button_getState_should_returnTheStateOFGivenButton(void)

{













       for(int i = 0 ; i < 3 ; i++)

       {



            ga_buttons_state[i] = i%4;

            Buttons_state_t button_expected_state = i%4;





            Buttons_state_t button_actual_state = button_getState(i);





            UnityAssertEqualNumber((UNITY_INT)((button_expected_state)), (UNITY_INT)((button_actual_state)), (

           ((void *)0)

           ), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_INT);

       }

}





void test_Button_getState_should_return_PARAM_OUT_OF_RANG_when_passed_OFR_PARM(void)

{

        int arr[] = {

                    (-32768)

                             ,-1,3,

                                             32767

                                                      };





        for(int i = 0 ; i < sizeof(arr)/sizeof(arr[0]) ; i++)

        {



            ERR_t exp_button_err = PARAM_OUT_OF_RANG_ERR;



            ERR_t act_button_err = button_getState(arr[i]);



            UnityAssertEqualNumber((UNITY_INT)((exp_button_err)), (UNITY_INT)((act_button_err)), (

           ((void *)0)

           ), (UNITY_UINT)(131), UNITY_DISPLAY_STYLE_INT);



        }

}







uint8_t updatedataFromFile(char * fileName,Buttons_state_t *Exp_buttonState,unsigned char *Exp_button_P_presstime)

{

    static char fristTime =1;



    static FILE *filePointer ;





    char dataToBeRead[200];



    if(fristTime)

    {





        filePointer = fopen(fileName, "r") ;







        if ( filePointer == 

                           ((void *)0) 

                                )

        {

            printf( "%s file failed to open.",fileName ) ;



            return 0;

        }

        fgets ( dataToBeRead, 200, filePointer );



        fristTime = 0;

    }



    if( fgets ( dataToBeRead, 200, filePointer ) != 

                                                                ((void *)0) 

                                                                     )

    {





        char * pch = strtok (dataToBeRead,"    ");

        char counter = 0 ;

        while (pch != 

                     ((void *)0)

                         )

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

            pch = strtok (

                         ((void *)0)

                             , "    ");

        }

        return 1;



    }

    else

    {



        fclose(filePointer) ;

        return 0;

    }

}



void test_Button_updateState_should_return_OK_when_moduleIsInited(void)

{















        ERR_t exp_button_err = OK;







        unsigned char testNum = 1;

        ERR_t act_button_err = button_updateState(testNum);



        UnityAssertEqualNumber((UNITY_INT)((exp_button_err)), (UNITY_INT)((act_button_err)), (

       ((void *)0)

       ), (UNITY_UINT)(218), UNITY_DISPLAY_STYLE_INT);

}







void test_Button_updateState_should_return_MODUL_IS_IDLE_when_moduleIsNotInited(void)

{















        Button_gMoudleState = BTN_IDLE;



        ERR_t exp_button_err = MODULE_IS_IDLE_ERR;







        unsigned char testNum = 1;

        ERR_t act_button_err = button_updateState(testNum);



        UnityAssertEqualNumber((UNITY_INT)((exp_button_err)), (UNITY_INT)((act_button_err)), (

       ((void *)0)

       ), (UNITY_UINT)(241), UNITY_DISPLAY_STYLE_INT);

}





void test_Button_updateState_should_update_buttonsState(void)

{















        ERR_t exp_button_err = OK;



        Buttons_state_t Expected_buttonsState[3];

        unsigned char Expected_p_pressedTime = -1;

        unsigned char testNum = 1;

        while(updatedataFromFile(("W:\\scienceAndStuff\\projects&code\\vaccum_Cleaner\\Vaccum_Cleaner\\src\\SwitchStateInput.txt"),Expected_buttonsState,&Expected_p_pressedTime))

        {





            for(int i =0 ; i < 3 ; i++)

                ga_buttons_state[i] = -1;



            p_pressedTime = -1;







            ERR_t act_button_err = button_updateState(testNum);

            testNum++;





            UnityAssertEqualNumber((UNITY_INT)((exp_button_err)), (UNITY_INT)((act_button_err)), (

           ((void *)0)

           ), (UNITY_UINT)(274), UNITY_DISPLAY_STYLE_INT);



            for(int i = 0 ; i < 3 ; i++)

                UnityAssertEqualNumber((UNITY_INT)((Expected_buttonsState[i])), (UNITY_INT)((ga_buttons_state[i])), (

               ((void *)0)

               ), (UNITY_UINT)(277), UNITY_DISPLAY_STYLE_INT);



            UnityAssertEqualNumber((UNITY_INT)((Expected_p_pressedTime)), (UNITY_INT)((p_pressedTime)), (

           ((void *)0)

           ), (UNITY_UINT)(279), UNITY_DISPLAY_STYLE_INT);

        }

}
