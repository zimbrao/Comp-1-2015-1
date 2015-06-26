// O Bunker
// Autor: GZS

#ifndef BUNKER_H
#define BUNKER_H

#define TAMANHO_BUNKER (8*10)
#define COR_BUNKER al_map_rgb(0, 255, 0)

enum EstadoBunker { INTEIRO, AVARIADO, DESTRUIDO };
enum LegoBunker { VAZIO, QUADRADO, 
                  SUPERIOR_ESQUERDO, SUPERIOR_DIREITO, 
		  INFERIOR_ESQUERDO, INFERIOR_DIREITO };

struct Bunker {
  int posicao_x, posicao_y;
  LegoBunker desenho[8][4];
  EstadoBunker pedaco[8][4];
};

void inicializa_bunker( Bunker *bunker, int posicao_x, int posicao_y );

void finaliza_bunker( Bunker *bunker );

void desenha_bunker( Bunker* bunker );

void processa_bunker( Bunker* bunker );

#endif
