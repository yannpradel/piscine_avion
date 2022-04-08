#include "Affichage.h"

void gotoXY(float x, float y)
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C;
    C.X = x;
    C.Y = y;
    SetConsoleCursorPosition(H, C);
}





Allegro::Allegro()
{


    couleur[1]=makecol(217,179,64);
    couleur[2]=makecol(255,255,255);
    couleur[3]=makecol(158,158,158);
    couleur[4]=makecol(255,8,1);
    couleur[5]=makecol(0,0,0);

    souris = load_sample("clique.wav");


    //play_sample(souris,255,128,1000,0);



    averia = load_font("Segoe-UI-18.PCX", NULL, NULL);
    Segoe = load_font("Segoe-UI-Bold-Italic.PCX", NULL, NULL);
    SegoeGrand = load_font("Segoe-UI-36.PCX", NULL, NULL);

    image[1] = load_bitmap("cursor.BMP", NULL);
    image[2] = load_bitmap("menu.BMP", NULL);
    image[3] = load_bitmap("earth.BMP", NULL);
    image[4] = load_bitmap("petit_avion.BMP", NULL);
    image[5] = load_bitmap("moyen_avion.BMP", NULL);
    image[6] = load_bitmap("grand_avion.BMP", NULL);


    /*

    for(int i=1; i<=nombre_image ; i++)
        if(image[i]==NULL)
            std::cout<<"NULLELELELELEELELLLE"<<i;*/


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
FONT* Allegro::getFont3()
{
    return SegoeGrand;
}
int Allegro::getCoul(int col)
{
    return couleur[col];
}

void Allegro::destruction()//fonction de destruction se fait par appel a la fin du main, evite les crash et on est sur que le programme s'arrete normalement
{

/*
    for(int i=1; i<=nombre_image; i++)
        destroy_bitmap(image[i]);*/


    std::cout<<"\nle tout a ete suprime\n";
}




/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

