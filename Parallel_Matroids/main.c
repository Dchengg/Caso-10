#include <stdio.h>#include <stdlib.h>#include <stdbool.h>#include <string.h>#include "matroid.h"bool hasA(char string[]){    char* pPosition = strchr(string, 'a');    if(pPosition){        return true;    }else{        return false;    }}bool IsPair(int number){    if(number%2 == 0) return true;    else return false;}int main(){    // matroids = malloc(sizeof(*matroids));    int array[5] = {1, 2, 3, 4, 5};    int array_e[5];    generateMatroid(&array, &array_e, INT, 5, (bool (*)(void *)) IsPair);    int array2[5] = {6, 7, 8, 9, 10};    int array_e2[5];    generateMatroid(&array2, &array_e2, INT, 5, (bool (*)(void *)) IsPair);    char* array3[4] = {"hola","Soy","un","calamar"};    int array_e3[4];    generateMatroid(&array3, array_e3, POINTER_TO_CHAR, 4, (bool (*)(void *)) hasA);    printf("hjfhngd \n");}/*int main() {    struct Matroid matroids[3];    int array[5] = {1,2,3,4,5};    struct Matroid m;    m.S = array;    m.sizeS = (int)( sizeof(array) / sizeof(array[0]));    m.t = INT;    m.function = IsPair;    matroids[0] = m;    int array2[5] = {6,7,8,9,10};    struct Matroid m2;    m2.S = array2;    m2.sizeS = (int)( sizeof(array2) / sizeof(array2[0]));    m2.t = INT;    m2.function = IsPair;    matroids[1] = m2;    char* array3[] = {"hola","Soy","un","calamar"};    struct Matroid m3;    m3.S = array3;    m3.sizeS = (int)( sizeof(array3) / sizeof(array3[0]));    m3.t = STRING;    m3.function = hasA;    matroids[2] = m3;    int element;    int sizeMatroids = (int)( sizeof(matroids) / sizeof(matroids[0]));    for(element = 0; element < sizeMatroids;element++){        struct Matroid matroid = matroids[element];        // matroid.I = apply_Matroid(matroid.S, matroid.sizeS, matroid.function);        // char **solution = matroid.I;        //char **solution = apply_Matroid(matroid.S, matroid.sizeS, STRING,matroid.function);        void **solution = apply_Matroid(matroid.S, matroid.sizeS, matroid.t,matroid.function);        printf("\n");        int loop;        for(loop = 0; loop < 3; loop++)            if(matroid.t == STRING){                char* str = ((char**)(solution))[loop];                if(str != 0xa){                    printf("%s",str);                }            }else{                printf("%d",(solution)[loop]);            }    }    return 0;}*/