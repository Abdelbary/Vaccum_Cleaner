/* AUTOGENERATED FILE. DO NOT EDIT. */
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_button.h"

static const char* CMockString_btn = "btn";
static const char* CMockString_button_getState = "button_getState";
static const char* CMockString_button_init = "button_init";
static const char* CMockString_button_updateState = "button_updateState";
static const char* CMockString_testNum = "testNum";

typedef struct _CMOCK_button_init_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  ERR_t ReturnVal;
  int CallOrder;

} CMOCK_button_init_CALL_INSTANCE;

typedef struct _CMOCK_button_getState_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  Buttons_state_t ReturnVal;
  int CallOrder;
  Buttons_t Expected_btn;

} CMOCK_button_getState_CALL_INSTANCE;

typedef struct _CMOCK_button_updateState_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  ERR_t ReturnVal;
  int CallOrder;
  unsigned char Expected_testNum;

} CMOCK_button_updateState_CALL_INSTANCE;

static struct mock_buttonInstance
{
  char button_init_IgnoreBool;
  ERR_t button_init_FinalReturn;
  char button_init_CallbackBool;
  CMOCK_button_init_CALLBACK button_init_CallbackFunctionPointer;
  int button_init_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE button_init_CallInstance;
  char button_getState_IgnoreBool;
  Buttons_state_t button_getState_FinalReturn;
  char button_getState_CallbackBool;
  CMOCK_button_getState_CALLBACK button_getState_CallbackFunctionPointer;
  int button_getState_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE button_getState_CallInstance;
  char button_updateState_IgnoreBool;
  ERR_t button_updateState_FinalReturn;
  char button_updateState_CallbackBool;
  CMOCK_button_updateState_CALLBACK button_updateState_CallbackFunctionPointer;
  int button_updateState_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE button_updateState_CallInstance;
} Mock;

extern jmp_buf AbortFrame;
extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_button_Verify(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_MEM_INDEX_TYPE call_instance;
  call_instance = Mock.button_init_CallInstance;
  if (Mock.button_init_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_button_init);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.button_init_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.button_getState_CallInstance;
  if (Mock.button_getState_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_button_getState);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.button_getState_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
  call_instance = Mock.button_updateState_CallInstance;
  if (Mock.button_updateState_IgnoreBool)
    call_instance = CMOCK_GUTS_NONE;
  if (CMOCK_GUTS_NONE != call_instance)
  {
    UNITY_SET_DETAIL(CMockString_button_updateState);
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLess);
  }
  if (Mock.button_updateState_CallbackFunctionPointer != NULL)
  {
    call_instance = CMOCK_GUTS_NONE;
    (void)call_instance;
  }
}

void mock_button_Init(void)
{
  mock_button_Destroy();
}

void mock_button_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

