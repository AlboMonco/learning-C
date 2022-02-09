#include <stdio.h>

int main() {

    // imprime cabeçalho do jogo
    printf("******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");

    int numero_secreto = 42;

    int chute;
    int tentativas = 1;

    int pontos = 1000;

    while(1){ 
        printf("Tentativa %d\n", tentativas);
        printf("Qual é o seu chute? ");
        scanf("%d", &chute);
        printf("Seu chute é %d\n", chute);

        if(chute < 0){
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        int acertou = chute == numero_secreto;
        int maior = chute > numero_secreto;

        if (acertou) {
            printf("Parabéns! Você acertou!\n");
            printf("Jogue de novo, você é um bom jogador!\n");
            
            break;
        }
        
        else if(maior){
            printf("Seu chute foi maior que o número secreto.\n");

        }

        else {
            printf("Seu chute foi menor que o número secreto.\n");
        }

        tentativas++;

        int pontos_perdidos = (chute - numero_secreto)/2;
        pontos -= pontos_perdidos;
    }
    
    printf("Fim de jogo!\n");
    printf("Você acertou em %d tentativas\n", tentativas);
    printf("Total de pontos: %d\n", pontos);
       
}

