#include <stdio.h>
#include <stdlib.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;

int acabou(){
    return 0;
}

void move(char direcao){
    
    m.matriz[heroi.x][heroi.y] = '.';

    switch(direcao){
        case 'a':
            m.matriz[heroi.x][heroi.y-1] = '@';
            heroi.y--;
            break;
        case 's':
            m.matriz[heroi.x+1][heroi.y] = '@';
            heroi.x++;
            break;
        case 'w':
            m.matriz[heroi.x-1][heroi.y] = '@';
            heroi.x--;
            break;
        case 'd':
            m.matriz[heroi.x][heroi.y+1] = '@';
            heroi.y++;
            break;
    }

    
}

int main(){

    le_mapa(&m);
    encontra_mapa(&m, &heroi, '@');

    do{

        imprime_mapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while(!acabou());
    
    libera_mapa(&m);

}