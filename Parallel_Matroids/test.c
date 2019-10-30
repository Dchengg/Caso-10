#include <stdio.h>

/*
#define typename(x) _Generic((x),        \
        _Bool: "_Bool",\
        unsigned char: "unsigned char",          \
        char: "char",\
        signed char: "signed char",            \
        short int: "short int",         \
        unsigned short int: "unsigned short int",     \
        int: "int",                     \
        unsigned int: "unsigned int",           \
        long int: "long int",           \
        unsigned long int: "unsigned long int",      \
        long long int: "long long int", \
        unsigned long long int: "unsigned long long int", \
        float: "float",                         \
        double: "double",                 \
        long double: "long double",                   \
        char *: "pointer to char",        \
        void *: "pointer to void",                \
        int *: "pointer to int",         \
        default: "other")
*/

#define typename(x) _Generic((x),        \
        _Bool: BOOL,\
        unsigned char: UNSIGNED_CHAR,          \
        char: CHAR,\
        signed char: SIGNED_CHAR,            \
        short int: SHORT_INT,         \
        unsigned short int: UNSIGNED_SHORT_INT,     \
        int: INT,                     \
        unsigned int: UNSIGNED_INT,           \
        long int: LONG_INT,           \
        unsigned long int: UNSIGNED_LONG_INT,      \
        long long int: LONG_LONG_INT, \
        unsigned long long int: UNSIGNED_LONG_LONG_INT, \
        float: FLOAT,                         \
        double: DOUBLE,                 \
        long double: LONG_DOUBLE,                   \
        char *: POINTER_TO_CHAR,        \
        void *: POINTER_TO_VOID,                \
        int *: POINTER_TO_INT,         \
        default: OTHER)


enum t_typename {
    BOOL,
    UNSIGNED_CHAR,
    CHAR,
    SIGNED_CHAR,
    SHORT_INT,
    UNSIGNED_SHORT_INT,
    INT,
    UNSIGNED_INT,
    LONG_INT,
    UNSIGNED_LONG_INT,
    LONG_LONG_INT,
    UNSIGNED_LONG_LONG_INT,
    FLOAT,
    DOUBLE,
    LONG_DOUBLE,
    POINTER_TO_CHAR,
    POINTER_TO_VOID,
    POINTER_TO_INT,
    OTHER
};

int main(){
    int arr[4] = {1, 2, 3, 4};
    int k = 8;
    double arr2[4] = {1.1, 2.2, 3.3, 4.4};
    char arr3[4] = {'s', 'q', 'g', 'j'};

    if(typename(arr[0]) == INT){
        printf("%d", INT);
    }

    return 0;
}