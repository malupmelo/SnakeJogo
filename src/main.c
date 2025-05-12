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

int main(){
    screenInit(0);
    keyboardInit();
    char* nome = pedir_nome();
    screenClear();
    cor_tela(BLACK);
   while(1) {
       int escolha_menu = menu();
       if (escolha_menu == 1) {
           int pontuacao = jogar();
           adicionar_pontuacao(nome, pontuacao);
           tela_highscore();
       }
       if (escolha_menu == 0) {
           break;
       }
   }
    keyboardDestroy();
    screenDestroy();
    return 0;
}


