// O Jogo Space Invaders
// Autor: GZS

#ifndef JOGO_H
#define JOGO_H

#define FUNDO al_map_rgb(0, 0, 0)

#define N_BUNKERS 4

#include "bunker.h"
#include "tanque.h"
#include "zbuffer.h"


struct Jogo {
  int largura, altura; 
  Bunker bunker[N_BUNKERS];
  Tanque tanque;
  ZBuffer zbuffer;
  ALLEGRO_EVENT_QUEUE *fila_eventos;
};

void inicializa_jogo( Jogo* jogo, int x, int y, int largura, int altura );

void finaliza_jogo( Jogo* jogo );

void loop_eventos_jogo( Jogo* jogo );

#endif