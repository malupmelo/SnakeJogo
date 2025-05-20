#include "utils.h"
#include "cobra.h"  
#include <stdlib.h>
#include "../biblioteca/screen.h"
#include "../biblioteca/keyboard.h"

void cor_tela(screenColor cor){
    screenSetColor(WHITE,cor);
    for (int x = 1; x <= 80; x++){
        for (int y = 1; y<= 24; y++){
            screenGotoxy(x,y);
            printf(" ");
        }
    }
    screenUpdate();
}


void gerar_comida(int posicaoComida_x, int posicaoComida_y){
    screenSetColor(RED, BLACK);
    screenGotoxy(posicaoComida_x, posicaoComida_y);
    printf("*");
    screenUpdate();
}

int pontuar(Posicao *comida, int *tamanho, Posicao **cobra){
    if (comida->x == (*cobra)[0].x && comida->y == (*cobra)[0].y){
        (*tamanho)++;
        *cobra = realloc(*cobra, *tamanho * sizeof(Posicao));
        (*cobra)[*tamanho-1] = (*cobra)[*tamanho-2];

        do {
            comida->x = rand() % (78 - 3 + 1) + 3;
            comida->y = rand() % (22 - 3 + 1) + 3;
        } while (checar_comida(*cobra, *tamanho, comida->x, comida->y));

        gerar_comida(comida->x, comida->y);
        return 1;
    }
    return 0;
}

int colisao(Posicao *cobra, int tamanho){
    if (cobra[0].x>= 1 && cobra[0].x <= 80 && cobra[0].y == 1){
        return 1;
    }
    if (cobra[0].x>= 1 && cobra[0].x <= 80 && cobra[0].y == 24){
        return 1;
    }
    if (cobra[0].y>= 1 && cobra[0].y <= 24 && cobra[0].x == 1){
        return 1;
    }
    if (cobra[0].y>= 1 && cobra[0].y <= 24 && cobra[0].x == 80){
        return 1;
    }
    for (int i = tamanho - 1; i > 0; i--){
        if (cobra[0].x == cobra[i].x && cobra[0].y == cobra[i].y){
            return 1;
        }
    }
    return 0;
}

int checar_comida(Posicao *cobra, int tamanho, int comida_x, int comida_y) {
    for (int i = 1; i < tamanho; i++) {
        if (cobra[i].x == comida_x && cobra[i].y == comida_y) {
            return 1;
        }
    }
    return 0;
}

void mostrar_pontuacao(int pontos) {
    screenGotoxy(36,2);
    screenSetColor(GREEN, BLACK);
    printf("Pontos: ");
    screenGotoxy(44,2);
    printf("%d", pontos);
}