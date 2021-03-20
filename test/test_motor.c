#include "unity.h"
#include "motor.h"
#include "mock_button.h"

void setUp(void)
{
}

void tearDown(void)
{
}

#define P           0
#define P_TIME      1
#define MINUS_VE    2
#define PLUSE_VE    3


char SW_CASE1[] = {BTN_PRESSED,30,BTN_PREPRESSED,BTN_PREPRESSED};    /*{p , p_time , -ve , +ve}*/
char SW_CASE2[] = {BTN_PRESSED,29,BTN_PREPRESSED,BTN_PREPRESSED};    /*{p , p_time , -ve , +ve}*/
char SW_CASE3[] = {BTN_PRESSED,10,BTN_PRESSED,BTN_PREPRESSED};    /*{p , p_time , -ve , +ve}*/
char SW_CASE4[] = {BTN_PREPRESSED,30,BTN_PREPRESSED,BTN_PREPRESSED}; /*{p , p_time , -ve , +ve}*/
char SW_CASE5[] = {BTN_PREPRESSED,30,BTN_RELEASED,BTN_PREPRESSED};   /*{p , p_time , -ve , +ve}*/
char SW_CASE6[] = {BTN_PREPRESSED,30,BTN_RELEASED,BTN_RELEASED};     /*{p , p_time , -ve , +ve}*/

extern  Motor_module_state_t Motor_gModuleState;
extern motor_angles_t Motor_gCurrentMotorAngle;

/***************************************************motor_init_test****************************************************/
/** Doxygen Test Case Description **/
void test_motor_init_should_return_OK_when_moduleIsIdel(void)
{

    /*!
        * @par Given : module uninited 
        * @par When  : motor_init() is called 
        * @par Then  : moudle return OK
    */

    /*setup*/
    Motor_gModuleState = MOTOR_IDLE; /*set module to unintalized state*/
    /*Expect*/
    ERR_t exp_motor_err = OK;
    /*Act*/     
    ERR_t act_motor_err =  motor_init();
        /*Assert*/
    TEST_ASSERT_EQUAL_INT(exp_motor_err,act_motor_err);
} 

/** Doxygen Test Case Description **/
void test_motor_init_should_setModuleStateToInited(void)
{

    /*!
        * @par Given : module uninited 
        * @par When  : motor_init() is called 
        * @par Then  : moudle state should be inited
    */

    /*setup*/
    Motor_gModuleState = MOTOR_IDLE; /*set module to unintalized state*/
    /*Expect*/
    ERR_t exp_motor_err = OK;
    /*Act*/     
    ERR_t act_motor_err =  motor_init();
    /*Assert*/
    TEST_ASSERT_EQUAL_INT(MOTOR_INT,Motor_gModuleState);
} 

/** Doxygen Test Case Description **/
void test_motor_init_should_setMotorAngleToMidAngle(void)
{

    /*!
        * @par Given : module uninited 
        * @par When  : motor_init() is called 
        * @par Then  : moudle motor_angel should be set to mediem speed as default
    */

    /*setup*/
    Motor_gModuleState = MOTOR_IDLE; /*set module to unintalized state*/
    Motor_gCurrentMotorAngle = -1;    /*set it to out of range state*/
    /*Expect*/
    ERR_t exp_motor_err = OK;
    motor_angles_t exp_motor_angle = MidAngle;
    /*Act*/     
    ERR_t act_motor_err =  motor_init();
    /*Assert*/
    TEST_ASSERT_EQUAL_INT(exp_motor_angle,Motor_gCurrentMotorAngle);
} 

/** Doxygen Test Case Description **/
void test_motor_init_should_return_MULTIPLE_INIT_ERR_when_calledWithModuleStateInited(void)
{

    /*!
        * @par Given : module inited 
        * @par When  : motor_init() is called 
        * @par Then  : moudle should return MULTIPLE_INIT_ERR
    */

    /*setup*/
    Motor_gModuleState = MOTOR_INT; /*set module to intalized state*/
    /*Expect*/
    ERR_t exp_motor_err = MULTIPLE_INIT_ERR;
    /*Act*/     
    ERR_t act_motor_err =  motor_init();
    /*Assert*/
    TEST_ASSERT_EQUAL_INT(exp_motor_err,act_motor_err);
} 

