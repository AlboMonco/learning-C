#ifndef _MAPA_H_
#define _MAPA_H_

#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'
#define PILULA 'P'
#define BOMBA 'b'

struct mapa{
    char** matriz;
    int linhas;
    int colunas;
};

typedef struct mapa MAPA;

struct posicao{
    int x;
    int y;
};

typedef struct posicao POSICAO;

void le_mapa(MAPA* m);
void libera_mapa(MAPA* m);
void aloca_mapa(MAPA* m);
int encontra_mapa(MAPA* m, POSICAO* p, char c);
int eh_valida(MAPA* m, int x, int y);
int eh_vazia(MAPA* m, int x, int y);
int eh_personagem(MAPA* m, char personagem, int x, int y);
void anda_no_mapa(MAPA* m, int x_origem, int y_origem,
    int x_destino, int y_destino);
void copia_mapa(MAPA* destino, MAPA* origem);
int pode_andar(MAPA* m, char personagem, int x, int y);
int eh_parede(MAPA* m, int x, int y);

#endif