#include<stdio.h>

#include"verificacao_linear.h"

// Verifica se algum jogador venceu na jogada;
char verifica_vitoria(int n, char **tabuleiro, int p) {
    int i, j;
    char vencedor = ' ';

    printf("\nEntrou em verificação: \n");

    // Varre ponto a ponto do tabuleiro para fazer as verificações
    for(j = 0; j < n; j++) {
        for(i = 0; i < n; i++) {

            printf("Analizando em torno de %c (%d, %d)\n", tabuleiro[i][j], i, j);

            // Verifica apenas casas que receberam uma jogada
            if(tabuleiro[i][j] != ' ') {

                // Verifica se é possível fazer a analise para cima
                if(j-p+1 >= 0&&vencedor == ' ') {

                    // Faz a analize para cima (0, 1)
                    vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, 0, 1);

                    // Verifica se é possível fazer a analise para esquerda
                    if(i-p+1 >= 0&&vencedor == ' ') { // Permite analise na diagonal (-1, 1)

                        // Faz a analise na diagonal (-1, 1)
                        vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, -1, 1);
                    }

                    // Verifica se é possível fazer a analise para direita
                    if(i+p-1 < n&&vencedor == ' ') { // Permite analise na diagonal (1, 1)

                        // Faz a analise na diagonal (1, 1)
                        vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, 1, 1);
                    }
                }

                // Verifica se é possível fazer a analise para baixo
                if(j+p-1 < n&&vencedor == ' ') {

                    // Faz analise para baixo (0, -1)
                    vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, 0, -1);

                    // Verifica se é possível fazer a analise para esquerda
                    if(i-p+1 >= 0&&vencedor == ' ') { // Permite analise diagonal (-1, -1)

                        // Faz a analise na diagonal (-1, -1)
                        vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, -1, -1);
                    }

                    // Verifica se é possível fazer a analise para direita

                    // Verifica se é possível fazer a analise para direita
                    if(i+p-1 < n&&vencedor == ' ') { // Permite analise diagonal (1, -1)

                        // Faz a analise na diagonal (1, -1)
                        vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, 1, -1);
                    }
                }

                // Verifica se é possível fazer a analise para esquerda
                if(i-p+1 >= 0&&vencedor == ' ') {

                    // Faz analise para esquerda (-1, 0)
                    vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, -1, 0);
                }

                // Verifica se é possível fazer a analise para direita
                if(i+p-1 < n&&vencedor == ' ') {

                    // Faz analise para esquerda (1, 0)
                    vencedor = verificacao_linear(n, tabuleiro, p, tabuleiro[i][j], i, j, 1, 0);
                }
            }

            // Sai do for(i) se o vencedor é identificado para não sobreescrever
            if(vencedor != ' ') break;
        }

        // Sai do for(j) se o vencedor é identificado para não sobreescrever
        if(vencedor != ' ') break;
    }

    // Retorna o simbolo do vencedor encontrdo
    return vencedor;
}
