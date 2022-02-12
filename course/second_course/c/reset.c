#include <stdio.h>

void soma(int* numero, int a, int b){
    *numero += a+b;
}

int main(){

    int num = 0;

    printf("%d\n", num);
    soma(&num, 1,5);
    printf("%d\n", num);

}   