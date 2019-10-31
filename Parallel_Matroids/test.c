#include <stdbool.h>
#include <stdio.h>

bool greaterTen(double number){
    return number > 10.0;
}

int main() {
    double array4[5] = {9.9, 10.2, 45.6, 3.6, 69.420};
    for(int i = 0; i < 5; i++){
        if(greaterTen(array4[i])) printf("%lf \n", array4[i]);
    }
}