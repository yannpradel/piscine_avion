#include "Affichage.h"

void gotoXY(float x, float y)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C;
    C.X = x;
    C.Y = y;
    SetConsoleCursorPosition(H, C);
}


void initialiser_allegro();


Allegro::Allegro()
{


    //play_sample(souris,255,128,1000,0);

    initialiser_allegro();

    averia = load_font("averia_18_B.PCX", NULL, NULL);
    Segoe = load_font("Segoe-UI-Bold-Italic.PCX", NULL, NULL);

    image[1] = load_bitmap("cursor.BMP", NULL);
    image[2] = load_bitmap("menu.BMP", NULL);
    image[3] = load_bitmap("earth.BMP", NULL);


    for(int i=1; i<=nombre_image ; i++)
        if(image[i]==NULL)
            std::cout<<"NULLELELELELEELELLLE"<<i;


}

Allegro::~Allegro() {} //pas de destructeur car probeleme avec allegro qui detruit les bitmap a la fin d'un sous programme


BITMAP* Allegro::getImage(int i)
{
    return image[i];
}
SAMPLE* Allegro::getClique()
{
    return souris;
}
FONT* Allegro::getFont()
{
    return averia;
}
FONT* Allegro::getFont2()
{
    return Segoe;
}
int Allegro::getCoul(int col)
{
    return couleur[col];
}

void Allegro::destruction()//fonction de destruction se fait par appel a la fin du main, evite les crash et on est sur que le programme s'arrete normalement
{

    for(int i=1; i<=nombre_image; i++)
        destroy_bitmap(image[i]);

    std::cout<<"\nle tout a ete suprime\n";
}

void delay(int milli_seconds)//https://www.geeksforgeeks.org/time-delay-c/
{

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void initialiser_allegro()
{
    srand(time(NULL));
    // initialisation allegro obligatoire
    allegro_init() ;

    // sélection de la profondeur de couleur, si rien n'est spécifié le mode couleur est en 8 bits
    set_color_depth(32);

    // définir un mode graphique en contrôlant qu'il fonctionne

    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,1824,1026,0,0)!=0)
    {
        allegro_message("l'ecran est trop petit il faut mettre la resolution a 100 dans parametres -> systeme -> resolution");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    set_window_title("ECE Flight Simulator");
    set_close_button_callback(allegro_exit);

    // pour disposer du clavier (si besoin)
    install_keyboard();

    // pour disposer de la souris (si besoin)
    install_mouse();

    //musique
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    int play_sample(const SAMPLE *spl, int vol, int pan, int freq, int loop);

    //autres initialisations
    install_timer();
}
END_OF_FUNCTION(initialiser_allegro)
