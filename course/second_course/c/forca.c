#include <stdio.h>
#include <string.h>
#include "forca.h"

// Global Variables
char palavra_secreta[20];
char chutes[26];
int chutes_dados = 0;

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

void escolhe_palavra(){
    sprintf(palavra_secreta, "MELANCIA");
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

    return erros >= 5;
}

int main(){ 
    
    escolhe_palavra();
    abertura();

    do {
        
        desenha_forca();
        chuta();

        } while (!acertou() && !enforcou());

}