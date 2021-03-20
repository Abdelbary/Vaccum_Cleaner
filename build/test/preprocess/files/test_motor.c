#include "build/temp/_test_motor.c"
#include "build/test/mocks/mock_button.h"
#include "src/motor.h"
#include "C:/Ruby27-x64/lib/ruby/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


void setUp(void)

{

}



void tearDown(void)

{

}















char SW_CASE1[] = {BTN_PRESSED,30,BTN_PREPRESSED,BTN_PREPRESSED};

char SW_CASE2[] = {BTN_PRESSED,29,BTN_PREPRESSED,BTN_PREPRESSED};

char SW_CASE3[] = {BTN_PRESSED,10,BTN_PRESSED,BTN_PREPRESSED};

char SW_CASE4[] = {BTN_PREPRESSED,30,BTN_PREPRESSED,BTN_PREPRESSED};

char SW_CASE5[] = {BTN_PREPRESSED,30,BTN_RELEASED,BTN_PREPRESSED};

char SW_CASE6[] = {BTN_PREPRESSED,30,BTN_RELEASED,BTN_RELEASED};



extern Motor_module_state_t Motor_gModuleState;

extern motor_angles_t Motor_gCurrentMotorAngle;







void test_motor_init_should_return_OK_when_moduleIsIdel(void)

{

    Motor_gModuleState = MOTOR_IDLE;



    ERR_t exp_motor_err = OK;



    ERR_t act_motor_err = motor_init();



    UnityAssertEqualNumber((UNITY_INT)((exp_motor_err)), (UNITY_INT)((act_motor_err)), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

}





void test_motor_init_should_setModuleStateToInited(void)

{

    Motor_gModuleState = MOTOR_IDLE;



    ERR_t exp_motor_err = OK;



    ERR_t act_motor_err = motor_init();



    UnityAssertEqualNumber((UNITY_INT)((MOTOR_INT)), (UNITY_INT)((Motor_gModuleState)), (

   ((void *)0)

   ), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

}





void test_motor_init_should_setMotorAngleToMidAngle(void)

{

    Motor_gModuleState = MOTOR_IDLE;

    Motor_gCurrentMotorAngle = -1;



    ERR_t exp_motor_err = OK;

    motor_angles_t exp_motor_angle = MidAngle;



    ERR_t act_motor_err = motor_init();



    UnityAssertEqualNumber((UNITY_INT)((exp_motor_angle)), (UNITY_INT)((Motor_gCurrentMotorAngle)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);

}





void test_motor_init_should_return_MULTIPLE_INIT_ERR_when_calledWithModuleStateInited(void)

{

    Motor_gModuleState = MOTOR_INT;



    ERR_t exp_motor_err = MULTIPLE_INIT_ERR;



    ERR_t act_motor_err = motor_init();



    UnityAssertEqualNumber((UNITY_INT)((exp_motor_err)), (UNITY_INT)((act_motor_err)), (

   ((void *)0)

   ), (UNITY_UINT)(109), UNITY_DISPLAY_STYLE_INT);

}







void test_motor_setAngle_should_return_MODULE_IS_IDLE_ERR_when_calledBeforInit(void)

{

    Motor_gModuleState = MOTOR_IDLE;



    ERR_t exp_motor_err = MODULE_IS_IDLE_ERR;



    motor_angles_t testAngle = MidAngle;

    ERR_t act_motor_err = motor_setAngle(MidAngle);



    UnityAssertEqualNumber((UNITY_INT)((exp_motor_err)), (UNITY_INT)((act_motor_err)), (

   ((void *)0)

   ), (UNITY_UINT)(131), UNITY_DISPLAY_STYLE_INT);

}





void test_motor_setAngle_should_return_OK_InNormalOperation(void)

{

    Motor_gModuleState = MOTOR_INT;



    ERR_t exp_motor_err = OK;



    motor_angles_t testAngle = MidAngle;

    ERR_t act_motor_err = motor_setAngle(MidAngle);



    UnityAssertEqualNumber((UNITY_INT)((exp_motor_err)), (UNITY_INT)((act_motor_err)), (

   ((void *)0)

   ), (UNITY_UINT)(152), UNITY_DISPLAY_STYLE_INT);

}





void test_motor_setAngle_should_return_PARAM_OUT_OF_RANG_ERR_when_angleGivenIsOutOfRange(void)

{

    Motor_gModuleState = MOTOR_INT;

    motor_angles_t angles[] = {

                              (-32768)

                                       ,-1,9,141,100,

                                                     32767

                                                              };



    ERR_t exp_motor_err = PARAM_OUT_OF_RANG_ERR;



    for(int i = 0 ; i < sizeof(angles)/sizeof(angles[0]) ; i++)

    {

        motor_angles_t testAngle = angles[i];

        ERR_t act_motor_err = motor_setAngle(angles[i]);



        UnityAssertEqualNumber((UNITY_INT)((exp_motor_err)), (UNITY_INT)((act_motor_err)), (

       ((void *)0)

       ), (UNITY_UINT)(177), UNITY_DISPLAY_STYLE_INT);



    }

}







void test_motor_setAngle_should_setAngle_when_angleIsPassedInValidRange(void)

{

    Motor_gModuleState = MOTOR_INT;



    ERR_t exp_motor_err = OK;



    motor_angles_t Exp_angle = MinAngle;

    ERR_t act_motor_err = motor_setAngle(MinAngle);



    UnityAssertEqualNumber((UNITY_INT)((Motor_gCurrentMotorAngle)), (UNITY_INT)((Exp_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(201), UNITY_DISPLAY_STYLE_INT);

}











void test_motor_getAngle_should_return_MODULE_IS_IDLE_ERR_when_moduleIsIdle(void)

{

    Motor_gModuleState = MOTOR_IDLE;



    ERR_t exp_motor_err = MODULE_IS_IDLE_ERR;



    motor_angles_t angle;

    ERR_t act_motor_err = motor_getAngel(&angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_motor_err)), (UNITY_INT)((act_motor_err)), (

   ((void *)0)

   ), (UNITY_UINT)(225), UNITY_DISPLAY_STYLE_INT);

}





void test_motor_getAngle_should_get_setted_angle(void)

{

    motor_init();



    motor_angles_t exp_angle = MidAngle;

    motor_setAngle(exp_angle);



    motor_angles_t act_angle;

    ERR_t act_motor_err = motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(247), UNITY_DISPLAY_STYLE_INT);

}





void test_motor_getAngle_should_return_OK_InNormalOperation(void)

{

    motor_init();



    ERR_t exp_motor_err = OK;

    motor_angles_t exp_angle = MidAngle;

    motor_setAngle(exp_angle);



    motor_angles_t act_angle;

    ERR_t act_motor_err = motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_motor_err)), (UNITY_INT)((act_motor_err)), (

   ((void *)0)

   ), (UNITY_UINT)(270), UNITY_DISPLAY_STYLE_INT);

}











