#include <iostream>
#include "Simulateur.h"


int main()
{
    std::vector<int> z;

    Simulateur a;

    a.load_aeroport();
    a.load_carac();
    a.afficher2();

    std::cout << "___________________________________________________________________________\n\n";
    std::cout << "___________________________________________________________________________\n\n";
    std::cout << "___________________________________________________________________________\n\n";

    a.load_avion();
    a.afficherAvion();

    std::cout << "___________________________________________________________________________\n\n";
    z = a.Dijkstra(a.getTaille(),a.getOrdre(),a.getID());


    return 0;
}
