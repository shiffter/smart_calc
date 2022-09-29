#include "../smart_calc.h"
#include <check.h>

#define MAX_CHAR 122
#define MIN_CHAR 97
#define stack_size 30

static char mass[stack_size];

Suite *push_in_test();
