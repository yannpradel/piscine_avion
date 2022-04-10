#include "Aeroport.h"

Aeroport::Aeroport()
{
    //ctor
}

Aeroport::~Aeroport()
{
    //dtor
}

Aeroport::Aeroport(int num,std::string name)
{
    m_num = num;
    m_name = name;
}

int Aeroport::getNombreStationDispo()
{
    int nb = Get_places_park();

    for (int i=0;i<m_stations.size();i++)
    {
        if (m_stations[i].getRempli() == 1)
            nb--;
    }
    return nb;
}

int Aeroport::getNombrePisteDispo()
{
    int nb = Get_nbr_pistes();

    for (int i=0;i<m_pistes.size();i++)
    {
        if (m_pistes[i].getRempli() == 1)
            nb--;
    }
    return nb;
}

void Aeroport::afficherStations()
{
    for(int i= 0;i<m_stations.size();i++)
    {
        std::cout << "---Station : " << i << " --- : --- " << m_stations[i].getRempli()<<std::endl;
    }
}

void Aeroport::afficherPistes()
{
    for(int i= 0;i<m_pistes.size();i++)
    {
        std::cout << "---Piste : " << i << " --- : --- " << m_pistes[i].getRempli()<<std::endl;
    }
}
