#include <stdio.h>
/*
    main - it verifies if a number is multiple by three or five, and sum in "soma"

*/
#define NUMERO 1000

int main(){

    int soma = 0;

    for (int i = 1; i < NUMERO; i++){
        if(i % 3 == 0 || i%5 == 0){
            soma+= i;
            
        }
        
    }
    printf("%d\n", soma);
}
