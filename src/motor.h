#ifndef MOTOR_H
#define MOTOR_H
#include "config.h"



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

/**
* \b Description: motor_init initalize motor state to it's default values
*@param: void 
* <br>
*@return: ERR_t 
*
*
*@see     Config.h motor.c
*/
ERR_t motor_init(void);

/**
* \b Description: motor_setAngle set motor angle to the given paramter
*@param: motor_angles_t angle 
* <br>
*@return: ERR_t 
*
*
*@see     Config.h motor.c
*/
ERR_t motor_setAngle(motor_angles_t angle);

/**
* \b Description: motor_getAngel return motor current angle
*@param: motor_angles_t *angle 
* <br>
*@return: ERR_t 
*
*
*@see     Config.h motor.c
*/
ERR_t motor_getAngel(motor_angles_t *angle);

/**
* \b Description: SpeedControlTask Task runs every 50ms update motor angle
                    based on the updated buttons states
*@param: unsigned char testNum 
* <br>
*@return: ERR_t 
*
*
*@see     Config.h motor.c main.c
*/
void SpeedControlTask(unsigned char testNum);

 #endif // MOTOR_H
