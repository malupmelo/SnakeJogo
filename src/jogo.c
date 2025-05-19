#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/screen.h"
#include "../biblioteca/timer.h"
#include "../biblioteca/keyboard.h"
#include "jogo.h"
#include "cobra.h"
#include "menu.h"
#include "utils.h"

int jogar() {
    int velocidade = 150;
    timerInit(velocidade);

    cor_tela(BLACK);

    int tamanho = 1;
    int tecla = 0;
   
    Posicao *cobra = malloc(tamanho * sizeof(Posicao));
    Posicao comida;

    cobra[0].x = 40;
    cobra[0].y = 12;
    comida.x = rand() % (78 - 3 + 1) + 3;
    comida.y = rand() % (23 - 3 + 1) + 3;

    desenhar_cobra(cobra, tamanho);
    gerar_comida(comida.x, comida.y);

    while (tecla != 10) {
        if (keyhit()) {
            tecla = readch();
        }
        if (timerTimeOver() && tecla != 0) {
            if(pontuar(&comida, &tamanho, &cobra)) {
                if (velocidade > 20) {
                    velocidade -= 5;
                }
                timerUpdateTimer(velocidade);
            };
            limpar(cobra, tamanho);
            mover_cobra(cobra, tamanho, tecla);
            desenhar_cobra(cobra, tamanho);
            if (colisao(cobra, tamanho)) {
                break;
            }
        }
    }

    free(cobra);
    menu_final(tamanho);
    screenUpdate();
    while (readch() != 10); 
    cor_tela(BLACK);
    timerDestroy();
    return (tamanho - 1) * 10;
}
