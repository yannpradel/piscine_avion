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

void Avion::afficherDansStation(){

    if (m_dansStation == 0)
        std::cout << "\n\n------------L'AVION EST DANS LES AIRS-------------\n\n";

    if (m_dansStation == 1)
        std::cout << "\n\n------------L'AVION EST DANS LA STATION-------------\n\n";

    if (m_dansStation == 2)
        std::cout << "\n\n------------L'AVION EST SUR LA PISTE POUR DECOLLER-------------\n\n";

    if (m_dansStation == 3)
        std::cout << "\n\n------------L'AVION EST DANS LA STATION EST S'APPRETE A DECOLLER-------------\n\n";

    if (m_dansStation == 4)
        std::cout << "\n\n------------L'AVION EST SUR LA PISTE POUR RENTRER DANS LA STATION-------------\n\n";

    if (m_dansStation == 5)
        std::cout << "\n\n------------L'AVION EST EN PHASE DE DECOLLAGE-------------\n\n";

    if (m_dansStation == 6)
        std::cout << "\n\n------------L'AVION EST EN PHASE D'ATTERISSAGE-------------\n\n";



}

