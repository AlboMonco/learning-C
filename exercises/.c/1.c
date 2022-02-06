#include <stdio.h>

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
