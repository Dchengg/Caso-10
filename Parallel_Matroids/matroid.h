#ifndef PARALLEL_MATROIDS_MATROID_H
#define PARALLEL_MATROIDS_MATROID_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define typename(x) _Generic((x),                           \
        _Bool: BOOL,                                        \
        unsigned char: UNSIGNED_CHAR,                       \
        char: CHAR,                                         \
        signed char: SIGNED_CHAR,                           \
        short int: SHORT_INT,                               \
        unsigned short int: UNSIGNED_SHORT_INT,             \
        int: INT,                                           \
        unsigned int: UNSIGNED_INT,                         \
        long int: LONG_INT,                                 \
        unsigned long int: UNSIGNED_LONG_INT,               \
        long long int: LONG_LONG_INT,                       \
        unsigned long long int: UNSIGNED_LONG_LONG_INT,     \
        float: FLOAT,                                       \
        double: DOUBLE,                                     \
        long double: LONG_DOUBLE,                           \
        char *: POINTER_TO_CHAR,                            \
        void *: POINTER_TO_VOID,                            \
        int *: POINTER_TO_INT,                              \
        default: OTHER)


enum type {
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
};      // Define types for generic template

typedef struct Matroid{
    void *S;
    int sizeS;
    void *I;
    enum type t;
    bool (*function)(void*);
} matrix;       // Structure for the matroid

struct Matroid matroids[3];

static int counter = 0;     // Index of matroid in array

void generateMatroid(void *Sp, void *Ip, enum type tp, int size, bool(*functionp)(void*)){
    struct Matroid m;
    m.S = Sp;
    m.I = Ip;
    m.t = tp;
    //m.sizeS = (int)(sizeof(Sp) / sizeof(Sp[0]));
    m.sizeS = size;
    m.function = functionp;
    matroids[counter] = m;
    counter++;
    //printf("%d", m.sizeS);
}

/*
void iterate(){
    for(int element = 0; element < counter; element++){
        struct Matroid matroid = matroids[element];
        void **solution = apply_Matroid(matroid.S, matroid.sizeS, matroid.t,matroid.function);
        printf("\n");
        int loop;
        for(loop = 0; loop < 3; loop++)
            if(matroid.t == STRING){
                char* str = ((char**)(solution))[loop];
                if(str != 0xa){
                    printf("%s",str);
                }

            }else{
                printf("%d",(solution)[loop]);
            }

    }
}

void** apply_Matroid(void* array[], int arraySize,enum type t, bool (*function)(void*)){
    static void* solution[3];
    int position = 0;
    int loop;
    if(t == POINTER_TO_CHAR){
        for(loop = 0; loop < arraySize;loop++){
            if(function(((char**)(array))[loop])){
                solution[position] = ((char**)(array))[loop];
                position++;
            }
        }
    }else{
        for(loop = 0; loop < arraySize;loop++){
            if(function(((int*)(array))[loop])){
                solution[position] = ((int*)(array))[loop];
                position++;
            }
        }
    }

    return solution;
}

 */
#endif //PARALLEL_MATROIDS_MATROID_H
