#ifndef SIMULATEUR_H
#define SIMULATEUR_H


#include "Affichage.h"
#include "Aeroport.h"
#include "Avion.h"
#include "Coordonnes.h"
#include "Plateau.h"
#include <Liaison.h>
#include <vector>
#include <string>
#define NB_AEROPORT 7

class Simulateur
{
    public:
        Simulateur();
        ~Simulateur();

        void load_aeroport();
        std::vector<std::string> Dijkstra(int ordre, int taille,std::vector<std::vector<unsigned>> IDgraphe,std::string depart, std::string arrivee);
        void load_carac();
        void afficher();
        void afficher2();
        void afficherAvion();
        void afficherLiaison();
        void afficherPlateau();
        void load_avion();
        void lancerSimu();
        void initialiserAeroport(int choixx[2],int numA);
        void remplirLiaison();
        void setAeroPlateau();
        void afficherOccupCases();

        void lancerDij(Avion plane);
        void lancerVol(Avion &plane);
        void mettreSurPiste(Avion &plane);
        void faireDecoller(Avion &plane);
        void faireAterrir(Avion &plane);
        void avantAtterissage(Avion &plane);
        void mettreVersLaPiste(Avion &plane);

        Allegro getAffichage(){return a;}

        int getOrdre(){return m_ordre;}
        int getTaille(){return m_taille;}
        std::vector<std::vector<unsigned>> getID(){return m_IDgraphe;}
        std::vector<int> getDistance(){return m_distance;}

        Plateau getPlateau(){return m_plateau;}





    protected:

    private:


        Allegro a;

        int m_ordre;
        int m_taille;
        std::vector<std::vector<unsigned>> m_IDgraphe;
        int m_nb_aeroport=NB_AEROPORT;
        int m_crise;
        std::vector<std::pair<int, std::string>> m_aero_name;

        std::vector<int> m_distance;
        std::vector<std::pair<unsigned int,unsigned int>> m_aeros_liaisons;

        Plateau m_plateau;
        std::vector<Aeroport> m_aeros;
        std::vector<Avion> m_avions;
        std::vector<Avion> m_avions_bougants;
        std::vector<Liaison> m_liaisons;

};

#endif // SIMULATEUR_H