/***************************************************motor_setAngle_test****************************************************/
/** Doxygen Test Case Description **/
void test_motor_setAngle_should_return_MODULE_IS_IDLE_ERR_when_calledBeforInit(void)
{

    /*!
        * @par Given : module not inited 
        * @par When  : motor_setAngle() is called 
        * @par Then  : return MODULE_IS_IDLE_ERR
    */

    /*setup*/
    Motor_gModuleState = MOTOR_IDLE; /*set module to intalized state*/
    /*Expect*/
    ERR_t exp_motor_err = MODULE_IS_IDLE_ERR;
    /*Act*/     
    motor_angles_t testAngle  = MidAngle;
    ERR_t act_motor_err =  motor_setAngle(MidAngle);
    /*Assert*/
    TEST_ASSERT_EQUAL_INT(exp_motor_err,act_motor_err);
} 

/** Doxygen Test Case Description **/
void test_motor_setAngle_should_return_OK_InNormalOperation(void)
{

    /*!
        * @par Given : module  inited 
        * @par When  : motor_setAngle() is called with valid angle
        * @par Then  : return OK
    */

    /*setup*/
    Motor_gModuleState = MOTOR_INT; /*set module to intalized state*/
    /*Expect*/
    ERR_t exp_motor_err = OK;
    /*Act*/     
    motor_angles_t testAngle  = MidAngle;
    ERR_t act_motor_err =  motor_setAngle(MidAngle);
    /*Assert*/
    TEST_ASSERT_EQUAL_INT(exp_motor_err,act_motor_err);
} 

/** Doxygen Test Case Description **/
void test_motor_setAngle_should_return_PARAM_OUT_OF_RANG_ERR_when_angleGivenIsOutOfRange(void)
{

    /*!
        * @par Given : module  inited 
        * @par When  : motor_setAngle() is called with NON-valid angle
        *              tested Values {INT16_MIN,-1,9,141,100,INT16_MAX}
        * @par Then  : return PARAM_OUT_OF_RANG_ERR
    */

    /*setup*/
    Motor_gModuleState = MOTOR_INT; /*set module to intalized state*/
    motor_angles_t angles[] = {INT16_MIN,-1,9,141,100,INT16_MAX};
    /*Expect*/
    ERR_t exp_motor_err = PARAM_OUT_OF_RANG_ERR;
    /*Act*/     
    for(int i = 0 ; i < sizeof(angles)/sizeof(angles[0]) ; i++)
    {
        motor_angles_t testAngle  = angles[i];
        ERR_t act_motor_err =  motor_setAngle(angles[i]);
        /*Assert*/
        TEST_ASSERT_EQUAL_INT(exp_motor_err,act_motor_err);

    }
} 


/** Doxygen Test Case Description **/
void test_motor_setAngle_should_setAngle_when_angleIsPassedInValidRange(void)
{

    /*!
        * @par Given : module  inited 
        * @par When  : motor_setAngle() is called with valid angle
        * @par Then  : angle should be reflected on local variable
    */

    /*setup*/
    Motor_gModuleState = MOTOR_INT; /*set module to intalized state*/
    /*Expect*/
    ERR_t exp_motor_err = OK;
    /*Act*/     
    motor_angles_t Exp_angle  = MinAngle;
    ERR_t act_motor_err =  motor_setAngle(MinAngle);
    /*Assert*/
    TEST_ASSERT_EQUAL_INT(Motor_gCurrentMotorAngle,Exp_angle);
} 


/***************************************************motor_getSpeed_test****************************************************/

/** Doxygen Test Case Description **/
void test_motor_getAngle_should_return_MODULE_IS_IDLE_ERR_when_moduleIsIdle(void)
{

    /*!
        * @par Given : module  inited 
        * @par When  : motor_setAngle() is called with valid angle
        * @par Then  : angle should be reflected on local variable
    */

    /*setup*/
    Motor_gModuleState = MOTOR_IDLE; /*set module to idle state*/
    /*Expect*/
    ERR_t exp_motor_err = MODULE_IS_IDLE_ERR;
    /*Act*/     
    motor_angles_t angle;
    ERR_t act_motor_err =  motor_getAngel(&angle);
    /*Assert*/
    TEST_ASSERT_EQUAL_INT(exp_motor_err,act_motor_err);
} 

