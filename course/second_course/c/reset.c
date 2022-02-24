#include <stdio.h>

int soma(int lista[3], int tamanho){
    
    int soma = 0;

    for (int i = 0; i < tamanho; i++){
        soma += lista[i];
    }
    
    return soma;
}

int main(){

    int nums[3]= {10,20,30};
    
    int total = soma(nums, 3); //não precisa mandar o endereço de memória
    printf("%d\n", total);


}