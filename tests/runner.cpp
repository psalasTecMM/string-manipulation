#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness_c.h"

TEST_GROUP_C_WRAPPER(Cadenas){};

TEST_C_WRAPPER(Cadenas, test_alphabet);



int main(int ac, const char** av){
    return RUN_ALL_TESTS(ac,av);
}