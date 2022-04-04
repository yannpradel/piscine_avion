#include <iostream>
#include "Simulateur.h"


int main()
{

     Simulateur a;
     std::vector<int> z;

     a.load_aeroport();
     a.load_carac();
     a.load_avion();

     int res;
    do
    {do {
        std::cout << " Menu " <<std::endl;
        std::cout <<"1. Afficher les aeroport " <<std::endl;
        std::cout <<"2. Dijkstra" <<std::endl;
        std::cout <<"3. Afficher les avions " << std::endl;
        std::cin >> res;
    } while(!(res > 0 && res < 4));

    switch(res) {
    case 1:

        a.afficher2();
        break;
    case 2:

        z = a.Dijkstra(a.getTaille(),a.getOrdre(),a.getID());
        break;
    case 3:
        a.afficherAvion();
        break;
    }
    }
    while(1);

    //a.afficher2();

    std::cout << "___________________________________________________________________________\n\n";
    std::cout << "___________________________________________________________________________\n\n";
    std::cout << "___________________________________________________________________________\n\n";

    //a.load_avion();
    //a.afficherAvion();

    std::cout << "___________________________________________________________________________\n\n";
    //z = a.Dijkstra(a.getTaille(),a.getOrdre(),a.getID());


    return 0;
}
