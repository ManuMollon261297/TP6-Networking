#include "Output.h"

//Animaciones
#define CAT_RUNNING 'A'
#define EXPLOSION1 'B'
#define EXPLOSION2 'C'
#define HOMER_DANCE 'D'
#define SUPER_MARIO 'E' 
#define SONIC 'F'

//Offsets
#define CAT_OFFSET 2
#define HOMER_OFFSET 100
#define MARIO_OFFSET 2
#define SONIC_OFFSET 17.5

//Periodos
#define CAT_PERIOD 0.1
#define HOMER_PERIOD 0.1
#define MARIO_PERIOD 0.04
#define SONIC_PERIOD 0.06
#define EXP1_PERIOD 0.12
#define EXP2_PERIOD 0.1

//Paths de las imagenes
#define BACKGROUND_PATH "../Images/background.png"
#define POSY 600

//Homer
#define H_F1 "../Images/Homer Dance/homerdance-F1.png"
#define H_F2 "../Images/Homer Dance/homerdance-F2.png"
#define H_F3 "../Images/Homer Dance/homerdance-F3.png"
#define H_F4 "../Images/Homer Dance/homerdance-F4.png"
#define H_F5 "../Images/Homer Dance/homerdance-F5.png"
#define H_F6 "../Images/Homer Dance/homerdance-F6.png"
#define H_F7 "../Images/Homer Dance/homerdance-F7.png"
#define H_F8 "../Images/Homer Dance/homerdance-F8.png"
#define H_F9 "../Images/Homer Dance/homerdance-F9.png"
#define H_F10 "../Images/Homer Dance/homerdance-F10.png"

#define HOMER_W 150
#define HOMER_H 150
//Cat

#define C_F1 "../Images/Cat Running/Cat Running-F1.png"
#define C_F2 "../Images/Cat Running/Cat Running-F2.png"
#define C_F3 "../Images/Cat Running/Cat Running-F3.png"
#define C_F4 "../Images/Cat Running/Cat Running-F4.png"
#define C_F5 "../Images/Cat Running/Cat Running-F5.png"
#define C_F6 "../Images/Cat Running/Cat Running-F6.png"
#define C_F7 "../Images/Cat Running/Cat Running-F7.png"
#define C_F8 "../Images/Cat Running/Cat Running-F8.png"
#define C_F9 "../Images/Cat Running/Cat Running-F9.png"
#define C_F10 "../Images/Cat Running/Cat Running-F10.png"
#define C_F11 "../Images/Cat Running/Cat Running-F11.png"
#define C_F12 "../Images/Cat Running/Cat Running-F12.png"

#define CAT_W 150
#define CAT_H 150

//Explosion1
#define E1_F1 "../Images/Explosion 1/Explosion 1-F1.png"
#define E1_F2 "../Images/Explosion 1/Explosion 1-F2.png"
#define E1_F3 "../Images/Explosion 1/Explosion 1-F3.png"
#define E1_F4 "../Images/Explosion 1/Explosion 1-F4.png"
#define E1_F5 "../Images/Explosion 1/Explosion 1-F5.png"
#define E1_F6 "../Images/Explosion 1/Explosion 1-F6.png"
#define E1_F7 "../Images/Explosion 1/Explosion 1-F7.png"
#define E1_F8 "../Images/Explosion 1/Explosion 1-F8.png"


