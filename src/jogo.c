#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/screen.h"
#include "../biblioteca/timer.h"
#include "../biblioteca/keyboard.h"
#include "jogo.h"
#include "cobra.h"
#include "menu.h"
#include "utils.h"
#include "highscore.h"

int jogar() {
    int velocidade = 150;
    timerInit(velocidade);

    cor_tela(BLACK);

    int tamanho = 1;
    int tecla = 0;
   
    Posicao *cobra = malloc(tamanho * sizeof(Posicao));
    Posicao comida;

    cobra[0].x = 40;
    cobra[0].y = 12;
    comida.x = rand() % (78 - 3 + 1) + 3;
    comida.y = rand() % (23 - 3 + 1) + 3;

    desenhar_cobra(cobra, tamanho);
    gerar_comida(comida.x, comida.y);

    while (1) {
        if (keyhit()) {
            int nova_tecla = readch();
            if (nova_tecla == 'w' || nova_tecla == 'a' || nova_tecla == 's' || nova_tecla == 'd') {
                tecla = nova_tecla;
            }
        }
        if (timerTimeOver() && tecla != 0) {
            mostrar_pontuacao(tamanho-1);
            if(pontuar(&comida, &tamanho, &cobra)) {
                if (velocidade > 20) {
                    velocidade -= 5;
                }
                timerUpdateTimer(velocidade);
            };
            limpar(cobra, tamanho);
            mover_cobra(cobra, tamanho, tecla);
            desenhar_cobra(cobra, tamanho);
            if (colisao(cobra, tamanho)) {
                break;
            }
        }
    }

    free(cobra);
    menu_final(tamanho);
    screenUpdate();
    while (readch() != 10); 
    cor_tela(BLACK);
    timerDestroy();
    return (tamanho - 1) * 10;
}

int jogar_reverso() {
    int velocidade = 150;
    timerInit(velocidade);

    cor_tela(BLACK);

    int tamanho = 3;
    int tecla = 100;

    Posicao *cobra = malloc(tamanho * sizeof(Posicao));
    Posicao comida;
    Posicao cauda_temp;

    cobra[0].x = 40;
    cobra[0].y = 12;
    cobra[1].x = 39;
    cobra[1].y = 12;
    cobra[2].x = 38;
    cobra[2].y = 12;

    comida.x = rand() % (75 - 5 + 1) + 5;
    comida.y = rand() % (20 - 5 + 1) + 5;

    desenhar_cobra(cobra, tamanho);
    gerar_comida(comida.x, comida.y);

    while (1) {
        if (keyhit()) {
            int nova_tecla = readch();
            if (nova_tecla == 'w' || nova_tecla == 'a' || nova_tecla == 's' || nova_tecla == 'd') {
                tecla = nova_tecla;
            }
        }

        if (timerTimeOver() && tecla != 0) {
            mostrar_pontuacao(tamanho-3);
            cauda_temp = cobra[tamanho-1];

            if (pontuar(&comida, &tamanho, &cobra)) {
                // Modo teletransporte: cobra se inverte
                limpar(cobra, tamanho);

                // Aumentar velocidade quando pontua
                if (velocidade > 20) {
                    velocidade -= 5;
                }
                timerUpdateTimer(velocidade);

                // Modo teletransporte: inverter a cobra (cabeça vira cauda)
                for (int i = tamanho-1; i > 0; i--) {
                    cobra[i] = cobra[i-1];
                }

                cobra[0] = cauda_temp;

                // Determinar nova direção baseada na nova posição da cabeça em relação ao corpo
                if (tamanho > 2) {
                    if (cauda_temp.x > cobra[1].x) tecla = 'd';
                    else if (cauda_temp.x < cobra[1].x) tecla = 'a';
                    else if (cauda_temp.y > cobra[1].y) tecla = 's';
                    else if (cauda_temp.y < cobra[1].y) tecla = 'w';
                }
            } else {
                // Movimento normal da cobra
                limpar(cobra, tamanho);
                mover_cobra(cobra, tamanho, tecla);
            }

            desenhar_cobra(cobra, tamanho);

            // Verificar colisão com as bordas
            if (cobra[0].x <= 1 || cobra[0].x >= 80 || cobra[0].y <= 1 || cobra[0].y >= 24) {
                break;
            }
        }
    }

    free(cobra);
    menu_final(tamanho);
    screenUpdate();
    while (readch() != 10);
    cor_tela(BLACK);
    timerDestroy();
    return (tamanho - 3) * 10;
}

void iniciar() {
    screenInit(0);
    keyboardInit();
    char* nome = pedir_nome();
    cor_tela(BLACK);

    while (1) {
        int escolha_menu = menu();

        if (escolha_menu == 1) {
            screenClear();
            int modo = menu_modos();

            if (modo == 1) {
                int pontuacao = jogar();
                adicionar_pontuacao(nome, pontuacao);
                tela_highscore();
                screenClear();
            }
            else if (modo == 2) {
                int pontuacao = jogar_reverso();
                adicionar_pontuacao(nome, pontuacao);
                tela_highscore();
                screenClear();
            }
        }

        if (escolha_menu == 0) {
            screenClear();
            tela_highscore();
        }
        if (escolha_menu == 2) {
            break;
        }
    }
    free(nome);
    keyboardDestroy();
    screenDestroy();
}
