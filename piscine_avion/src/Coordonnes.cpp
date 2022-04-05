#include "Coordonnes.h"
#include <iostream>

void gotoXY(float x, float y);

Coordonnes::Coordonnes()
{
    m_x = 0;
    m_y = 0;
}

Coordonnes::Coordonnes(int x, int y)
{
    m_x = x;
    m_y = y;
}

Coordonnes::~Coordonnes()
{

}

void Coordonnes::afficherCoord()
{
    char color;
  //  rectfill(screen,29+m_x*26,35+2+m_y*32,29+m_x*26+20,20+2+m_y*32+35,x);
    if (m_occupe == "vide")
        color = '.';

    if (m_occupe == "aeroport")
        color = '@';

    gotoXY((m_x*2)+1,m_y+1);

    std::cout << color ;
}

