#include <stdio.h>
#include "../biblioteca/screen.h"
#include "../biblioteca/keyboard.h"

const char* nome_arquivo = "./Documents/Codigos/Faculdade/2Periodo/PIF/projeto_snake/SnakeJogo/highscores/highscores.txt";

void adicionar_pontuacao(char* nome, int pontuacao) {
    FILE* arquivo = fopen(nome_arquivo, "a");
    fprintf(arquivo, "%s %d\n", nome, pontuacao);
    fclose(arquivo);
}

void tela_highscore() {
    FILE* arquivo = fopen(nome_arquivo, "r");
    char nome[15];
    int pontuacao;
    screenSetColor(GREEN,BLACK);
    screenGotoxy(31,2);
    printf("HIGHSCORE");
    int y = 10;
    while (fscanf(arquivo, "%s %d", nome, &pontuacao) == 2) {
        screenGotoxy(31, y);
        printf("%s  :  %d", nome, pontuacao);
        y++;
    }
    screenUpdate();
    while (readch() != 10);
    screenClear();
    fclose(arquivo);
}