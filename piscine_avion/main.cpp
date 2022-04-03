#include <iostream>
#include "Simulateur.h"


int main()
{
    std::vector<int> z;

    Simulateur a;

    z = a.Dijkstra();

    a.afficher();

    return 0;
}