//Explsion2
#define E2_F1 "../Images/Explosion 2/Explosion 2-F1.png"
#define E2_F2 "../Images/Explosion 2/Explosion 2-F2.png"
#define E2_F3 "../Images/Explosion 2/Explosion 2-F3.png"
#define E2_F4 "../Images/Explosion 2/Explosion 2-F4.png"
#define E2_F5 "../Images/Explosion 2/Explosion 2-F5.png"
#define E2_F6 "../Images/Explosion 2/Explosion 2-F6.png"
#define E2_F7 "../Images/Explosion 2/Explosion 2-F7.png"
#define E2_F8 "../Images/Explosion 2/Explosion 2-F8.png"
#define E2_F9 "../Images/Explosion 2/Explosion 2-F9.png"
#define E2_F10 "../Images/Explosion 2/Explosion 2-F10.png"
#define E2_F11 "../Images/Explosion 2/Explosion 2-F11.png"
#define E2_F12 "../Images/Explosion 2/Explosion 2-F12.png"
#define E2_F13 "../Images/Explosion 2/Explosion 2-F13.png"
#define E2_F14 "../Images/Explosion 2/Explosion 2-F14.png"
#define E2_F15 "../Images/Explosion 2/Explosion 2-F15.png"
#define E2_F16 "../Images/Explosion 2/Explosion 2-F16.png"
#define E2_F17 "../Images/Explosion 2/Explosion 2-F17.png"
#define E2_F18 "../Images/Explosion 2/Explosion 2-F18.png"
#define E2_F19 "../Images/Explosion 2/Explosion 2-F19.png"
#define E2_F20 "../Images/Explosion 2/Explosion 2-F20.png"
#define E2_F21 "../Images/Explosion 2/Explosion 2-F21.png"
#define E2_F22 "../Images/Explosion 2/Explosion 2-F22.png"
#define E2_F23 "../Images/Explosion 2/Explosion 2-F23.png"
#define E2_F24 "../Images/Explosion 2/Explosion 2-F24.png"
#define E2_F25 "../Images/Explosion 2/Explosion 2-F25.png"
#define E2_F26 "../Images/Explosion 2/Explosion 2-F26.png"
#define E2_F27 "../Images/Explosion 2/Explosion 2-F27.png"
#define E2_F28 "../Images/Explosion 2/Explosion 2-F28.png"
#define E2_F29 "../Images/Explosion 2/Explosion 2-F29.png"
#define E2_F30 "../Images/Explosion 2/Explosion 2-F30.png"
#define E2_F31 "../Images/Explosion 2/Explosion 2-F31.png"
#define E2_F32 "../Images/Explosion 2/Explosion 2-F32.png"
#define E2_F33 "../Images/Explosion 2/Explosion 2-F33.png"
#define E2_F34 "../Images/Explosion 2/Explosion 2-F34.png"
#define E2_F35 "../Images/Explosion 2/Explosion 2-F35.png"
#define E2_F36 "../Images/Explosion 2/Explosion 2-F36.png"
#define E2_F37 "../Images/Explosion 2/Explosion 2-F37.png"
#define E2_F38 "../Images/Explosion 2/Explosion 2-F38.png"
#define E2_F39 "../Images/Explosion 2/Explosion 2-F39.png"
#define E2_F40 "../Images/Explosion 2/Explosion 2-F40.png"
#define E2_F41 "../Images/Explosion 2/Explosion 2-F41.png"
#define E2_F42 "../Images/Explosion 2/Explosion 2-F42.png"
#define E2_F43 "../Images/Explosion 2/Explosion 2-F43.png"
#define E2_F44 "../Images/Explosion 2/Explosion 2-F44.png"
#define E2_F45 "../Images/Explosion 2/Explosion 2-F45.png"
#define E2_F46 "../Images/Explosion 2/Explosion 2-F46.png"
#define E2_F47 "../Images/Explosion 2/Explosion 2-F47.png"
#define E2_F48 "../Images/Explosion 2/Explosion 2-F48.png"

//Sonic
#define S_F1 "../Images/Sonic/Sonic Running-F1.png"
#define S_F2 "../Images/Sonic/Sonic Running-F2.png"
#define S_F3 "../Images/Sonic/Sonic Running-F3.png"
#define S_F4 "../Images/Sonic/Sonic Running-F4.png"
#define S_F5 "../Images/Sonic/Sonic Running-F5.png"
#define S_F6 "../Images/Sonic/Sonic Running-F6.png"
#define S_F7 "../Images/Sonic/Sonic Running-F7.png"
#define S_F8 "../Images/Sonic/Sonic Running-F8.png"
#define S_F9 "../Images/Sonic/Sonic Running-F9.png"
#define S_F10 "../Images/Sonic/Sonic Running-F10.png"

#define SONIC_W 210
#define SONIC_H 180