static unsigned char testNum = 1;





void test_SpeedControlTask_should_setAngleToMid_when_angleIsMax_And_BTN3_Prepressed(void)

{













    button_updateState_CMockExpectAndReturn(288, testNum, OK);

    motor_setAngle(MaxAngle);

    button_getState_CMockExpectAndReturn(290, BTN3, BTN_PRESSED);

    p_pressedTime = 50;



    motor_angles_t exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(300), UNITY_DISPLAY_STYLE_INT);

}









void test_SpeedControlTask_should_setAngleToMin_when_angleIsMid_And_BTN3_Prepressed(void)

{













    button_updateState_CMockExpectAndReturn(314, testNum, OK);

    motor_setAngle(MidAngle);

    button_getState_CMockExpectAndReturn(316, BTN3, BTN_PRESSED);

    p_pressedTime = 50;



    motor_angles_t exp_angle = MinAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(326), UNITY_DISPLAY_STYLE_INT);

}







void test_SpeedControlTask_should_DoNoting_when_angleIsMax_And_BTN3_Prepressed_And_AngleIsMin(void)

{













    button_updateState_CMockExpectAndReturn(339, testNum, OK);

    motor_setAngle(MinAngle);

    button_getState_CMockExpectAndReturn(341, BTN3, BTN_PRESSED);

    button_getState_CMockExpectAndReturn(342, BTN2, BTN_RELEASED);

    button_getState_CMockExpectAndReturn(343, BTN1, BTN_RELEASED);

    p_pressedTime = 50;



    motor_angles_t exp_angle = MinAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(353), UNITY_DISPLAY_STYLE_INT);

}





void test_SpeedControlTask_Angle_should_StayTheSame_when_angleIsMid_And_BTN3_Prepressed_And_pressTimeBelowThreshold(void)

{













    motor_setAngle(MidAngle);

    button_updateState_CMockExpectAndReturn(366, testNum, OK);

    p_pressedTime = 10;

    button_getState_CMockExpectAndReturn(368, BTN3, BTN_PRESSED);

    button_getState_CMockExpectAndReturn(369, BTN2, BTN_RELEASED);

    button_getState_CMockExpectAndReturn(370, BTN1, BTN_RELEASED);





    motor_angles_t exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(380), UNITY_DISPLAY_STYLE_INT);

}





