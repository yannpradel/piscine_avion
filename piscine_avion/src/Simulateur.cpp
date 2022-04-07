#include "Simulateur.h"
#include <Piste.h>
#include <Station.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <utility>
#include <Coordonnes.h>
#define COEF_DISTANCE 10
#define TEMPS_UT 300

void delay(int milli_seconds);


Simulateur::Simulateur()
{

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
    std::vector<int> elem;

    for(unsigned i = 0; i<m_aeros.size(); i++)
    {
        elem.push_back(0);
        //Coordonnes* a;
        //a = m_aeros[i].Get_gps();
        std::cout << "------------------------------------------------------------\n";
        std::cout << "------------------- AEROPORT : "<< m_aero_name[i].second << " -----------------------\n";
        std::cout << "------------------------------------------------------------\n";
        std::cout << "x : "<< m_aeros[i].Get_gps().Get_x() << " : " << "y : "<< m_aeros[i].Get_gps().Get_y() << "\n";
        std::cout << "nbre de pistes : " << m_aeros[i].Get_nbr_pistes() << "\n";
        std::cout << "nbre de stations disponible: " << m_aeros[i].getNombreStationDispo() << "\n";
        std::cout << "nbre places au sol : " << m_aeros[i].Get_places_park() << "\n";
        std::cout << "delai attente sol : " << m_aeros[i].Get_delai_att_grd() << "\n";
        std::cout << "temps acces piste : " << m_aeros[i].Get_tempsAccesPiste() << "\n";

        std::cout << "delai anti collision : " << m_aeros[i].Get_delaiAntiCol() << "\n";
        std::cout << "temps decol/att : " << m_aeros[i].Get_tempsDecAtt() << "\n";
        std::cout << "duree boucle vol : " << m_aeros[i].Get_dureeBoucleAtt() << "\n";

    }



    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

    bool sortie=false;


    ///GAME LOOP
    do
    {


        draw_sprite(buffer, a.getImage(3), 0, 0);

        for(unsigned i = 0; i<m_aeros.size(); i++)
        {

            if(elem[i]==0)
                textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18, m_aeros[i].Get_gps().Get_y()-36, a.getCoul(2), -1, "%s", m_aero_name[i].second.c_str());
            else
                textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18, m_aeros[i].Get_gps().Get_y()-36-4, a.getCoul(3), -1, "%s", m_aero_name[i].second.c_str());

            rectfill(buffer, m_aeros[i].Get_gps().Get_x()-10, m_aeros[i].Get_gps().Get_y()-10, m_aeros[i].Get_gps().Get_x()+10, m_aeros[i].Get_gps().Get_y()+10, a.getCoul(4));
            //rect(buffer, m_aeros[i].Get_gps().Get_x()+18, m_aeros[i].Get_gps().Get_y()-36+9, m_aeros[i].Get_gps().Get_x()+18+100, m_aeros[i].Get_gps().Get_y(), a.getCoul(1));

        }






        //textprintf_ex(buffer, a.getFont2(), 20, 724+i*0, a.getCoul(2), -1, "Afficher les Aeroports");


        //rect(buffer, 50, 724+18, 324, 724+36+18, a.getCoul(1));

        for(unsigned i = 0; i<m_aeros.size(); i++)
        {
            elem[i]=0;
            if((mouse_x>=m_aeros[i].Get_gps().Get_x()+18) && (mouse_x<=m_aeros[i].Get_gps().Get_x()+18+100) & (mouse_y>=m_aeros[i].Get_gps().Get_y()-36+9) && (mouse_y<=m_aeros[i].Get_gps().Get_y()))
            {
                elem[i]=1;
                if(i<5)
                {
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18+150, m_aeros[i].Get_gps().Get_y()-36-4, a.getCoul(2), -1, "Nombre de Pistes: %d", m_aeros[i].Get_nbr_pistes());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18+150, m_aeros[i].Get_gps().Get_y()-36-4+27, a.getCoul(2), -1, "Nombre de Station disponile: %d", m_aeros[i].getNombreStationDispo());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18+150, m_aeros[i].Get_gps().Get_y()-36-4+27+27, a.getCoul(2), -1, "Nombre dePlaces au Sol: %d", m_aeros[i].Get_places_park());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18+150, m_aeros[i].Get_gps().Get_y()-36-4+27+27+27, a.getCoul(2), -1, "Delais d'attente Sol: %d", m_aeros[i].Get_delai_att_grd());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18+150, m_aeros[i].Get_gps().Get_y()-36-4+27+27+27+27, a.getCoul(2), -1, "Temps acces piste: %d", m_aeros[i].Get_tempsAccesPiste());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18+150, m_aeros[i].Get_gps().Get_y()-36-4+27+27+27+27+27, a.getCoul(2), -1, "Delai anti colision: %d", m_aeros[i].Get_delaiAntiCol());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18+150, m_aeros[i].Get_gps().Get_y()-36-4+27+27+27+27+27+27, a.getCoul(2), -1, "Temps decolage/atterisage: %d", m_aeros[i].Get_tempsDecAtt());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18+150, m_aeros[i].Get_gps().Get_y()-36-4+27+27+27+27+27+27+27, a.getCoul(2), -1, "Duree boucle vol: %d", m_aeros[i].Get_dureeBoucleAtt());
                }
                else
                {
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18-350, m_aeros[i].Get_gps().Get_y()-36-4+20, a.getCoul(2), -1, "Nombre de Pistes: %d", m_aeros[i].Get_nbr_pistes());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18-350, m_aeros[i].Get_gps().Get_y()-36-4+27+20, a.getCoul(2), -1, "Nombre de Station disponile: %d", m_aeros[i].getNombreStationDispo());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18-350, m_aeros[i].Get_gps().Get_y()-36-4+27+27+20, a.getCoul(2), -1, "Nombre dePlaces au Sol: %d", m_aeros[i].Get_places_park());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18-350, m_aeros[i].Get_gps().Get_y()-36-4+27+27+27+20, a.getCoul(2), -1, "Delais d'attente Sol: %d", m_aeros[i].Get_delai_att_grd());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18-350, m_aeros[i].Get_gps().Get_y()-36-4+27+27+27+27+20, a.getCoul(2), -1, "Temps acces piste: %d", m_aeros[i].Get_tempsAccesPiste());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18-350, m_aeros[i].Get_gps().Get_y()-36-4+27+27+27+27+27+20, a.getCoul(2), -1, "Delai anti colision: %d", m_aeros[i].Get_delaiAntiCol());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18-350, m_aeros[i].Get_gps().Get_y()-36-4+27+27+27+27+27+27+20, a.getCoul(2), -1, "Temps decolage/atterisage: %d", m_aeros[i].Get_tempsDecAtt());
                    textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18-350, m_aeros[i].Get_gps().Get_y()-36-4+27+27+27+27+27+27+27+20, a.getCoul(2), -1, "Duree boucle vol: %d", m_aeros[i].Get_dureeBoucleAtt());
                }

                std::cout<<i;
            }
        }




        ///Images
        draw_sprite(buffer, a.getImage(1), mouse_x, mouse_y);///souri
        draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
    }
    while(!sortie);


    ///destruction
    destroy_bitmap(buffer);
}


