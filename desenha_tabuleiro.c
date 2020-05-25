// Desenha o tabuleiro com as jogadas feitas até então
#include<stdio.h>
void desenha_tabuleiro(int n, char **tabuleiro) {

    int i, j;

    for(j = 0; j < n; j++) {
        for(i = 0; i < 4*n+1; i++) {
            printf("-");
        }
        printf("\n");

        for(i = 0; i < n; i++) {
            printf("| %c ", tabuleiro[i][j]);
        }
        printf("|\n");

    }

    for(i = 0; i < 4*n+1; i++) {
        printf("-");
    }
    printf("\n");
}

