/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_MOTOR_H
#define _MOCK_MOTOR_H

#include "unity.h"
#include "motor.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_motor_Init(void);
void mock_motor_Destroy(void);
void mock_motor_Verify(void);




#define motor_init_IgnoreAndReturn(cmock_retval) motor_init_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void motor_init_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, ERR_t cmock_to_return);
#define motor_init_StopIgnore() motor_init_CMockStopIgnore()
void motor_init_CMockStopIgnore(void);
#define motor_init_ExpectAndReturn(cmock_retval) motor_init_CMockExpectAndReturn(__LINE__, cmock_retval)
void motor_init_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, ERR_t cmock_to_return);
typedef ERR_t (* CMOCK_motor_init_CALLBACK)(int cmock_num_calls);
void motor_init_AddCallback(CMOCK_motor_init_CALLBACK Callback);
void motor_init_Stub(CMOCK_motor_init_CALLBACK Callback);
#define motor_init_StubWithCallback motor_init_Stub
#define motor_setAngle_IgnoreAndReturn(cmock_retval) motor_setAngle_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void motor_setAngle_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, ERR_t cmock_to_return);
#define motor_setAngle_StopIgnore() motor_setAngle_CMockStopIgnore()
void motor_setAngle_CMockStopIgnore(void);
#define motor_setAngle_ExpectAndReturn(angle, cmock_retval) motor_setAngle_CMockExpectAndReturn(__LINE__, angle, cmock_retval)
void motor_setAngle_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, motor_angles_t angle, ERR_t cmock_to_return);
typedef ERR_t (* CMOCK_motor_setAngle_CALLBACK)(motor_angles_t angle, int cmock_num_calls);
void motor_setAngle_AddCallback(CMOCK_motor_setAngle_CALLBACK Callback);
void motor_setAngle_Stub(CMOCK_motor_setAngle_CALLBACK Callback);
#define motor_setAngle_StubWithCallback motor_setAngle_Stub
#define motor_getAngel_IgnoreAndReturn(cmock_retval) motor_getAngel_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void motor_getAngel_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, ERR_t cmock_to_return);
#define motor_getAngel_StopIgnore() motor_getAngel_CMockStopIgnore()
void motor_getAngel_CMockStopIgnore(void);
#define motor_getAngel_ExpectAndReturn(angle, cmock_retval) motor_getAngel_CMockExpectAndReturn(__LINE__, angle, cmock_retval)
void motor_getAngel_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, motor_angles_t* angle, ERR_t cmock_to_return);
typedef ERR_t (* CMOCK_motor_getAngel_CALLBACK)(motor_angles_t* angle, int cmock_num_calls);
void motor_getAngel_AddCallback(CMOCK_motor_getAngel_CALLBACK Callback);
void motor_getAngel_Stub(CMOCK_motor_getAngel_CALLBACK Callback);
#define motor_getAngel_StubWithCallback motor_getAngel_Stub
#define motor_getAngel_ExpectWithArrayAndReturn(angle, angle_Depth, cmock_retval) motor_getAngel_CMockExpectWithArrayAndReturn(__LINE__, angle, angle_Depth, cmock_retval)
void motor_getAngel_CMockExpectWithArrayAndReturn(UNITY_LINE_TYPE cmock_line, motor_angles_t* angle, int angle_Depth, ERR_t cmock_to_return);
#define motor_getAngel_ReturnThruPtr_angle(angle) motor_getAngel_CMockReturnMemThruPtr_angle(__LINE__, angle, sizeof(motor_angles_t))
#define motor_getAngel_ReturnArrayThruPtr_angle(angle, cmock_len) motor_getAngel_CMockReturnMemThruPtr_angle(__LINE__, angle, (int)(cmock_len * (int)sizeof(*angle)))
#define motor_getAngel_ReturnMemThruPtr_angle(angle, cmock_size) motor_getAngel_CMockReturnMemThruPtr_angle(__LINE__, angle, cmock_size)
void motor_getAngel_CMockReturnMemThruPtr_angle(UNITY_LINE_TYPE cmock_line, motor_angles_t* angle, int cmock_size);
#define SpeedControlTask_Ignore() SpeedControlTask_CMockIgnore()
void SpeedControlTask_CMockIgnore(void);
#define SpeedControlTask_StopIgnore() SpeedControlTask_CMockStopIgnore()
void SpeedControlTask_CMockStopIgnore(void);
#define SpeedControlTask_Expect(testNum) SpeedControlTask_CMockExpect(__LINE__, testNum)
void SpeedControlTask_CMockExpect(UNITY_LINE_TYPE cmock_line, unsigned char testNum);
typedef void (* CMOCK_SpeedControlTask_CALLBACK)(unsigned char testNum, int cmock_num_calls);
void SpeedControlTask_AddCallback(CMOCK_SpeedControlTask_CALLBACK Callback);
void SpeedControlTask_Stub(CMOCK_SpeedControlTask_CALLBACK Callback);
#define SpeedControlTask_StubWithCallback SpeedControlTask_Stub

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif