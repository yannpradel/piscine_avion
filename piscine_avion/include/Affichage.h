#ifndef AFFICHAGE_H
#define AFFICHAGE_H


#include <iostream>
#include <stdio.h>

#include<allegro.h>
#include<winalleg.h>






#define nombre_image 10
class Allegro
{
private:
    BITMAP* image[nombre_image];
    SAMPLE* souris;
    FONT* averia;
    FONT* Segoe;
    FONT* SegoeGrand;
    FONT* SegoePetit;


    int couleur[10];


public:
    Allegro();
    ~Allegro(); //pas de destructeur car probeleme avec allegro qui detruit les bitmap a la fin d'un sous programme
    BITMAP* getImage(int i);
    FONT* getFont();
    FONT* getFont2();
    FONT* getFont3();
    FONT* getFont4();
    int getCoul(int col);
    void destruction();
    SAMPLE* getClique();
};








#endif // AFFICHAGE_H
