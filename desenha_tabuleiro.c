#include<stdio.h>

// Struct de estrutura de informações de un jogador
typedef struct {
    char simbolo;
    char tipo;
} Jogador;

// Desenha o tabuleiro com as jogadas feitas até então
void desenha_tabuleiro(int n, char **tabuleiro, Jogador jogadores) {
    int i, j;

    if(jogadores.tipo == 'c') {
        system("clear");
        printf("\n    Vez do Computador %c\n\n", jogadores.simbolo);
    }
    if(jogadores.tipo == 'h') {
        system("clear");
        printf("\n    Vez do Humano %c\n\n", jogadores.simbolo);
    }

    // Imprime uma linha horizontal e uma linha de conteúdo do tabuleiro por loop
    for(j = 0; j < n; j++) {

        // Imprime uma linha horizontal para iniciar o tabuleiro e separar as linhas
        printf("    ");
        for(i = 0; i < 4*n+1; i++) {
            printf("-");
        }
        printf("\n");

        // Imprime a linha i+1 do tabuleiro com o conteúdo da matriz das jogadas
        printf("    ");
        for(i = 0; i < n; i++) {
            printf("| %c ", tabuleiro[i][j]);
        }
        printf("|\n");
    }

    // Imprime uma ultima linha horizontal para fechar o tabuleiro
    printf("    ");
    for(i = 0; i < 4*n+1; i++) {
        printf("-");
    }
    printf("\n\n");

    if(jogadores.tipo == 'c') {
        printf("    Pressione ENTER para continuar.");
        getchar();
    }
}
