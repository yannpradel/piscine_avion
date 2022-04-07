#ifndef AVION_H
#define AVION_H

#include <Liaison.h>



class Liaison;
class Aeroport;
class Avion
{
    public:
        Avion();
        ~Avion();



        std::string Get_type() { return m_type; }
        void Set_type(std::string val) { m_type = val; }

        std::string Get_Couleur() { return m_couleur; }
        void Set_Couleur(std::string _couleur) { m_couleur = _couleur; }

        std::string Get_Nom() { return m_nom; }
        void Set_Nom(std::string _nom) { m_nom = _nom; }

        Coordonnes Get_gps() { return m_gps; }
        void Set_gps(Coordonnes val) { m_gps = val; }

        int Get_consommation() { return m_consommation; }
        void Set_consommation(int val) { m_consommation = val; }

        int Get_vitesse() { return m_vitesse; }
        void Set_vitesse(int val) { m_vitesse = val; }

        int Get_capacite() { return m_capacite; }
        void Set_capacite(int val) { m_capacite = val; }

        int Get_altitude() { return m_altitude; }
        void Set_altitude(int val) { m_altitude = val; }

        bool Get_situationUrgence() { return m_situationUrgence; }
        void Set_situationUrgence(bool val) { m_situationUrgence = val; }

        bool Get_fuite() { return m_fuite; }
        void Set_fuite(bool val) { m_fuite = val; }

        std::vector<Aeroport> getTrajet(){return m_trajet;}
        void setTrajet(std::vector<Aeroport> _trajet){m_trajet = _trajet;}

        int calculTemps(int distance);

        std::vector<Aeroport> m_trajet;

        void setDansStation(int a){m_dansStation = a;}
        int getDansStation(){return m_dansStation;}

        int getAaeroportArrivee(){return m_a_aeroport_arrivee;}
        void setAeroportarrive(int a){m_a_aeroport_arrivee = a;}

        Liaison getLiaison(){return m_liaisonActuelle;}
        void setLiaison( Liaison a){m_liaisonActuelle = a;}



    protected:

    private:
        std::string m_type;
        Coordonnes m_gps;
        int m_consommation;
         ///le premier c'est depart et le dernier arrivée (c'est chiant))

        int m_dansStation = 0; //0 vol 1 station 2 piste


        ///calculer coord a chaque instant if coord x avion < x arrivée x++;
        //faire une fonction qui incremente y et x une fois
        std::string m_couleur;
        std::string m_nom;
        int m_vitesse = 100;
        int m_capacite;
        int m_altitude;
        bool m_situationUrgence;
        bool m_fuite;

        Liaison m_liaisonActuelle;

        int m_a_aeroport_arrivee;


        ///en fonction de l'état de l'avion, il faut quand meme faire avancer d'un ut






};

#endif // AVION_H
