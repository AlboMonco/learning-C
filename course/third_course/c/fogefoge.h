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
