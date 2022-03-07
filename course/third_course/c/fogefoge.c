#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"
#include "ui.h"

MAPA m;
POSICAO heroi;
int tem_pilula = 0;

int pra_onde_o_fantasma_vai(int x_atual, int y_atual,
    int* x_destino, int* y_destino){
    
    int opcoes[4][2]= {
        {x_atual, y_atual +1},
        {x_atual + 1, y_atual},
        {x_atual, y_atual - 1},
        {x_atual - 1, y_atual}
    };

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int posicao = rand() % 4;

        if (pode_andar(&m, FANTASMA, opcoes[posicao][0], opcoes[posicao][1])){
            *x_destino = opcoes[posicao][0];
            *y_destino = opcoes[posicao][1];

            return 1;
        }
    }

    return 0;
}

void fantasmas(){
    MAPA copia;

    copia_mapa(&copia, &m);

    for (int i = 0; i < m.linhas; i++){
        for (int j = 0; j < m.colunas; j++){
            
            if(copia.matriz[i][j] == FANTASMA){

                int x_destino;
                int y_destino;

                int encontrou = pra_onde_o_fantasma_vai(i, j, &x_destino, &y_destino);

                if(encontrou){
                    anda_no_mapa(&m, i, j, x_destino, y_destino);
                    
                }
            }
        }
    }

    libera_mapa(&copia);
}

int acabou(){
    POSICAO pos;
    int fogefoge_no_mapa = encontra_mapa(&m, &pos, HEROI);
    return !fogefoge_no_mapa;
}

int eh_direcao(char direcao){
    return 
        direcao == ESQUERDA ||
        direcao == CIMA || 
        direcao == BAIXO || 
        direcao == DIREITA;
}

void move(char direcao){

    if(!eh_direcao(direcao))
        return;

    int proximo_x = heroi.x;
    int proximo_y = heroi.y;

    switch(direcao){
        case ESQUERDA:
            proximo_y--;
            break;
        case CIMA:
            proximo_x--;
            break;
        case BAIXO:
            proximo_x++;
            break;
        case DIREITA:
            proximo_y++;
            break;

    }

    if(!pode_andar(&m, HEROI, proximo_x, proximo_y))
        return;

    if (eh_personagem(&m, PILULA, proximo_x, proximo_y)){
        tem_pilula = 1;
    }
    
    anda_no_mapa(&m, heroi.x, heroi.y,
        proximo_x, proximo_y);
    
    heroi.x = proximo_x;
    heroi.y = proximo_y;
}

void explode_pilula(){

    if(!tem_pilula) return;

    explode_pilula2(heroi.x, heroi.y, 0, 1, 3);
    explode_pilula2(heroi.x, heroi.y, 0, -1, 3);
    explode_pilula2(heroi.x, heroi.y, 1, 0, 3);
    explode_pilula2(heroi.x, heroi.y, -1, 0, 3);

    tem_pilula = 0;
}

void explode_pilula2(int x, int y, int soma_x, int soma_y, int quantidade){
    
    if (quantidade == 0) return;
    
    int novo_x = x + soma_x;
    int novo_y = y + soma_y;

    if(!eh_valida(&m, novo_x, novo_y)) return;
    if(eh_parede(&m, novo_x, novo_y)) return;

    m.matriz[novo_x][novo_y] = VAZIO;
    explode_pilula2(novo_x, novo_y, soma_x, soma_y, quantidade - 1);

}

int main(){

    le_mapa(&m);
    encontra_mapa(&m, &heroi, HEROI);

    do{

        printf("Tem pilula: %s\n", (tem_pilula ? "SIM" : "NÃO"));
        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);

        
        move(comando);

        if (comando == BOMBA) explode_pilula();
        fantasmas();

    } while(!acabou());
    
    libera_mapa(&m);

}