#include<stdio.h>

// Verificação linear no range p, em linha, coluna ou diagonal
// Argumentos x,y são como no plano carteziano
    // (ex.: (0,1) é para cima, (1, -1) é diagonal direita para baixo)
char verificacao_linear(int n, char **tabuleiro, int p, char casa_analisada, int i, int j, int x, int y) {
    int verif_igual, k;
    char vencedor = ' ';

    printf("Analise (%d, %d)\n", x, y);

    verif_igual = 1;                            // Flag de verificação
    for(k = 1; k < p; k++) {                    // Varre a sequencia de p valoes da direção dada
        printf("Analizando sequencia para k = %d (Valor comparado: %c(%d,%d))\n", k, tabuleiro[i+(k*x)][j-(k*y)], i+(k*x), j-(k*y));
        if(casa_analisada != tabuleiro[i+(k*x)][j-(k*y)]) { // Verifica se algum valor difere do primeiro
            verif_igual = 0;                    // Se diferenciar, aciona o flag
            break;
        }
    }
    if((verif_igual == 1) && (casa_analisada != ' ')) {     // Se o flag não for acionado
        vencedor = casa_analisada;                          // o valor analisado é dado como vencedor
    }
    printf("    %c - %d\n", vencedor, verif_igual);

    return vencedor;                            // Retorna ' ' se não há vencedor,
                                                //ou o simbolo do vencedor se há vencedor
}
