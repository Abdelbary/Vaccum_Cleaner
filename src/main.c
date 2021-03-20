#include "main.h"
#include "motor.h"
#include "button.h"

STATIC unsigned char TestNum = 1;





#ifndef TEST
ERR_t main()
#else
ERR_t TestableMain()
#endif
{
    motor_init();
    button_init();

    while(TestNum <= TESTS)
    {
        SpeedControlTask(TestNum);
        TestNum++;
        /*a delay of 50 ms should be inserted*/
    }
    return OK;
}
