#include "Avion.h"

Avion::Avion()
{

}

Avion::~Avion()
{
    //dtor
}

int Avion::calculTemps(int distance)
{
    int temps;
    temps = distance / m_vitesse;
    return temps;
}