/** Doxygen Test Case Description **/
void test_motor_getAngle_should_get_setted_angle(void)
{

    /*!
        * @par Given : module  inited ,set angle called to set angle to specific value
        * @par When  : motor_getAngle() is called
        * @par Then  : angle should be returned as setted
    */

    /*setup*/
    motor_init();
    /*Expect*/
    motor_angles_t exp_angle = MidAngle;
    motor_setAngle(exp_angle);
    /*Act*/   
    motor_angles_t act_angle;  
    ERR_t act_motor_err =  motor_getAngel(&act_angle);
    /*Assert*/
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
} 

/** Doxygen Test Case Description **/
void test_motor_getAngle_should_return_OK_InNormalOperation(void)
{

    /*!
        * @par Given : module  inited ,set angle called to set angle to specific value
        * @par When  : motor_getAngle() is called
        * @par Then  : angle should be returned as setted
    */

    /*setup*/
    motor_init();
    /*Expect*/
    ERR_t exp_motor_err = OK;
    motor_angles_t exp_angle = MidAngle;
    motor_setAngle(exp_angle);
    /*Act*/   
    motor_angles_t act_angle;  
    ERR_t act_motor_err =  motor_getAngel(&act_angle);
    /*Assert*/
    TEST_ASSERT_EQUAL_INT(exp_motor_err,act_motor_err);
} 



/********************************************************SpeedControl***********************************************************/

static unsigned char testNum = 1;

/** Doxygen Test Case Description **/
void test_SpeedControlTask_should_setAngleToMid_when_angleIsMax_And_BTN3_Prepressed(void)
{
    /*!
        * @par Given : p switch BTN_PRESSED , angle is max , p_pressedTime >=30
        * @par When  : SpeedControl() is called 
        * @par Then  : angle change to mid angle
    */ 
    /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    motor_setAngle(MaxAngle);
    button_getState_ExpectAndReturn(BTN3,BTN_PRESSED);
    p_pressedTime = 50;
    /*Expect*/
    motor_angles_t exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}



/** Doxygen Test Case Description **/
void test_SpeedControlTask_should_setAngleToMin_when_angleIsMid_And_BTN3_Prepressed(void)
{
    /*!
        * @par Given : p switch BTN_PRESSED , angle is Mid , p_pressedTime >=30
        * @par When  : SpeedControl() is called 
        * @par Then  : angle change to Min angle
    */ 
    /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    motor_setAngle(MidAngle);
    button_getState_ExpectAndReturn(BTN3,BTN_PRESSED);
    p_pressedTime = 50;
    /*Expect*/
    motor_angles_t exp_angle = MinAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}


/** Doxygen Test Case Description **/
void test_SpeedControlTask_should_DoNoting_when_angleIsMax_And_BTN3_Prepressed_And_AngleIsMin(void)
{
    /*!
        * @par Given : p switch BTN_PRESSED , angle is min , p_pressedTime >=30
        * @par When  : SpeedControl() is called 
        * @par Then  : angle change to mid angle
    */ 
    /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    motor_setAngle(MinAngle);
    button_getState_ExpectAndReturn(BTN3,BTN_PRESSED);
    button_getState_ExpectAndReturn(BTN2,BTN_RELEASED);
    button_getState_ExpectAndReturn(BTN1,BTN_RELEASED);
    p_pressedTime = 50;
    /*Expect*/
    motor_angles_t exp_angle = MinAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}

