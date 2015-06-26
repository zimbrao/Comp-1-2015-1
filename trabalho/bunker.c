// Bunker
// Autor: GZS

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "jogo.h"
#include "bunker.h"

void inicializa_bunker( Bunker *bunker, int posicao_x, int posicao_y ) {
  bunker->posicao_x = posicao_x;
  bunker->posicao_y = posicao_y;
  
  for( int i = 0; i < 8; i++ ) 
    for( int j = 0; j < 4; j++ ) {
      bunker->pedaco[i][j] = INTEIRO;
      bunker->desenho[i][j] = QUADRADO;
    }
       
  bunker->desenho[0][0] = INFERIOR_DIREITO;    
  bunker->desenho[7][0] = INFERIOR_ESQUERDO;    
  bunker->desenho[2][2] = SUPERIOR_ESQUERDO;    
  bunker->desenho[5][2] = SUPERIOR_DIREITO;    
  bunker->desenho[2][3] = VAZIO;    
  bunker->desenho[3][3] = VAZIO;    
  bunker->desenho[3][2] = VAZIO;    
  bunker->desenho[4][3] = VAZIO;    
  bunker->desenho[4][2] = VAZIO;    
  bunker->desenho[5][3] = VAZIO;     
}  

void finaliza_bunker( Bunker *bunker ) {
}

void desenha_pedaco_bunker( int x, int y, LegoBunker lego, EstadoBunker estado ) {	     
  switch( lego ) {
    
    case VAZIO:
         break;
    
    case QUADRADO:
           al_draw_filled_rectangle( x, y, x + TAMANHO_BUNKER / 8, 
				     y + TAMANHO_BUNKER / 8, COR_BUNKER );
         break;
    
    case INFERIOR_DIREITO:
           al_draw_filled_triangle( x + TAMANHO_BUNKER / 8, y + TAMANHO_BUNKER / 8,
				    x, y + TAMANHO_BUNKER / 8,
				    x + TAMANHO_BUNKER / 8, y, COR_BUNKER );
         break;

    case INFERIOR_ESQUERDO:
           al_draw_filled_triangle( x + TAMANHO_BUNKER / 8, y + TAMANHO_BUNKER / 8,
				    x, y + TAMANHO_BUNKER / 8,
				    x, y, COR_BUNKER );
         break;
    
    case SUPERIOR_ESQUERDO:
           al_draw_filled_triangle( x + TAMANHO_BUNKER / 8, y,
				    x, y + TAMANHO_BUNKER / 8,
				    x, y, COR_BUNKER );
         break;
    
    case SUPERIOR_DIREITO:
           al_draw_filled_triangle( x + TAMANHO_BUNKER / 8, y + TAMANHO_BUNKER / 8,
				    x + TAMANHO_BUNKER / 8, y,
				    x, y, COR_BUNKER );
         break;
    
  }
}
  
void desenha_bunker( Bunker* bunker ) {
  for( int i = 0, x = bunker->posicao_x; 
       i < 8; 
       i++, x += TAMANHO_BUNKER / 8 )
    for( int j = 0, y = bunker->posicao_y; 
         j < 4; 
         j++, y += TAMANHO_BUNKER / 8 ) {
             
      desenha_pedaco_bunker( x, y, bunker->desenho[i][j], bunker->pedaco[i][j] );     
    }
}

void processa_bunker( Bunker *bunker ) {
  desenha_bunker( bunker );
}
