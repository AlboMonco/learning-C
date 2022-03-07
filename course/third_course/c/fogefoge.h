#ifndef _FOGE_FOGE_H_
#define _FOGE_FOGE_H_

#define CIMA 'w'
#define BAIXO 's'
#define DIREITA 'd'
#define ESQUERDA 'a'

int acabou();
void move(char direcao);
int eh_direcao(char direcao);
void fantasmas();
int pra_onde_o_fantasma_vai(int x_atual, int y_atual,
    int* x_destino, int* y_destino);
void explode_pilula();
void explode_pilula2(int x, int y, int soma_x, int soma_y, int quantidade);

#endif