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
#define TEMPS_UT 150
#define NbIlian 13

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


void Simulateur::afficher2() ///on affiche en mode console et sur allegro toutes les carac des aeroports
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
         do
        {
        if(key[KEY_LEFT])
    {
        BITMAP* image;
        rectfill(screen,0,0,0,0,makecol(10,10,10));
        image = load_bitmap("Earth2.bmp",NULL);
        blit(image,screen,0,0,0,0,image->w,image->h);

    }
    }while(key[KEY_LEFT]);


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
    while(!key[KEY_ENTER]);


    ///destruction
    destroy_bitmap(buffer);
}


void Simulateur::load_aeroport() ///on lit le fichier qui contient les aeroports
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

std::vector<std::string> Simulateur::Dijkstra(int ordre, int taille,std::vector<std::vector<unsigned>> IDgraphe, std::string depart, std::string arrivee) ///on met en parametre un graphe un aeroport de depart et un d'arriv?e
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

void Simulateur::load_carac() ///on load les caracteristiques de tout les aeroports
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

    welsh_powell(); ///on appelle la coloration




}

void Simulateur::load_avion() ///on lit le fichier des avions
{
    int nbr_Avion = 20;
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
            //   std::cout << "Sa capacit? :" << r << std::endl;
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
///on d?finit la consommation en fonction du type d'avion

        if(m_avions[j].Get_type()== "court")
                m_avions[j].Set_consommation(0.18);
            else if(m_avions[j].Get_type()== "moyen")
                m_avions[j].Set_consommation(1.30);
            else
                m_avions[j].Set_consommation(5.00);
        }
        fichier.close();

    }

}

void Simulateur::afficherAvion() ///on affiche les avions sur la console
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

void Simulateur::afficherLiaison() ///pour afficher les liaisons de tout les avions
{
    for (unsigned int i=0; i<m_liaisons.size(); i++)
        std::cout << m_liaisons[i].Get_aeroport1().Get_name() << " : " << m_liaisons[i].Get_aeroport2().Get_name() << " --- " << m_liaisons[i].Get_distance() << std::endl;
}


void Simulateur::lancerAleatoireComplet() ///ici, tout les facteur sont aleatoire, le nombre de vol, le type d'avion, et les destinations de depart et d'arriv?e
{
    srand(time(NULL));

        int nbAvions = rand()%16+5;
    std::cout << "nombre d'avions : " << nbAvions;
    int Haiti=0;



    for(int i=0;i<nbAvions;i++)
    {
        m_avions[i].setChoisi(1);
        int choix[2];
        //
        if(m_avions[i].Get_type() == "court")
        {

        do{
            choix[0] = rand()%3;
            if(choix[0]==2)
            {
                choix[0]=3;
            }

            if(choix[0]==1)
                Haiti++;


        }while(Haiti > 5);



        do{

            choix[1] = rand()%3;
            if(choix[1]==2)
            {
                choix[1]=3;
            }


        }while(choix[1] == choix[0]);


        }

        if(m_avions[i].Get_type() == "moyen")
        {
            do{
            choix[0] = rand()%6;
            if(choix[0]==5)
            {
                choix[0]=6;
            }

            if(choix[0]==1)
                Haiti++;

            }while(Haiti > 5);

        do{

            choix[1] = rand()%6;
            if(choix[1]==5)
            {
                choix[1]=6;
            }

        }while(choix[1] == choix[0]);

        }

        if(m_avions[i].Get_type() == "long")
        {

            do{
            choix[0] = rand()%7;
            choix[1] = rand()%7;


            }while(choix[1] == choix[0]);

        }


        initialiserAeroport(choix,i);
    }

    SimuApresInit(nbAvions);
}



void Simulateur::lancerSimu()
{
    int nbVol = 0;
    int numAvion=0, nombre=0;

    bool sortie1=false, sortie2=false;





     ///BITMAPS
    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
    int compt=0;
    do
    {
        draw_sprite(buffer, a.getImage(3), 0, 0);
        textprintf_ex(buffer,a.getFont3(), 50, 75, a.getCoul(2), -1, "Nombre de vols: ");

        if(compt>0)
        {
            char b=(readkey()&0xFF);
            if((b>='0' && b<='9'))
            {
                nombre=b-48;
            }
            if(nombre!=0)
            {
                textprintf_ex(buffer, a.getFont3(), 450, 75, a.getCoul(2), -1, "%d", nombre);
            }
            if(key[KEY_ENTER] && nombre !=0)
            {
                sortie1=true;
                nbVol=nombre;
                nombre=0;
            }

        }
        if(compt==0)
            compt++;


        ///Images
        draw_sprite(screen, buffer, 0, 0);
        clear(buffer);

    }
    while(!sortie1);
    sortie1=false;
    compt=0;



    std::vector<int> elem;
    for(unsigned i = 0; i<m_aeros.size(); i++)
    {
        elem.push_back(0);
    }




    int c=0;




    do
    {



        sortie1=false;
        compt=0;
        do
        {
            draw_sprite(buffer, a.getImage(3), 0, 0);
            textprintf_ex(buffer,a.getFont3(), 50, 75, a.getCoul(2), -1, "Numero d'avion: ");

            if(compt>0)
            {
                char b=(readkey()&0xFF);
                if((b>='0' && b<='9'))
                {
                    nombre=b-48;
                }
                textprintf_ex(buffer, a.getFont3(), 450, 75, a.getCoul(2), -1, "%d", nombre);


                if(key[KEY_ENTER])
                {

                    numAvion=nombre;

                    //std::cout<<m_avions[numAvion].getChoisi()<< "  ----  ";
                    if(m_avions[numAvion].getChoisi()==0)
                        sortie1=true;
                }
            }
            if(compt==0)
                compt++;

            draw_sprite(screen, buffer, 0, 0);
            clear(buffer);

        }
        while (!sortie1);












        ///BITMAPS
        BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
        int choix[2];

        sortie2=false;
        sortie1=false;
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
    }
    while (c < nbVol);

    SimuApresInit(nbVol);
}

