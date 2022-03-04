#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

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
void imprime_mapa(MAPA* m);
void encontra_mapa(MAPA* m, POSICAO* p, char c);
int eh_valida(MAPA* m, int x, int y);
int eh_vazia(MAPA* m, int x, int y);
void anda_no_mapa(MAPA* m, int x_origem, int y_origem,
    int x_destino, int y_destino);
void copia_mapa(MAPA* destino, MAPA* origem);



