desenha_tabuleiro.o : desenha_tabuleiro.c
	gcc -o desenha_tabuleiro.o -c desenha_tabuleiro.c

input_jogadores.o : input_jogadores.c
	gcc -o input_jogadores.o -c input_jogadores.c

jogada_computador.o : jogada_computador.c
	gcc -o jogada_computador.o -c jogada_computador.c

jogada_humano.o : jogada_humano.c
	gcc -o jogada_humano.o -c jogada_humano.c

verificacao_linear.o : verificacao_linear.c
	gcc -o verificacao_linear.o -c verificacao_linear.c

verifica_vitoria.o : verifica_vitoria.c
	gcc -o verifica_vitoria.o -c verifica_vitoria.c

inteligencia_checagem.o : inteligencia_checagem.c
	gcc -o inteligencia_checagem.o -c inteligencia_checagem.c

inteligencia_varredura.o : inteligencia_varredura.c
	gcc -o inteligencia_varredura.o -c inteligencia_varredura.c

ex2.o : ex2.c
	gcc -o ex2.o -c ex2.c

ex2 : ex2.o verifica_vitoria.o verificacao_linear.o jogada_humano.o jogada_computador.o input_jogadores.o desenha_tabuleiro.o inteligencia_checagem.o inteligencia_varredura.o
	gcc -o ex2 *.o


all : ex2

run: ex2
	./ex2

clean : ex2
	rm *.o ex2
