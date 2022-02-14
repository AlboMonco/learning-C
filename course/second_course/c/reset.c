#include <stdio.h>

void potencia(int* resultado, int base, int expoente) {
    int potencia = 1;
    for (int i = 1; i <= expoente; i++){
        potencia *= base;
    }
    (*resultado) = potencia;
    
    printf("%d\n", (*resultado));

}

int main(){
    
    int resultado;
    int jogar = 0;
    do{
        int base;
        int expoente;
        
        printf("Base: ");
        scanf("%d", &base);

        printf("Expoente: ");
        scanf("%d", &expoente);

        potencia(&resultado, base, expoente);

        printf("Quer jogar de novo? Sim (1) Não (0)\n");
        scanf("%d", &jogar);   
    
    } while(jogar);


   
}