ERR_t button_init(void)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_button_init_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_button_init);
  cmock_call_instance = (CMOCK_button_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.button_init_CallInstance);
  Mock.button_init_CallInstance = CMock_Guts_MemNext(Mock.button_init_CallInstance);
  if (Mock.button_init_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.button_init_FinalReturn;
    memcpy((void*)(&Mock.button_init_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(ERR_t[sizeof(cmock_call_instance->ReturnVal) == sizeof(ERR_t) ? 1 : -1])); /* add ERR_t to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.button_init_CallbackBool &&
      Mock.button_init_CallbackFunctionPointer != NULL)
  {
    ERR_t cmock_cb_ret = Mock.button_init_CallbackFunctionPointer(Mock.button_init_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  if (Mock.button_init_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.button_init_CallbackFunctionPointer(Mock.button_init_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void button_init_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, ERR_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_button_init_CALL_INSTANCE));
  CMOCK_button_init_CALL_INSTANCE* cmock_call_instance = (CMOCK_button_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.button_init_CallInstance = CMock_Guts_MemChain(Mock.button_init_CallInstance, cmock_guts_index);
  Mock.button_init_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.button_init_IgnoreBool = (char)1;
}

void button_init_CMockStopIgnore(void)
{
  if(Mock.button_init_IgnoreBool)
    Mock.button_init_CallInstance = CMock_Guts_MemNext(Mock.button_init_CallInstance);
  Mock.button_init_IgnoreBool = (char)0;
}

void button_init_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, ERR_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_button_init_CALL_INSTANCE));
  CMOCK_button_init_CALL_INSTANCE* cmock_call_instance = (CMOCK_button_init_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.button_init_CallInstance = CMock_Guts_MemChain(Mock.button_init_CallInstance, cmock_guts_index);
  Mock.button_init_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(ERR_t[sizeof(cmock_to_return) == sizeof(ERR_t) ? 1 : -1])); /* add ERR_t to :treat_as_array if this causes an error */
}

void button_init_AddCallback(CMOCK_button_init_CALLBACK Callback)
{
  Mock.button_init_IgnoreBool = (char)0;
  Mock.button_init_CallbackBool = (char)1;
  Mock.button_init_CallbackFunctionPointer = Callback;
}

void button_init_Stub(CMOCK_button_init_CALLBACK Callback)
{
  Mock.button_init_IgnoreBool = (char)0;
  Mock.button_init_CallbackBool = (char)0;
  Mock.button_init_CallbackFunctionPointer = Callback;
}

Buttons_state_t button_getState(Buttons_t btn)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_button_getState_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_button_getState);
  cmock_call_instance = (CMOCK_button_getState_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.button_getState_CallInstance);
  Mock.button_getState_CallInstance = CMock_Guts_MemNext(Mock.button_getState_CallInstance);
  if (Mock.button_getState_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.button_getState_FinalReturn;
    memcpy((void*)(&Mock.button_getState_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(Buttons_state_t[sizeof(cmock_call_instance->ReturnVal) == sizeof(Buttons_state_t) ? 1 : -1])); /* add Buttons_state_t to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.button_getState_CallbackBool &&
      Mock.button_getState_CallbackFunctionPointer != NULL)
  {
    Buttons_state_t cmock_cb_ret = Mock.button_getState_CallbackFunctionPointer(btn, Mock.button_getState_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_button_getState,CMockString_btn);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_btn), (void*)(&btn), sizeof(Buttons_t), cmock_line, CMockStringMismatch);
  }
  if (Mock.button_getState_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.button_getState_CallbackFunctionPointer(btn, Mock.button_getState_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_button_getState(CMOCK_button_getState_CALL_INSTANCE* cmock_call_instance, Buttons_t btn)
{
  memcpy((void*)(&cmock_call_instance->Expected_btn), (void*)(&btn),
         sizeof(Buttons_t[sizeof(btn) == sizeof(Buttons_t) ? 1 : -1])); /* add Buttons_t to :treat_as_array if this causes an error */
}

void button_getState_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, Buttons_state_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_button_getState_CALL_INSTANCE));
  CMOCK_button_getState_CALL_INSTANCE* cmock_call_instance = (CMOCK_button_getState_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.button_getState_CallInstance = CMock_Guts_MemChain(Mock.button_getState_CallInstance, cmock_guts_index);
  Mock.button_getState_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.button_getState_IgnoreBool = (char)1;
}

void button_getState_CMockStopIgnore(void)
{
  if(Mock.button_getState_IgnoreBool)
    Mock.button_getState_CallInstance = CMock_Guts_MemNext(Mock.button_getState_CallInstance);
  Mock.button_getState_IgnoreBool = (char)0;
}

void button_getState_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, Buttons_t btn, Buttons_state_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_button_getState_CALL_INSTANCE));
  CMOCK_button_getState_CALL_INSTANCE* cmock_call_instance = (CMOCK_button_getState_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.button_getState_CallInstance = CMock_Guts_MemChain(Mock.button_getState_CallInstance, cmock_guts_index);
  Mock.button_getState_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_button_getState(cmock_call_instance, btn);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(Buttons_state_t[sizeof(cmock_to_return) == sizeof(Buttons_state_t) ? 1 : -1])); /* add Buttons_state_t to :treat_as_array if this causes an error */
}

void button_getState_AddCallback(CMOCK_button_getState_CALLBACK Callback)
{
  Mock.button_getState_IgnoreBool = (char)0;
  Mock.button_getState_CallbackBool = (char)1;
  Mock.button_getState_CallbackFunctionPointer = Callback;
}