//Mario
#define M_F1 "../Images/Super Mario/Super Mario Running-F1.png"
#define M_F2 "../Images/Super Mario/Super Mario Running-F2.png"
#define M_F3 "../Images/Super Mario/Super Mario Running-F3.png"
#define M_F4 "../Images/Super Mario/Super Mario Running-F4.png"
#define M_F5 "../Images/Super Mario/Super Mario Running-F5.png"
#define M_F6 "../Images/Super Mario/Super Mario Running-F6.png"
#define M_F7 "../Images/Super Mario/Super Mario Running-F7.png"
#define M_F8 "../Images/Super Mario/Super Mario Running-F8.png"
#define M_F9 "../Images/Super Mario/Super Mario Running-F9.png"
#define M_F10 "../Images/Super Mario/Super Mario Running-F10.png"
#define M_F11 "../Images/Super Mario/Super Mario Running-F11.png"
#define M_F12 "../Images/Super Mario/Super Mario Running-F12.png"

#define MARIO_W 150
#define MARIO_H 150

bool InitializeAllegroOutput(void);
//Inicializa los  addons necesarios de allegro para
//utilizar el modulo de output.


void destruir_canciones(ALLEGRO_SAMPLE**, int);
//Funcion que libera el espacio de todas la canciones cargadas.
//recibe un puntero al arreglo de dichas canciones y el numero de las mismas.


ALLEGRO_BITMAP * load_image_at_size(char* image_name, int size_x, int size_y);
//Devuelve el bitmap de la imagen cargada en el tamano deseado.
//En caso de error devuelve NULL.

void destroy_images(ALLEGRO_BITMAP  **imagen, unsigned int num_imagenes);
//Libera toda la memoria utilizada por las imagenes creadas.


viewer::viewer(unsigned int width_, unsigned int height_)
{
	height = height_;
	width = width_;
	//Arreglos con los paths.
	char* homer_path[HOMER_FRAMES] = { H_F1, H_F2, H_F3, H_F4, H_F5, H_F6, H_F7, H_F8, H_F9, H_F10};
	char* cat_path[CAT_FRAMES] = {C_F1, C_F2,C_F3, C_F4, C_F5, C_F6, C_F7,C_F8, C_F9, C_F10, C_F11,C_F12};
	char* exp1_path[EXPLOSION1_FRAMES] = { E1_F1, E1_F2, E1_F3, E1_F4, E1_F5, E1_F6, E1_F7, E1_F8}; 
	char* exp2_path[EXPLOSION2_FRAMES] = { E2_F1, E2_F2, E2_F3, E2_F4, E2_F5, E2_F6, E2_F7, E2_F8, E2_F9, E2_F10, E2_F11, E2_F12,
											E2_F13, E2_F14, E2_F15, E2_F16 , E2_F17, E2_F18, E2_F19, E2_F20, E2_F21, E2_F22,
											E2_F23, E2_F24, E2_F25, E2_F26, E2_F27, E2_F28, E2_F29, E2_F30 , E2_F31, E2_F32, E2_F33,
											E2_F34, E2_F35, E2_F36, E2_F37 , E2_F38, E2_F39, E2_F40, E2_F41, E2_F42, E2_F43, E2_F44,
											E2_F45, E2_F46, E2_F47, E2_F48};
	char* mario_path[MARIO_FRAMES] = { M_F1, M_F2, M_F3, M_F4, M_F5, M_F6, M_F7, M_F8, M_F9, M_F10, M_F11, M_F12 };
	char* sonic_path[MARIO_FRAMES] = { S_F1, S_F2, S_F3, S_F4, S_F5, S_F6, S_F7, S_F8, S_F9, S_F10};

	init = InitializeAllegroOutput();
	if (init)
	{
		init = InitializeResources(homer_path, cat_path, exp1_path, exp2_path, mario_path, sonic_path);
	}

}

viewer:: ~viewer()
{
	if (init)
	{
		al_stop_samples();
		al_destroy_bitmap(background);
		destroy_images(homer_dance, HOMER_FRAMES);
		destroy_images(cat_running, CAT_FRAMES);
		destroy_images(explosion1, EXPLOSION1_FRAMES);
		destroy_images(explosion2, EXPLOSION2_FRAMES);
		destroy_images(super_mario, MARIO_FRAMES);
		destroy_images(sonic, SONIC_FRAMES);
		destruir_canciones(&music, NUMBER_OF_SAMPLES);
		al_destroy_display(display);

	}
}