void Simulateur::SimuApresInit(int nbVol) ///voici la grosse boucle de simulation
{
    int Fin=0;
    int aerofin = 0; ///c'est le numero dans le vecteur aero de l'aeroport final d'un trajet
    int aerodep = 0; ///c'est le numero dans le vecteur aero de l'aeroport de depart d'un trajet

    if(m_avions_bougants.size() >= 3);
            m_avions_bougants[2].Set_fuite(true);

    BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);
    int fin=1;
    do
    {

        draw_sprite(buffer, a.getImage(3),0,0);
        fin=1;


        ///soit on reste comme ?a
        ///soit on affiche la liste de toutes les pistes et stations des aeroports avec les for en desosus
        /*
        for(unsigned i = 0; i<m_aeros.size(); i++)
        {
            for(unsigned j = 0; j<m_aeros[i].m_stations.size();j++)
            std::cout << m_aeros[i].m_stations[j].getRempli();

            for(unsigned j = 0; j<m_aeros[i].m_pistes.size();j++)
            std::cout << m_aeros[i].m_pistes[j].getRempli();
        }

        */



        for(unsigned i = 0; i<m_aeros.size(); i++)
        {


            textprintf_ex(buffer, a.getFont(), m_aeros[i].Get_gps().Get_x()+18, m_aeros[i].Get_gps().Get_y()-36, a.getCoul(2), -1, "%s", m_aero_name[i].second.c_str());
            rectfill(buffer, m_aeros[i].Get_gps().Get_x()-10, m_aeros[i].Get_gps().Get_y()-10, m_aeros[i].Get_gps().Get_x()+10, m_aeros[i].Get_gps().Get_y()+10, a.getCoul(4));
            //rect(buffer, m_aeros[i].Get_gps().Get_x()+18, m_aeros[i].Get_gps().Get_y()-36+9, m_aeros[i].Get_gps().Get_x()+18+100, m_aeros[i].Get_gps().Get_y(), a.getCoul(1));


            for(unsigned j = 0; j<m_aeros[i].m_stations.size();j++)
                textprintf_ex(buffer, a.getFont4(), m_aeros[i].Get_gps().Get_x()-120, m_aeros[i].Get_gps().Get_y()-80+10*j, a.getCoul(2), -1, "Station %2d: %2d", j, m_aeros[i].m_stations[j].getRempli()); ///j'ai modifi? la

            for(unsigned j = 0; j<m_aeros[i].m_pistes.size();j++)
                textprintf_ex(buffer, a.getFont4(), m_aeros[i].Get_gps().Get_x(), m_aeros[i].Get_gps().Get_y()-80+10*j, a.getCoul(2), -1, "Piste %2d: %2d", j, m_aeros[i].m_pistes[j].getRempli());

        }


        for (unsigned int j=0; j<m_avions_bougants.size(); j++)
        {
            for (auto elem : m_aero_name)
            {
                if (elem.second == m_avions_bougants[j].m_trajet[0].Get_name())
                    aerodep = elem.first;
            }

            for (auto elem : m_aero_name)
            {
                if (elem.second == m_avions_bougants[j].m_trajet[1].Get_name())
                    aerofin = elem.first;
            }

            textprintf_ex(buffer, a.getFont4(),m_avions_bougants[j].Get_gps().Get_x()-25, m_avions_bougants[j].Get_gps().Get_y()-50, a.getCoul(1), -1, "%2s", m_avions_bougants[j].Get_Nom().c_str());

            textprintf_ex(buffer, a.getFont4(), 0, 160-80+35*j, a.getCoul(2), -1, "Avion %2d: %2s : (%2s) - Aeroport : %2s", j, m_avions_bougants[j].Get_Nom().c_str(),m_avions_bougants[j].Get_type().c_str(),m_aeros[aerodep].Get_name().c_str()); ///j'ai modifi? la$

            if(m_avions_bougants[j].getDansStation()==0)
                textprintf_ex(buffer, a.getFont4(), 0, 170-80+35*j, a.getCoul(2), -1, "L'avion est dans les airs", j, m_avions_bougants[j].Get_Nom().c_str());

            if(m_avions_bougants[j].getDansStation()==1)
                textprintf_ex(buffer, a.getFont4(), 0, 170-80+35*j, a.getCoul(2), -1, "L'avion est dans la station", j, m_avions_bougants[j].Get_Nom().c_str());

            if(m_avions_bougants[j].getDansStation()==2)
                textprintf_ex(buffer, a.getFont4(), 0, 170-80+35*j, a.getCoul(2), -1, "L'avion est sur la piste pour decoller", j, m_avions_bougants[j].Get_Nom().c_str());

            if(m_avions_bougants[j].getDansStation()==3)
                textprintf_ex(buffer, a.getFont4(), 0, 170-80+35*j, a.getCoul(2), -1, "L'avion est dans la station et s'apprete a decoller", j, m_avions_bougants[j].Get_Nom().c_str());

            if(m_avions_bougants[j].getDansStation()==4)
                textprintf_ex(buffer, a.getFont4(), 0, 170-80+35*j, a.getCoul(2), -1, "L'avion est sur la piste et s'apprete a rentrer", j, m_avions_bougants[j].Get_Nom().c_str());

            if(m_avions_bougants[j].getDansStation()==5)
                textprintf_ex(buffer, a.getFont4(), 0, 170-80+35*j, a.getCoul(2), -1, "L'avion est en phase de decollage", j, m_avions_bougants[j].Get_Nom().c_str());

            if(m_avions_bougants[j].getDansStation()==6)
                textprintf_ex(buffer, a.getFont4(), 0, 170-80+35*j, a.getCoul(2), -1, "L'avion est en phase d'atterissage", j, m_avions_bougants[j].Get_Nom().c_str());

            if(m_avions_bougants[j].getDansStation()==7)
                textprintf_ex(buffer, a.getFont4(), 0, 170-80+35*j, a.getCoul(1), -1, "L'avion n'a plus de vol", j, m_avions_bougants[j].Get_Nom().c_str());
        }


        for (unsigned int j=0; j<m_avions_bougants.size(); j++)
        {
            for (auto elem : m_aero_name)
            {
                if (elem.second == m_avions_bougants[j].m_trajet[0].Get_name())
                    aerodep = elem.first;
            }

            for (auto elem : m_aero_name)
            {
                if (elem.second == m_avions_bougants[j].m_trajet[1].Get_name())
                    aerofin = elem.first;
            }



            ///afficherAvionAllegro();
            if(m_avions_bougants[j].Get_fuite() == true && m_avions_bougants[j].Get_capacite()<=0)
            {
                draw_sprite(buffer, a.getImage(7), m_avions_bougants[j].Get_gps().Get_x(), m_avions_bougants[j].Get_gps().Get_y());
                m_aeros[aerofin].m_stations[m_avions_bougants[j].getStationUtiliseFin()].setRempli(0);
                m_aeros[aerofin].m_pistes[m_avions_bougants[j].getPisteUtiliseFin()].setRempli(0);
                m_avions_bougants[j].setDansStation(7);
            }

            else if(m_avions_bougants[j].Get_type() == "court")
                rotate_sprite(buffer, a.getImage(4), m_avions_bougants[j].Get_gps().Get_x()-25, m_avions_bougants[j].Get_gps().Get_y()-25, itofix(m_avions_bougants[j].Get_angle_alleg()));///souri
            else if(m_avions_bougants[j].Get_type() == "moyen")
                rotate_sprite(buffer, a.getImage(5), m_avions_bougants[j].Get_gps().Get_x()-25, m_avions_bougants[j].Get_gps().Get_y()-25, itofix(m_avions_bougants[j].Get_angle_alleg()));///souri
            else
            {
                rotate_sprite(buffer, a.getImage(6), m_avions_bougants[j].Get_gps().Get_x()-25, m_avions_bougants[j].Get_gps().Get_y()-25, itofix(m_avions_bougants[j].Get_angle_alleg()));///souri

            }

        }

        for(int z=0;z<m_avions_bougants.size();z++)
                {
                    if(m_avions_bougants[z].getDansStation()!=7)
                        fin=0;
                }



        for (unsigned int j=0; j<m_avions_bougants.size(); j++)
        {



            std::cout << "-------------on avance d'un ut---------------\n\n";

            for (auto elem : m_aero_name)
            {
                if (elem.second == m_avions_bougants[j].m_trajet[0].Get_name())
                    aerodep = elem.first;
            }

            for (auto elem : m_aero_name)
            {
                if (elem.second == m_avions_bougants[j].m_trajet[1].Get_name())
                    aerofin = elem.first;
            }





            //  std::cout << i << std::endl;


            ///-------------juste il est dans la station--------------------------------------

            if(m_avions_bougants[j].getDansStation() == 1) ///dans la station
            {

                std::cout << "l'avion a une station de depart : " << m_avions_bougants[j].getAaeroportStationDepart();
                std::cout << "l'avion a une piste de depart : " << m_avions_bougants[j].getAaeroportPisteDepart();
                std::cout << "l'avion a une station d'arrivee : " << m_avions_bougants[j].getAaeroportArrivee();
                std::cout << "l'avion a une piste d'arrivee : " << m_avions_bougants[j].getAaeroportPisteArrivee();

                if(m_avions_bougants[j].getAaeroportStationDepart()==1 && m_avions_bougants[j].getAaeroportPisteDepart()==0)
                {
                    if(m_aeros[aerodep].getNombrePisteDispo() > 0 && m_avions_bougants[j].getAaeroportPisteDepart() == 0)
                    {
                        std::cout << "lavion a une station de depart mais pas de piste, on annule sa station de depart";
                        m_aeros[aerodep].m_stations[m_avions_bougants[j].getStationUtilise()].setRempli(0);
                        m_avions_bougants[j].setAeroportStationDepart(0);
                        m_avions_bougants[j].setPisteUtilise(-1);
                        m_avions_bougants[j].setStationUtilise(-1);

                    }
                }



                if(m_avions_bougants[j].m_trajet.size()<2)
                {
                    m_avions_bougants[j].setDansStation(7);
                    std::cout << "l'avion " <<m_avions_bougants[j].Get_Nom() << "  a tout fini il reste dans sa station";
                }
                else
                {





                    //si c'est la premiere fois qu'il est la
                    if(m_avions_bougants[j].getDijDone() == 0)
                    {
                        lancerDij(m_avions_bougants[j]);
                    }

                    for (auto elem : m_aero_name)
                    {
                        if (elem.second == m_avions_bougants[j].m_trajet[0].Get_name())
                            aerodep = elem.first;
                    }

                    for (auto elem : m_aero_name)
                    {
                        if (elem.second == m_avions_bougants[j].m_trajet[1].Get_name())
                            aerofin = elem.first;
                    }

                    std::cout << "aerofin : " << aerofin;
                    std::cout << "\n\naerodep : " << aerodep;



                    for (int i=0 ; i<m_avions_bougants[j].m_trajet.size(); i++)
                        std::cout << " ___ " << m_avions_bougants[j].m_trajet[i].Get_name();

                    if(m_avions_bougants[j].getPisteUtilise() == -1 && m_avions_bougants[j].getStationUtilise() == -1)
                {

                    ///------------------------On v?rifie si y'a de la place dans l'aeoport de depart sur la piste------------------------///



                    if(m_aeros[aerodep].getNombrePisteDispo() > 0 && m_avions_bougants[j].getAaeroportPisteDepart() == 0)
                    {

                        for (unsigned int i=0; i<m_aeros[aerodep].m_pistes.size(); i++)
                        {
                            if(m_aeros[aerodep].m_pistes[i].getRempli()==0)
                            {

                                std::cout << "la piste : " << i << " est libre---------------------------------------\n\n\n";

                                std::cout << "\nNom de l'avion : " << m_avions_bougants[j].Get_Nom() << std::endl;

                                std::cout << "\n\nl'avion a reserv? a l'aeroport : " << m_aeros[aerodep].Get_name() << " la piste :  "<< i << std::endl;
                                m_avions_bougants[j].setPisteUtilise(i);
                                m_avions_bougants[j].setAeroportPisteDepart(1); ///une des conditions si il peut d?coller

                                m_aeros[aerodep].m_pistes[i].setRempli(1);

                                std::cout << "voici si la piste i est rempli ou pas : " << m_aeros[aerodep].m_pistes[i].getRempli();


                                break;
                            }

                        }

                    }
                    else
                    {

                        //l'avion ne peut pas d?coller
                        m_avions_bougants[j].setAeroportPisteDepart(0); ///une des conditions si il peut d?coller
                        m_avions_bougants[j].setDansStation(1);
                        std::cout << "\n\nL'aeroport de Depart n'as pas de PISTE\n" << std::endl;
                    }

                    ///------------------------On v?rifie si y'a de la place dans l'aeoport de depart sur la station------------------------///

                    if(m_aeros[aerodep].getNombreStationDispo() > 0 && m_avions_bougants[j].getAaeroportStationDepart() == 0)
                    {
                        for (unsigned int i=0; i<m_aeros[aerodep].Get_stations().size(); i++)
                        {
                            if(m_aeros[aerodep].m_stations[i].getRempli()==0)
                            {
                                std::cout << "\nNom de l'avion : " << m_avions_bougants[j].Get_Nom() << std::endl;
                                m_aeros[aerodep].m_stations[i].setRempli(1);
                                std::cout << "\n\nl'avion a reserv? a l'aeroport : " << m_aeros[aerodep].Get_name() << " la station :  "<< i << std::endl;
                                m_avions_bougants[j].setStationUtilise(i);
                                m_avions_bougants[j].setAeroportStationDepart(1); ///une des conditions si il peut d?coller


                                break;
                            }

                        }

                    }

                    else
                    {
                        if(m_avions_bougants[j].getAaeroportPisteDepart() == 1 && m_avions_bougants[j].getAaeroportStationDepart() == 0) ///cas particulier
                        {
                            std::cout << "lavion a une piste d'arriv?e mais pas de station, on annule sa piste d'arriv?e";
                            m_aeros[aerofin].m_pistes[m_avions_bougants[j].getPisteUtilise()].setRempli(0);
                            m_avions_bougants[j].setAeroportPisteDepart(0);

                        }
                        //l'avion ne peut pas d?coller
                        m_avions_bougants[j].setAeroportStationDepart(0); ///une des conditions si il peut d?coller
                        m_avions_bougants[j].setDansStation(1);
                        std::cout << "\n\nL'aeroport de Depart n'as pas de STATION\n" << std::endl;
                    }



                }

                    ///------------------------On v?rifie si y'a de la place dans l'aeoport de fin sur la piste------------------------///

                    if(m_aeros[aerofin].getNombrePisteDispo() > 0 && m_avions_bougants[j].getAaeroportPisteArrivee() == 0 && m_avions_bougants[j].getAaeroportStationDepart() == 1 && m_avions_bougants[j].getAaeroportPisteDepart() == 1)
                    {
                        for (unsigned int i=0; i<m_aeros[aerofin].Get_pistes().size(); i++)
                        {
                            if(m_aeros[aerofin].m_pistes[i].getRempli()==0)
                            {
                                std::cout << "\nNom de l'avion : " << m_avions_bougants[j].Get_Nom() << std::endl;
                                m_aeros[aerofin].m_pistes[i].setRempli(1);
                                std::cout << "\n\nl'avion a reserv? a l'aeroport : " << m_aeros[aerofin].Get_name() << " la piste :  "<< i << std::endl;
                                m_avions_bougants[j].setAeroportPisteArrive(1);
                                m_avions_bougants[j].setPisteUtiliseFin(i);
                                break;
                            }

                        }

                    }
                    else

                    {
                        if(m_avions_bougants[j].getAaeroportArrivee() == 1 && m_avions_bougants[j].getAaeroportPisteArrivee() == 0) ///cas particulier
                        {
                            std::cout << "lavion a une station d'arriv?e mais pas de piste, on annule sa station d'arriv?e";
                            m_aeros[aerofin].m_stations[m_avions_bougants[j].getStationUtiliseFin()].setRempli(0);
                            m_avions_bougants[j].setAeroportarrive(0);

                        }

                        //l'avion ne peut pas d?coller
                        m_avions_bougants[j].setAeroportPisteArrive(0); ///une des conditions si il peut d?coller
                        m_avions_bougants[j].setDansStation(1);
                        std::cout << "\n\nL'aeroport de Fin n'as pas de PISTE\n" << std::endl;
                    }


                    ///------------------------On v?rifie si y'a de la place dans l'aeoport de fin dans une station------------------------///
                    if(m_aeros[aerofin].getNombreStationDispo() > 0 && m_avions_bougants[j].getAaeroportArrivee() == 0 && m_avions_bougants[j].getAaeroportPisteArrivee() == 1 && m_avions_bougants[j].getAaeroportStationDepart() == 1 && m_avions_bougants[j].getAaeroportPisteDepart() == 1)
                    {
                        for (unsigned int i=0; i<m_aeros[aerofin].Get_stations().size(); i++)
                        {
                            if(m_aeros[aerofin].m_stations[i].getRempli()==0)
                            {
                                std::cout << "\nNom de l'avion : " << m_avions_bougants[j].Get_Nom() << std::endl;
                                m_aeros[aerofin].m_stations[i].setRempli(1);
                                m_avions_bougants[j].setStationUtiliseFin(i);
                                std::cout << "\n\nl'avion a reserv? a l'aeroport : " << m_aeros[aerofin].Get_name() << "la station :  "<< i << std::endl;
                                m_avions_bougants[j].setAeroportarrive(1);

                                break;
                            }

                        }

                    }
                    else
                    {
                        if(m_avions_bougants[j].getAaeroportPisteArrivee() == 1 && m_avions_bougants[j].getAaeroportArrivee() == 0) ///cas particulier
                        {
                            std::cout << "lavion a une piste d'arriv?e mais pas de station, on annule sa piste d'arriv?e";
                            m_aeros[aerofin].m_pistes[m_avions_bougants[j].getPisteUtiliseFin()].setRempli(0);
                            m_avions_bougants[j].setAeroportPisteArrive(0);

                        }

                        //l'avion ne peut pas d?coller
                        m_avions_bougants[j].setAeroportarrive(0); ///une des conditions si il peut d?coller
                        m_avions_bougants[j].setDansStation(1);
                        std::cout << "\n\nl'aeroport de FIN n'as pas de place il ne peut pas d?coller\n\n" << std::endl;
                    }





                    m_avions_bougants[j].afficherDansStation();
                    std::cout << m_avions_bougants[j].getAaeroportArrivee() << "-----------" << m_avions_bougants[j].getAaeroportPisteDepart() << "-----------" << m_avions_bougants[j].getAaeroportPisteArrivee() << "-----------";

                    if(m_avions_bougants[j].getAaeroportArrivee()==1 && m_avions_bougants[j].getAaeroportPisteDepart()==1 && m_avions_bougants[j].getAaeroportPisteArrivee()==1 && m_avions_bougants[j].getAaeroportStationDepart()==1)
                        mettreVersLaPiste(m_avions_bougants[j]);

                    else
                    {
                        if(m_avions_bougants[j].m_trajet.size() == 1)
                           {
                        m_avions_bougants[j].setDansStation(7);

                        std::cout << "l'avion " <<m_avions_bougants[j].Get_Nom() << "  a tout fini il reste dans sa station";

                           }
                        else{
                        std::cout << "l'avion ne peux pas decoller, DSL :)\n\n";

                        m_aeros[aerodep].m_pistes[m_avions_bougants[j].getPisteUtilise()].setRempli(0);
                        }





                }
                //il est dans une station et soit il y reste, soit il peut d?coller du coup
                //apres il va sur une piste son num passe a deux et quand il d?collle c'est a 0
            }
            }


            if(m_avions_bougants[j].getDansStation() == 3) ///dans la station et s'apprete a aller sur la piste il charge les passagers
            {
                m_avions_bougants[j].afficherDansStation();
                m_aeros[aerodep].m_pistes[m_avions_bougants[j].getPisteUtilise()].setRempli(1);
                ///mettre dans la piste

                mettreSurPiste(m_avions_bougants[j]);
            }

            if(m_avions_bougants[j].getDansStation() == 4) ///dans la piste pour rentrer dans la station
            {
                m_avions_bougants[j].afficherDansStation();
                rentrerAvion(m_avions_bougants[j]);
            }

            if(m_avions_bougants[j].getDansStation() == 2) ///dans la piste pour d?coller
            {
                m_avions_bougants[j].afficherDansStation();
                faireDecoller(m_avions_bougants[j]);
            }

            if(m_avions_bougants[j].getDansStation() == 5) ///avant le d?collage
            {
                std::cout << "------------------5------------------";
                m_avions_bougants[j].afficherDansStation();

                std::cout << "station de depart : " << m_avions_bougants[j].getStationUtilise();
                std::cout << "\n\nstation de fin : " << m_avions_bougants[j].getStationUtiliseFin();
                std::cout << "\nl'aeroport de depart :" <<  m_aeros[aerodep].Get_name();
                std::cout << "\n\npiste de depart : " << m_avions_bougants[j].getPisteUtilise();
                std::cout << "\n\npiste de depart : " << m_avions_bougants[j].getPisteUtiliseFin();
                std::cout << "\nl'aeroport de fin :" <<  m_aeros[aerofin].Get_name();



                m_aeros[aerofin].m_stations[m_avions_bougants[j].getStationUtiliseFin()].setRempli(1);
                m_aeros[aerofin].m_pistes[m_avions_bougants[j].getPisteUtiliseFin()].setRempli(1);

                m_aeros[aerodep].m_stations[m_avions_bougants[j].getStationUtilise()].setRempli(0);
                m_aeros[aerodep].m_pistes[m_avions_bougants[j].getPisteUtilise()].setRempli(0);

                lancerVol(m_avions_bougants[j]);


            }

            if(m_avions_bougants[j].getDansStation() == 6) ///pendant l'atterissage il decharge les passagers
            {
                std::cout << "------------------6------------------";
                m_avions_bougants[j].afficherDansStation();
                avantAtterissage(m_avions_bougants[j]);
            }

            if(m_avions_bougants[j].getDansStation() == 0) ///dans les airs
            {
                m_avions_bougants[j].afficherDansStation();
                lancerVol(m_avions_bougants[j]);
            }

            if(m_avions_bougants[j].getDansStation() == 7) ///dans la station sans vol pr?vu
            {
                if(m_avions_bougants[j].getToutFini() == 0){
                m_aeros[aerodep].m_pistes[m_avions_bougants[j].getPisteUtilise()].setRempli(0);

                std::cout << "c'est la premiere fois qu'il fini son trajet";
                }



                m_avions_bougants[j].setToutFini(1);

                m_avions_bougants[j].afficherDansStation();


               // m_aeros[aerodep].m_stations[m_avions_bougants[j].getStationUtilise()].setRempli(1);
                std::cout << "L'avion n'a plus de vol";
                m_avions_bougants[j].setDijDone(0);


            }

             if(m_avions_bougants[j].getDansStation() == 8)
             {
                 accesAuPiste(m_avions_bougants[j]);
             }


            for (auto elem : m_aero_name)
            {
                if (elem.second == m_avions_bougants[j].m_trajet[0].Get_name())
                    aerodep = elem.first;
            }

            for (auto elem : m_aero_name)
            {
                if (elem.second == m_avions_bougants[j].m_trajet[1].Get_name())
                    aerofin = elem.first;
            }




            m_aeros[aerodep].afficherStations();
            m_aeros[aerodep].afficherPistes();

            m_aeros[aerofin].afficherStations();
            m_aeros[aerofin].afficherPistes();



            ///on doit lancer plusieurs fois vol
            // lancerVol(m_avions_bougants[j]);
           // delay(200);

        }
        // delay(25)


    draw_sprite(screen, buffer, 0, 0);
    clear(buffer);
    delay(TEMPS_UT/nbVol);

    }
    while(fin == 0);
   // destroy_bitmap(buffer);

}



