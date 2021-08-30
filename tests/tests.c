#include "CppUTest/TestHarness_c.h"
#include "mystring.h"

TEST_C(Cadenas, test_alphabet){
    char* actual = alphabet("686f6c61");
    CHECK_EQUAL_C_STRING("68fc1",actual);
    cpputest_free(actual);
}

TEST_C(Cadenas, test_len){
    CHECK_EQUAL_C_INT(8,len("686f6c61"));
    CHECK_EQUAL_C_INT(0,len(""));
}

TEST_C(Cadenas, test_concat){
    char* holamundo = concat("hola", "mundo");
    CHECK_EQUAL_C_STRING("holamundo",holamundo);
    char* hola1 = concat("","Hola");
    char* hola2 = concat("Hola","");
    CHECK_EQUAL_C_STRING("Hola",hola1);
    cpputest_free(hola1);
    CHECK_EQUAL_C_STRING("Hola",hola2);
    cpputest_free(hola2);
    CHECK_EQUAL_C_INT(9,len(holamundo));
    CHECK_EQUAL_C_INT(len("hola")+len("mundo"),len(holamundo));
    cpputest_free(holamundo);
}

TEST_C(Cadenas, test_spow){
    char* first = spow("aab",3);
    CHECK_EQUAL_C_STRING("aabaabaab",first);
    cpputest_free(first);
    CHECK_EQUAL_C_STRING("",spow("aab",0));
}

TEST_C(Cadenas, test_inverse){
    char* actual = inverse("evausabarimel");
    CHECK_EQUAL_C_STRING("lemirabasuave",actual);
    cpputest_free(actual);
}

TEST_C(Cadenas, test_occurrences){
    CHECK_EQUAL_C_INT(4,ocurrences('6', "686f6c61"));
    CHECK_EQUAL_C_INT(0,ocurrences('a', "686f6c61"));
    CHECK_EQUAL_C_INT(1,ocurrences('1', "686f6c61"));
}

TEST_C(Cadenas, test_equal){
    CHECK_EQUAL_C_INT(0,equal("Hola", "hola"));
    CHECK_EQUAL_C_INT(1,equal("hola", "hola"));
    CHECK_EQUAL_C_INT(0,equal("holas", "hola"));
}