bool viewer::IsInitOK(void)
{
	return init;
}

void viewer:: RunAnimation(char anim)
{
	al_set_target_backbuffer(display);
	switch (anim)
	{
		case CAT_RUNNING:
			UpdateAnimation(CAT_OFFSET, cat_running, CAT_FRAMES, CAT_PERIOD);
			break;

		case EXPLOSION1:
			for (int i = 0; i<EXPLOSION1_FRAMES; i++)
			{
				al_clear_to_color(al_color_name("black"));
				al_draw_bitmap(explosion1[i], 0, 0, 0);
				al_flip_display();
				al_rest(EXP1_PERIOD);
			}
			break;

		case EXPLOSION2:
			for (int i = 0; i<EXPLOSION2_FRAMES; i++)
			{
				al_clear_to_color(al_color_name("black"));
				al_draw_bitmap(explosion2[i], 0, 0, 0);
				al_flip_display();
				al_rest(EXP2_PERIOD);
			}
			break;

		case HOMER_DANCE:
			UpdateAnimation(HOMER_OFFSET, homer_dance, HOMER_FRAMES, HOMER_PERIOD);
			break;

		case SUPER_MARIO:
			UpdateAnimation(MARIO_OFFSET, super_mario, MARIO_FRAMES, MARIO_PERIOD);
			break;

		case SONIC:
			UpdateAnimation(SONIC_OFFSET, sonic, SONIC_FRAMES, SONIC_PERIOD);
			break;
	}
}


/*
void viewer::UpdateDisplay(Worm* worms, unsigned int worm_count)
{
	ALLEGRO_BITMAP* current_target = al_get_target_bitmap(); //guarda el target actual para no perderlo.

	al_set_target_backbuffer(display);
	al_clear_to_color(al_color_name("black"));
	al_draw_bitmap(landscape, 0, 0, 0);
	al_draw_bitmap(background, 0, 0, 0);

	//al_flip_display();
	int state = 0;
	int facing = 0; //Sentido en el que mira el gusano.
	int jump_stage = 0;
	int walk_stage = 0;
	int period = 0;
	int secuence = 0; //indica en que frame de la accion se encuentra el worm
	for (unsigned int i = 0; i < worm_count; i++)
	{
		state = ((worms + i)->get_state());
		facing = ((worms + i)->get_sentido());
		switch (state)
		{
		case MOVING:
		case END_MOVEMENT:
			walk_stage = (worms + i)->get_move_stage_animation();
			walk_stage %= 50;

			if (walk_stage == 1)
			{
				(graph_pos[i]).x = ((worms + i)->get_position()).x;
				(graph_pos[i]).y = ((worms + i)->get_position()).y;
			}

			if (walk_stage <= 0)
			{
				walk_stage = 1;
				(graph_pos[i]).x = ((worms + i)->get_position()).x;
				(graph_pos[i]).y = ((worms + i)->get_position()).y;
			}
			if (walk_stage <= WARM_UP)
			{
				PrintMove(worms[i], walk_stage - 1, facing, i);
			}
			else
			{
				walk_stage -= WARM_UP;
				if (((walk_stage % WALK_CYCLE) == 0))
				{
					if (facing == RIGHT)
					{
						(graph_pos[i]).x += 3.4;
					}
					else
					{
						(graph_pos[i]).x -= 3.4;
					}

					PrintMove(worms[i], IDLE_FRAME, facing, i);
				}
				else
				{
					PrintMove(worms[i], IDLE_FRAME + (walk_stage%WALK_CYCLE) - 1, facing, i);
				}
			}
			break;

		case JUMPING:
			jump_stage = (worms + i)->get_jump_stage_animation();
			period = (worms + i)->get_jump_period();


			if (jump_stage <= 0)
			{
				jump_stage = 1;
			}
			if (jump_stage <= WARM_UP)
			{

				PrintJump(worms[i], jump_stage - 1, facing);
			}

			jump_stage %= period;

			if ((jump_stage >= (period - 6))) //unwind del salto
			{
				PrintJump(worms[i], IDLE_FRAME + UNWIND_FRAMES - (period - jump_stage), facing);
			}
			else
			{
				PrintJump(worms[i], IDLE_FRAME, facing);
			}
			break;

		case MONITOR_MOVING:
		case MONITOR_JUMPING:
		case IDLE:
		default: //En caso de recibir algun state desconocido lo trata com si fuera IDLE.
			PrintPos(worms[i], facing);
			break;

		}
	}

	al_set_target_bitmap(current_target);
}
*/

