#include "build/temp/_test_main.c"
#include "build/test/mocks/mock_button.h"
#include "build/test/mocks/mock_motor.h"
#include "src/main.h"
#include "C:/Ruby27-x64/lib/ruby/gems/2.7.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"


extern unsigned char TestNum ;

void setUp(void)

{

}



void tearDown(void)

{

}

void test_xxx()

{

    SpeedControlTask_CMockExpect(16, OK);

}







void test_main_should_CallSpeedControlTask_TestNum_times_then_return_zeroAfterEnding(void)

{













   ERR_t expectedReturn = OK;



   motor_init_CMockIgnoreAndReturn(31, OK);

   button_init_CMockIgnoreAndReturn(32, OK);

   unsigned char temp = 1;

   while(temp <= 10)

    SpeedControlTask_CMockExpect(35, temp++);



   ERR_t acutalReturn = TestableMain();



    UnityAssertEqualNumber((UNITY_INT)((expectedReturn)), (UNITY_INT)((acutalReturn)), (

   ((void *)0)

   ), (UNITY_UINT)(39), UNITY_DISPLAY_STYLE_INT);

}







void test_main_should_call_motor_init(void)

{













    motor_init_CMockExpectAndReturn(52, OK);

    button_init_CMockIgnoreAndReturn(53, OK);





    ERR_t acutalReturn = TestableMain();

}





void test_main_should_call_button_init(void)

{













    motor_init_CMockIgnoreAndReturn(68, OK);

    button_init_CMockExpectAndReturn(69, OK);







    ERR_t acutalReturn = TestableMain();

}
