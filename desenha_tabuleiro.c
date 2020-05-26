#include<stdio.h>

// Desenha o tabuleiro com as jogadas feitas até então
void desenha_tabuleiro(int n, char **tabuleiro) {
    int i, j;

    // Imprime uma linha horizontal e uma linha de conteúdo do tabuleiro por loop
    for(j = 0; j < n; j++) {

        // Imprime uma linha horizontal para iniciar o tabuleiro e separar as linhas
        for(i = 0; i < 4*n+1; i++) {
            printf("-");
        }
        printf("\n");

        // Imprime a linha i+1 do tabuleiro com o conteúdo da matriz das jogadas
        for(i = 0; i < n; i++) {
            printf("| %c ", tabuleiro[i][j]);
        }
        printf("|\n");
    }

    // Imprime uma ultima linha horizontal para fechar o tabuleiro
    for(i = 0; i < 4*n+1; i++) {
        printf("-");
    }
    printf("\n\n");
}
