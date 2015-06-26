// O Tanque
// Autor: GZS

#ifndef TANQUE_H
#define TANQUE_H

enum COMANDO { ESQUERDA = -1, DIREITA = 1, PARAR = 0 };

struct Tanque {
  int posicao_x, posicao_y;
  COMANDO direcao;
  COMANDO direcao_imagem;
  int v_x;
  int min_x, max_x, min_y, max_y;
  int atual;
  int limite_inferior;
  int limite_superior;
  ALLEGRO_BITMAP* bitmap[2];
};

void inicializa_tanque( Tanque* t, int x, int y, 
			int limite_inferior, int limite_superior );

void finaliza_tanque( Tanque* t );

void desenha_tanque( Tanque* t, COMANDO direcao );

void move_tanque( Tanque* t, COMANDO direcao );

void processa_tanque( Tanque* tanque );

#endif