#include "Avion.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Avion::Avion()
{

}

Avion::~Avion()
{
    //dtor
}

int Avion::calculTemps(int distance)
{
    int temps;
    temps = distance / m_vitesse;
    return temps;
}

void Avion::afficherDansStation(){ ///ce sous programme permet d'afficher l'état de l'avion

    if (m_dansStation == 0)
        std::cout << "\n\n------------L'AVION " << m_trajet[0].Get_name() << " - " << m_trajet[1].Get_name() << " EST DANS LES AIRS-------------\n\n";

    if (m_dansStation == 1)
        std::cout << "\n\n------------L'AVION" << m_trajet[0].Get_name() << " - " << m_trajet[1].Get_name() <<" EST DANS LA STATION-------------\n\n";

    if (m_dansStation == 2)
        std::cout << "\n\n------------L'AVION" << m_trajet[0].Get_name() << " - " << m_trajet[1].Get_name() <<" EST SUR LA PISTE POUR DECOLLER-------------\n\n";

    if (m_dansStation == 3)
        std::cout << "\n\n------------L'AVION" << m_trajet[0].Get_name() << " - " << m_trajet[1].Get_name() <<" EST DANS LA STATION EST S'APPRETE A DECOLLER-------------\n\n";

    if (m_dansStation == 4)
        std::cout << "\n\n------------L'AVION" << m_trajet[0].Get_name() << " - " << m_trajet[1].Get_name() <<" EST SUR LA PISTE POUR RENTRER DANS LA STATION-------------\n\n";

    if (m_dansStation == 5)
        std::cout << "\n\n------------L'AVION" << m_trajet[0].Get_name() << " - " << m_trajet[1].Get_name() <<" EST EN PHASE DE DECOLLAGE-------------\n\n";

    if (m_dansStation == 6)
        std::cout << "\n\n------------L'AVION" << m_trajet[0].Get_name() << " - " << m_trajet[1].Get_name() <<" EST EN PHASE D'ATTERISSAGE-------------\n\n";



}

void Avion::loadAeroportMoyen() ///pour avoir un bon dijkdra et kruksal fonctionnel, on remet un graphe pour les avions moyens
{
unsigned compteur = 0, taille = 0, valeur1, valeur2, valeur3;
    unsigned ordre, z;  //z poubelle
    std::string name;
    std::vector<int> temp;


    ///afin de lier aeroport a chiffre
    std::vector<std::pair<int, std::string>> aero_name;

    std::vector<std::vector<unsigned>> IDgraphe;
    std::vector<std::vector<int>> Connexe;
    std::vector<int> Degre;

    std::string nom("aeroportsMoyen.txt");
    std::ifstream fichier(nom.c_str());   //ofstream : ecriture


    ///lecture de la liste
    if(!fichier)
        exit(EXIT_FAILURE);

    while(compteur<=ordre+taille+1)
    {
        if(compteur==0)
        {
            fichier>> ordre;
            for(unsigned i=0; i<ordre; i++)
            {
                IDgraphe.push_back(std::vector<unsigned>());
                for(unsigned j=0; j<ordre; j++)
                {
                    IDgraphe[i].push_back(0);
                }

                //init vecteur de pair
                fichier >> z;
                fichier >> name;
            }
        }

        valeur1 = z;

        if (compteur==ordre)
        {
            fichier>> taille;
        }
        else if(compteur>ordre+1)
        {
            fichier>> valeur1;
            fichier>> valeur2;
            fichier>> valeur3;
            IDgraphe[valeur1][valeur2]=valeur3;

            m_distance.push_back(valeur3);
        }
        compteur++;
    }
    fichier.close();

      m_ordre = ordre;
      m_taille = taille;
      m_IDgraphe = IDgraphe;

}

