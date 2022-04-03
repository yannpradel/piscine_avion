#include "Simulateur.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

Simulateur::Simulateur()
{
    //ctor
}

Simulateur::~Simulateur()
{
    //dtor
}

void Simulateur::afficher()
{
    for(unsigned i = 0; i<m_aero_name.size(); i++)
    {
        std::cout << m_aero_name[i].first << " : " << m_aero_name[i].second << "\n";
    }
}

std::vector<int> Simulateur::Dijkstra()
{
    unsigned compteur = 0, taille = 0, valeur1, valeur2, valeur3;
    unsigned ordre, z;  //z poubelle
    std::string name;

    ///afin de lier aeroport a chiffre
    std::vector<std::pair<int, std::string>> aero_name;

    std::vector<std::vector<unsigned>> IDgraphe;
    std::vector<std::vector<int>> Connexe;
    std::vector<int> Degre;

    std::string nom("aeroports.txt");
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
                m_aero_name.push_back(std::pair<int, std::string>());
                m_aero_name[i].first = i;
                fichier >> z;
                fichier >> name;
                m_aero_name[i].second = name;
            }
        }

        if(compteur<ordre)
            fichier>> valeur1;

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
        }
        compteur++;
    }

/*
    ///affichage du graphe
    for (size_t i = 0; i < IDgraphe.size(); ++i)
        for (size_t j = 0; j < IDgraphe[i].size(); ++j)
        {
            if(IDgraphe[i][j]!=0)
                std::cout<<i<<" "<<j<<" "<<IDgraphe[i][j]<<"\n";
        }
*/
    std::cout << "nombre de sommet : " << ordre << std::endl;
    std::cout << "nombre d'aretes: " << taille << std::endl;
    unsigned sommet_i, sommet_a;
    std::cout<<"Sommet initial : ";
    std::cin>>sommet_i;
    std::cout<<"Sommet d'arrivee : ";
    std::cin>>sommet_a;

    if(sommet_a<0 || sommet_a>=IDgraphe.size() || sommet_i<0 || sommet_i>=IDgraphe.size())
        exit(EXIT_FAILURE);


    std::vector<unsigned> distance;
    std::vector<bool> sommet_verif;
    std::vector<int>chemin;
    unsigned minimum =-1;//pour la premiere verification on utilise une valeur de disntance impossible
    unsigned sommet_leplusproche;


    for (unsigned i=0;i<IDgraphe.size();++i)
    {
        chemin.push_back(-1);//initialisation de chaque valeur a -1 (chemin pas possible dans un graphe)
        distance.push_back(minimum);
        sommet_verif.push_back(false);//initialise tout les sommets a non verifier
    }

    distance[sommet_i] = 0; //la distance du sommet initial au sommet initial est 0)

    for (unsigned i=0;i<IDgraphe.size();++i)
    {
        minimum=-1;
        for (unsigned k=0; k<IDgraphe.size(); k++)
        {
            if (!sommet_verif[k] && distance[k]<=minimum)
            {
                minimum=distance[k];
                sommet_leplusproche=k;
            }
        }
        sommet_verif[sommet_leplusproche] = true;//marque le sommet comme verifier

        for (unsigned j=0;j<IDgraphe.size();j++)
        {
            if (!sommet_verif[j] && distance[sommet_leplusproche]+IDgraphe[sommet_leplusproche][j]<distance[j] && IDgraphe[sommet_leplusproche][j]>0)
            {

                chemin[j]=sommet_leplusproche;
                distance[j]=distance[sommet_leplusproche]+IDgraphe[sommet_leplusproche][j];

            }
        }
    }

    std::cout<<"\n\n";
    std::cout<<sommet_i<<" vers "<<sommet_a<<"| distance: "<<distance[sommet_a]<<"| chemin : "<<sommet_i<<" ";

    std::stack<int> pile;//pour inverser l'ordre

    int j = sommet_a;

    while(chemin[j]!=-1)//cree la pile du chemin
    {
        pile.push(j);
        j=chemin[j];
    }

    while(!pile.empty())//pour afficher l'inverse
    {
        std::cout << pile.top() << " ";
        pile.pop();
    }
std::cout<<"\n\n";

}
