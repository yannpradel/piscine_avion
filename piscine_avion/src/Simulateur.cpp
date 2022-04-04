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

void Simulateur::afficher2()
{
    for(unsigned i = 0; i<m_aeros.size(); i++)
    {
        //Coordonnes* a;
        //a = m_aeros[i].Get_gps();
        std::cout << m_aeros[i].Get_gps().Get_x() << " : " << m_aeros[i].Get_gps().Get_y() << "\n";
        std::cout << "nbre de pistes : " << m_aeros[i].Get_nbr_pistes() << "\n";
        std::cout << "nbre places au sol : " << m_aeros[i].Get_places_park() << "\n";
        std::cout << "delai attente sol : " << m_aeros[i].Get_delai_att_grd() << "\n";
        std::cout << "temps acces piste : " << m_aeros[i].Get_tempsAccesPiste() << "\n";

        std::cout << "delai anti collision : " << m_aeros[i].Get_delaiAntiCol() << "\n";
        std::cout << "temps decol/att : " << m_aeros[i].Get_tempsDecAtt() << "\n";
        std::cout << "duree boucle vol : " << m_aeros[i].Get_dureeBoucleAtt() << "\n";
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
        }
        compteur++;
    }
    fichier.close();



    load_carac(ordre);
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



    std::vector<int> vide;
    return vide;
}


void Simulateur::load_carac(int taille)
{
    std::string nom("carac_aero.txt");
    std::ifstream fichier(nom.c_str());   //ofstream : ecriture
    std::vector<Piste*> pistes;

    std::vector<Coordonnes> listes_coord;


    ///lecture de la liste
    if(!fichier)
        exit(EXIT_FAILURE);
    else
    {

        //init vect de aeroport
        for(int i = 0; i<taille; i++)
        {
            Aeroport a;
            m_aeros.push_back(a);

            Coordonnes b;
            listes_coord.push_back(b);
        }


        std::cout << "debut" << "\n";
        for(int j = 0; j<taille; j++)
        {
            int t;

            fichier >> t;
            std::cout << "x : " << t << "\n";
            listes_coord[j].Set_x(t);

            fichier >> t;
            std::cout << "y : " << t << "\n";
            listes_coord[j].Set_y(t);

            fichier >> t;
            std::cout << "nbre piste : " << t << "\n";
            m_aeros[j].Set_nbr_pistes(t);

            fichier >> t;
            std::cout << "places parking : " << t << "\n";
            m_aeros[j].Set_places_park(t);

            fichier >> t;
            std::cout << "delai att sol : " << t << "\n";
            m_aeros[j].Set_delai_att_grd(t);

            fichier >> t;
            std::cout << "temps acces piste : " << t << "\n";
            m_aeros[j].Set_tempsAccesPiste(t);

            fichier >> t;
            std::cout << "delai anti-col : " << t << "\n";
            m_aeros[j].Set_delaiAntiCol(t);

            fichier >> t;
            std::cout << "temps decatt : " << t << "\n";
            m_aeros[j].Set_tempsDecAtt(t);

            fichier >> t;
            std::cout << "duree boucle : " << t << "\n";
            m_aeros[j].Set_dureeBoucleAtt(t);

        }
        fichier.close();

        ///set gps values
        for(int i = 0; i<(int)listes_coord.size(); i++)
        {
            m_aeros[i].Set_gps(listes_coord[i]);
        }

        ///init vector pistes : cree vecteur de piste que l'on pushback nbre_de_piste fois
        for(int i = 0; i<(int)m_aeros.size(); i++)
        {
            std::vector<Piste*>pp;
            for(int j = 0; j<m_aeros[i].Get_nbr_pistes(); j++)
            {
                //var temporaire
                Piste* p;
                pp.push_back(p);
                //m_aeros[i].m_pistes.push_back(p);
            }

            m_aeros[i].Set_pistes(pp);
        }
    }

}

void Simulateur::load_avion()
{
    int nbr_Avion = 4;
    std::string nom("avion.txt");
    std::ifstream fichier(nom.c_str());   //ofstream : ecriture

    ///lecture de la liste
    if(!fichier)
        exit(EXIT_FAILURE);
    else
    {
        for(int i = 0; i < nbr_Avion; i++)
        {
            Avion a;
            m_avions.push_back(a);
        }

        //init vect de aeroport


        std::cout << "debut" << "\n";
        for(int j = 0; j<nbr_Avion; j++)
        {
            std::string t;

            fichier >> t;
            std::cout << "Type d'avion :" << t << std::endl;
            m_avions[j].Set_type(t);

            int r;

            fichier >> r;
            std::cout << "Sa consommation :" << r << std::endl;
            m_avions[j].Set_consommation(r);

            fichier >> r;
            std::cout << "Sa capacit� :" << r << std::endl;
            m_avions[j].Set_capacite(r);


            fichier >> t;
            std::cout << "Sa couleur :" << t << std::endl;
            m_avions[j].Set_Couleur(t);

            fichier >> t;
            std::cout << "Son nom :" << t << std::endl;
            m_avions[j].Set_Nom(t);






            /*

            fichier >> t;
            std::cout << "temps acces piste : " << t << "\n";
            m_aeros[j].Set_tempsAccesPiste(t);

            fichier >> t;
            std::cout << "delai anti-col : " << t << "\n";
            m_aeros[j].Set_delaiAntiCol(t);

            fichier >> t;
            std::cout << "temps decatt : " << t << "\n";
            m_aeros[j].Set_tempsDecAtt(t);

            fichier >> t;
            std::cout << "duree boucle : " << t << "\n";
            m_aeros[j].Set_dureeBoucleAtt(t);
            */
        }
        fichier.close();

    }

}

void Simulateur::afficherAvion()
{
    for(int i = 0 ; i<4 ; i++ )
    {

    std::cout <<   m_avions[i].Get_type() << std::endl;
    std::cout <<   m_avions[i].Get_consommation() << std::endl;
    std::cout <<   m_avions[i].Get_capacite() << std::endl;
    std::cout <<   m_avions[i].Get_Couleur() << std::endl;
    std::cout <<   m_avions[i].Get_Nom() << std::endl;


    }
}
