#include <stdio.h>
#include "menu.h"
#include "../biblioteca/screen.h"
#include "../biblioteca/keyboard.h"
#include "util.h"
#include "../include/utils.h"

void mostrar_scores() {
    screenClear();
    screenSetColor(WHITE, BLACK);
    screenGotoxy(30, 10); printf("Pontuações anteriores:");
    screenGotoxy(30, 12); printf("1. JogadorA - 120 pontos");
    screenGotoxy(30, 13); printf("2. JogadorB - 90 pontos");
    screenGotoxy(30, 15); printf("Pressione ENTER para voltar...");
    screenUpdate();
    while (readch() != 10);
}

int menu_inicial() {
    int opcao = 0;
    int tecla = 0;

    while (1) {
        screenClear();

        screenGotoxy(30, 10);
        screenSetColor(opcao == 0 ? BLACK : WHITE, opcao == 0 ? WHITE : BLACK);
        printf("Start");

        screenGotoxy(30, 12);
        screenSetColor(opcao == 1 ? BLACK : WHITE, opcao == 1 ? WHITE : BLACK);
        printf("Scores anteriores");

        screenUpdate();
        if (keyhit()) {
            tecla = readch();
        }
        if (tecla == 'w' && opcao > 0) opcao--;
        else if (tecla == 's' && opcao < 1) opcao++;
        if (opcao == 0 && tecla == 10) {
            return 0;
        }
        else if (opcao == 1 && tecla == 10) {
            mostrar_scores();
            return 1;
        }
    }
}
int menu() {
    int tecla = 0;
    static int opcao = 0;
    if (keyhit()) {
        tecla = readch();
    }
    if (opcao == 0 && tecla == 115) {
        opcao = 1;
    }
    if (opcao == 1 && tecla == 119) {
        opcao = 0;
    }
    screenGotoxy(30,10);
    screenSetColor(GREEN, BLACK);
    printf(opcao == 0 ? "* START *" : "  START  ");
    screenGotoxy(30,12);
    printf(opcao == 1 ? "* SAIR *" : "  SAIR  ");
    if (opcao == 0 && tecla == 10) {
        return 1;
    }
    if (opcao == 1 && tecla == 10) {
        return 0;
    }
    return 2;
}


