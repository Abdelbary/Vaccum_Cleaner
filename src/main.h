#ifndef MAIN_H
#define MAIN_H
#include "config.h"





#ifndef TEST
ERR_t main();
#else
ERR_t TestableMain();
#endif

#endif // MAIN_H
