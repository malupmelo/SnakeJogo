#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#define MAX_HIGHSCORES 5

struct Jogador {
    char nome[15];
    int pontuacao;
} typedef Jogador;

void adicionar_pontuacao(char* nome, int pontuacao);
void tela_highscore();
int checar_top5(int pontuacao_nova);
void ler_highscores(Jogador jogador[]);

#endif