void Simulateur::load_aeroport()
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
            m_aeros_liaisons.push_back(std::make_pair(valeur1,valeur2));

            m_distance.push_back(valeur3);
        }
        compteur++;
    }
    fichier.close();

    load_carac();

    //  std::cout << "sdfs" << m_aeros[0].Get_name() << std::endl;

    m_ordre = ordre;
    m_taille = taille;
    m_IDgraphe = IDgraphe;

    Aeroport a;
    Aeroport b;

    for (size_t p=0; p<getDistance().size(); p++)
    {
        //  std::cout << "distance " << i << " : " << m_distance[i] << std::endl;
        //    std::cout << "aeroport 1 : " << m_aeros_liaisons[i].first << std::endl;
        //   std::cout << "aeroport 2 : "  << m_aeros_liaisons[i].second << std::endl;
        //     std::cout << "get un : " << m_aeros_liaisons[i].first<< "get deux : " << m_aeros_liaisons[i].second << "distance : " << m_distance[i]<<std::endl;
        //  Liaison b(m_aeros_liaisons[p].first,m_aeros_liaisons[p].second,m_distance[p]);

        Aeroport q,v;
        for (size_t i=0; i<m_aero_name.size(); i++)
        {
            //  std::cout << m_aero_name[i].first;
            //  std::cout << m_aeros_liaisons[p].first;

            if(m_aero_name[i].first == int(m_aeros_liaisons[p].first)) ///si l'int du nom = le premier aeroport
            {
                std::string temporaire;
                temporaire = m_aero_name[i].second;

                //  std::cout << temporaire;
                // std::cout << m_aeros.size();
                for (size_t j=0; j<m_aeros.size(); j++)
                {
                    // std::cout << m_aeros[j].Get_name();
                    if(temporaire == m_aeros[j].Get_name())
                    {
                        //    std::cout << m_aeros[j].Get_name();
                        q = m_aeros[j];
                    }
                }
            }



            if(m_aero_name[i].first == int(m_aeros_liaisons[p].second)) ///si l'int du nom = le 2 aeroport
            {
                std::string temporaire;
                temporaire = m_aero_name[i].second;

                for (size_t j=0; j<m_aeros.size(); j++)
                {
                    if(temporaire == m_aeros[j].Get_name())
                    {

                        v = m_aeros[j];
                    }
                }
            }
        }

        Liaison b(q,v,m_distance[p]);
        m_liaisons.push_back(b);
    }




}

