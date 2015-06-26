// Jogo
// Autor: GZS
#include <stdlib.h>
#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "jogo.h"

void inicializa_jogo( Jogo* jogo, int x, int y, int largura, int altura ) {
   ALLEGRO_DISPLAY *display = NULL;

   al_set_new_window_position( x, y );
  
   if(!al_init()) {
      fprintf(stderr, "Falha ao inicializar o Allegro!\n");
      exit(-1);
   }
   
   if (!al_init_primitives_addon()) {
     fprintf(stderr, "Falha ao inicializar add-on de primitivas.\n");
     exit(-1);
   }
   
   if (!al_init_image_addon()) {
     fprintf(stderr, "Falha ao inicializar add-on de imagens.\n");
     exit(-1);
   }
   
   display = al_create_display( largura, altura );
   if(!display) {
      fprintf(stderr, "Falha ao criar o display!\n");
      exit(-1);
   }
   
   if (!al_install_keyboard())
    {
        fprintf(stderr, "Falha ao inicializar o teclado.\n");
        exit(-1);
    }
    
    jogo->fila_eventos = al_create_event_queue();
    if (!jogo->fila_eventos)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        exit(-1);
    }
   
   jogo->altura = altura;
   jogo->largura = largura;
      
   for( int i = 0, x = (jogo->largura / 4 - TAMANHO_BUNKER) / 2; 
        i < 4; 
        i++, x += jogo->largura / 4 ) {
     inicializa_bunker( &jogo->bunker[i], x, 360 );
   } 
   
   inicializa_tanque( &jogo->tanque, jogo->largura/2, 475 );

   inicializa_zbuffer( &jogo->zbuffer, display, jogo->altura, jogo->largura, 
                       jogo->bunker, &jogo->tanque );

  al_register_event_source(jogo->fila_eventos, al_get_keyboard_event_source());
}

void finaliza_jogo( Jogo* jogo ) {
  al_destroy_event_queue(jogo->fila_eventos);

  finaliza_zbuffer( &jogo->zbuffer );  
  finaliza_tanque( &jogo->tanque );

  for( int i = 0; i < 4; i++ )
    finaliza_bunker( &jogo->bunker[i] );  
}

void desenha_jogo( Jogo* jogo ) {
   processa_zbuffer( &jogo->zbuffer );  
}

void move_tanque_jogo( Jogo* jogo, DIRECAO direcao ) {
  switch( direcao ) {
    case ESQUERDA :
      if( jogo->tanque.min_x > 0 ) {
        move_tanque( &jogo->tanque, direcao, -2, 0 );
      }  
      break;

    case DIREITA :
      if( jogo->tanque.max_x < 639 ) {
        move_tanque( &jogo->tanque, direcao, 2, 0 );
      }
      break;
  }
}

void loop_eventos_jogo( Jogo* jogo ) {
   bool sair = false;
   
    while( !sair ) {
      if( !al_is_event_queue_empty(jogo->fila_eventos) ) {
	ALLEGRO_EVENT evento;
        al_wait_for_event( jogo->fila_eventos, &evento );
	
	if( evento.type == ALLEGRO_EVENT_KEY_CHAR )
          switch( evento.keyboard.keycode ) {
            case ALLEGRO_KEY_LEFT:
              move_tanque_jogo( jogo, ESQUERDA );
              break;
            
	    case ALLEGRO_KEY_RIGHT:
              move_tanque_jogo( jogo, DIREITA );
              break;
            
	    case ALLEGRO_KEY_X:
	      sair = true;  
	      break;
          }
      }
      
      desenha_jogo( jogo );
    }
}


























