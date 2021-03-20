#include "src/config.h"










typedef enum

{

    MinAngle = 10,

    MidAngle = 90,

    MaxAngle = 140

}motor_angles_t;



typedef enum

{

    MOTOR_IDLE,

    MOTOR_INT

}Motor_module_state_t;

ERR_t motor_init(void);

ERR_t motor_setAngle(motor_angles_t angle);

ERR_t motor_getAngel(motor_angles_t *angle);

void SpeedControlTask(unsigned char testNum);
