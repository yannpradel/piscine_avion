#include "Aeroport.h"

Aeroport::Aeroport()
{
    //ctor
}

Aeroport::~Aeroport()
{
    //dtor
}

int Aeroport::getNombreStationDispo()
{
    int nb = Get_nbr_pistes();

    for (int i=0;i<m_stations.size();i++)
    {
        if (m_stations[i].getRempli() == 1)
            nb--;
    }
    return nb;
}

int Aeroport::getNombrePisteDispo()
{
    int nb = Get_places_park();

    for (int i=0;i<m_pistes.size();i++)
    {
        if (m_pistes[i].getRempli() == 1)
            nb--;
    }
    return nb;
}
