// Roda uma jogada aleatória de um jogador do computador
#include<stdio.h>
#include <stdlib.h>
typedef struct {
    char simbolo;
    char tipo;
} Jogador;
void jogada_computador(int n, char **tabuleiro, Jogador jogador) {

    int i, j;

    i = rand() % n;
    j = rand() % n;

    while(tabuleiro[i][j] != ' ') {
        i = rand() % n;
        j = rand() % n;
    }

    tabuleiro[i][j] = jogador.simbolo;
}
