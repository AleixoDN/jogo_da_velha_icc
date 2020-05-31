#include<stdio.h>
#include<stdlib.h>

// Struct de estrutura de informações de un jogador
typedef struct {
    char simbolo;
    char tipo;
} Jogador;

// Coleta as informações dos m jogadores
void input_jogadores(int m, Jogador *jogadores) {
    int i, j, eq;
    char aux;

    system("clear");

    printf("\n                ####################################\n                ##                                ##\n                ##        Jogo da Velha ++        ##\n                ##                                ##\n                ####################################\n\n");

    printf("\n    [%d] jogadores: Insira os simbolos de cada um e quem vai controlá-los.\n\n", m);

    // Colhe dos M jogadores os simbolos que os representarão e se serão
    // controlados por um usuário ou pela máquina
    for(i = 0; i < m; i++) {

        // Colhe o símbolo do jogador i
        printf("    Símbolo para representar o jogador %d: ", i+1);
        scanf("%c", &jogadores[i].simbolo);
        scanf("%c", &aux);
        eq = 1;

        while(eq == 1) {
            eq = 0;

            for(j = 0; j < i; j++) {
                if(jogadores[i].simbolo == jogadores[j].simbolo) {
                    eq = 1;
                }
            }
            if(eq == 1) {
                printf("        Simbolo já usado.\n    Símbolo para representar o jogador %d: ", i+1);
                scanf("%c", &jogadores[i].simbolo);
                scanf("%c", &aux);
            }
        }

        // Colhe o tipo do jogador i
        printf("    Jogador %d será um humano ou um computador[h/c]: ", i+1);
        scanf("%c", &jogadores[i].tipo);
        scanf("%c", &aux);

        // Certifica que o tipo é válido
        while((jogadores[i].tipo != 'h') && (jogadores[i].tipo != 'c')) {
            printf("        Resposta Invalida.\n    Jogador %d será um humano ou um computador[h/c]: ", i+1);
            scanf("%c", &jogadores[i].tipo);
            scanf("%c", &aux);
        }
        printf("\n");
    }
}
