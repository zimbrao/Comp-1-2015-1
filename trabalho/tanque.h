// O Tanque
// Autor: GZS

#ifndef TANQUE_H
#define TANQUE_H

enum DIRECAO { ESQUERDA, DIREITA };

struct Tanque {
  int posicao_x, posicao_y;
  DIRECAO direcao;
  int min_x, max_x, min_y, max_y;
  int atual;
  ALLEGRO_BITMAP* bitmap[2];
};

void inicializa_tanque( Tanque* t, int x, int y );

void finaliza_tanque( Tanque* t );

void desenha_tanque( Tanque* t, DIRECAO direcao );

void move_tanque( Tanque* t, DIRECAO direcao, int delta_x, int delta_y );

void processa_tanque( Tanque* tanque );

#endif