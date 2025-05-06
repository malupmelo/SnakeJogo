#include "cobra.h"
#include "screen.h"

void limpar(Posicao *cobra, int tamanho){ 
    screenSetColor(WHITE,BLACK);
    screenGotoxy(cobra[tamanho-1].x, cobra[tamanho-1].y);
    printf(" ");
}

void desenhar_cobra(Posicao *cobra, int tamanho){
    screenSetColor(GREEN, BLUE);
    for (int i = 0; i < tamanho; i++ ){
        screenGotoxy(cobra[i].x, cobra[i].y);
        if (i == 0){
            printf("0");
        }
        else{
            printf("o");
        }
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