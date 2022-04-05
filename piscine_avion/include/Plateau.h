#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include <vector>
#include <Aeroport.h>
#include <Avion.h>


class Coordonnes;
class Avion;
class Plateau
{
    public:
        Plateau();
        Plateau(std::vector<Avion*> toutlesAvion);
        Plateau(Coordonnes C);
        //Plateau(Coordonnes C,int type (avion ou aeroport));
        ~Plateau();
        void ajouterCoord(Coordonnes C);
        void afficherPlateau();
        std::vector<Coordonnes> getCoords();
        void afficherAsurPlateau();

        std::vector<Coordonnes> m_coords;

        void setAvions(std::vector<Avion*> a){m_avions = a;}

    protected:

    private:

        std::vector<Aeroport*> m_aeroports;
        std::vector<Avion*> m_avions;
};

#endif // PLATEAU_H