void test_SpeedControlTask_Angle_should_setToMinAngel_when_angleIsMid_And_BTN3_NOT_Prepressed_And_BTN2_PREPRESSED(void)

{













    motor_setAngle(MidAngle);

    button_updateState_CMockExpectAndReturn(393, testNum, OK);

    p_pressedTime = 0;

    button_getState_CMockExpectAndReturn(395, BTN3, BTN_PREPRESSED);

    button_getState_CMockExpectAndReturn(396, BTN2, BTN_PREPRESSED);



    motor_angles_t exp_angle = MinAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(405), UNITY_DISPLAY_STYLE_INT);

}











void test_SpeedControlTask_Angle_should_setToMidAngel_when_angleIsMax_And_BTN3_NOT_Prepressed_And_BTN2_PREPRESSED(void)

{













    motor_setAngle(MaxAngle);

    button_updateState_CMockExpectAndReturn(421, testNum, OK);

    p_pressedTime = 0;

    button_getState_CMockExpectAndReturn(423, BTN3, BTN_PREPRESSED);

    button_getState_CMockExpectAndReturn(424, BTN2, BTN_PREPRESSED);



    motor_angles_t exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(433), UNITY_DISPLAY_STYLE_INT);

}







void test_SpeedControlTask_Angle_should_DoNothing_when_angleIsMin_And_BTN3_NOT_Prepressed_And_BTN2_PREPRESSED_And_BTN1_RELEASED(void)

{













    motor_setAngle(MinAngle);

    button_updateState_CMockExpectAndReturn(447, testNum, OK);

    p_pressedTime = 0;

    button_getState_CMockExpectAndReturn(449, BTN3, BTN_PREPRESSED);

    button_getState_CMockExpectAndReturn(450, BTN2, BTN_PREPRESSED);

    button_getState_CMockExpectAndReturn(451, BTN1, BTN_RELEASED);



    motor_angles_t exp_angle = MinAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(460), UNITY_DISPLAY_STYLE_INT);

}





void test_SpeedControlTask_Angle_should_setToMidAngel_when_angleIsMin_And_BTN3_NOT_Prepressed_And_BTN2_Not_prePressed_And_BTN1_prePressed(void)

{













    motor_setAngle(MinAngle);

    button_updateState_CMockExpectAndReturn(473, testNum, OK);

    p_pressedTime = 0;

    button_getState_CMockExpectAndReturn(475, BTN3, BTN_RELEASED);

    button_getState_CMockExpectAndReturn(476, BTN2, BTN_RELEASED);

    button_getState_CMockExpectAndReturn(477, BTN1, BTN_PREPRESSED);



    motor_angles_t exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(486), UNITY_DISPLAY_STYLE_INT);

}





void test_SpeedControlTask_Angle_should_DoNothing_when_angleIsMax_And_BTN3_NOT_Prepressed_And_BTN2_Not_prePressed_And_BTN1_prePressed(void)

{













    motor_setAngle(MaxAngle);

    button_updateState_CMockExpectAndReturn(499, testNum, OK);

    p_pressedTime = 0;

    button_getState_CMockExpectAndReturn(501, BTN3, BTN_RELEASED);

    button_getState_CMockExpectAndReturn(502, BTN2, BTN_RELEASED);

    button_getState_CMockExpectAndReturn(503, BTN1, BTN_PREPRESSED);



    motor_angles_t exp_angle = MaxAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(512), UNITY_DISPLAY_STYLE_INT);

}





void test_SpeedControlTask_Angle_should_DoNothing_when_angleIsMax_And_AllReleased(void)

{













    motor_setAngle(MaxAngle);

    button_updateState_CMockExpectAndReturn(525, testNum, OK);

    p_pressedTime = 0;

    button_getState_CMockExpectAndReturn(527, BTN3, BTN_RELEASED);

    button_getState_CMockExpectAndReturn(528, BTN2, BTN_RELEASED);

    button_getState_CMockExpectAndReturn(529, BTN1, BTN_RELEASED);



    motor_angles_t exp_angle = MaxAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(538), UNITY_DISPLAY_STYLE_INT);

}









void test_SpeedControlTask_switchCoverage_TreeFirstBranch_MIN_MID_MIN_MID(void)

