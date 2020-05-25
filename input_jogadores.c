// Coleta as informações dos m jogadores
#include<stdio.h>
typedef struct {
    char simbolo;
    char tipo;
} Jogador;
void input_jogadores(int m, Jogador *jogadores) {

    int i;
    char aux;

    printf("\n");
    for(i = 0; i < m; i++) {
        printf("Símbolo para representar o jogador %d: ", i+1);
        scanf("%c", &jogadores[i].simbolo);
        scanf("%c", &aux);
        printf("Jogador %d será um humano ou um computador[h/c]: ", i+1);
        scanf("%c", &jogadores[i].tipo);
        scanf("%c", &aux);
        while((jogadores[i].tipo != 'h') && (jogadores[i].tipo != 'c')) {
            printf("Resposta Invalida.\nJogador %d será um humano ou um computador[h/c]: ", i+1);
            scanf("%c", &jogadores[i].tipo);
            scanf("%c", &aux);
        }
        printf("\n");
    }
}
