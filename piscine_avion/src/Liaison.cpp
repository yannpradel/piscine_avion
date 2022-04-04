#include "Liaison.h"
#include "Aeroport.h"

Liaison::Liaison()
{
    //ctor
}

Liaison::Liaison(int a, int b, int dist)
{
    m_1_t = a;
    m_2_t = b;
    m_distance = dist;
}

Liaison::Liaison(Aeroport a, Aeroport b, int dist)
{
    m_aeroport1 = a;
    m_aeroport2 = b;
    m_distance = dist;
}

Liaison::~Liaison()
{
    //dtor
}
