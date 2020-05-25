#include<stdio.h>
#include"verificacao_linear.h"
// Verifica se algum jogador venceu na jogada;
char verifica_vitoria(int n, char **tabuleiro, int p) {
    int i, j;
    char vencedor = ' ';

    printf("\nEntrou em verificação\n");

    for(j = 0; j < n; j++) {
        for(i = 0; i < n; i++) {

            printf("Analizando em torno de %c (%d, %d)\n", tabuleiro[i][j], i, j);

            if(tabuleiro[i][j] != ' ') {

                if(j-p+1 >= 0&&vencedor == ' ') { // Verifica se é possível fazer a analise para cima
                    vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, 0, 1);

                    // Se é possível testar para cima E para um lado,
                    // é possível testar para a diagonal desse lado

                    if(i-p+1 >= 0&&vencedor == ' ') { // Verifica se é possível fazer a analise para esquerda
                        vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, -1, 1);
                    }

                    if(i+p-1 < n&&vencedor == ' ') { // Verifica se é possível fazer a analise para direita
                        vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, 1, 1);
                    }
                }

                if(j+p-1 < n&&vencedor == ' ') { // Verifica se é possível fazer a analise para baixo
                    vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, 0, -1);

                    // Igualmente pra as diagonais inferiores

                    if(i-p+1 >= 0&&vencedor == ' ') { // Verifica se é possível fazer a analise para esquerda
                        vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, -1, -1);
                    }

                    if(i+p-1 < n&&vencedor == ' ') { // Verifica se é possível fazer a analise para direita
                        vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, 1, -1);
                    }
                }

                if(i-p+1 >= 0&&vencedor == ' ') { // Verifica se é possível fazer a analise para esquerda
                    vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, -1, 0);
                }

                if(i+p-1 < n&&vencedor == ' ') { // Verifica se é possível fazer a analise para direita
                    vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, 1, 0);
                }

            }

            if(vencedor != ' ') break;
        }

        if(vencedor != ' ') break;
    }

    return vencedor;
}
