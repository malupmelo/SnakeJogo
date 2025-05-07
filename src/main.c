#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"
#include "cobra.h"
#include "jogo.h"

int main(){
    screenInit(0);
    keyboardInit();
    timerInit(150);
    cor_tela(BLACK);

    int tamanho = 1;
    int tecla = 0;
    Posicao *cobra = malloc(tamanho * sizeof(Posicao));
    Posicao comida;
    cobra[0].x = 40;
    cobra[0].y = 12;
    comida.x = rand() % (78 - 3 + 1) + 3;
    comida.y = rand() % (23 - 3 + 1) + 3;
    desenhar_cobra(cobra,tamanho);
    gerar_comida(comida.x,comida.y);
    while (tecla != 10){
        if (keyhit()){
            tecla = readch();
        }
        if(timerTimeOver() && tecla != 0){
            pontuar(&comida,&tamanho,&cobra);
            limpar(cobra,tamanho);
            mover_cobra(cobra,tamanho,tecla);
            desenhar_cobra(cobra,tamanho);
            if (colisao(cobra,tamanho)){
                break;
            }
        }
        
    }
    free(cobra);
    timerDestroy();
    keyboardDestroy();
    screenDestroy();

    return 0;
}


