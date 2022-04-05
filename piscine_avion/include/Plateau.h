#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include <vector>
#include <Aeroport.h>

class Coordonnes;
class Plateau
{
    public:
        Plateau();
        Plateau(std::vector<Aeroport*> toutlesA);
        Plateau(Coordonnes C);
        ~Plateau();
        void ajouterCoord(Coordonnes* C);
        void afficherPlateau();
        std::vector<Coordonnes*> getCoords();
        void afficherAsurPlateau();

    protected:

    private:
        std::vector<Coordonnes*> m_coords;
        std::vector<Aeroport*> m_aeroports;
};

#endif // PLATEAU_H
