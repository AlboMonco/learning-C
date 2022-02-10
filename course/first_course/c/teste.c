#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){ 
    
    /*
    
    short a = 3;
    short b = 2;
    double c = a / (double)b;

    printf("%d\n%d\n%.1f\n", a, b, c);
    
    */

    /*
    
    short a = 3;
    short b = -3;   
    short c = a*b;
    short d = abs(a*b); 
    
    printf("%d %d\n", c, d);

    */

    int segundos = time(0);
    srand(segundos);

    int n1 = rand();
    int n2 = rand();

    printf("%d %d\n", n1, n2);

}