std::vector<std::string> Simulateur::Dijkstra(int ordre, int taille,std::vector<std::vector<unsigned>> IDgraphe, std::string depart, std::string arrivee)
{
    std::cout << "nombre de liaisons : " << ordre << std::endl;
    std::cout << "nombre d'aeroports: " << taille << std::endl;
    std::string Ssommet_i, Ssommet_a;
    int sommet_i, sommet_a;


    Ssommet_i = depart;
    Ssommet_a = arrivee;

    std::vector<std::string> m_resultat;


    for (auto elem : m_aero_name)
    {
        if (elem.second == Ssommet_i)
            sommet_i = elem.first;
    }

    for (auto elem : m_aero_name)
    {
        if (elem.second == Ssommet_a)
            sommet_a = elem.first;
    }



    if(sommet_a<0 || int(sommet_a>=IDgraphe.size()) || sommet_i<0 || sommet_i>=int(IDgraphe.size()))
        exit(EXIT_FAILURE);


    std::vector<unsigned> distance;
    std::vector<bool> sommet_verif;
    std::vector<int>chemin;
    std::string affiche_tempo;
    unsigned minimum =-1;//pour la premiere verification on utilise une valeur de disntance impossible
    unsigned sommet_leplusproche;


    for (unsigned i=0; i<IDgraphe.size(); ++i)
    {
        chemin.push_back(-1);//initialisation de chaque valeur a -1 (chemin pas possible dans un graphe)
        distance.push_back(minimum);
        sommet_verif.push_back(false);//initialise tout les sommets a non verifier
    }

    distance[sommet_i] = 0; //la distance du sommet initial au sommet initial est 0)

    for (unsigned i=0; i<IDgraphe.size(); ++i)
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

        for (unsigned j=0; j<IDgraphe.size(); j++)
        {
            if (!sommet_verif[j] && distance[sommet_leplusproche]+IDgraphe[sommet_leplusproche][j]<distance[j] && IDgraphe[sommet_leplusproche][j]>0)
            {

                chemin[j]=sommet_leplusproche;
                distance[j]=distance[sommet_leplusproche]+IDgraphe[sommet_leplusproche][j];

            }
        }
    }
    std::vector<std::string> vide;
    vide.push_back(Ssommet_i);

    std::cout<<"\n\n";
    std::cout<<Ssommet_i<<" vers "<<Ssommet_a<<"| distance: "<<distance[sommet_a]<<"| chemin : "<<Ssommet_i<<" -- ";

    std::stack<int> pile;//pour inverser l'ordre

    int j = sommet_a;

    while(chemin[j]!=-1)//cree la pile du chemin
    {
        pile.push(j);
        j=chemin[j];
    }

    while(!pile.empty())//pour afficher l'inverse
    {
        for (auto elem : m_aero_name)
        {
            if (elem.first == pile.top())
            {
                affiche_tempo = elem.second;
                vide.push_back(elem.second);
            }
        }
        std::cout << affiche_tempo << " -- ";
        pile.pop();
    }

    std::cout<<"\n\n";

    return vide;

}

void Simulateur::load_carac()
{
    std::string nom("carac_aero.txt");
    std::ifstream fichier(nom.c_str());   //ofstream : ecriture
    std::vector<Piste*> pistes;
    int taille = m_nb_aeroport;

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





        for(int j = 0; j<taille; j++)
        {
            int t;

            fichier >> t;
            //std::cout << "x : " << t << "\n";
            listes_coord[j].Set_x(t);

            fichier >> t;
            // std::cout << "y : " << t << "\n";
            listes_coord[j].Set_y(t);

            fichier >> t;
            // std::cout << "nbre piste : " << t << "\n";
            m_aeros[j].Set_nbr_pistes(t);

            fichier >> t;
            //  std::cout << "places parking : " << t << "\n";
            m_aeros[j].Set_places_park(t);

            fichier >> t;
            //  std::cout << "delai att sol : " << t << "\n";
            m_aeros[j].Set_delai_att_grd(t);

            fichier >> t;
            // std::cout << "temps acces piste : " << t << "\n";
            m_aeros[j].Set_tempsAccesPiste(t);

            fichier >> t;
            // std::cout << "delai anti-col : " << t << "\n";
            m_aeros[j].Set_delaiAntiCol(t);

            fichier >> t;
            //  std::cout << "temps decatt : " << t << "\n";
            m_aeros[j].Set_tempsDecAtt(t);

            fichier >> t;
            //  std::cout << "duree boucle : " << t << "\n";
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
            std::vector<Piste>pp;
            for(int j = 0; j<m_aeros[i].Get_nbr_pistes(); j++)
            {
                //var temporaire
                Piste p;
                pp.push_back(p);
                //m_aeros[i].m_pistes.push_back(p);
            }

            m_aeros[i].Set_pistes(pp);
        }

        ///init vector stations : cree vecteur de station que l'on pushback nbre_de_piste fois
        for(int i = 0; i<(int)m_aeros.size(); i++)
        {
            std::vector<Station>pp;
            for(int j = 0; j<m_aeros[i].Get_places_park(); j++)
            {
                //var temporaire
                Station p;
                pp.push_back(p);
                //m_aeros[i].m_pistes.push_back(p);
            }

            m_aeros[i].Set_stations(pp);
        }
    }
    for (unsigned int i=0; i<m_aeros.size(); i++)
    {

        m_aeros[i].Set_name(m_aero_name[i].second);

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

        for(int j = 0; j<nbr_Avion; j++)
        {
            std::string t;

            fichier >> t;
            //  std::cout << "Type d'avion :" << t << std::endl;
            m_avions[j].Set_type(t);

            int r;

            fichier >> r;
            //  std::cout << "Sa consommation :" << r << std::endl;
            m_avions[j].Set_consommation(r);

            fichier >> r;
            //   std::cout << "Sa capacité :" << r << std::endl;
            m_avions[j].Set_capacite(r);


            fichier >> t;
            //      std::cout << "Sa couleur :" << t << std::endl;
            m_avions[j].Set_Couleur(t);

            fichier >> t;
            //    std::cout << "Son nom :" << t << std::endl;
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
        std::cout << "------------------------------------------------------------\n";
        std::cout << "------------------- AVION : "<<m_avions[i].Get_Nom()<< " -----------------------\n";
        std::cout << "------------------------------------------------------------\n";
        std::cout  << "Type d'avion : " <<   m_avions[i].Get_type() << std::endl;
        std::cout << "Sa consommation : " <<   m_avions[i].Get_consommation() << std::endl;
        std::cout << "Sa capacite : " <<   m_avions[i].Get_capacite() << std::endl;
        std::cout << "Sa couleur : " <<   m_avions[i].Get_Couleur() << std::endl;
    }
}

