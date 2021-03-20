#include "motor.h"
#include "button.h"
#include  <stdio.h>
STATIC motor_angles_t Motor_gCurrentMotorAngle;
STATIC Motor_module_state_t Motor_gModuleState = MOTOR_IDLE;

ERR_t motor_init()
{
    if(Motor_gModuleState == MOTOR_INT)
    {
        return MULTIPLE_INIT_ERR;
    }
    else
    {
        Motor_gCurrentMotorAngle = MidAngle;
        Motor_gModuleState = MOTOR_INT;
        return OK;
    }
    
    
    
}
ERR_t motor_setAngle(motor_angles_t angle)
{
    if(Motor_gModuleState == MOTOR_IDLE)
    {
        return MODULE_IS_IDLE_ERR;
    }
    else if(angle != MinAngle && angle != MidAngle && angle != MaxAngle)
    {
        return PARAM_OUT_OF_RANG_ERR;
    }
    else
    {
       Motor_gCurrentMotorAngle = angle;
       return OK;
    }
}

ERR_t motor_getAngel(motor_angles_t *angle)
{
    if(Motor_gModuleState == MOTOR_IDLE)
    {
        return MODULE_IS_IDLE_ERR;
    }
    else
    {
        *angle = Motor_gCurrentMotorAngle ;
        return OK;
    }
}


void SpeedControlTask(unsigned char testNum)
{
    button_updateState(testNum);
    static FILE * fp;
    static unsigned char firstTime = 1;
    if(firstTime)
    {
        fp = fopen (OUTPUT_FILE_ABS_PATH,"w");
        firstTime = 0;
    }
  

    if(button_getState(BTN3) == BTN_PRESSED &&  Motor_gCurrentMotorAngle != MinAngle && p_pressedTime >= 30)
    {
        switch (Motor_gCurrentMotorAngle)
        {
        case MaxAngle:
            motor_setAngle(MidAngle);   
            break;
        case MidAngle:
            motor_setAngle(MinAngle);
            break;
        default:
            printf("Angle is not valid\n");
            break;
        }
    }
    else if(button_getState(BTN2) == BTN_PREPRESSED &&  Motor_gCurrentMotorAngle != MinAngle)
    {
        switch (Motor_gCurrentMotorAngle)
        {
        case MaxAngle:
            motor_setAngle(MidAngle);   
            break;
        case MidAngle:
            motor_setAngle(MinAngle);
            break;
        default:
            printf("Angle is not valid\n");
            break;
        }
    }
    else if(button_getState(BTN1) == BTN_PREPRESSED &&  Motor_gCurrentMotorAngle != MaxAngle)
    {
        switch (Motor_gCurrentMotorAngle)
        {
        case MinAngle:
            motor_setAngle(MidAngle);   
            break;
        case MidAngle:
            motor_setAngle(MaxAngle);
            break;
        default:
            printf("Angle is not valid\n");
            break;
        }
    }

    fprintf (fp, "TestNum %d : %d\n",testNum,Motor_gCurrentMotorAngle);

    if(testNum == TESTS)
    {
        /* close the file*/  
        fclose (fp);
    }


}
