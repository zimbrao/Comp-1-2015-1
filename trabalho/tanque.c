// O Tanque
// Autor: GZS

#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "tanque.h"

#define LARGURA_TANQUE 64
#define ALTURA_TANQUE  64

#define DELTA_X (-LARGURA_TANQUE/2)
#define DELTA_Y (-ALTURA_TANQUE)

void inicializa_tanque( Tanque* t, int x, int y ) {
  t->posicao_x = x;
  t->posicao_y = y;
  t->min_x = t->posicao_x + DELTA_X;
  t->max_x = t->posicao_x - DELTA_X;
  t->min_y = t->posicao_x + DELTA_Y;
  t->min_y = t->posicao_y;
  t->atual = 0;
  
  t->bitmap[0] = al_load_bitmap("imagens/tank_1.png");
  t->bitmap[1] = al_load_bitmap("imagens/tank_2.png");

  if( t->bitmap[0] == NULL || t->bitmap[1] == NULL ) {
    puts( "Erro ao carregar o arquivo imagens/tank.png");
    exit(0);
  }
}

void finaliza_tanque( Tanque* t ) {
  al_destroy_bitmap( t->bitmap[0] );
  al_destroy_bitmap( t->bitmap[1] );
}

void desenha_tanque( Tanque* t, DIRECAO direcao ) {
  int flags = 0;
  
  if( direcao == DIREITA )
    flags = ALLEGRO_FLIP_HORIZONTAL;
  
 al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_ALPHA); 
 al_draw_bitmap( t->bitmap[t->atual], 
		  t->posicao_x + DELTA_X, 
		  t->posicao_y + DELTA_Y, flags );
 al_set_blender(ALLEGRO_ADD, ALLEGRO_ONE, ALLEGRO_INVERSE_ALPHA); 
  
  t->atual = (t->atual + 1) % 2;
}

void move_tanque( Tanque* t, DIRECAO direcao, int delta_x, int delta_y ) {
  t->posicao_x += delta_x;
  t->posicao_y += delta_y;  
  t->direcao = direcao;
  t->min_x = t->posicao_x + DELTA_X;
  t->max_x = t->posicao_x - DELTA_X;
  t->min_y = t->posicao_x + DELTA_Y;
  t->min_y = t->posicao_y;
}

void processa_tanque( Tanque* tanque ) {
  desenha_tanque( tanque, tanque->direcao );
}