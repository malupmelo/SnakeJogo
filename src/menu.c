#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "../biblioteca/screen.h"
#include "../biblioteca/keyboard.h"
#include "../include/utils.h"


int menu() {
    int tecla = 0;
    static int opcao = 0;
    screenGotoxy(8, 2);
    printf(" ________  ________   ________  ___  __    _______      ");
    screenGotoxy(8, 3);
    printf("|\\   ____\\|\\   ___  \\|\\   __  \\|\\  \\|\\  \\ |\\  ___ \\     ");
    screenGotoxy(8, 4);
    printf("\\ \\  \\___|\\ \\  \\\\ \\  \\ \\  \\|\\  \\ \\  \\/  /|\\ \\   __/|    ");
    screenGotoxy(8, 5);
    printf(" \\ \\_____  \\ \\  \\\\ \\  \\ \\   __  \\ \\   ___  \\ \\  \\_|/__  ");
    screenGotoxy(8, 6);
    printf("  \\|____|\\  \\ \\  \\\\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\_|\\ \\ ");
    screenGotoxy(8, 7);
    printf("    ____\\_\\  \\ \\__\\\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\");
    screenGotoxy(8, 8);
    printf("   |\\_________\\|__| \\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|");
    screenGotoxy(8, 9);
    printf("   \\|_________|                                         ");
    if (keyhit()) {
        tecla = readch();
    }
    if (opcao == 0 && tecla == 115) {
        opcao = 1;
    }
    else if (opcao == 1 && tecla == 119) {
        opcao = 0;
    }
    else if (opcao == 1 && tecla == 115) {
        opcao = 2;
    }
    else if (opcao == 2 && tecla == 119) {
        opcao = 1;
    }
    screenGotoxy(30,15);
    screenSetColor(GREEN, BLACK);
    printf(opcao == 0 ? "* START *" : "  START  ");
    screenGotoxy(30,17);
    printf(opcao == 1 ? "* HIGH SCORE *" : "  HIGH SCORE  ");
    screenGotoxy(30,19);
    printf(opcao == 2 ? "* SAIR *" : "  SAIR  ");
    if (opcao == 0 && tecla == 10) {
        return 1;
    }
    if (opcao == 1 && tecla == 10) {
        return 0;
    }
    if (opcao == 2 && tecla == 10 ) {
        return 2;
    }
    return 3;
}

int menu_modos() {
   
    int tecla = 0;
    static int opcao = 0;

    while (1) {
        screenGotoxy(30, 8);
        screenSetColor(GREEN, BLACK);
        printf("ESCOLHA O MODO DE JOGO:");

        screenGotoxy(30, 10);
        printf(opcao == 0 ? "* BÁSICO *"     : "  BÁSICO  ");

        screenGotoxy(30, 12);
        printf(opcao == 1 ? "* REVERSO *" : "  REVERSO  ");


        if (keyhit()) {
            tecla = readch();

            if (tecla == 'w' && opcao == 1) {
                opcao=0;
            } else if (tecla == 's' && opcao == 0) {
                opcao=1;
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
    char* nome =  malloc(15*sizeof(char));
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

void menu_final(int pontuacao) {
    cor_tela(BLACK);
    screenSetColor(GREEN, BLACK);
    screenGotoxy(32, 8);
    printf("GAME OVER");
    screenGotoxy(30, 13);
    printf("Pontuação: %d", (pontuacao - 1) * 10);
    screenGotoxy(22, 15);
    printf("Pressione ENTER para sair...");
}


