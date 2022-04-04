#ifndef SIMULATEUR_H
#define SIMULATEUR_H
#include "Aeroport.h"
#include "Avion.h"
#include "Coordonnes.h"
#include <vector>
#include <string>
#define NB_AEROPORT 7

class Simulateur
{
    public:
        Simulateur();
        ~Simulateur();

        void load_aeroport();
        std::vector<int> Dijkstra(int ordre, int taille,std::vector<std::vector<unsigned>> IDgraphe);
        void load_carac();
        void afficher();
        void afficher2();
        void afficherAvion();
        void load_avion();

        int getOrdre(){return m_ordre;}
        int getTaille(){return m_taille;}
        std::vector<std::vector<unsigned>> getID(){return m_IDgraphe;}



    protected:

    private:
        int m_ordre;
        int m_taille;
        std::vector<std::vector<unsigned>> m_IDgraphe;
        int m_nb_aeroport=NB_AEROPORT;
        int m_crise;
        std::vector<std::pair<int, std::string>> m_aero_name;
        std::vector<Aeroport> m_aeros;
        std::vector<Avion> m_avions;

};

#endif // SIMULATEUR_H