{













    motor_setAngle(MinAngle);

    button_updateState_CMockExpectAndReturn(553, testNum, OK);

    button_getState_CMockExpectAndReturn(554, BTN3, SW_CASE5[0]);

    button_getState_CMockExpectAndReturn(555, BTN2, SW_CASE5[2]);

    button_getState_CMockExpectAndReturn(556, BTN1, SW_CASE5[3]);

    p_pressedTime = SW_CASE5[1];



    motor_angles_t exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(566), UNITY_DISPLAY_STYLE_INT);







    button_updateState_CMockExpectAndReturn(570, testNum, OK);

    button_getState_CMockExpectAndReturn(571, BTN3, SW_CASE1[0]);





    p_pressedTime = SW_CASE1[1];



    exp_angle = MinAngle;





    SpeedControlTask(testNum++);

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(582), UNITY_DISPLAY_STYLE_INT);







    button_updateState_CMockExpectAndReturn(586, testNum, OK);

    button_getState_CMockExpectAndReturn(587, BTN3, SW_CASE5[0]);

    button_getState_CMockExpectAndReturn(588, BTN2, SW_CASE5[2]);

    button_getState_CMockExpectAndReturn(589, BTN1, SW_CASE5[3]);

    p_pressedTime = SW_CASE5[1];



    exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(598), UNITY_DISPLAY_STYLE_INT);



}









void test_SpeedControlTask_switchCoverage_TreeSecondBranch_MIN_MID_MIN_MID(void)

{













    motor_setAngle(MinAngle);

    button_updateState_CMockExpectAndReturn(614, testNum, OK);

    button_getState_CMockExpectAndReturn(615, BTN3, SW_CASE5[0]);

    button_getState_CMockExpectAndReturn(616, BTN2, SW_CASE5[2]);

    button_getState_CMockExpectAndReturn(617, BTN1, SW_CASE5[3]);

    p_pressedTime = SW_CASE5[1];



    motor_angles_t exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(627), UNITY_DISPLAY_STYLE_INT);







    button_updateState_CMockExpectAndReturn(631, testNum, OK);

    button_getState_CMockExpectAndReturn(632, BTN3, SW_CASE2[0]);

    button_getState_CMockExpectAndReturn(633, BTN2, SW_CASE2[2]);



    p_pressedTime = SW_CASE2[1];



    exp_angle = MinAngle;





    SpeedControlTask(testNum++);

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(643), UNITY_DISPLAY_STYLE_INT);







    button_updateState_CMockExpectAndReturn(647, testNum, OK);

    button_getState_CMockExpectAndReturn(648, BTN3, SW_CASE5[0]);

    button_getState_CMockExpectAndReturn(649, BTN2, SW_CASE5[2]);

    button_getState_CMockExpectAndReturn(650, BTN1, SW_CASE5[3]);

    p_pressedTime = SW_CASE5[1];



    exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(659), UNITY_DISPLAY_STYLE_INT);



}







void test_SpeedControlTask_switchCoverage_TreeThirdBranch_MIN_MID_MIN_MID(void)

{













    motor_setAngle(MinAngle);

    button_updateState_CMockExpectAndReturn(674, testNum, OK);

    button_getState_CMockExpectAndReturn(675, BTN3, SW_CASE5[0]);

    button_getState_CMockExpectAndReturn(676, BTN2, SW_CASE5[2]);

    button_getState_CMockExpectAndReturn(677, BTN1, SW_CASE5[3]);

    p_pressedTime = SW_CASE5[1];



    motor_angles_t exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(687), UNITY_DISPLAY_STYLE_INT);







    button_updateState_CMockExpectAndReturn(691, testNum, OK);

    button_getState_CMockExpectAndReturn(692, BTN3, SW_CASE4[0]);

    button_getState_CMockExpectAndReturn(693, BTN2, SW_CASE4[2]);



    p_pressedTime = SW_CASE4[1];



    exp_angle = MinAngle;





    SpeedControlTask(testNum++);

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(703), UNITY_DISPLAY_STYLE_INT);







    button_updateState_CMockExpectAndReturn(707, testNum, OK);

    button_getState_CMockExpectAndReturn(708, BTN3, SW_CASE5[0]);

    button_getState_CMockExpectAndReturn(709, BTN2, SW_CASE5[2]);

    button_getState_CMockExpectAndReturn(710, BTN1, SW_CASE5[3]);

    p_pressedTime = SW_CASE5[1];



    exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(719), UNITY_DISPLAY_STYLE_INT);

}









void test_SpeedControlTask_switchCoverage_TreeForthBranch_MIN_MID_MAX_MID(void)

