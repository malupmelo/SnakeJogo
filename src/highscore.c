#include <stdio.h>
#include <string.h>
#include "../biblioteca/screen.h"
#include "../biblioteca/keyboard.h"
#include  "../include/highscore.h"

#define MAX_HIGHSCORES 5
const char* nome_arquivo = "./highscores/highscores.txt";

void adicionar_pontuacao(char* nome, int pontuacao) {
    Jogador highscores[MAX_HIGHSCORES + 1];
    int total = 0;

    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo != NULL) {
        while (total < MAX_HIGHSCORES &&
               fscanf(arquivo, "%s %d", highscores[total].nome, &highscores[total].pontuacao) == 2) {
            total++;
        }
        fclose(arquivo);
    }

    strcpy(highscores[total].nome, nome);
    highscores[total].pontuacao = pontuacao;
    total++;

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (highscores[j].pontuacao < highscores[j + 1].pontuacao) {
                Jogador temp = highscores[j];
                highscores[j] = highscores[j + 1];
                highscores[j + 1] = temp;
            }
        }
    }

    arquivo = fopen(nome_arquivo, "w");
    if (arquivo != NULL) {
        int limite = (total < MAX_HIGHSCORES) ? total : MAX_HIGHSCORES;
        for (int i = 0; i < limite; i++) {
            fprintf(arquivo, "%s %d\n", highscores[i].nome, highscores[i].pontuacao);
        }
        fclose(arquivo);
    }
}

int checar_top5(int pontuacao_nova) {
    Jogador highscores[MAX_HIGHSCORES];
    int total = 0;

    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo != NULL) {
        while (total < MAX_HIGHSCORES &&
               fscanf(arquivo, "%s %d", highscores[total].nome, &highscores[total].pontuacao) == 2) {
            total++;
        }
        fclose(arquivo);
    }

    if (total < MAX_HIGHSCORES) {
        return 1;
    }

    int menor_pontuacao = highscores[0].pontuacao;
    for (int i = 1; i < total; i++) {
        if (highscores[i].pontuacao < menor_pontuacao) {
            menor_pontuacao = highscores[i].pontuacao;
        }
    }

    return pontuacao_nova > menor_pontuacao;
}

void tela_highscore() {
    Jogador highscores[MAX_HIGHSCORES];
    int total = 0;

    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo != NULL) {
        while (total < MAX_HIGHSCORES &&
               fscanf(arquivo, "%s %d", highscores[total].nome, &highscores[total].pontuacao) == 2) {
            total++;
        }
        fclose(arquivo);
    }

    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - i - 1; j++) {
            if (highscores[j].pontuacao < highscores[j + 1].pontuacao) {
                Jogador temp = highscores[j];
                highscores[j] = highscores[j + 1];
                highscores[j + 1] = temp;
            }
        }
    }

    screenSetColor(GREEN, BLACK);
    screenGotoxy(31, 2);
    printf("HIGHSCORE");

    for (int i = 0; i < total; i++) {
        screenGotoxy(31, 10 + i);
        printf("%d. %s  :  %d", i+1, highscores[i].nome, highscores[i].pontuacao);
    }

    screenUpdate();
    while (readch() != 10);
    screenClear();
}