#ifndef OUTPUT_H
#define OUTPUT_H
//Este modulo asume que ya se incializo exitosamente Allegro.

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_color.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>


#define UNIT 1

//Constantes de Audio
#define NUMBER_OF_SAMPLES 1
#define MUSIC_PATH "../Music/Get_Ready_For_This_8-bit_.flac"
#define VOLUME 1

//Frames de las animaciones
#define HOMER_FRAMES 10
#define CAT_FRAMES 12
#define SONIC_FRAMES 10
#define MARIO_FRAMES 12
#define EXPLOSION1_FRAMES 8
#define EXPLOSION2_FRAMES 48



class viewer //Se ocupa de todo lo relacionado con el output de la simulacion
{
public:
	viewer(unsigned int width_, unsigned int height_);
	~viewer();
	void RunAnimation(char); 
	bool IsInitOK(void);				//deveulve true si todos los recursos se crearon exitosamente.
	ALLEGRO_DISPLAY* GetDisplay(void);
	void flipViewer(void); //hace flip display.

private:

	unsigned int height;
	unsigned int width;
	ALLEGRO_SAMPLE* music;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_BITMAP* background;

	//Arreglos con las imagenes de caddda animacion.
	ALLEGRO_BITMAP* homer_dance[HOMER_FRAMES]; 
	ALLEGRO_BITMAP* cat_running[CAT_FRAMES]; 
	ALLEGRO_BITMAP* sonic[SONIC_FRAMES]; 
	ALLEGRO_BITMAP* super_mario[MARIO_FRAMES]; 
	ALLEGRO_BITMAP* explosion1[EXPLOSION1_FRAMES]; 
	ALLEGRO_BITMAP* explosion2[EXPLOSION2_FRAMES]; 

	bool init; //indica si hubo o no error en la inicializacion.
	bool InitializeResources(char** homer, char** cat, char** exp1, char** exp2, char** mario, char** sonic);
	bool LoadSong(char*, int);
	void UpdateAnimation(double offset, ALLEGRO_BITMAP** anim, int size, double period);
};

#endif //OUTPUT_H

