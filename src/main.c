#include <stdio.h>
#include <stdlib.h>
#include "../biblioteca/screen.h"
#include "../biblioteca/keyboard.h"
#include "../biblioteca/timer.h"
#include "cobra.h"
#include "jogo.h"
#include "menu.h"
#include "utils.h"

int main(){
    screenInit(0);
    keyboardInit();
    pedir_nome();
    screenClear();
    cor_tela(BLACK);
   while(1) {
       int escolha_menu = menu();
       if (escolha_menu == 1) {
           jogar();
       }
       if (escolha_menu == 0) {
           break;
       }
   }
    keyboardDestroy();
    screenDestroy();
    return 0;
}


