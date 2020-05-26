#include<stdio.h>

// Struct de estrutura de informações de un jogador
typedef struct {
    char simbolo;
    char tipo;
} Jogador;

// Colhe e roda uma jogada de um jogador humano
void jogada_humano(int n, char **tabuleiro, Jogador jogador) {
    int i, j;

    printf("Vez do humano %c\n", jogador.simbolo);

    // Colhe a posição da jogada do usuário
    printf("Linha: ");
    scanf("%d", &j);
    printf("Coluna: ");
    scanf("%d", &i);

    // Garante que a posição é válida e ainda vazia
    while((tabuleiro[i-1][j-1] != ' ') || (i < 1) || (i > n) || (j < 1) || (j > n)) {
        printf("Linha: ");
        scanf("%d", &j);
        printf("Coluna: ");
        scanf("%d", &i);
    }
    printf("\n");

    // Retorna para a matriz de jogadas a jogada feita pelo usuário
    tabuleiro[i-1][j-1] = jogador.simbolo;
}