void Simulateur::afficherLiaison()
{
    for (unsigned int i=0; i<m_liaisons.size(); i++)
        std::cout << m_liaisons[i].Get_aeroport1().Get_name() << " : " << m_liaisons[i].Get_aeroport2().Get_name() << " --- " << m_liaisons[i].Get_distance() << std::endl;
}





void Simulateur::lancerSimu()
{
    int nbVol = 0;
    int Fin=0;
    int numAvion=0;

    std::cout << "------------------Choisir Nb de Vols----------------";
    std::cin >> nbVol;



    std::vector<int> elem;
    for(unsigned i = 0; i<m_aeros.size(); i++)
    {
        elem.push_back(0);
    }
int c=0;
    do{


    do
    {
        std::cout << "------------------Choisir Avion----------------";
        std::cin >> numAvion;
    }while (m_avions[numAvion].getChoisi()==1);


    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    int choix[2];

    bool sortie2=false;
    bool sortie1=false;
    ///GAME LOOP
    do
    {
        draw_sprite(buffer, a.getImage(3), 0, 0);

        if(!sortie1)
            textprintf_ex(buffer,a.getFont3(), 50, 75, a.getCoul(2), -1, "Aeroport de depart");
        else
            textprintf_ex(buffer,a.getFont3(), 50, 75, a.getCoul(2), -1, "Aeroport d'arivee");

        for(unsigned i = 0; i<m_aeros.size(); i++)
        {

            if(elem[i]==0)
                textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18, m_aeros[i].Get_gps().Get_y()-36, a.getCoul(2), -1, "%s", m_aero_name[i].second.c_str());
            else
                textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18, m_aeros[i].Get_gps().Get_y()-36-4, a.getCoul(3), -1, "%s", m_aero_name[i].second.c_str());

            rectfill(buffer, m_aeros[i].Get_gps().Get_x()-10, m_aeros[i].Get_gps().Get_y()-10, m_aeros[i].Get_gps().Get_x()+10, m_aeros[i].Get_gps().Get_y()+10, a.getCoul(4));
            //rect(buffer, m_aeros[i].Get_gps().Get_x()+18, m_aeros[i].Get_gps().Get_y()-36+9, m_aeros[i].Get_gps().Get_x()+18+100, m_aeros[i].Get_gps().Get_y(), a.getCoul(1));
        }






        //textprintf_ex(buffer, a.getFont2(), 20, 724+i*0, a.getCoul(2), -1, "Afficher les Aeroports");


        //rect(buffer, 50, 724+18, 324, 724+36+18, a.getCoul(1));

        for(unsigned i = 0; i<m_aeros.size(); i++)
        {
            elem[i]=0;
            if((mouse_x>=m_aeros[i].Get_gps().Get_x()+18) && (mouse_x<=m_aeros[i].Get_gps().Get_x()+18+100) & (mouse_y>=m_aeros[i].Get_gps().Get_y()-36+9) && (mouse_y<=m_aeros[i].Get_gps().Get_y()))
            {
                elem[i]=1;
                if(mouse_b==1 && !sortie1)
                {
                    choix[0]=i;
                    sortie1=true;
                    std::cout<<i;
                    delay(300);
                }
                else if(mouse_b==1 && sortie1)
                {
                    choix[1]=i;
                    sortie2=true;
                    std::cout<<i;
                    delay(300);
                }
            }
        }




        ///Images
        draw_sprite(buffer, a.getImage(1), mouse_x, mouse_y);///souri
        draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
    }
    while(!sortie2 && !sortie2);


    ///destruction
    destroy_bitmap(buffer);


    ///on a tout initialiser,


    m_avions[numAvion].setChoisi(1);
    initialiserAeroport(choix,numAvion);
    std::cout << "la taille de tout les avions dans la simu" << m_avions_bougants.size();
    c++;
    }while (c < nbVol);

