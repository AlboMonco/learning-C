#include <stdio.h>

int main(){
    FILE* f;

    f = fopen("teste.txt", "r");
    if (f == 0){
        printf("Desculpe, banco de dados não disponível\n\n");
        exit(1);
    }


    fclose(f);
}