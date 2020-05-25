// Colhe e roda uma jogada de um jogador humano
#include<stdio.h>
typedef struct {
    char simbolo;
    char tipo;
} Jogador;
void jogada_humano(int n, char **tabuleiro, Jogador jogador) {

    int i, j;

    printf("Linha: ");
    scanf("%d", &j);
    printf("Coluna: ");
    scanf("%d", &i);

    while((tabuleiro[i-1][j-1] != ' ') || (i < 1) || (i > n) || (j < 1) || (j > n)) {
        printf("Linha: ");
        scanf("%d", &j);
        printf("Coluna: ");
        scanf("%d", &i);

        printf("Char antigo: (%c)", tabuleiro[i-1][j-1]);
    }

    printf("\n");

    tabuleiro[i-1][j-1] = jogador.simbolo;
}