do{
    for (unsigned int j=0;j<m_avions_bougants.size();j++)
    {
            delay(TEMPS_UT/nbVol);
            std::cout << "-------------on avance d'un ut---------------\n\n";
            Fin++;

          //  std::cout << i << std::endl;


            ///-------------juste il est dans la station--------------------------------------

            if(m_avions_bougants[j].getDansStation() == 1) ///dans la station
            {

                if(m_avions_bougants[j].m_trajet.size()<2)
                {
                     m_avions_bougants[j].setDansStation(7);
                     std::cout << "l'avion " <<m_avions_bougants[j].Get_Nom() << "  a tout fini il reste dans sa station";
                }
                else{

                int aerofin = 0; ///c'est le numero dans le vecteur aero de l'aeroport final d'un trajet
                int aerodep = 0; ///c'est le numero dans le vecteur aero de l'aeroport de depart d'un trajet

                    for (auto elem : m_aero_name)
                    {
                    if (elem.second == m_avions_bougants[j].m_trajet[1].Get_name())
                        aerofin = elem.first;
                    }

                    for (auto elem : m_aero_name)
                    {
                    if (elem.second == m_avions_bougants[j].m_trajet[0].Get_name())
                        aerodep = elem.first;
                    }
                std::cout << "aerofin : " << aerofin;
                std::cout << "\n\naerodep : " << aerodep;

                //si c'est la premiere fois qu'il est la
                if(m_avions_bougants[j].getDijDone() == 0)
                    lancerDij(m_avions_bougants[j]);

                for (int i=0 ; i<m_avions_bougants[j].m_trajet.size();i++)
                    std::cout << " ___ " << m_avions_bougants[j].m_trajet[i].Get_name();

                ///------------------------On vérifie si y'a de la place dans l'aeoport de depart sur la piste------------------------///

                if(m_aeros[aerodep].getNombrePisteDispo() > 0)
                {
                    for (unsigned int i=0; i<m_aeros[aerodep].Get_pistes().size(); i++)
                    {
                        if(m_aeros[aerodep].m_pistes[i].getRempli()==0)
                        {
                            std::cout << "\nNom de l'avion : " << m_avions_bougants[j].Get_Nom() << std::endl;
                            m_aeros[aerodep].m_pistes[i].setRempli(1);
                            std::cout << "\n\nl'avion a reservé a l'aeroport : " << m_aeros[aerodep].Get_name() << " la piste :  "<< i << std::endl;
                            m_avions_bougants[j].setAeroportPisteDepart(1);

                            break;
                        }

                    }

                }
                else
                {
                    //l'avion ne peut pas décoller
                    m_avions[numAvion].setAeroportPisteDepart(0); ///une des conditions si il peut décoller
                    m_avions_bougants[j].setDansStation(1);
                    std::cout << "l'aeroport n'as pas de place de piste a l'aeroport de depart il ne peut pas décoller" << std::endl;
                }

                ///------------------------On vérifie si y'a de la place dans l'aeoport de fin sur la piste------------------------///

                if(m_aeros[aerofin].getNombrePisteDispo() > 0)
                {
                    for (unsigned int i=0; i<m_aeros[aerofin].Get_pistes().size(); i++)
                    {
                        if(m_aeros[aerofin].m_pistes[i].getRempli()==0)
                        {
                            std::cout << "\nNom de l'avion : " << m_avions_bougants[j].Get_Nom() << std::endl;
                            m_aeros[aerofin].m_pistes[i].setRempli(1);
                            std::cout << "\n\nl'avion a reservé a l'aeroport : " << m_aeros[aerofin].Get_name() << " la piste :  "<< i << std::endl;
                            m_avions_bougants[j].setAeroportPisteArrive(1);

                            break;
                        }

                    }

                }
                else
                {
                    //l'avion ne peut pas décoller
                    m_avions[numAvion].setAeroportPisteArrive(0); ///une des conditions si il peut décoller
                    m_avions_bougants[j].setDansStation(1);
                    std::cout << "l'aeroport n'as pas de place de piste a l'aeroport de fin il ne peut pas décoller" << std::endl;
                }


                ///------------------------On vérifie si y'a de la place dans l'aeoport de fin dans une station------------------------///
                if(m_aeros[aerofin].getNombreStationDispo() > 0)
                {
                    for (unsigned int i=0; i<m_aeros[aerofin].Get_stations().size(); i++)
                    {
                        if(m_aeros[aerofin].m_stations[i].getRempli()==0)
                        {
                            std::cout << "\nNom de l'avion : " << m_avions_bougants[j].Get_Nom() << std::endl;
                            m_aeros[aerofin].m_stations[i].setRempli(1);
                            std::cout << "\n\nl'avion a reservé a l'aeroport : " << m_aeros[aerofin].Get_name() << "la station :  "<< i << std::endl;
                            m_avions_bougants[j].setAeroportarrive(1);

                            break;
                        }

                    }

                }
                else
                {
                    //l'avion ne peut pas décoller
                    m_avions[numAvion].setAeroportarrive(0); ///une des conditions si il peut décoller
                    m_avions_bougants[j].setDansStation(1);
                    std::cout << "l'aeroport n'as pas de place il ne peut pas décoller" << std::endl;
                }





                m_avions_bougants[j].afficherDansStation();

                if(m_avions_bougants[j].m_trajet.size()>1 && m_avions_bougants[j].getAaeroportArrivee()==1 && m_avions_bougants[j].getAaeroportPisteDepart()==1 && m_avions_bougants[j].getAaeroportPisteArrivee()==1)
                    mettreVersLaPiste(m_avions_bougants[j]);

                    else{
                        std::cout << "l'avion ne peux pas decoller, DSL :)\n\n";
                        m_avions_bougants[j].setDansStation(7);
                      std::cout << "l'avion " <<m_avions_bougants[j].Get_Nom() << "  a tout fini il reste dans sa station";

                }
                }
                //il est dans une station et soit il y reste, soit il peut décoller du coup
                //apres il va sur une piste son num passe a deux et quand il décollle c'est a 0
            }


            if(m_avions_bougants[j].getDansStation() == 3) ///dans la station et s'apprete a aller sur la piste il charge les passagers
            {
                m_avions_bougants[j].afficherDansStation();
                ///mettre dans la piste

                mettreSurPiste(m_avions_bougants[j]);
            }

            if(m_avions_bougants[j].getDansStation() == 4) ///dans la piste pour rentrer dans la station
            {
                m_avions_bougants[j].afficherDansStation();
                rentrerAvion(m_avions_bougants[j]);
            }

            if(m_avions_bougants[j].getDansStation() == 2) ///dans la piste pour décoller
            {
                m_avions_bougants[j].afficherDansStation();
                faireDecoller(m_avions_bougants[j]);
            }

            if(m_avions_bougants[j].getDansStation() == 5) ///avant le décollage
            {
                m_avions_bougants[j].afficherDansStation();
                lancerVol(m_avions_bougants[j]);
            }

            if(m_avions_bougants[j].getDansStation() == 6) ///pendant l'atterissage il decharge les passagers
            {
                m_avions_bougants[j].afficherDansStation();
                avantAtterissage(m_avions_bougants[j]);
            }

            if(m_avions_bougants[j].getDansStation() == 0) ///dans les airs
            {
                m_avions_bougants[j].afficherDansStation();
                lancerVol(m_avions_bougants[j]);
            }

            if(m_avions_bougants[j].getDansStation() == 7) ///dans la station sans vol prévu
            {
                m_avions_bougants[j].afficherDansStation();
                std::cout << "L'avion n'a plus de vol";
                m_avions_bougants[j].setDijDone(0);
            }


            ///on doit lancer plusieurs fois vol
           // lancerVol(m_avions_bougants[j]);
            //delay(25);

        }
       // delay(25)




}while(Fin < 50000);
}

