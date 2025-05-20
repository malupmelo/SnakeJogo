#ifndef COBRA_H
#define COBRA_H

struct Posicao{
    int x;
    int y;
} typedef Posicao;

void limpar(Posicao *cobra, int tamanho);

void desenhar_cobra(Posicao *cobra, int tamanho);

void mover_cobra(Posicao *cobra, int tamanho, int tecla);


#endif