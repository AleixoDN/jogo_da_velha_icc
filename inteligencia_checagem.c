#include<stdio.h>

#include"inteligencia_varredura.h"

// Verifica se algum jogador venceu na jogada;
char inteligencia_checagem(int n, char **tabuleiro, int p, char simbolo) {
    int i, j;
    char jogada = ' ';


    // Varre ponto a ponto do tabuleiro para fazer as verificações
    for(j = 0; j < n; j++) {
        for(i = 0; i < n; i++) {
            // Verifica apenas casas que receberam uma jogada
            if(tabuleiro[i][j] != ' ') {

                // Verifica se é possível fazer a analise para cima
                if(j-p+1 >= 0&&jogada == ' ') {

                    // Faz a analise para cima (0, 1)
                    jogada = inteligencia_varredura(n, tabuleiro, p, simbolo, i, j, 0, 1);

                    // Verifica se é possível fazer a analise para esquerda
                    if(i-p+1 >= 0&&jogada == ' ') { // Permite analise na diagonal (-1, 1)

                        // Faz a analise na diagonal (-1, 1)
                        jogada = inteligencia_varredura(n, tabuleiro, p, simbolo, i, j, -1, 1);
                    }

                    // Verifica se é possível fazer a analise para direita
                    if(i+p-1 < n&& jogada == ' ') { // Permite analise na diagonal (1, 1)

                        // Faz a analise na diagonal (1, 1)
                        jogada = inteligencia_varredura(n, tabuleiro, p, simbolo, i, j, 1, 1);
                    }
                }

                // Verifica se é possível fazer a analise para baixo
                if(j+p-1 < n&&jogada == ' ') {

                    // Faz analise para baixo (0, -1)
                    jogada = inteligencia_varredura(n, tabuleiro, p, simbolo, i, j, 0, -1);

                    // Verifica se é possível fazer a analise para esquerda
                    if(i-p+1 >= 0&&jogada == ' ') { // Permite analise diagonal (-1, -1)

                        // Faz a analise na diagonal (-1, -1)
                        jogada = inteligencia_varredura(n, tabuleiro, p, simbolo, i, j, -1, -1);
                    }

                    // Verifica se é possível fazer a analise para direita

                    // Verifica se é possível fazer a analise para direita
                    if(i+p-1 < n&&jogada == ' ') { // Permite analise diagonal (1, -1)

                        // Faz a analise na diagonal (1, -1)
                        jogada = inteligencia_varredura(n, tabuleiro, p, simbolo, i, j, 1, -1);
                    }
                }

                // Verifica se é possível fazer a analise para esquerda
                if(i-p+1 >= 0&&jogada == ' ') {

                    // Faz analise para esquerda (-1, 0)
                    jogada = inteligencia_varredura(n, tabuleiro, p, simbolo, i, j, -1, 0);
                }

                // Verifica se é possível fazer a analise para direita
                if(i+p-1 < n&&jogada == ' ') {

                    // Faz analise para esquerda (1, 0)
                    jogada = inteligencia_varredura(n, tabuleiro, p, simbolo, i, j, 1, 0);
                }
            }

            // Sai do for(i) se o vencedor é identificado para não sobreescrever
            if(jogada != ' ') break;
        }

        // Sai do for(j) se o vencedor é identificado para não sobreescrever
        if(jogada != ' ') break;
    }

    // Retorna o simbolo do vencedor encontrdo
    return jogada;
}
