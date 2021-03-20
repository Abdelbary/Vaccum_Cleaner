#ifndef CONFIG_H_
#define CONFIG_H_

#ifndef TEST
#define STATIC static
#else
#define STATIC 
#endif 



#ifndef NULL
#define NULL ((void *)0)
#endif

#define INPUT_FILE_ABS_PATH     ("W:\\scienceAndStuff\\projects&code\\vaccum_Cleaner\\Vaccum_Cleaner\\src\\SwitchStateInput.txt")

#ifndef TEST
#define OUTPUT_FILE_ABS_PATH    ("W:\\scienceAndStuff\\projects&code\\vaccum_Cleaner\\Vaccum_Cleaner\\src\\SpeedOut_release.txt")
#else
#define OUTPUT_FILE_ABS_PATH    ("W:\\scienceAndStuff\\projects&code\\vaccum_Cleaner\\Vaccum_Cleaner\\src\\SpeedOut_uniteTesting.txt")
#endif

#define INPUT_LINE_LEGHT  200

#ifndef TEST
#define TESTS   2
#else
#define TESTS   10
#endif


typedef enum
{
    OK,
    MULTIPLE_INIT_ERR,
    PARAM_OUT_OF_RANG_ERR,
    NULL_POINTER_PARM_ERR,
    MODULE_IS_IDLE_ERR
}ERR_t;

#endif //CONFIG_H_