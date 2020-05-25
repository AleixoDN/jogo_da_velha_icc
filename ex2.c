#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Struct de estrutura de informações de un jogador
typedef struct {
    char simbolo;
    char tipo;
} Jogador;

#include "desenha_tabuleiro.h"
#include "input_jogadores.h"
#include "jogada_computador.h"
#include "jogada_humano.h"
#include "verificacao_linear.h"
#include "verifica_vitoria.h"

int main() {

    int n, i, j, m, p,k=0;//k é a variavel referente ao numero de jogadas
    char aux, vencedor = ' ';

    // Inicio e reforço a pseudo-aleatoriedade da função rand()

    srand((unsigned int)time(NULL));
    rand();
    rand();
    rand();

    // Input de tamanho do tabuleiro

    printf("Número de linhas e colunas do tabuleiro: ");
    scanf("%d", &n);

    // Declaração do tabuleiro no tamanho indicado

    char **tabuleiro;
    tabuleiro=(char**)malloc(sizeof(char)*n);
    for(int i=0;i<n;i++){
	tabuleiro[i]=malloc(sizeof(char)*n);
    }

    // Input do tamanho da sequencia para vitoria

    printf("Tamanho da sequencia para vitória: ");
    scanf("%d", &p);

    // Input de quantos e quais jogadores serão

    printf("Número de jogadores: ");
    scanf("%d", &m);
    scanf("%c", &aux);

    Jogador *jogadores;
    jogadores=(Jogador*) malloc(sizeof(Jogador)*m);

    input_jogadores(m, jogadores);

    // Zerando a matriz que conterá as jogadas feitas

    for(j = 0; j < n; j++) {
        for(i = 0; i < n; i++) {
            tabuleiro[i][j] = ' ';
        }
    }

    // Loop que inicia jogada por jogada


    desenha_tabuleiro(n, tabuleiro);
    while(vencedor == ' '&&k!=n*n) { // critério temporário

        // Rodar jogadores, cada um em uma jogada
        for(i = 0; i < m; i++) {

            // Verificar se o jogador atual é um humano ou um computador
            if (jogadores[i].tipo == 'h') {
                jogada_humano(n, tabuleiro, jogadores[i]);
            } else if(jogadores[i].tipo == 'c') {
                jogada_computador(n, tabuleiro, jogadores[i]);
            }
            k++;

            // Verifica se o jogador ganhou com a ultima jogada
            vencedor = verifica_vitoria(n, tabuleiro, p);

            // Desenha o tabuleiro contendo a ultima jogada
            desenha_tabuleiro(n, tabuleiro);

            // Break para sair do for, uma vez que ele sairá automaticamente do while
            if(vencedor != ' ') {
                printf("O vencedor é o jogador de símbolo: %c\n", vencedor);
                break;
            }
	    //Break para sair do for caso dê velha, uma vez que ele sairá automaticamente do while
            if(k==n*n){
		printf("Velha");
		break;
	    }
        }

    }

    return 0;
}
