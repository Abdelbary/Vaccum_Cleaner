#include "button.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>




STATIC Button_ModuleState_t Button_gMoudleState = BTN_IDLE;







STATIC Buttons_state_t ga_buttons_state[NUM_OF_BTNS];

ERR_t button_init(void)
{
    /*
    *   1-check if the module already inited
    *   2-set the default state for the buttons
    *   3-set moudle state to initalized
    */
   if(Button_gMoudleState == BTN_INT)
   {
       return MULTIPLE_INIT_ERR;
   }
   else
   {
       Button_gMoudleState = BTN_INT;
       for(int i = 0 ; i < NUM_OF_BTNS ; i++)
            ga_buttons_state[i] = BTN_RELEASED;
   }
   return 0;
}


Buttons_state_t button_getState(Buttons_t btn)
{
    /*
    * if module is not initalized:
    *   return error
    * else 
    *     validate paramters
    *     if valid 
    *       return state of given btn number
    */
    if(btn < 0 || btn >= NUM_OF_BTNS )
    {
        return PARAM_OUT_OF_RANG_ERR;
    }
    else
    {
        return  ga_buttons_state[btn];
    }
}


ERR_t  button_updateState(unsigned char testNum)
{
    /*
    * if module is not initalized:
    *   return error
    * else 
    *     validate paramters
    *     if valid 
    *       update state of given btn number
    */
    if(Button_gMoudleState == BTN_IDLE)
    {
        return MODULE_IS_IDLE_ERR;
    }
    else
    {
        FILE* f = fopen(INPUT_FILE_ABS_PATH,"r+");
        char str1[20];
        char str2[20];
        char str3[20];
        char str4[20];

        if(f)
        {
            unsigned char i = 0 ;

            for(i = 0; i <= testNum; i++)
            {
                memset(str1,0,20);
                memset(str2,0,20);
                memset(str3,0,20);
                fscanf(f, "%s    %s    %s    %s\n",str1, str2, str3,str4);
            }

            char *ss[20] = {str1,str2,str3};

            /*this iteratation will only work if the values order in the input file is the same as the button enum*/
            for(int i = 0 ; i < NUM_OF_BTNS ; i++)
            {
                if(strcmp(ss[i],"BTN_PREPRESSED") == 0)
                {
                    ga_buttons_state[i] = BTN_PREPRESSED;
                }
                else if (strcmp(ss[i],"BTN_PRESSED") == 0)
                {
                    ga_buttons_state[i] = BTN_PRESSED;
                }
                else if(strcmp(ss[i],"BTN_PRERELEASED") == 0)
                {
                    ga_buttons_state[i] = BTN_PRERELEASED;
                }
                else if(strcmp(ss[i],"BTN_RELEASED") == 0)
                {
                    ga_buttons_state[i] = BTN_RELEASED;
                }
                else
                {
                    printf("Incorrect test data\n");
                    return OK;
                }
            }
            p_pressedTime = atoi(str4);
            //printf("unite undr test>>>%d %d %d %d %d\n",ga_buttons_state[0],ga_buttons_state[1],ga_buttons_state[2],ga_buttons_state[3],p_pressedTime);

            fclose(f);
        }
        else
        {
            printf("Failed To open the file");
        }

        

        return OK;
        /*update state*/
    }

}