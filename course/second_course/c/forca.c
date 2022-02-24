#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "forca.h"

// Global Variables
char palavra_secreta[TAMANHO_PALAVRA];
char chutes[26];
int chutes_dados = 0;

int chutes_errados(){
    int erros = 0;

    for (int i = 0; i < chutes_dados; i++){
        int existe = 0;

        for (int j = 0; j < strlen(palavra_secreta); j++){
            if (ja_chutou(palavra_secreta[i])){
                
                existe = 1;
                break;
            }
        }
        
        if(!existe) erros++;
    }

    return erros;
}

void abertura() {
    printf("*****************\n");
    printf("* Jogo de forca *\n");
    printf("*****************\n\n");
}

void chuta(){
    char chute;
    scanf(" %c", &chute);

    chutes[chutes_dados] = chute;
    
    chutes_dados++;
}

int ja_chutou(char letra){

    int achou = 0;

    for (int j = 0; j < chutes_dados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }

    return achou;
    
}

void desenha_forca(){

    int erros = chutes_errados();
    printf("  _______      \n");
    printf(" |/      |     \n");
    printf(" |      %s%s%s \n", erros >= 1 ? "(" : " ", erros >= 1 ? "_" : " ", erros >= 1 ? ")" : " ");
    printf(" |      %s%s%s \n",erros >= 3 ? "\\" : " ",erros >= 2 ? "|" : "",erros >= 3 ? "/" : " ");
    printf(" |       %s    \n", erros >= 2 ? "|" : " ");
    printf(" |      %s %s  \n",erros >= 4 ? "/" : " ",erros >= 4 ? "\\" : " ");
    printf(" |             \n");
    printf("_|___          \n");
    printf("\n\n");

    for (int i = 0; i < strlen(palavra_secreta); i++){
        
        int achou = ja_chutou(palavra_secreta[i]);

        if(achou){
            printf("%c ", palavra_secreta[i]);
        } else{
            printf("_ ");
        }
        
    }
    printf("\n");
}

void adiciona_palavra(){

    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo? (S/N) ");
    scanf(" %c", &quer);

    if (quer == 'S'){

        char nova_palavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", nova_palavra);

        FILE* f;

        f = fopen("palavras.txt", "r+");
        if (f == 0){
            printf("Desculpe, banco de dados não disponível\n\n");
            exit(1);
        }

        int quantidade;
        fscanf(f, "%d", &quantidade);
        quantidade++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", quantidade);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", nova_palavra);

        fclose(f);

    }
}

void escolhe_palavra(){
    FILE* f; 

    f = fopen("palavras.txt", "r");
    if(f == 0){
        printf("Desculpe, banco de dados não disponível\n\n");
        exit(1);
    }

    int quantidade_palavras;
    fscanf(f, "%d", &quantidade_palavras);

    srand(time(0));
    int randomico = rand()%quantidade_palavras;

    for (int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavra_secreta);
    }


    fclose(f);

}

int acertou(){
    for (int i = 0; i < strlen(palavra_secreta);i++){
        if(!ja_chutou(palavra_secreta[i])){
            return 0;
        }
    }

    return 1;
}

int enforcou(){
    
    return chutes_errados() >= 5;
}

int main(){ 
    
    escolhe_palavra();
    abertura();

    do {
        
        desenha_forca();
        chuta();

        } while (!acertou() && !enforcou());

    if(acertou()){
        printf("\nParabéns! Você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    } else {
        printf("\nPuxa! Você foi enforcado!\n");
        printf("A palavra secreta era **%s**\n\n", palavra_secreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
}