#include <iostream>
#include <string>
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <Windows.h>
int main()
{
	if (!al_init())
	{
		al_show_native_message_box(NULL, "ERROR CRITICO", "ERROR 404", "No se pudo abrir allegro", NULL, ALLEGRO_MESSAGEBOX_QUESTION);
	}

	al_init_font_addon();
	al_init_ttf_addon();


	int ancho = GetSystemMetrics(SM_CXSCREEN);
	int alto = GetSystemMetrics(SM_CYSCREEN);


	
	ALLEGRO_DISPLAY* ventana = al_create_display(800, 600);
	ALLEGRO_FONT* cookie = al_load_font("Tough Cookie Three.otf",70,0);
	
	al_set_window_title(ventana,"Mi primer juego - Allegro :)");
	al_set_window_position(ventana, ancho/2 -400, alto/2 -300);

	ALLEGRO_TIMER *segundoTimer = al_create_timer(1.0);
	ALLEGRO_EVENT evento;
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

	al_register_event_source(queue, al_get_timer_event_source(segundoTimer));
	al_start_timer(segundoTimer);

	//al_show_native_message_box(NULL, "ERROR CRITICO", "ERROR 404", "HOLA SI ME ABRI UWU", NULL, ALLEGRO_MESSAGEBOX_OK_CANCEL);
	
	int segundo = 0;
	while (true)
	{
		al_wait_for_event(queue, &evento);
		if (evento.type == ALLEGRO_EVENT_TIMER)
		{
			if (evento.timer.source == segundoTimer)
			{
				segundo++;
			}
		}
		al_clear_to_color(al_map_rgb(segundo * 10 % 255, segundo * 3 % 255, segundo * 7 % 255));
		al_draw_text(cookie, al_map_rgb(255, 255, 255), 200, 200, NULL, ("Segundo: " + std::to_string(segundo)).c_str());
		
		al_flip_display();
	}
	return 0;
}