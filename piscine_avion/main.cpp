#include <iostream>
#include "Simulateur.h"


int main()
{
    std::vector<int> z;

    Simulateur a;

    z = a.Dijkstra();

    //a.afficher();
    a.afficher2();

    std::cout << "caca";
    return 0;
}
