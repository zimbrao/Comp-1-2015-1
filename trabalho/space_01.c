#include <stdio.h>
#include <allegro5/allegro.h>

#include "jogo.h"
#include "bunker.h"
#include "tanque.h"

int main(int argc, char **argv){
   Jogo jogo;
   
   inicializa_jogo( &jogo, 160, 0, 640, 480 );

   loop_eventos_jogo( &jogo );
   
   finaliza_jogo( &jogo );
   
   return 0;
}