bool InitializeAllegroOutput(void)
{
	if (!al_init_image_addon())
	{
		return false;
	}
	if (!al_install_audio())
	{
		return false;
	}
	if (!al_init_acodec_addon())
	{
		return false;
	}
	if (!al_reserve_samples(NUMBER_OF_SAMPLES))
	{
		return false;
	}

	return true;
}
ALLEGRO_DISPLAY* viewer::GetDisplay(void)
{
	return display;
}

bool viewer::InitializeResources(char** homer, char** cat, char** exp1, char** exp2, char** mario, char** sonic_)
{

	if (!LoadSong(MUSIC_PATH, NUMBER_OF_SAMPLES))
	{
		return false;
	}

	display = al_create_display(width*(UNIT), height*(UNIT));
	al_play_sample(music, VOLUME, 0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	if (display == NULL)
	{
		al_stop_samples();
		destruir_canciones(&music, NUMBER_OF_SAMPLES);
		return false;
	}


	background = load_image_at_size(BACKGROUND_PATH, width*(UNIT), height*(UNIT)); //crea el bitmap con el background
	if (background == nullptr)
	{
		al_stop_samples();
		destruir_canciones(&music, NUMBER_OF_SAMPLES);
		al_destroy_display(display);
		return false;
	}

	
	for (unsigned int i = 0; i < HOMER_FRAMES; i++) //Crea los bitmaps con los frames del homer dancing.
	{
		homer_dance[i] = load_image_at_size(homer[i], HOMER_W, HOMER_H);
		if ((homer_dance[i]) == nullptr)
		{
			al_stop_samples();
			destruir_canciones(&music, NUMBER_OF_SAMPLES);
			al_destroy_display(display);
			al_destroy_bitmap(background);
			destroy_images(homer_dance, i);
			return false;
		}
	}

	for (unsigned int i = 0; i < CAT_FRAMES; i++) //Crea los bitmaps con los frames del cat running.
	{
		cat_running[i] = load_image_at_size(cat[i], CAT_W, CAT_H);
		if ((cat_running[i]) == nullptr)
		{
			al_stop_samples();
			destruir_canciones(&music, NUMBER_OF_SAMPLES);
			al_destroy_display(display);
			al_destroy_bitmap(background);
			destroy_images(homer_dance, HOMER_FRAMES);
			destroy_images(cat_running, i);
			return false;
		}
	}
	for (unsigned int i = 0; i < EXPLOSION1_FRAMES; i++) //Crea los bitmaps con los frames de explosion1.
	{
		explosion1[i] = load_image_at_size(exp1[i], width, height);
		if ((explosion1[i]) == nullptr)
		{
			al_stop_samples();
			destruir_canciones(&music, NUMBER_OF_SAMPLES);
			al_destroy_display(display);
			al_destroy_bitmap(background);
			destroy_images(homer_dance, HOMER_FRAMES);
			destroy_images(cat_running, CAT_FRAMES);
			destroy_images(explosion1, i);
			return false;
		}
	}
	for (unsigned int i = 0; i < EXPLOSION2_FRAMES; i++) //Crea los bitmaps con los frames de explosion 2.
	{
		explosion2[i] = load_image_at_size(exp2[i], width, height);
		if ((explosion2[i]) == nullptr)
		{
			al_stop_samples();
			destruir_canciones(&music, NUMBER_OF_SAMPLES);
			al_destroy_display(display);
			al_destroy_bitmap(background);
			destroy_images(homer_dance, HOMER_FRAMES);
			destroy_images(cat_running, CAT_FRAMES);
			destroy_images(explosion1, EXPLOSION1_FRAMES);
			destroy_images(explosion2, i);
			return false;
		}
	}
	
	for (unsigned int i = 0; i < MARIO_FRAMES; i++) //Crea los bitmaps con los frames de mario running.
	{
		super_mario[i] = load_image_at_size(mario[i], MARIO_W, MARIO_H);
		if ((super_mario[i]) == nullptr)
		{
			al_stop_samples();
			destruir_canciones(&music, NUMBER_OF_SAMPLES);
			al_destroy_display(display);
			al_destroy_bitmap(background);
			destroy_images(homer_dance, HOMER_FRAMES);
			destroy_images(cat_running, CAT_FRAMES);
			destroy_images(explosion1, EXPLOSION1_FRAMES);
			destroy_images(explosion2, EXPLOSION2_FRAMES);
			destroy_images(super_mario, i);
			return false;
		}
	}

	for (unsigned int i = 0; i <SONIC_FRAMES; i++) //Crea los bitmaps con los frames de mario running.
	{
		sonic[i] = load_image_at_size(sonic_[i], SONIC_W, SONIC_H);
		if ((sonic[i]) == nullptr)
		{
			al_stop_samples();
			destruir_canciones(&music, NUMBER_OF_SAMPLES);
			al_destroy_display(display);
			al_destroy_bitmap(background);
			destroy_images(homer_dance, HOMER_FRAMES);
			destroy_images(cat_running, CAT_FRAMES);
			destroy_images(explosion1, EXPLOSION1_FRAMES);
			destroy_images(explosion2, EXPLOSION2_FRAMES);
			destroy_images(super_mario, MARIO_FRAMES);
			destroy_images(sonic, i);
			return false;
		}
	}

	return true;

}

void destroy_images(ALLEGRO_BITMAP  **imagen, unsigned int num_imagenes)
{
	unsigned int i;
	for (i = 0; i<num_imagenes; i++)
	{
		al_destroy_bitmap(imagen[i]);
	}
}

ALLEGRO_BITMAP* load_image_at_size(char* image_name, int size_x, int size_y)
{
	ALLEGRO_BITMAP * image = nullptr;
	ALLEGRO_BITMAP * current_target = nullptr;
	ALLEGRO_BITMAP * resized_image = nullptr;

	current_target = al_get_target_bitmap(); //salva el target original para no perderlo

	image = al_load_bitmap(image_name);
	if (image == NULL)
	{
		return nullptr;
	}

	resized_image = al_create_bitmap(size_x, size_y);
	if (resized_image == NULL)
	{
		al_destroy_bitmap(image);
		return nullptr;


	}

	al_set_target_bitmap(resized_image);
	al_draw_scaled_bitmap(image, 0, 0, al_get_bitmap_width(image), al_get_bitmap_height(image),
		0, 0, size_x, size_y, 0);

	al_set_target_bitmap(current_target); //vuelve al target original
	al_destroy_bitmap(image);
	return resized_image;
}
bool viewer::LoadSong(char * nombre, int numero_de_canciones)
{
	int i;
	int valido = true;
	for (i = 0; (i<numero_de_canciones) && (valido); i++)
	{
		music = al_load_sample(nombre);
		if (music == NULL)
		{
			valido = false;
		}

	}

	return valido;

}

void destruir_canciones(ALLEGRO_SAMPLE** canciones, int numero_de_canciones)
{
	int i;
	for (i = 0; i< numero_de_canciones; i++)
	{
		al_destroy_sample(canciones[i]);
	}

}



void viewer::flipViewer(void)
{
	al_flip_display();
}

void viewer:: UpdateAnimation(double offset, ALLEGRO_BITMAP** anim, int size, double period)
{
	int i = 0;
	double posx = 0.0;

	while (posx < width)
	{
		al_clear_to_color(al_color_name("black"));
		al_draw_bitmap(background,0.0,0.0,0);
		if (i >= size)
		{
			i = 0;
		}

		al_draw_bitmap(anim[i++], posx, POSY, 0);
		posx += offset;
		al_flip_display();
		al_rest(period);
	}
}