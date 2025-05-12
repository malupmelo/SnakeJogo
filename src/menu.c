#include <stdio.h>
#include "menu.h"
#include "../biblioteca/screen.h"
#include "../biblioteca/keyboard.h"
#include "util.h"
#include "../include/utils.h"




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
    printf(opcao == 1 ? "* HIGH SCORE *" : "  HIGH SCORE  ");
    if (opcao == 0 && tecla == 10) {
        return 1;
    }
    if (opcao == 1 && tecla == 10) {
        return 0;
    }
    return 2;
}


#include "menu.h"

int menu_modos() {
   
    int tecla = 0;
    static int opcao = 0;

    while (1) {
        screenClear();

        screenGotoxy(30, 8);
        screenSetColor(GREEN, BLACK);
        printf("ESCOLHA O MODO DE JOGO:");

        screenGotoxy(30, 10);
        printf(opcao == 0 ? "* BÁSICO *"     : "  BÁSICO  ");

        screenGotoxy(30, 12);
        printf(opcao == 1 ? "* OBSTÁCULOS *" : "  OBSTÁCULOS  ");

        screenGotoxy(30, 14);
        printf(opcao == 2 ? "* DIFÍCIL *"    : "  DIFÍCIL  ");

        if (keyhit()) {
            tecla = readch();

            if (tecla == 'w' && opcao > 0) { 
                opcao--;
            } else if (tecla == 's' && opcao < 2) { 
                opcao++;
            } else if (tecla == 10) { 
                return opcao + 1; 
            }
        }
    }
}

char* pedir_nome() {
    cor_tela(BLACK);
    int letra = 0;
    int tecla = 0;
    char nome[15];
    screenSetColor(GREEN,BLACK);
    screenGotoxy(30,10);
    printf("Digite seu nome: ");
    int x = 47;
    screenUpdate();
    while (1) {
        if (keyhit()) {
            tecla = readch();
            if (tecla == 10) {
                break;
            }
            if (tecla >= 65 && tecla <= 122) {
                nome[letra] = (char)tecla;
                screenGotoxy(x,10);
                printf("%c", nome[letra]);
                letra++;
                x++;
                screenUpdate();
            }
        }
    }
    nome[letra] = '\0';
    return nome;
}