/** Doxygen Test Case Description **/
void test_SpeedControlTask_Angle_should_StayTheSame_when_angleIsMid_And_BTN3_Prepressed_And_pressTimeBelowThreshold(void)
{
    /*!
        * @par Given : p switch BTN_PRESSED , angle is Mid , p_pressedTime < 30 , BTN2 releasd ,BTN1 released 
        * @par When  : SpeedControl() is called 
        * @par Then  : angle stay same _Min angle_
    */ 
    /*Setup*/
    motor_setAngle(MidAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    p_pressedTime = 10;
    button_getState_ExpectAndReturn(BTN3,BTN_PRESSED);
    button_getState_ExpectAndReturn(BTN2,BTN_RELEASED);
    button_getState_ExpectAndReturn(BTN1,BTN_RELEASED);

    /*Expect*/
    motor_angles_t exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}

/** Doxygen Test Case Description **/
void test_SpeedControlTask_Angle_should_setToMinAngel_when_angleIsMid_And_BTN3_NOT_Prepressed_And_BTN2_PREPRESSED(void)
{
    /*!
        * @par Given : p switch prepressed , angle is Mid , p_pressedTime = 0 , -ve prepressed
        * @par When  : SpeedControl() is called 
        * @par Then  : angle change to Min angle
    */ 
    /*Setup*/
    motor_setAngle(MidAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    p_pressedTime = 0;
    button_getState_ExpectAndReturn(BTN3,BTN_PREPRESSED);
    button_getState_ExpectAndReturn(BTN2,BTN_PREPRESSED);
    /*Expect*/
    motor_angles_t exp_angle = MinAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}




/** Doxygen Test Case Description **/
void test_SpeedControlTask_Angle_should_setToMidAngel_when_angleIsMax_And_BTN3_NOT_Prepressed_And_BTN2_PREPRESSED(void)
{
    /*!
        * @par Given : p switch prepressed , angle is Max , p_pressedTime = 0 , -ve prepressed
        * @par When  : SpeedControl() is called 
        * @par Then  : angle change to Mid angle
    */ 
    /*Setup*/
    motor_setAngle(MaxAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    p_pressedTime = 0;
    button_getState_ExpectAndReturn(BTN3,BTN_PREPRESSED);
    button_getState_ExpectAndReturn(BTN2,BTN_PREPRESSED);
    /*Expect*/
    motor_angles_t exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}


/** Doxygen Test Case Description **/
void test_SpeedControlTask_Angle_should_DoNothing_when_angleIsMin_And_BTN3_NOT_Prepressed_And_BTN2_PREPRESSED_And_BTN1_RELEASED(void)
{
    /*!
        * @par Given : p switch prepressed , angle is Min , p_pressedTime = 0 , -ve prepressed
        * @par When  : SpeedControl() is called 
        * @par Then  : angle stay same _ Min angle_
    */ 
    /*Setup*/
    motor_setAngle(MinAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    p_pressedTime = 0;
    button_getState_ExpectAndReturn(BTN3,BTN_PREPRESSED);
    button_getState_ExpectAndReturn(BTN2,BTN_PREPRESSED);
    button_getState_ExpectAndReturn(BTN1,BTN_RELEASED);
    /*Expect*/
    motor_angles_t exp_angle = MinAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}

/** Doxygen Test Case Description **/
void test_SpeedControlTask_Angle_should_setToMidAngel_when_angleIsMin_And_BTN3_NOT_Prepressed_And_BTN2_Not_prePressed_And_BTN1_prePressed(void)
{
    /*!
        * @par Given : p switch prepressed , angle is Min , p_pressedTime = 0 , -ve Released , +ve Prepressed
        * @par When  : SpeedControl() is called 
        * @par Then  : angle change to Mid angle
    */ 
    /*Setup*/
    motor_setAngle(MinAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    p_pressedTime = 0;
    button_getState_ExpectAndReturn(BTN3,BTN_RELEASED);
    button_getState_ExpectAndReturn(BTN2,BTN_RELEASED);
    button_getState_ExpectAndReturn(BTN1,BTN_PREPRESSED);
    /*Expect*/
    motor_angles_t exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}

/** Doxygen Test Case Description **/
void test_SpeedControlTask_Angle_should_DoNothing_when_angleIsMax_And_BTN3_NOT_Prepressed_And_BTN2_Not_prePressed_And_BTN1_prePressed(void)
{
    /*!
        * @par Given : p switch prepressed , angle is MAx , p_pressedTime = 0 , -ve Released , +ve Prepressed
        * @par When  : SpeedControl() is called 
        * @par Then  : angle stay the same _MAX_
    */ 
    /*Setup*/
    motor_setAngle(MaxAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    p_pressedTime = 0;
    button_getState_ExpectAndReturn(BTN3,BTN_RELEASED);
    button_getState_ExpectAndReturn(BTN2,BTN_RELEASED);
    button_getState_ExpectAndReturn(BTN1,BTN_PREPRESSED);
    /*Expect*/
    motor_angles_t exp_angle = MaxAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}

/** Doxygen Test Case Description **/
void test_SpeedControlTask_Angle_should_DoNothing_when_angleIsMax_And_AllReleased(void)
{
    /*!
        * @par Given : p switch Released , angle is MAx , p_pressedTime = 0 , -ve Released , +ve Released
        * @par When  : SpeedControl() is called 
        * @par Then  : angle stay the same _MAX_
    */ 
    /*Setup*/
    motor_setAngle(MaxAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    p_pressedTime = 0;
    button_getState_ExpectAndReturn(BTN3,BTN_RELEASED);
    button_getState_ExpectAndReturn(BTN2,BTN_RELEASED);
    button_getState_ExpectAndReturn(BTN1,BTN_RELEASED);
    /*Expect*/
    motor_angles_t exp_angle = MaxAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}

/************************1-switch coverage for speed control*****************************************/

/** Doxygen Test Case Description **/
void test_SpeedControlTask_switchCoverage_TreeFirstBranch_MIN_MID_MIN_MID(void)
{
    /*!
        * @par Given : MinAngle -> sw Case 5 -> Mid Angle -> Sw Case 1 -> MinAgnle -> SW Cas5 -> Mid Angle
        * @par When  : SpeedControl() is called 
        * @par Then  : angle change to mid angle
    */ 
    /*Setup*/
    motor_setAngle(MinAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE5[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE5[MINUS_VE]);
    button_getState_ExpectAndReturn(BTN1,SW_CASE5[PLUSE_VE]);
    p_pressedTime = SW_CASE5[P_TIME];
    /*Expect*/
    motor_angles_t exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);


     /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE1[P]);
    //button_getState_ExpectAndReturn(BTN2,SW_CASE1[MINUS_VE]);
    //button_getState_ExpectAndReturn(BTN1,SW_CASE1[PLUSE_VE]);
    p_pressedTime = SW_CASE1[P_TIME];
    /*Expect*/
    exp_angle = MinAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);


    /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE5[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE5[MINUS_VE]);
    button_getState_ExpectAndReturn(BTN1,SW_CASE5[PLUSE_VE]);
    p_pressedTime = SW_CASE5[P_TIME];
    /*Expect*/
    exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);

}



/** Doxygen Test Case Description **/
void test_SpeedControlTask_switchCoverage_TreeSecondBranch_MIN_MID_MIN_MID(void)
{
    /*!
        * @par Given : MinAngle -> sw Case 5 -> Mid Angle -> Sw Case 2 -> MinAgnle -> SW Cas5 -> Mid Angle
        * @par When  : SpeedControl() is called 
        * @par Then  : angle change to mid angle
    */ 
    /*Setup*/
    motor_setAngle(MinAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE5[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE5[MINUS_VE]);
    button_getState_ExpectAndReturn(BTN1,SW_CASE5[PLUSE_VE]);
    p_pressedTime = SW_CASE5[P_TIME];
    /*Expect*/
    motor_angles_t exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);


     /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE2[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE2[MINUS_VE]);
    //button_getState_ExpectAndReturn(BTN1,SW_CASE1[PLUSE_VE]);
    p_pressedTime = SW_CASE2[P_TIME];
    /*Expect*/
    exp_angle = MinAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);


    /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE5[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE5[MINUS_VE]);
    button_getState_ExpectAndReturn(BTN1,SW_CASE5[PLUSE_VE]);
    p_pressedTime = SW_CASE5[P_TIME];
    /*Expect*/
    exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);

}


/** Doxygen Test Case Description **/
void test_SpeedControlTask_switchCoverage_TreeThirdBranch_MIN_MID_MIN_MID(void)
{
    /*!
        * @par Given : MinAngle -> sw Case 5 -> Mid Angle -> Sw Case 4 -> MinAgnle -> SW Cas5 -> Mid Angle
        * @par When  : SpeedControl() is called 
        * @par Then  : angle change to mid angle
    */ 
    /*Setup*/
    motor_setAngle(MinAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE5[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE5[MINUS_VE]);
    button_getState_ExpectAndReturn(BTN1,SW_CASE5[PLUSE_VE]);
    p_pressedTime = SW_CASE5[P_TIME];
    /*Expect*/
    motor_angles_t exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);


     /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE4[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE4[MINUS_VE]);
    //button_getState_ExpectAndReturn(BTN1,SW_CASE1[PLUSE_VE]);
    p_pressedTime = SW_CASE4[P_TIME];
    /*Expect*/
    exp_angle = MinAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);


    /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE5[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE5[MINUS_VE]);
    button_getState_ExpectAndReturn(BTN1,SW_CASE5[PLUSE_VE]);
    p_pressedTime = SW_CASE5[P_TIME];
    /*Expect*/
    exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}



/** Doxygen Test Case Description **/
void test_SpeedControlTask_switchCoverage_TreeForthBranch_MIN_MID_MAX_MID(void)
{
    /*!
        * @par Given : MinAngle -> sw Case 5 -> Mid Angle -> Sw Case 5 -> MaxAgnle -> SW Cas1 -> Mid Angle
        * @par When  : SpeedControl() is called 
        * @par Then  : angle change to mid angle
    */ 
    /*Setup*/
    motor_setAngle(MinAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE5[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE5[MINUS_VE]);
    button_getState_ExpectAndReturn(BTN1,SW_CASE5[PLUSE_VE]);
    p_pressedTime = SW_CASE5[P_TIME];
    /*Expect*/
    motor_angles_t exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);


     /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE5[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE5[MINUS_VE]);
    button_getState_ExpectAndReturn(BTN1,SW_CASE5[PLUSE_VE]);
    p_pressedTime = SW_CASE5[P_TIME];
    /*Expect*/
    exp_angle = MaxAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);


    /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE1[P]);
    //button_getState_ExpectAndReturn(BTN2,SW_CASE1[MINUS_VE]);
    //button_getState_ExpectAndReturn(BTN1,SW_CASE1[PLUSE_VE]);
    p_pressedTime = SW_CASE1[P_TIME];
    /*Expect*/
    exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}