void Simulateur::mettreVersLaPiste(Avion &thePlane) /// transi entre 1 et 3

{

    std::cout << std::endl;
    std::cout << std::endl;

    ///mettre l'algo

    thePlane.setDansStation(3);

}

void Simulateur::accesAuPiste(Avion &thePlane)

{

        thePlane.setDansStation(2);




     std::cout << "il est reste : " << thePlane.getTempsAttente();








    std::cout << std::endl;
    std::cout << std::endl;

    ///mettre l'algo



}

void Simulateur::mettreSurPiste(Avion &thePlane) ///3
{


    ///mettre l'algo
    if(thePlane.getTempsAttente() < thePlane.m_trajet[0].Get_tempsAccesPiste())
        thePlane.setTempsAttente(thePlane.getTempsAttente()+1);




    else
    {
        thePlane.setDansStation(8);
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

    int aerodep;
    for(auto elem : m_aero_name)
    {
        if (elem.second == thePlane.m_trajet[0].Get_name())
            aerodep = elem.first;
    }

    int  val_add = 0;
    val_add = 500*(m_aeros[aerodep].Get_alt());


    if(thePlane.Get_type() == "court")
    {
        thePlane.Set_altitude(3500+val_add);
        thePlane.Set_capacite(1000);
    }
    else if(thePlane.Get_type() == "moyen")
    {
        thePlane.Set_altitude(6500+val_add);
        thePlane.Set_capacite(15000);
    }
    else
    {
        thePlane.Set_altitude(10500+val_add);
        thePlane.Set_capacite(75000);
    }

    std::cout << "\n\n indice_aero = " << m_aeros[aerodep].Get_alt();
    std::cout << "\n altitude = " << thePlane.Get_altitude() << "\n" "\n";

}

void Simulateur::rentrerAvion(Avion &thePlane) ///4
{
    std::cout << "AVANT , voici la piste utilis? par l'avion : " << thePlane.getPisteUtilise();
    std::cout << "\n\nvoici la station utilis? par l'avion : " << thePlane.getStationUtilise();

    if(thePlane.getTempsAttente() < thePlane.m_trajet[0].Get_tempsAccesPiste())
        thePlane.setTempsAttente(thePlane.getTempsAttente()+1);








    else
    {
        int aerodep;

        for (auto elem : m_aero_name)
        {
            if (elem.second == thePlane.m_trajet[0].Get_name())
                aerodep = elem.first;
        }





        std::cout << "voici la piste utilis? par l'avion : " << thePlane.getPisteUtilise() << "dans l'aeroport  ! " <<  m_aeros[aerodep].Get_name();
        std::cout << "\n\nvoici la station utilis? par l'avion : " << thePlane.getStationUtilise();

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
    // afficher2(); //c'est confirm?
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
                // std::cout << "_____________On peut faire le trajet, il a ?t? trouv? !____________________" ;
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
        std::cout << "\n \n ----------- CONSOMMATION = " << thePlane.Get_consommation();
        std::cout << "\n ----------- CAPACITE = " << thePlane.Get_capacite() << "\n \n";

        thePlane.Set_capacite(thePlane.Get_capacite()-(118*thePlane.Get_consommation()));

        ///pour fuite reservoir
        if(thePlane.Get_type()=="court")
        {
            if(thePlane.Get_fuite() == true && thePlane.Get_capacite() <= 0)
                return;
            else if(thePlane.Get_fuite() == true && thePlane.Get_capacite() <= 750)
            {
                fuite_reservoir(thePlane);
                thePlane.Set_capacite(thePlane.Get_capacite()-(118*thePlane.Get_consommation()));
            }
        }
        else if(thePlane.Get_type()=="moyen")
        {
            if(thePlane.Get_fuite() == true && thePlane.Get_capacite() <= 0)
                return;
            else if(thePlane.Get_fuite() == true && thePlane.Get_capacite() <= 12000)
            {
                fuite_reservoir(thePlane);
                thePlane.Set_capacite(thePlane.Get_capacite()-(118*thePlane.Get_consommation()));
            }
        }
        if(thePlane.Get_type()=="long")
        {
            if(thePlane.Get_fuite() == true && thePlane.Get_capacite() <= 0)
                return;
            else if(thePlane.Get_fuite() == true && thePlane.Get_capacite() <= 60000)
            {
                fuite_reservoir(thePlane);
                thePlane.Set_capacite(thePlane.Get_capacite()-(118*thePlane.Get_consommation()));
            }
        }


       // draw_sprite(buffer, a.getImage(3), 0, 0);

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
            if(thePlane.Get_gps().Get_y() < thePlane.getLiaison().Get_aeroport2().Get_gps().Get_y())
            position_y = position_y + (distance_x)/COEF_DISTANCE;
            else
            position_y = position_y - (distance_x)/COEF_DISTANCE;

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




        std::cout<<"----->"<<coeff<<"-<--- ";


        angle=atan(coeff)*180/3.14;

        if(xb<xa && yb<ya)
            angle=angle+180;
        if(xa>xb && yb>ya)
            angle=angle+180;

        angle_alleg=angle*0.7083333*1.00000;

        thePlane.Set_angle_alleg(angle_alleg);



        std::cout<<angle_alleg<<" "<<angle<<" \n";
      //  rotate_sprite(buffer, a.getImage(4), position_x, position_y, itofix(angle_alleg));///souri
      //  draw_sprite(screen, buffer, 0, 0);
      //  clear(buffer);
        //  delay(3000);


        std::cout << "\n \n ----------- CONSOMMATION = " << thePlane.Get_consommation();
        std::cout << "\n ----------- CAPACITE = " << thePlane.Get_capacite() << "\n \n";

        thePlane.Set_capacite(thePlane.Get_capacite()-(118*thePlane.Get_consommation()));
    }
    else
    {
        ///destruction
      //  destroy_bitmap(buffer);
        std::cout << " TRAJET TERMINE PLACE AU SUIVANT------------------------\n\n\n\n";

        thePlane.setDansStation(6);
        thePlane.m_trajet.erase(thePlane.m_trajet.begin(),thePlane.m_trajet.begin() + 1);



        thePlane.setStationUtilise(thePlane.getStationUtiliseFin());
        thePlane.setPisteUtilise(thePlane.getPisteUtiliseFin());




        for (auto elem : thePlane.m_trajet)
            std::cout << " : " <<elem.Get_name();

    }




    ///dans temp on a aerop de depart d'arriv?e et la distance
    ///on associe la liaison au trajet
    ///faire le deplacement

}
void Simulateur::lancerDij(Avion &thePlane)
{


    std::vector<std::string> m_resultat;
    m_resultat.push_back(thePlane.getTrajet()[0].Get_name());
    m_resultat.push_back(thePlane.getTrajet()[thePlane.getTrajet().size()-1].Get_name());


    if(thePlane.Get_type() == "moyen"){
        thePlane.loadAeroportMoyen();
        m_resultat = Dijkstra(thePlane.GetOrdre(),thePlane.GetTaille(),thePlane.GetIDgraphe(),m_resultat[0],m_resultat[1]);
    }
    else
    m_resultat = Dijkstra(m_ordre,m_taille,m_IDgraphe,m_resultat[0],m_resultat[1]);

    for (auto elem : m_resultat)
        std::cout << " AAA:BBB " <<elem;

    std::cout << std::endl;

    ///m_resultat vecteur de string on doit trouver les aeroport associ?s et les push dans m_trajet

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


    m_avions[numAvion].m_trajet.push_back(m_aeros[adep]);

    Coordonnes pourAvion(m_aeros[adep].Get_gps().Get_x(),m_aeros[adep].Get_gps().Get_y());
    m_avions[numAvion].Set_gps(pourAvion);




    ///------------------------L'avion souhaite aller dans un aeroport de fin------------------------///

    std::cout << "\n\nAEROPORT DE FIN New-York, Haiti, Paz, Paris, CapeTown, Bangkok, Perth (0 a 6) : ";



    m_avions[numAvion].m_trajet.push_back(m_aeros[choix]);
    m_avions[numAvion].setDansStation(1);
    m_avions_bougants.push_back(m_avions[numAvion]);




}

void Simulateur::welsh_powell()
{
    std::cout << "pipiiiiiiiiiiiiiiiiiiiiiiiiiii" << "\n";
    std::cout << m_aeros_liaisons.size() << "\n";

    std::vector<std::pair<unsigned int, unsigned int>> aeros_connexites;
    int compteur = 0, compteur_precedent = 0, cmpt_c = 0;

    for(int i = 0; i<=m_aeros_liaisons.size(); i++)//parcour du vecteur de liaons entre aeroports
    {
        //std::cout << m_aeros_liaisons[i].first << " : " << m_aeros_liaisons[i].second << "\n";
        compteur_precedent = compteur;
        compteur = m_aeros_liaisons[i].first;

        if(compteur_precedent != compteur)  //si changement d'aeroport
        {
            //init pair pour vecteur temporaire de pair
            std::pair<int, int> a;
            a.first = 0; a.second = 0;
            aeros_connexites.push_back(a);

            //1er element du vecteur de pair temportaire = le poids
            aeros_connexites[compteur_precedent].second = compteur_precedent;
            //2eme element du vecteur de pair temportaire = l'aeroport
            aeros_connexites[compteur_precedent].first = cmpt_c;
            cmpt_c = 1;
        }
        else
            cmpt_c++;
    }

/*
    for(int i =0; i < aeros_connexites.size(); i++)
    {
        std::cout << aeros_connexites[i].first << " : " << aeros_connexites[i].second << "\n";
    }
*/
    std::sort(aeros_connexites.rbegin(), aeros_connexites.rend());

    //std::cout << "-------------------------" << "\n";

    for(int i =0; i < aeros_connexites.size(); i++)
    {
        std::cout << aeros_connexites[i].first << " : " << aeros_connexites[i].second << "\n";
    }

    int k = 0, cc = 0;

    do
    {
        int compteur_couleur = 0;

        for(int i = 0; i<m_aeros.size(); i++)
        {
            int compteur_couleur = 0;
            if(m_aeros[aeros_connexites[i].second].Get_alt()==0)//si l'aeroport n'est pas traite
            {
                int a = -1;

                do//trouver l'indice d'o?? commencer
                {
                    a++;
                    std::cout << " a : " << a << "\n";
                    std::cout << " b : " << m_aeros_liaisons[a].first << "\n";
                }while(m_aeros_liaisons[a].first != aeros_connexites[i].second);

    std::cout << " aaa : " << a << "\n";

                for(int j = a; j<a + aeros_connexites[i].first; j++)//on verifie les n nombre de connexitees de l'aeroport
                {
                    std::cout << "aeroport d'arrive : " << m_aeros_liaisons[j].second << "\n";
                    if(m_aeros[m_aeros_liaisons[j].second].Get_alt()!=k+1)
                    {
                        compteur_couleur++;
                        //m_aeros[m_aeros_liaisons[j].second].Set_alt(1);
                       // compteur_couleur++;
                    }
                }

                std::cout << "nombre de compteur : " << compteur_couleur << "\n";
                std::cout << "nombre de connexite : " << aeros_connexites[i].first << "\n";

                if(compteur_couleur == aeros_connexites[i].first)//si tous les aeroports connexes pas de la couleur
                {
                    std::cout << "aeroport changement couleur  : " << aeros_connexites[i].second << "\n";
                    m_aeros[aeros_connexites[i].second].Set_alt(k+1);   //alors on applique la couleur
                    cc++;
                }

            }
            std::cout << "COULEUR AEROPORT ACTUEL : " << m_aeros[aeros_connexites[i].second].Get_alt() << "\n";
        }

        k = (k+1);
    }
    while(cc!=m_aeros.size());

    for(int i = 0; i<m_aeros.size(); i++)
    {
        std::cout << m_aeros[i].Get_alt() << "\n";
    }
}

void Simulateur::fuite_reservoir(Avion &thePlane)
{
    int recup = 0;
    unsigned int res = 0, tempo = 20000;

    //recherche la distance minimale entre l'avion et les aeroports
    for(int i = 0; i<m_aeros.size(); i++)
    {
        res = sqrt(pow((m_aeros[i].Get_gps().Get_x()-thePlane.Get_gps().Get_x()),2) + pow((m_aeros[i].Get_gps().Get_y()-thePlane.Get_gps().Get_y()),2));
        if(res<tempo)
        {
            tempo = res;
            recup = i;
        }

        std::cout << "\n \n res = " << res << " tempo : " << tempo << " recup : " << recup << "\n";
    }

    thePlane.Set_capacite(thePlane.Get_capacite()-50);
    std::cout << "\n AEROPORT LE PLUS PROCHE : " << m_aeros[recup].Get_name() << "\n";
}

std::vector<Liaison> Simulateur::Kruskal()
{


    std::vector<Liaison> liaisons;
    std::vector<Aeroport*> aeros;
    int taille,ordre;
    std::string nomFichier = "graphebis.txt";

    std::ifstream ifs{nomFichier};
    if (!ifs)
        throw std::runtime_error( "Impossible d'ouvrir en lecture " + nomFichier );

    ifs >> ordre;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture ordre du graphe");


    int num;
    std::string numbis;
    for (int i=0; i < ordre; ++i)
    {
        ifs>>num>>numbis;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture sommets");
        aeros.push_back(new Aeroport(num, numbis));

    }


    ifs >> taille;
    if ( ifs.fail() )
        throw std::runtime_error("Probleme lecture taille du graphe");

    //std::string num1,num2;
    int num1,num2;
    int num3;
    for(int i=0; i < taille; i++)
    {
        ifs>>num1;
        //ifs>>num1bis;
        ifs>>num2;
        //ifs>>num2bis;
        ifs>>num3;
        std::cout << num1 << "   " <<   num2 << "    " << num3 << std::endl;
        if ( ifs.fail() )
            throw std::runtime_error("Probleme lecture arc du graphe");


        liaisons.push_back(Liaison(aeros[num1],aeros[num2],num3));


    }

    std::cout<<std::endl<<"graphe :" << std::endl;
    std::cout<<"\tordre = "<<ordre<<std::endl;//<<"  ";
    std::cout<<"\tlistes d'adjacence :"<<std::endl;

    for(int i=0; i < ordre; i++)
    {
     std::cout<< aeros[i]->getNum()<<std::endl;
    }
    /* for (auto couple : aeros)
    {
       std::cout<<couple->Get_name() << " - "  << couple->getNum()<< std::endl;

    }*/

    for (auto couple : liaisons)
    {

       std::cout<<"("<<couple.Get_aero1()->Get_name()<< ")" <<" - ("<<couple.Get_aero2()->Get_name()<< ")"<< "  : " <<couple.Get_distance()<< std::endl;;

    }

    int nbArete=0;
    std::vector<Liaison> resultat;



    for (size_t i = 0; i < liaisons.size()-1 ; ++i)   ///trier
    {
        for (size_t j = 0; j < liaisons.size() - i - 1; ++j)
        {
            if (liaisons[j].Get_distance() > liaisons[j+1].Get_distance())
                std::swap(liaisons[j], liaisons[j+1]);
        }
    } ///trier

    for (int i = 0 ; i < aeros.size(); i++)
    {
        aeros[i]->setNumComposanteConnexe(i);
        // std::cout<<  aeros[i]->getNumComposanteConnexe() << std::endl;
    }


    /*for(int i = 0 ; i < (int)liaisons.size(); i++)
    {
        std::cout << liaisons[i].Get_aero1()->getNumComposanteConnexe() << liaisons[i].Get_aero2()->getNumComposanteConnexe() << std::endl;
    }*/

    for(int i = 0 ; i < (int)liaisons.size(); i++)
    {
        if(liaisons[i].Get_aero1()->getNumComposanteConnexe() != liaisons[i].Get_aero2()->getNumComposanteConnexe())
        {
            resultat.push_back(liaisons[i]);
            nbArete++;

            int valCCAChanger = liaisons[i].Get_aero2()->getNumComposanteConnexe();

            for (auto elem : aeros)
            {
                if(elem->getNumComposanteConnexe() == valCCAChanger)
                {

                    elem->setNumComposanteConnexe(liaisons[i].Get_aero1()->getNumComposanteConnexe());

                }
            }

            if(nbArete == m_ordre-1)
            {
                break;
            }

        }

    }

     for (size_t i = 0; i < resultat.size()-1 ; ++i)   ///trier
    {
        for (size_t j = 0; j < resultat.size() - i - 1; ++j)
        {
            if (resultat[j].Get_aero1()->getNum() > resultat[j+1].Get_aero1()->getNum())
                std::swap(resultat[j], resultat[j+1]);
        }
    }

    for(int i = 0; i < (int)resultat.size(); i++)
    {
        std::cout << "   " << std::endl;
        std::cout << resultat[i].Get_aero1()->Get_name() << " - " << resultat[i].Get_aero2()->Get_name() << " : " << resultat[i].Get_distance() << std::endl;
        std::cout << resultat[i].Get_aero2()->Get_name() << " - "  << resultat[i].Get_aero1()->Get_name() << " : " << resultat[i].Get_distance() << std::endl;

    }


    /*std::string fichier("grap.txt");
    std::ofstream monFlux(fichier.c_str());



     int tailleBis = ((int)resultat.size())*2;

    std::cout << tailleBis << std::endl;

    if(monFlux)
    {
         monFlux << ordre<<std::endl;

         for(int i = 0; i< (int)aeros.size();i++)
         {
             monFlux << aeros[i]->getNum() << std::endl;
         }
         monFlux << tailleBis<< std::endl;
         for(int i = 0; i < (int)resultat.size(); i++)
         {


             monFlux  << resultat[i].Get_aero1()->getNum() << "  " <<resultat[i].Get_aero2()->getNum() << "  " << resultat[i].Get_distance() << std::endl;

             monFlux  << resultat[i].Get_aero2()->getNum() << "  "  << resultat[i].Get_aero1()->getNum() << "  " << resultat[i].Get_distance() << std::endl;

         }

    }
    else
    {
       std::cout << "ERREUR : Impossible d'ouvrir le fichier" << std::endl;

    }
    */
     return resultat;

}






///le mettre dans une place le plus proche de 0 la ou y'a de la place
///dire que l'avion est dans un aeroport de depart