void Simulateur::mettreVersLaPiste(Avion &thePlane) /// transi entre 1 et 3

{

    std::cout << std::endl;
    std::cout << std::endl;

    ///mettre l'algo

    thePlane.setDansStation(3);

}

void Simulateur::mettreSurPiste(Avion &thePlane) ///3
{


    ///mettre l'algo
    if(thePlane.getTempsAttente() < thePlane.m_trajet[0].Get_tempsAccesPiste())
        thePlane.setTempsAttente(thePlane.getTempsAttente()+1);




    else
    {
    thePlane.setDansStation(2);
    thePlane.setTempsAttente(0);
    }

    std::cout << "il est reste : " << thePlane.getTempsAttente();

}

void Simulateur::faireDecoller(Avion &thePlane) ///2
{
   // std::cout << "lavion est sur le numero : " << thePlane.getDansStation();
   if(thePlane.getTempsAttente() < thePlane.m_trajet[0].Get_delai_att_grd()+thePlane.m_trajet[0].Get_tempsDecAtt())
        thePlane.setTempsAttente(thePlane.getTempsAttente()+1);


    ///mettre l'algo
    else
    {
    thePlane.setDansStation(5);
    thePlane.setTempsAttente(0);
    }

    std::cout << "il est reste : " << thePlane.getTempsAttente();

}

void Simulateur::rentrerAvion(Avion &thePlane) ///4
{
  if(thePlane.getTempsAttente() < thePlane.m_trajet[0].Get_tempsAccesPiste())
        thePlane.setTempsAttente(thePlane.getTempsAttente()+1);






    else
    {
    thePlane.setDansStation(1);
    thePlane.setTempsAttente(0);
    }

    std::cout << "il est reste : " << thePlane.getTempsAttente();
     std::cout << "aeroport de maintenant = " << thePlane.m_trajet[0].Get_name() << std::endl;

}

void Simulateur::avantAtterissage(Avion &thePlane) ///6
{
  if(thePlane.getTempsAttente() < thePlane.m_trajet[0].Get_delai_att_grd()+thePlane.m_trajet[0].Get_tempsDecAtt())
        thePlane.setTempsAttente(thePlane.getTempsAttente()+1);


    ///mettre l'algo
    else
    {
    thePlane.setDansStation(4);
    thePlane.setTempsAttente(0);
    }

    std::cout << "il est reste : " << thePlane.getTempsAttente();

}

