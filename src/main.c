#include <stdio.h>
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
    screenupdate();
}

void desenhar_cobra(Posicao *cobra, int tamanho){
    screenSetColor(BLUE, BLACK);
    for (int i = 0; i < tamanho; i++ ){
        screenGotoxy(cobra[tamanho].x, cobra[tamanho].y);
        printf("@");
    }
    screenUpdate();
}

void mover_cobra(Posicao *cobra, int tamanho, char direcao){
    for (int i = 0; i < tamanho; i++){
        cobra[i+1] = cobra[0];
    }
    if (direcao == 'w'){
        cobra[0].y--;
    }
    else if (direcao == 's'){
        cobra[0].y++;
    }
    else if (direcao == 'a'){
        cobra[0].x--;
    }
    else if(direcao == 'd'){
        cobra[0].x++;
    }
    screenUpdate();
}


int main(){
    screenInit(0);
    keyboardInit();
    cor_tela(BLACK);

    int tamanho = 1;

    return 0;
}

