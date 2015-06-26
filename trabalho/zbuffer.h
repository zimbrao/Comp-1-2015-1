// ZBuffer
// Autor: GZS

#ifndef ZBUFFER_H
#define ZBUFFER_H

struct ZBuffer {
  ALLEGRO_DISPLAY *display;
  ALLEGRO_BITMAP *buffer;

  ALLEGRO_BITMAP *fundo;  		// 0 Z-order
  Bunker* bunker; 		// 1
  Tanque* tanque;         		// 2
  // Alien* aliens[N_LINHAS_ALIENS][N_COLUNAS_ALIENS]; 	// 3
  int n_misseis;
  // Misseis *missel[N_MAX_MISSEIS];	// 4 
};

void inicializa_zbuffer( ZBuffer* z, ALLEGRO_DISPLAY *display,
			 int altura, int largura, Bunker b[N_BUNKERS], Tanque *t );

void finaliza_zbuffer( ZBuffer*z );

// Dá a cada objeto a sua chance de processamento, ou seja, "uma jogada".
void processa_zbuffer( ZBuffer* z );

#endif


