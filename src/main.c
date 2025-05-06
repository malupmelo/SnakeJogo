#include <stdio.h>
#include <stdlib.h>
#include "screen.h"
#include "keyboard.h"
#include "timer.h"

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

struct Posicao{
    int x;
    int y;
} typedef Posicao;

void limpar(Posicao *cobra, int tamanho){
    screenSetColor(WHITE,BLACK);
    screenGotoxy(cobra[tamanho-1].x, cobra[tamanho-1].y);
    printf(" ");
}

void desenhar_cobra(Posicao *cobra, int tamanho){
    screenSetColor(BLUE, BLACK);
    for (int i = 0; i < tamanho; i++ ){
        screenGotoxy(cobra[tamanho].x, cobra[tamanho].y);
        printf("@");
    }
    screenUpdate();
}

void mover_cobra(Posicao *cobra, int tamanho, int tecla){
    for (int i = 0; i < tamanho; i++){
        cobra[i+1] = cobra[i];
    }
    if (tecla == 119){
        limpar(cobra,tamanho);
        cobra[0].y--;
    }
    else if (tecla == 115){
        limpar(cobra,tamanho);
        cobra[0].y++;
    }
    else if (tecla == 97){
        limpar(cobra,tamanho);
        cobra[0].x--;
    }
    else if(tecla == 100){
        limpar(cobra,tamanho);
        cobra[0].x++;
    }
    desenhar_cobra(cobra, tamanho);
}


int main(){
    screenInit(0);
    keyboardInit();
    cor_tela(BLACK);

    int tamanho = 5;
    int tecla = 0;
    Posicao *cobra = malloc(tamanho * sizeof(Posicao));
    cobra[0].x = 10;
    cobra[0].y = 10;

    while (tecla != 10){
        if (keyhit()){
            tecla = readch();
        }
        mover_cobra(cobra, tamanho, tecla);
    }
    keyboardDestroy();
    screenDestroy();

    return 0;
}

