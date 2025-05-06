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
        screenGotoxy(cobra[i].x, cobra[i].y);
        printf("@");
    }
    screenUpdate();
}

void mover_cobra(Posicao *cobra, int tamanho, int tecla){
    for (int i = tamanho-1; i > 0; i--){
        cobra[i] = cobra[i-1];
    }
    if (tecla == 119){
        cobra[0].y--;
    }
    else if (tecla == 115){
        cobra[0].y++;
    }
    else if (tecla == 97){
        cobra[0].x--;
    }
    else if(tecla == 100){
        cobra[0].x++;
    }
}


int main(){
    screenInit(0);
    keyboardInit();
    timerInit(200);
    cor_tela(BLACK);

    int tamanho = 5;
    int tecla = 0;
    Posicao *cobra = malloc(tamanho * sizeof(Posicao));
    for (int i = 0; i<tamanho;i++){
        cobra[i].x = 10-i;
        cobra[i].y = 10;
    }
    desenhar_cobra(cobra,tamanho);
    while (tecla != 10){
        if (keyhit()){
            tecla = readch();
        }
        if(timerTimeOver() && tecla != 0){
            limpar(cobra,tamanho);
            mover_cobra(cobra,tamanho,tecla);
            desenhar_cobra(cobra,tamanho);
        }
        
    }
    free(cobra);
    timerDestroy();
    keyboardDestroy();
    screenDestroy();

    return 0;
}

