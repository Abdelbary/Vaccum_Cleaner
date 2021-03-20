#include "src/config.h"










typedef enum

{

    BTN1,

    BTN2,

    BTN3

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



int p_pressedTime;

ERR_t button_init(void);

Buttons_state_t button_getState(Buttons_t btn);

ERR_t button_updateState(unsigned char testNum);
