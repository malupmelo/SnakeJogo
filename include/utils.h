#ifndef UTILS_H
#define UTILS_H

#include "../biblioteca/screen.h"
#include "cobra.h" 

void cor_tela(screenColor cor);
void gerar_comida(int posicaoComida_x, int posicaoComida_y);
int pontuar(Posicao *comida, int *tamanho, Posicao **cobra);
int colisao(Posicao *cobra, int tamanho);
int checar_comida(Posicao *cobra, int tamanho, int comida_x, int comida_y);

#endif
