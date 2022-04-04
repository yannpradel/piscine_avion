#ifndef SIMULATEUR_H
#define SIMULATEUR_H
#include "Aeroport.h"
#include "Coordonnes.h"
#include <vector>
#include <string>

class Simulateur
{
    public:
        Simulateur();
        ~Simulateur();

        std::vector<int> Dijkstra();
        void load_carac(int taille);
        void afficher();
        void afficher2();


    protected:

    private:
        int m_crise;
        std::vector<std::pair<int, std::string>> m_aero_name;
        std::vector<Aeroport> m_aeros;

};

#endif // SIMULATEUR_H
