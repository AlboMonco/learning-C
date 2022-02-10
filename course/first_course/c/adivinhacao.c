#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    printf("\n\n");
    printf("        P  /_\\  P                                 \n");
    printf("       /_\\_|_|_/_\\                               \n");
    printf("   n_n | ||. .|| | n_n         Bem vindo ao        \n");
    printf("   |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação!    \n");
    printf("  |" "  |  |_|  |"  " |                            \n");
    printf("  |_____| ' _ ' |_____|                            \n");
    printf("        \\__|_|__/                                 \n");
    printf("\n\n");
    
    int segundos = time(0);
    srand(segundos);

    int numero_grande = rand();
    int numero_secreto = numero_grande % 100;
    int chute;
    int tentativas = 1;
    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nível de dificuldade?\n");
    printf("(1) Fácil, (2) Médio, (3) Difícil\n\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    int numero_de_tentativas;
    
    switch(nivel){
        case 1:
            numero_de_tentativas = 20;
            break;

        case 2:
            numero_de_tentativas = 15;
            break;

        default:
            numero_de_tentativas = 6;
            break;
    }

    for (int i = 1; i <= numero_de_tentativas; i++){
        printf("\nTentativa %d:\n", tentativas);
        printf("        Qual é o seu chute? ");
        scanf("%d", &chute);

        if(chute < 0){
            printf("Você não pode chutar números negativos!\n");
            continue;
        }

        acertou = (chute == numero_secreto);
        int maior = chute > numero_secreto;

        if (acertou) {
            break;
        }
        
        else if(maior){
            printf("Seu chute foi maior que o número secreto.\n");

        }

        else {
            printf("Seu chute foi menor que o número secreto.\n");
        }
    
        tentativas++;

        double pontos_perdidos = abs(chute - numero_secreto)/ (double)2;
        pontos -= pontos_perdidos;
    }
    

    printf("\nFim de jogo!\n");
    
    if(acertou){

        printf("\n\n");
        printf("             OOOOOOOOOOO              \n");
        printf("         OOOOOOOOOOOOOOOOOOO          \n"); 
        printf("      OOOOOO  OOOOOOOOO  OOOOOO       \n"); 
        printf("    OOOOOO      OOOOO      OOOOOO     \n");
        printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO   \n"); 
        printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO  \n"); 
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO \n"); 
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO \n"); 
        printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO \n"); 
        printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n"); 
        printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO   \n"); 
        printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO    \n"); 
        printf("      OOOOOO   OOOOOOOOO   OOOOOO     \n"); 
        printf("         OOOOOO         OOOOOO        \n"); 
        printf("             OOOOOOOOOOOO             \n");
        printf("\n\n");

        printf("Você ganhou!\n");
        printf("Você acertou em %d tentativas\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    } else {

        printf("\n\n");
        printf("   \\|/ ____ \\|/  \n");       
        printf("    @~/ ,. \\~@    \n");       
        printf("   /_( \\__/ )_\\  \n");      
        printf("      \\__U_/      \n");
        printf("\n\n");

        printf("Você perdeu! Tente de novo!\n");
    }
    
       
}