void Simulateur::lancerVol(Avion &thePlane) ///5 et 0
{

    //pour l'instant on a mis un avion dans un aeroport
    // afficher2(); //c'est confirmé
    if(thePlane.getDansStation()==5) ///
    {
    Liaison temp;
  //  std::cout << thePlane.getTrajet().size();
  //  std::cout << "aeroport de depart de : " << thePlane.Get_Nom() << " : " << thePlane.getTrajet()[0].Get_name();

  //  std::cout << std::endl;






   // std::cout << "\naeroport d'arrivee de : " << thePlane.Get_Nom() << " : " << thePlane.getTrajet()[1].Get_name();

   // std::cout << std::endl;
    ///trouver la liaison entre le 1 et le 2
    for (unsigned int k=0; k<m_liaisons.size(); k++)
        if ((thePlane.getTrajet()[0].Get_name() == m_liaisons[k].Get_aeroport1().Get_name()) && (thePlane.getTrajet()[1].Get_name() == m_liaisons[k].Get_aeroport2().Get_name()))
        {
           // std::cout << "_____________On peut faire le trajet, il a été trouvé !____________________" ;
          //  std::cout << std::endl;
          //  std::cout << std::endl << m_liaisons[k].Get_distance();
            temp=m_liaisons[k];
            thePlane.setLiaison(temp);
            thePlane.setDansStation(0);
        }




    ///on lance une simulation en temps reel

    Coordonnes new_plane = Coordonnes(thePlane.m_trajet[0].Get_gps().Get_x(),thePlane.m_trajet[0].Get_gps().Get_y());
    thePlane.Set_gps(new_plane);

    }

    float xa = thePlane.getLiaison().Get_aeroport1().Get_gps().Get_x();
    float xb = thePlane.getLiaison().Get_aeroport2().Get_gps().Get_x();
    float ya = thePlane.getLiaison().Get_aeroport1().Get_gps().Get_y();
    float yb = thePlane.getLiaison().Get_aeroport2().Get_gps().Get_y();

    int b;
    int lisa;

   // std::cout << xa << " : "<< xb << " : "<< ya << " : "<< yb;
   // std::cout << std::endl;

    if((xb-xa) == 0)
    {
        xa++;
    }

    float coeff = (yb-ya)/(xb-xa);

    if(thePlane.Get_gps().Get_x()==thePlane.getLiaison().Get_aeroport2().Get_gps().Get_x())
    {
        b = yb-ya;
      //  std::cout <<" QSDQSDQSD ";
       // std::cout << std::endl;

    }

    else
        b = ya - (coeff * xa);

  //  std::cout << "\nb : " << b << std::endl;
  //  std::cout << "coeff : " << coeff;

    int position_x = thePlane.Get_gps().Get_x();
    int position_y = thePlane.Get_gps().Get_y();


    float distance_x = sqrt(pow(xb-xa,2)+pow(yb-ya,2));
    float distance_xbxa = xb-xa;

    if(distance_xbxa <0)
        distance_xbxa = -distance_xbxa;


    float temps_voyage = float(distance_x) / thePlane.Get_vitesse();


    //  std::cout << m_avions[0].Get_vitesse();
   // std::cout << "temps en secondes" << temps_voyage;
   // std::cout << "-----------------------distance------------------ : " << distance_x;
    // std::cout << "-----------------------distance xb-xa------------------ : " << distance_xbxa;




    int position2x,position2y;

    ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    bool sortie=false;
    float angle,angle_alleg;



    if (position_y <= thePlane.getLiaison().Get_aeroport2().Get_gps().Get_y()-10 || position_y >= thePlane.getLiaison().Get_aeroport2().Get_gps().Get_y()+10)
    {


        draw_sprite(buffer, a.getImage(3), 0, 0);

       // std::cout << "avant position x : " << thePlane.Get_gps().Get_x() << " , avant position y : " << thePlane.Get_gps().Get_y() << std::endl;
        position2x = position_x;
        position2y = position_y;


        if(position_x < thePlane.getLiaison().Get_aeroport2().Get_gps().Get_x())
            position_x=position_x+COEF_DISTANCE*((distance_xbxa)/(distance_x));

        else if(position_x > thePlane.getLiaison().Get_aeroport2().Get_gps().Get_x())
            position_x=position_x-COEF_DISTANCE*((distance_xbxa)/(distance_x));


///faire x++; new y position


        if(thePlane.Get_gps().Get_x()==thePlane.getLiaison().Get_aeroport2().Get_gps().Get_x())
        {

            // std::cout << PRECISION;
            lisa = b;

            position_y = position_y + (distance_x)/COEF_DISTANCE;
           // std::cout << position_y << std::endl;
        }

        if(thePlane.Get_gps().Get_x()!= thePlane.getLiaison().Get_aeroport2().Get_gps().Get_x())
        {
            position_y = (coeff * position_x) + b;

        }


        Coordonnes temp(position_x,position_y);

        thePlane.Set_gps(temp);

        // m_plateau.m_coords.push_back(temp);


      //  delay(temps_voyage*1000/PRECISION);
        //  afficherPlateau();

      //  std::cout << "norme depuis le dernier : " << sqrt(pow(position_x-position2x,2)+pow(position_y-position2y,2));



        if(coeff>0)
            angle= 180+ atan(coeff)*180/3.14;
        else
            angle=atan(coeff)*180/3.14;

        angle_alleg=angle*0.7083333*1.00000;



        std::cout<<angle_alleg<<" "<<angle<<" \n";
        rotate_sprite(buffer, a.getImage(4), position_x, position_y, itofix(angle_alleg));///souri
        draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
      //  delay(3000);

      //  std::cout << "CACA X : " << thePlane.Get_gps().Get_x() << " , CACA Y : " << thePlane.Get_gps().Get_y() << std::endl;
    }
    else {
        ///destruction
    destroy_bitmap(buffer);
    std::cout << " TRAJET TERMINE PLACE AU SUIVANT------------------------\n\n\n\n";
    thePlane.setDansStation(6);
    thePlane.m_trajet.erase(thePlane.m_trajet.begin(),thePlane.m_trajet.begin() + 1);




    for (auto elem : thePlane.m_trajet)
        std::cout << " : " <<elem.Get_name();

    }




    ///dans temp on a aerop de depart d'arrivée et la distance
    ///on associe la liaison au trajet
    ///faire le deplacement

}
void Simulateur::lancerDij(Avion &thePlane)
{
    std::vector<std::string> m_resultat;
    m_resultat.push_back(thePlane.getTrajet()[0].Get_name());
    m_resultat.push_back(thePlane.getTrajet()[thePlane.getTrajet().size()-1].Get_name());





    std::cout << "\n------------------------------------------------------------------\n";
    m_resultat = Dijkstra(m_ordre,m_taille,m_IDgraphe,m_resultat[0],m_resultat[1]);

    for (auto elem : m_resultat)
        std::cout << " AAA:BBB " <<elem;

    std::cout << std::endl;

    ///m_resultat vecteur de string on doit trouver les aeroport associés et les push dans m_trajet

    for (unsigned int i=0 ; i<m_resultat.size(); i++)
    {
        for (unsigned int j=0 ; j<m_aeros.size(); j++)
        {
            if(m_resultat[i] == m_aeros[j].Get_name())
            {
                thePlane.m_trajet.push_back(m_aeros[j]);
            }

        }
    }


    thePlane.m_trajet.erase(thePlane.m_trajet.begin(),thePlane.m_trajet.begin() + 2);

    std::cout << "\n----------------------------DANS M_TRAJET--------------------------------------\n";

    for (auto elem : thePlane.m_trajet)
        std::cout << " 111:222 " <<elem.Get_name();

    thePlane.setDijDone(1);

    std::cout << std::endl;


    //m_avions_bougants.push_back(thePlane);



}

