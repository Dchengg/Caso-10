#include <stdio.h>#include <stdlib.h>#include <stdbool.h>bool IsPair(int number){    if(number%2 == 0){        return true;    }else{        return false;    }}int* apply_Matroid(int* array, int arraySize, bool (*function)(int)){    static int solution[3];    int position = 0;    int loop;    for(loop = 0; loop < arraySize;loop++){        if(function(array[loop])){            solution[position] = array[loop];            position++;        }    }    return solution;}struct Matroid{    int *S;    int sizeS;    int *I;    bool (*function)(int);};void addMatroid(struct Matroid *matroids, int *array, int arraySize, bool(*function)(int)){}int main() {    /*unsigned int_size = sizeof(int);    int arr[] = {10, 20, 30, 40, 50,60,12,13,542};    struct Matroid *m = Create_Matroid(arr, int_size,9 );*/    struct Matroid matroids[2];    int array[5] = {1,2,3,4,5};    struct Matroid m;    m.S = array;    m.sizeS = (int)( sizeof(array) / sizeof(array[0]));    m.function = IsPair;    matroids[0] = m;    int array2[5] = {6,7,8,9,10};    struct Matroid m2;    m2.S = array2;    m2.sizeS = (int)( sizeof(array2) / sizeof(array2[0]));    m2.function = IsPair;    matroids[1] = m2;    int element;    int sizeMatroids = (int)( sizeof(matroids) / sizeof(matroids[0]));    for(element = 0; element < sizeMatroids;element++){        struct Matroid matroid = matroids[element];        matroid.I = apply_Matroid(matroid.S, matroid.sizeS, matroid.function);        printf("\n");        int loop;        for(loop = 0; loop < 3; loop++)            printf("%d ", matroid.I[loop]);    }    return 0;}