/** Doxygen Test Case Description **/
void test_SpeedControlTask_switchCoverage_TreeFifthBranch_MIN_MID_MAX_MID(void)
{
    /*!
        * @par Given : MinAngle -> sw Case 5 -> Mid Angle -> Sw Case 5 -> MaxAgnle -> SW Cas2 -> Mid Angle
        * @par When  : SpeedControl() is called 
        * @par Then  : angle change to mid angle
    */ 
    /*Setup*/
    motor_setAngle(MinAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE5[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE5[MINUS_VE]);
    button_getState_ExpectAndReturn(BTN1,SW_CASE5[PLUSE_VE]);
    p_pressedTime = SW_CASE5[P_TIME];
    /*Expect*/
    motor_angles_t exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);


     /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE5[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE5[MINUS_VE]);
    button_getState_ExpectAndReturn(BTN1,SW_CASE5[PLUSE_VE]);
    p_pressedTime = SW_CASE2[P_TIME];
    /*Expect*/
    exp_angle = MaxAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);


    /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE2[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE2[MINUS_VE]);
    //button_getState_ExpectAndReturn(BTN1,SW_CASE1[PLUSE_VE]);
    p_pressedTime = SW_CASE2[P_TIME];
    /*Expect*/
    exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}


/** Doxygen Test Case Description **/
void test_SpeedControlTask_switchCoverage_TreeSixthBranch_MIN_MID_MAX_MID(void)
{
    /*!
        * @par Given : MinAngle -> sw Case 5 -> Mid Angle -> Sw Case 5 -> MaxAgnle -> SW Cas4-> Mid Angle
        * @par When  : SpeedControl() is called 
        * @par Then  : angle change to mid angle
    */ 
    /*Setup*/
    motor_setAngle(MinAngle);
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE5[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE5[MINUS_VE]);
    button_getState_ExpectAndReturn(BTN1,SW_CASE5[PLUSE_VE]);
    p_pressedTime = SW_CASE5[P_TIME];
    /*Expect*/
    motor_angles_t exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_angles_t act_angle;
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);


     /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE5[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE5[MINUS_VE]);
    button_getState_ExpectAndReturn(BTN1,SW_CASE5[PLUSE_VE]);
    p_pressedTime = SW_CASE2[P_TIME];
    /*Expect*/
    exp_angle = MaxAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);


    /*Setup*/
    button_updateState_ExpectAndReturn(testNum,OK);
    button_getState_ExpectAndReturn(BTN3,SW_CASE4[P]);
    button_getState_ExpectAndReturn(BTN2,SW_CASE4[MINUS_VE]);
    //button_getState_ExpectAndReturn(BTN1,SW_CASE4[PLUSE_VE]);
    p_pressedTime = SW_CASE4[P_TIME];
    /*Expect*/
    exp_angle = MidAngle;

    /*Act*/     
    SpeedControlTask(testNum++);
    motor_getAngel(&act_angle);
    /*Assert*/ 
    TEST_ASSERT_EQUAL_INT(exp_angle,act_angle);
}