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









void test_main_should_CallSpeedControlTask_TestNum_times_then_return_zeroAfterEnding(void)

{













   ERR_t expectedReturn = OK;



   motor_init_CMockIgnoreAndReturn(28, OK);

   button_init_CMockIgnoreAndReturn(29, OK);

   unsigned char temp = 1;

   while(temp <= 10)

    SpeedControlTask_CMockExpect(32, temp++);



   ERR_t acutalReturn = TestableMain();



    UnityAssertEqualNumber((UNITY_INT)((expectedReturn)), (UNITY_INT)((acutalReturn)), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

}







void test_main_should_call_motor_init(void)

{













    motor_init_CMockExpectAndReturn(49, OK);

    button_init_CMockIgnoreAndReturn(50, OK);





    ERR_t acutalReturn = TestableMain();

}





void test_main_should_call_button_init(void)

{













    motor_init_CMockIgnoreAndReturn(65, OK);

    button_init_CMockExpectAndReturn(66, OK);







    ERR_t acutalReturn = TestableMain();

}
