#include <stdio.h>#include <stdlib.h>#include <stdbool.h>#include <string.h>#include "matroid.h"bool hasA(char string[]){    char* pPosition = strchr(string, 'a');    if(pPosition){        return true;    }else{        return false;    }}bool IsPair(int number){    if(number%2 == 0) return true;    else return false;}bool greaterTen(int number){    return number > 10;}int main(){    struct Matroid matroids[3];    int array[5] = {1, 8, 3, 46, 5};    int array_e[5];    struct Matroid m1 = getMatroid(array, &array_e, INT, 5, IsPair);    int array2[6] = {6, 12, 9, 22, 15, 3};    int array_e2[6];    struct Matroid m2 = getMatroid(array2, &array_e2, INT, 6, greaterTen);    char* array3[4] = {"hola","Soy","un","calamar"};    char* array_e3[4];    struct Matroid m3 = getMatroid(array3, array_e3, POINTER_TO_CHAR, 4, hasA);    matroids[0] = m1;    matroids[1] = m3;    matroids[2] = m2;    resolveArrayMatroid(matroids, 3);    // Parte b)    struct Matroid matroidsB[10];    int b1[5] = {1, 2, 3, 4, 5};    int b1_e[5] = {};    struct Matroid m4 = getMatroid(b1, b1_e, INT, 5, IsPair);    int b2[5] = {2, 4, 7, 8, 9};    int b2_e[5];    struct Matroid m5 = getMatroid(b2, b2_e, INT, 5, IsPair);    int b3[5] = {10, 4, 2, 69, 47};    int b3_e[5];    struct Matroid m6 = getMatroid(b3, b3_e, INT, 5, IsPair);    int b4[5] = {4, 12, 13, 14, 2};    int b4_e[5];    struct Matroid m7 = getMatroid(b4, b4_e, INT, 5, IsPair);    int b5[5] = {19, 4, 17, 2, 18};    int b5_e[5];    struct Matroid m8 = getMatroid(b5, b5_e, INT, 5, IsPair);    int b6[5] = {4, 21, 22, 2,23};    int b6_e[5];    struct Matroid m9 = getMatroid(b6, b6_e, INT, 5, IsPair);    int b7[5] = {2, 24, 4, 27, 26};    int b7_e[5];    struct Matroid m10 = getMatroid(b7, b7_e, INT, 5, IsPair);    int b8[5] = {4, 28, 2, 29, 30};    int b8_e[5];    struct Matroid m11 = getMatroid(b8, b8_e, INT, 5, IsPair);    int b9[5] = {31, 4, 33, 2, 34};    int b9_e[5];    struct Matroid m12 = getMatroid(b9, b9_e, INT, 5, IsPair);    int b10[5] = {2, 35, 4, 37, 38};    int b10_e[5];    struct Matroid m13 = getMatroid(b10, b10_e, INT, 5, IsPair);    matroidsB[0] = m4;    matroidsB[1] = m5;    matroidsB[2] = m6;    matroidsB[3] = m7;    matroidsB[4] = m8;    matroidsB[5] = m9;    matroidsB[6] = m10;    matroidsB[7] = m11;    matroidsB[8] = m12;    matroidsB[9] = m13;    printf("\n Intersección: ");    intersect(matroidsB, 10, INT);    printf("");    return 0;}