{













    motor_setAngle(MinAngle);

    button_updateState_CMockExpectAndReturn(734, testNum, OK);

    button_getState_CMockExpectAndReturn(735, BTN3, SW_CASE5[0]);

    button_getState_CMockExpectAndReturn(736, BTN2, SW_CASE5[2]);

    button_getState_CMockExpectAndReturn(737, BTN1, SW_CASE5[3]);

    p_pressedTime = SW_CASE5[1];



    motor_angles_t exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(747), UNITY_DISPLAY_STYLE_INT);







    button_updateState_CMockExpectAndReturn(751, testNum, OK);

    button_getState_CMockExpectAndReturn(752, BTN3, SW_CASE5[0]);

    button_getState_CMockExpectAndReturn(753, BTN2, SW_CASE5[2]);

    button_getState_CMockExpectAndReturn(754, BTN1, SW_CASE5[3]);

    p_pressedTime = SW_CASE5[1];



    exp_angle = MaxAngle;





    SpeedControlTask(testNum++);

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(763), UNITY_DISPLAY_STYLE_INT);







    button_updateState_CMockExpectAndReturn(767, testNum, OK);

    button_getState_CMockExpectAndReturn(768, BTN3, SW_CASE1[0]);





    p_pressedTime = SW_CASE1[1];



    exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(779), UNITY_DISPLAY_STYLE_INT);

}







void test_SpeedControlTask_switchCoverage_TreeFifthBranch_MIN_MID_MAX_MID(void)

{













    motor_setAngle(MinAngle);

    button_updateState_CMockExpectAndReturn(793, testNum, OK);

    button_getState_CMockExpectAndReturn(794, BTN3, SW_CASE5[0]);

    button_getState_CMockExpectAndReturn(795, BTN2, SW_CASE5[2]);

    button_getState_CMockExpectAndReturn(796, BTN1, SW_CASE5[3]);

    p_pressedTime = SW_CASE5[1];



    motor_angles_t exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(806), UNITY_DISPLAY_STYLE_INT);







    button_updateState_CMockExpectAndReturn(810, testNum, OK);

    button_getState_CMockExpectAndReturn(811, BTN3, SW_CASE5[0]);

    button_getState_CMockExpectAndReturn(812, BTN2, SW_CASE5[2]);

    button_getState_CMockExpectAndReturn(813, BTN1, SW_CASE5[3]);

    p_pressedTime = SW_CASE2[1];



    exp_angle = MaxAngle;





    SpeedControlTask(testNum++);

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(822), UNITY_DISPLAY_STYLE_INT);







    button_updateState_CMockExpectAndReturn(826, testNum, OK);

    button_getState_CMockExpectAndReturn(827, BTN3, SW_CASE2[0]);

    button_getState_CMockExpectAndReturn(828, BTN2, SW_CASE2[2]);



    p_pressedTime = SW_CASE2[1];



    exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(838), UNITY_DISPLAY_STYLE_INT);

}







void test_SpeedControlTask_switchCoverage_TreeSixthBranch_MIN_MID_MAX_MID(void)

{













    motor_setAngle(MinAngle);

    button_updateState_CMockExpectAndReturn(852, testNum, OK);

    button_getState_CMockExpectAndReturn(853, BTN3, SW_CASE5[0]);

    button_getState_CMockExpectAndReturn(854, BTN2, SW_CASE5[2]);

    button_getState_CMockExpectAndReturn(855, BTN1, SW_CASE5[3]);

    p_pressedTime = SW_CASE5[1];



    motor_angles_t exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_angles_t act_angle;

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(865), UNITY_DISPLAY_STYLE_INT);







    button_updateState_CMockExpectAndReturn(869, testNum, OK);

    button_getState_CMockExpectAndReturn(870, BTN3, SW_CASE5[0]);

    button_getState_CMockExpectAndReturn(871, BTN2, SW_CASE5[2]);

    button_getState_CMockExpectAndReturn(872, BTN1, SW_CASE5[3]);

    p_pressedTime = SW_CASE2[1];



    exp_angle = MaxAngle;





    SpeedControlTask(testNum++);

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(881), UNITY_DISPLAY_STYLE_INT);







    button_updateState_CMockExpectAndReturn(885, testNum, OK);

    button_getState_CMockExpectAndReturn(886, BTN3, SW_CASE4[0]);

    button_getState_CMockExpectAndReturn(887, BTN2, SW_CASE4[2]);



    p_pressedTime = SW_CASE4[1];



    exp_angle = MidAngle;





    SpeedControlTask(testNum++);

    motor_getAngel(&act_angle);



    UnityAssertEqualNumber((UNITY_INT)((exp_angle)), (UNITY_INT)((act_angle)), (

   ((void *)0)

   ), (UNITY_UINT)(897), UNITY_DISPLAY_STYLE_INT);

}