void Simulateur::initialiserAeroport(int choixx[2],int numAvion)
{


    int adep=choixx[0];
    int choix=choixx[1];


    m_avions[numAvion].m_trajet.clear();
    std::cout << "AEROPORT DE DEPART (New-York, Haiti, Paz, Paris, CapeTown, Bangkok, Perth) : \n\n";



    std::cout << adep;


    ///on doit avoir un int pour le vecteur d'avion et un pour le vecteur d'aeroport


    m_avions[numAvion].m_trajet.push_back(m_aeros[adep]);
    ///quand on met un avion sur un aeroport
    ///verifier que y'a de la place dans la station

    Coordonnes pourAvion(m_aeros[adep].Get_gps().Get_x(),m_aeros[adep].Get_gps().Get_y());
    m_avions[numAvion].Set_gps(pourAvion);


    for (unsigned int i=0; i<m_aeros[0].m_stations.size(); i++)
    {
        m_aeros[adep].m_stations[i].setRempli(0);

        //  std::cout << "rempli ou pas" <<  m_aeros[0].m_stations[i].getRempli() << std::endl;

    }

    ///------------------------On met l'avion choisi dans l'aeroport de depart------------------------///


    for (int i=0; i<m_aeros[0].Get_stations().size(); i++)
    {

        //    std::cout << "piste rempli  : " << i << m_aeros[0].Get_stations()[i].getRempli() << std::endl;


        if(m_aeros[0].Get_stations()[i].getRempli()==0)
        {
            std::cout << "\nNom de l'avion : " << m_avions[numAvion].Get_Nom() << std::endl;
            //  m_aeros[0].Get_stations()[i]->setAvion(m_avions[1].Get_Nom());


            m_aeros[adep].m_stations[i].setRempli(1);



            std::cout << "\n\nl'avion est mis dans la place : " << i << std::endl;


            ///------------------------Il est dans la station la plus proche de 0 dans l'aeroport------------------------///


            m_avions[numAvion].setDansStation(1);


            break;
        }
        ///la station a un avion
        ///la station est rempli
    }

    for (unsigned int i=0; i<m_aeros[0].Get_stations().size(); i++)
    {
        //  std::cout << "rempli ou pas : " <<  m_aeros[adep].m_stations[i].getRempli() << std::endl;

    }


    ///------------------------L'avion souhaite aller dans un aeroport de fin------------------------///

    std::cout << "\n\nAEROPORT DE FIN New-York, Haiti, Paz, Paris, CapeTown, Bangkok, Perth (0 a 6) : ";



    m_avions[numAvion].m_trajet.push_back(m_aeros[choix]);
    m_avions_bougants.push_back(m_avions[numAvion]);




}

///le mettre dans une place le plus proche de 0 la ou y'a de la place
///dire que l'avion est dans un aeroport de depart







