  // ZBuffer
  // Autor: GZS

  #include <stdlib.h>
  #include <stdio.h>
  #include <allegro5/allegro.h>

  #include "jogo.h"
  #include "tanque.h"
  #include "bunker.h"
  #include "zbuffer.h"


  void inicializa_zbuffer( ZBuffer* z, ALLEGRO_DISPLAY *display,
			  int altura, int largura, Bunker b[], Tanque *t ) {
    z->display = display;
    z->buffer = al_create_bitmap( largura, altura );
    z->fundo  = al_load_bitmap("imagens/fundo.jpg");

    if( z->fundo == NULL ) {
      puts( "Erro ao carregar o arquivo imagens/fundo.jpg");
      exit(0);
    }
    
    z->bunker = b;
    z->tanque = t;         
    
    // z->aliens = a;
    // z->n_misseis = n_misseis;
    // z->missel = m; 
  }

  void finaliza_zbuffer( ZBuffer*z ) {
    al_destroy_bitmap( z->fundo );
    al_destroy_bitmap( z->buffer );
    
    al_destroy_display( z->display ); 
  }

  void processa_zbuffer( ZBuffer* z ) {
    al_set_target_bitmap( z->buffer );
    al_draw_bitmap( z->fundo, 0, 0, 0 );
  
    for( int i = 0; i < N_BUNKERS; i++ )
      processa_bunker( &z->bunker[i] );
    
    processa_tanque( z->tanque );

    al_set_target_backbuffer( z->display );
    al_draw_bitmap( z->buffer, 0, 0, 0 );
    al_flip_display(); 
  }