void button_getState_Stub(CMOCK_button_getState_CALLBACK Callback)
{
  Mock.button_getState_IgnoreBool = (char)0;
  Mock.button_getState_CallbackBool = (char)0;
  Mock.button_getState_CallbackFunctionPointer = Callback;
}

ERR_t button_updateState(unsigned char testNum)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_button_updateState_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_button_updateState);
  cmock_call_instance = (CMOCK_button_updateState_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.button_updateState_CallInstance);
  Mock.button_updateState_CallInstance = CMock_Guts_MemNext(Mock.button_updateState_CallInstance);
  if (Mock.button_updateState_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.button_updateState_FinalReturn;
    memcpy((void*)(&Mock.button_updateState_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(ERR_t[sizeof(cmock_call_instance->ReturnVal) == sizeof(ERR_t) ? 1 : -1])); /* add ERR_t to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.button_updateState_CallbackBool &&
      Mock.button_updateState_CallbackFunctionPointer != NULL)
  {
    ERR_t cmock_cb_ret = Mock.button_updateState_CallbackFunctionPointer(testNum, Mock.button_updateState_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  if (cmock_call_instance->CallOrder > ++GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledEarly);
  if (cmock_call_instance->CallOrder < GlobalVerifyOrder)
    UNITY_TEST_FAIL(cmock_line, CMockStringCalledLate);
  {
    UNITY_SET_DETAILS(CMockString_button_updateState,CMockString_testNum);
    UNITY_TEST_ASSERT_EQUAL_HEX8(cmock_call_instance->Expected_testNum, testNum, cmock_line, CMockStringMismatch);
  }
  if (Mock.button_updateState_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.button_updateState_CallbackFunctionPointer(testNum, Mock.button_updateState_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void CMockExpectParameters_button_updateState(CMOCK_button_updateState_CALL_INSTANCE* cmock_call_instance, unsigned char testNum)
{
  cmock_call_instance->Expected_testNum = testNum;
}

void button_updateState_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, ERR_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_button_updateState_CALL_INSTANCE));
  CMOCK_button_updateState_CALL_INSTANCE* cmock_call_instance = (CMOCK_button_updateState_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.button_updateState_CallInstance = CMock_Guts_MemChain(Mock.button_updateState_CallInstance, cmock_guts_index);
  Mock.button_updateState_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->ReturnVal = cmock_to_return;
  Mock.button_updateState_IgnoreBool = (char)1;
}

void button_updateState_CMockStopIgnore(void)
{
  if(Mock.button_updateState_IgnoreBool)
    Mock.button_updateState_CallInstance = CMock_Guts_MemNext(Mock.button_updateState_CallInstance);
  Mock.button_updateState_IgnoreBool = (char)0;
}

void button_updateState_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, unsigned char testNum, ERR_t cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_button_updateState_CALL_INSTANCE));
  CMOCK_button_updateState_CALL_INSTANCE* cmock_call_instance = (CMOCK_button_updateState_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.button_updateState_CallInstance = CMock_Guts_MemChain(Mock.button_updateState_CallInstance, cmock_guts_index);
  Mock.button_updateState_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  cmock_call_instance->CallOrder = ++GlobalExpectCount;
  CMockExpectParameters_button_updateState(cmock_call_instance, testNum);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(ERR_t[sizeof(cmock_to_return) == sizeof(ERR_t) ? 1 : -1])); /* add ERR_t to :treat_as_array if this causes an error */
}

void button_updateState_AddCallback(CMOCK_button_updateState_CALLBACK Callback)
{
  Mock.button_updateState_IgnoreBool = (char)0;
  Mock.button_updateState_CallbackBool = (char)1;
  Mock.button_updateState_CallbackFunctionPointer = Callback;
}

void button_updateState_Stub(CMOCK_button_updateState_CALLBACK Callback)
{
  Mock.button_updateState_IgnoreBool = (char)0;
  Mock.button_updateState_CallbackBool = (char)0;
  Mock.button_updateState_CallbackFunctionPointer = Callback;
}

