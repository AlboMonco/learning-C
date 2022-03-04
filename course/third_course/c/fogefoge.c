#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

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

        if (eh_valida(&m, opcoes[posicao][0], opcoes[posicao][1]) && eh_vazia(&m, opcoes[posicao][0], opcoes[posicao][1])){
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
    return 0;
}

int eh_direcao(char direcao){
    return direcao == ESQUERDA || direcao == CIMA || direcao == BAIXO || direcao == DIREITA;
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

    if(!eh_valida(&m, proximo_x, proximo_y))
        return;

    if (!eh_vazia(&m, proximo_x, proximo_y))
        return;
    
    anda_no_mapa(&m, heroi.x, heroi.y,
        proximo_x, proximo_y);
    
    heroi.x = proximo_x;
    heroi.y = proximo_y;
}

int main(){

    le_mapa(&m);
    encontra_mapa(&m, &heroi, HEROI);

    do{

        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
        fantasmas();

    } while(!acabou());
    
    libera_mapa(&m);

}