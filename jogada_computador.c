#include<stdio.h>
#include <stdlib.h>

// Struct de estrutura de informações de un jogador
typedef struct {
    char simbolo;
    char tipo;
} Jogador;

// Roda uma jogada aleatória de um jogador do computador
void jogada_computador(int n, char **tabuleiro, Jogador jogador) {
    int i, j;

    // Gera uma posição aleatória no tabuleiro
    i = rand() % n;
    j = rand() % n;

    // Garante que a posição gerada estará vazia
    while(tabuleiro[i][j] != ' ') {
        i = rand() % n;
        j = rand() % n;
    }

    // Edita a matriz de jogadas com a jogada aleatória da máquina
    tabuleiro[i][j] = jogador.simbolo;
}
