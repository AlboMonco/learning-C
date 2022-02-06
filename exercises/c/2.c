#include <stdio.h>

#define FIBONACCI_LIMIT 4000000


int main(){
    
    int primeiro_numero = 1;
    int segundo_numero = 2;
    int terceiro_numero;
    
    int soma = 2; 

    for (int i = 0; terceiro_numero < FIBONACCI_LIMIT; i++){
        
        terceiro_numero = primeiro_numero + segundo_numero;

        primeiro_numero = segundo_numero;
        segundo_numero = terceiro_numero;
        
        if (terceiro_numero%2 == 0){
            soma+= terceiro_numero;
            printf("%d\n", soma);
        }
        
    } 
}