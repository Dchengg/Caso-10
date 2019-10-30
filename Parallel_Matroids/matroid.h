#ifndef PARALLEL_MATROIDS_MATROID_H
#define PARALLEL_MATROIDS_MATROID_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>

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

struct Matroid matroids[];

static int counter = 0;     // Index of matroid in array

void generateMatroid(void *Sp, void *Ip, enum type tp, int size, bool(*functionp)(void*)){
    struct Matroid m;
    m.S = Sp;
    m.I = Ip;
    m.t = tp;
    m.sizeS = size;
    m.function = functionp;
    matroids[counter] = m;
    counter++;
}

void** apply_Matroid(struct Matroid matroid){
    static void* solution[3];
    int position = 0;
    int loop;

    if(matroid.t == POINTER_TO_CHAR){
        for(loop = 0; loop < matroid.sizeS; loop++){
            if(matroid.function(((char**)(matroid.S))[loop])){
                solution[position] = ((char**)(matroid.S))[loop];
                position++;
            }
        }
    }

    else if(matroid.t == INT){
        int *arr = (int*) (matroid.S);
        for(loop = 0; loop < matroid.sizeS; loop++){
            if(matroid.function(arr[loop])){
                solution[position] = ((int*)(matroid.S))[loop];
                position++;
            }
        }
    }

    else if(matroid.t == DOUBLE){
        double *arr = &matroid.S;
        for(loop = 0; loop < matroid.sizeS; loop++){
            if(matroid.function(calloc(arr[loop], sizeof(int)))){
                solution[position] = ((int*)(matroid.S))[loop];
                position++;
            }
        }
    }

    return solution;
}

void resolve(){
    for(int element = 0; element < counter; element++){
        //#pragma omp parallel for
        struct Matroid matroid = matroids[element];
        void **solution = apply_Matroid(matroid);
        int loop;
        for(loop = 0; loop < matroid.sizeS; loop++){
            if(matroid.t == POINTER_TO_CHAR){
                char* str = ((char**)(solution))[loop];
                if((int) str != 0xa){
                    printf("%s \n", str);
                }
            }
            else if (matroid.t == INT){
                printf("%d \n",(solution)[loop]);
            }
            else if (matroid.t == DOUBLE){
                printf("%lf \n", (solution)[loop]);
            }
        }
    }
}

struct Matroid getMatroid(void *Sp, void *Ip, enum type tp, int size, bool(*functionp)(void*)){
    struct Matroid m;
    m.S = Sp;
    m.I = Ip;
    m.t = tp;
    m.sizeS = size;
    m.function = functionp;
    return m;
}

void resolveArrayMatroid(struct Matroid matroidsArray[], int size){
    for(int element = 0; element < size; element++){
        #pragma omp parallel for
        {
            struct Matroid matroid = matroidsArray[element];
            void **solution = apply_Matroid(matroid);
            int loop;
            for(loop = 0; loop < matroid.sizeS; loop++){
                if(matroid.t == POINTER_TO_CHAR){
                    char* str = ((char**)(solution))[loop];
                    if((int) str != 0xa){
                        printf("%s \n", str);
                    }
                }
                else if (matroid.t == INT){
                    printf("%d \n",(solution)[loop]);
                }
            }
            //printf("Thread rank: %d\n", omp_get_thread_num());
        }
    }
}


#endif //PARALLEL_MATROIDS_MATROID_H
