#ifndef BUTTON_H
#define BUTTON_H
#include "config.h"

#define NUM_OF_BTNS 3

typedef enum
{
    BTN1, /*+ve*/
    BTN2, /*-ve*/
    BTN3  /*p*/
}Buttons_t;

typedef enum
{
    BTN_PREPRESSED,
    BTN_PRESSED,
    BTN_PRERELEASED,
    BTN_RELEASED
}Buttons_state_t;

typedef enum
{
    BTN_IDLE,
    BTN_INT
}Button_ModuleState_t;

int    p_pressedTime;


/**
* \b Description: button_init initalize the state  of button module
*@param: void 
* <br>
*@return: ERR_t 
*
*
*@see     Config.h button.c
*/
ERR_t  button_init(void);

/**
* \b Description: button_getState return the state of the given button
*@param: Buttons_t btn 
* <br>
*@return: Buttons_state_t 
*
*
*@see     Config.h button.c
*/
Buttons_state_t button_getState(Buttons_t btn);

/**
* \b Description: button_updateState update the state of the button from input file
*@param: unsigned char testNum 
* <br>
*@return: ERR_t 
*
*
*@see     Config.h button.c
*/
ERR_t  button_updateState(unsigned char testNum);

#endif // BUTTON_H
