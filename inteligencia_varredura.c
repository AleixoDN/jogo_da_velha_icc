#include <stdio.h>

// Verificação linear no range p, em linha, coluna ou diagonal
// Argumentos x,y são como no plano cartesiano
    // (ex.: (0,1) é para cima, (1, -1) é diagonal direita para baixo)
char inteligencia_varredura(int n, char **tabuleiro, int p, char casa_analisada, int i, int j, int x, int y) {
    int k, contasimb=1;
    for(k = 1; k < p; k++) {
        if(casa_analisada == tabuleiro[i+(k*x)][j-(k*y)]) {
            contasimb ++;
        }
    }
    if((contasimb==p-1) && (casa_analisada != ' ')) {
    	for(k = 1; k < p; k++) {
        	if(tabuleiro[i+(k*x)][j-(k*y)] == ' ') {
                printf("Catabimbas");
                tabuleiro[i+(k*x)][j-(k*y)] == casa_analisada;
                return 'J';
            }
        }
    }
    return ' ';
}
