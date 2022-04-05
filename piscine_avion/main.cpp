#include <iostream>
#include "Simulateur.h"
#include "Affichage.h"
#include <stdio.h>







int main()
{


     Simulateur a;

     Allegro alleg;

     std::vector<int> z;

     a.load_aeroport();

     a.load_avion();

     a.lancerSimu();

     draw_sprite(screen, alleg.getImage(1), 0, 0);


     int res;
    do
    {
        do {
        std::cout << "---------------------Menu----------------------\n " <<std::endl;
        std::cout <<"1. ---------Afficher les aeroport-------------- " <<std::endl;
        std::cout <<"2. ---------Dijkstra---------------------------" <<std::endl;
        std::cout <<"3. ---------Afficher les avions---------------- " << std::endl;
        std::cout <<"4. ---------Afficher les liaisons--------------\n " << std::endl;
        std::cout <<"5. ---------Afficher la carte--------------\n " << std::endl;
        std::cin >> res;
    } while(!(res > 0 && res < 15));

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

    case 4:

        a.afficherLiaison();
        break;

    case 5:
        system("CLS");
        a.afficherPlateau();
        std::cout << "\n\n";
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
}END_OF_MAIN();




