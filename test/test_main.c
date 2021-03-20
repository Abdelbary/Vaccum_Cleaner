#include "unity.h"
#include "main.h"
#include "mock_motor.h"
#include "mock_button.h"

extern unsigned char TestNum ;
void setUp(void)
{
}

void tearDown(void)
{
}


/********************************************************Testable_Mian**********************************************************/
/** Doxygen Test Case Description **/
void test_main_should_CallSpeedControlTask_TestNum_times_then_return_zeroAfterEnding(void)
{
    /*!
        * @par Given :  
        * @par When  : main() is called 
        * @par Then  : return zero after finishing
    */ 
    /*Expect*/
   ERR_t expectedReturn = OK;
    /*Act*/     
   motor_init_IgnoreAndReturn(OK);
   button_init_IgnoreAndReturn(OK);
   unsigned char temp = 1;
   while(temp <= TESTS)
    SpeedControlTask_Expect(temp++);
   
   ERR_t acutalReturn = TestableMain();
   /*Assert*/
    TEST_ASSERT_EQUAL_INT(expectedReturn,acutalReturn);
}


/** Doxygen Test Case Description **/
void test_main_should_call_motor_init(void)
{
    /*!
        * @par Given : expect motor init to be called  
        * @par When  : main() is called 
        * @par Then  : motor init should be called
    */ 
    /*Expect*/
    motor_init_ExpectAndReturn(OK);
    button_init_IgnoreAndReturn(OK);
    /*Act*/       
    /*Assert*/
    ERR_t acutalReturn = TestableMain();
}

/** Doxygen Test Case Description **/
void test_main_should_call_button_init(void)
{
    /*!
        * @par Given : expect button_init to be called  
        * @par When  : main() is called 
        * @par Then  : button_init should be called
    */ 
    /*Expect*/
    motor_init_IgnoreAndReturn(OK);
    button_init_ExpectAndReturn(OK);
    
    /*Act*/       
    /*Assert*/
    ERR_t acutalReturn = TestableMain();
}
