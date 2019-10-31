#ifndef PARALLEL_MATROIDS_MATROID_H
#define PARALLEL_MATROIDS_MATROID_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>
#include <time.h>

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

struct Inter{
    int iteration;
    void *value;
};

struct Matroid matroids[];

static int counter = 0;     // Index of matroid in array

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

struct Matroid getMatroid(void *Sp, void *Ip, enum type tp, int size, bool(*functionp)(void*)){
    struct Matroid m;
    m.S = Sp;
    m.I = Ip;
    m.t = tp;
    m.sizeS = size;
    m.function = functionp;
    return m;
}

void resolveArrayMatroid(struct Matroid matroidsArray[], int size) {
    #pragma omp parallel for
    for (int element = 0; element < size; element++) {
        printf("\n Resultado matroid %d: ", element);
        struct Matroid matroid = matroidsArray[element];
        void **solution = apply_Matroid(matroid);
        int loop;
        for (loop = 0; loop < matroid.sizeS; loop++) {
            if (matroid.t == POINTER_TO_CHAR) {
                char *str = ((char **) (solution))[loop];
                if ((int) str != NULL) {
                    printf("%s ", str);
                }
            }
            else if (matroid.t == INT) {
                int result = (int) (solution)[loop];
                if(result != 0) printf("%d ", result);
            }
        }
    }
}

bool contains(int array[], int size, int value){
    for(int i = 0; i < size; i++){
        if(array[i] == value) return true;
    }
    return false;
}

void validate(struct Inter intersection[], int counter, enum type t){
    if(t == INT){
        int solution[counter];
        int solutionCounter = 0;
        #pragma omp parallel for
        for(int i = 0; i < counter; i++){
            struct Inter current =  intersection[i];
            int number = (int) current.value;
            int iterations[counter];
            int count = 0;
            for(int j = 0; j < counter; j++){
                if(number == (int)intersection[j].value){
                    iterations[count] = intersection[j].iteration;
                    count++;
                }
            }
            if(contains(iterations, count, 0) && contains(iterations, count, 1) && contains(iterations, count, 2) &&
                    contains(iterations, count, 3) && contains(iterations, count, 4) && contains(iterations, count, 5) &&
                    contains(iterations, count, 6) && contains(iterations, count, 7) && contains(iterations, count, 8) &&
                    contains(iterations, count, 9)){
                if(!contains(solution, solutionCounter, number)){
                    solution[solutionCounter] = number;
                    solutionCounter++;
                }
            }
        }
        for(int i = 0; i < solutionCounter; i++){
            printf("%d, ", solution[i]);
        }
    }
}

void intersect(struct Matroid matroidsArray[], int size, enum type t){
    struct Inter intersection[100];
    int counter = 0;
    #pragma omp parallel for
    for (int element = 0; element < size; element++) {
        struct Matroid matroid = matroidsArray[element];
        void **solution = apply_Matroid(matroid);
        int loop;
        for (loop = 0; loop < matroid.sizeS; loop++) {
            if (matroid.t == POINTER_TO_CHAR) {
                char *str = ((char **) (solution))[loop];
                if ((int) str != 0xa && str != "(null)") {
                    struct Inter temp;
                    temp.iteration = element;
                    temp.value = str;
                    intersection[counter] = temp;
                    counter++;
                }
            }
            else if (matroid.t == INT) {
                struct Inter temp;
                temp.iteration = element;
                temp.value = (solution)[loop];
                if((int)temp.value != 0){
                    intersection[counter] = temp;
                    counter++;
                }
            }
        }
    }
    validate(intersection, counter, t);
}

#endif //PARALLEL_MATROIDS_MATROID_H