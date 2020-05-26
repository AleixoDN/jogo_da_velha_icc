#include<stdio.h>

// Struct de estrutura de informações de un jogador
typedef struct {
    char simbolo;
    char tipo;
} Jogador;

// Coleta as informações dos m jogadores
void input_jogadores(int m, Jogador *jogadores) {
    int i;
    char aux;

    printf("\n");
    // Colhe dos M jogadores os simbolos que os representarão e se serão
    // controlados por um usuário ou pela máquina
    for(i = 0; i < m; i++) {

        // Colhe o símbolo do jogador i
        printf("Símbolo para representar o jogador %d: ", i+1);
        scanf("%c", &jogadores[i].simbolo);
        scanf("%c", &aux);

        // Colhe o tipo do jogador i
        printf("Jogador %d será um humano ou um computador[h/c]: ", i+1);
        scanf("%c", &jogadores[i].tipo);
        scanf("%c", &aux);

        // Certifica que o tipo é válido
        while((jogadores[i].tipo != 'h') && (jogadores[i].tipo != 'c')) {
            printf("Resposta Invalida.\nJogador %d será um humano ou um computador[h/c]: ", i+1);
            scanf("%c", &jogadores[i].tipo);
            scanf("%c", &aux);
        }
        printf("\n");
    }
}
