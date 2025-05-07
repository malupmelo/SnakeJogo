#ifndef JOGO_H
#define JOGO_H

#include "screen.h"
#include "cobra.h"

void cor_tela(screenColor cor);

void gerar_comida(int posicaoComida_x, int posicaoComida_y);

void pontuar(Posicao *comida, int *tamanho, Posicao **cobra);

int colisao(Posicao *cobra, int tamanho);

#endif