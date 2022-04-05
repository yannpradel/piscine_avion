#ifndef AFFICHAGE_H
#define AFFICHAGE_H


#include <iostream>
#include <stdio.h>

#include<allegro.h>
#include<winalleg.h>






#define nombre_image 3
class Allegro
{
private:
    BITMAP* image[nombre_image];
    SAMPLE* souris;
    FONT* averia;
    FONT* Segoe;


    int couleur[4];


public:
    Allegro();
    ~Allegro(); //pas de destructeur car probeleme avec allegro qui detruit les bitmap a la fin d'un sous programme
    BITMAP* getImage(int i);
    FONT* getFont();
    FONT* getFont2();
    int getCoul(int col);
    void destruction();
    SAMPLE* getClique();
};







#endif // AFFICHAGE_H
