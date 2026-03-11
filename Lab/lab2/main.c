#include<stdio.h>
#include "utils.h"
int main(){
    int a = 10;
    int b = 20;
    int sum = add(a, b);
    printf("The sum of %d and %d is %d\n", a, b, sum);
    return 0;
}