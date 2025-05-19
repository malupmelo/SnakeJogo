#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/screen.h"
#include "../biblioteca/keyboard.h"
#include "../biblioteca/timer.h"
#include "cobra.h"
#include "jogo.h"
#include "menu.h"
#include "utils.h"
#include "highscore.h"

int main() {
    screenInit(0);
    keyboardInit();
    char* nome = pedir_nome();
    screenClear();
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
                
            }
            else if (modo == 3) {
                
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
    return 0;
}

//comidas especiais:
//dobro da velocidade por um tempo; dobro dos pontos por um tempo; diminuir a cobra
//modo teletransporte: cobra come e cabeça vai para onde o rabo estava

