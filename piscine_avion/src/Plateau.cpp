#include "Plateau.h"

Plateau::Plateau()
{
    //ctor
}

Plateau::~Plateau()
{
    //dtor
}

void Plateau::afficherPlateau()
{
    std::cout << m_coords.size();
    for (int i=0;i<m_coords.size();i++)
        {
            m_coords[i]->afficherCoord();
        }
}

std::vector<Coordonnes*> Plateau::getCoords()
{
    return m_coords;
}

void Plateau::ajouterCoord(Coordonnes* C)
{
    m_coords.push_back(C);
}
