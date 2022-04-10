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

        int getAaeroportPisteArrivee(){return m_a_aeroport_piste_arrivee;}
        void setAeroportPisteArrive(int a){m_a_aeroport_piste_arrivee = a;}

        int getAaeroportStationDepart(){return m_a_aeroport_station_depart;}
        void setAeroportStationDepart(int a){m_a_aeroport_station_depart = a;}

        int getAaeroportPisteDepart(){return m_a_aeroport_piste_depart;}
        void setAeroportPisteDepart(int a){m_a_aeroport_piste_depart = a;}

        Liaison getLiaison(){return m_liaisonActuelle;}
        void setLiaison( Liaison a){m_liaisonActuelle = a;}

        int getChoisi(){return m_choisi;}
        void setChoisi(int a){m_choisi=a;}

        void afficherDansStation();

        int getTempsAttente(){return m_tempsAttentePourPiste;}
        void setTempsAttente(int a){m_tempsAttentePourPiste=a;}

        void setDijDone(int a){m_DijDone=a;}
        int getDijDone(){return m_DijDone;}

        int getPisteUtilise(){return m_piste_utilise;}
        void setPisteUtilise(int a){m_piste_utilise = a;}

        int getStationUtilise(){return m_station_utilise;}
        void setStationUtilise(int a){m_station_utilise = a;}

        int getPisteUtiliseFin(){return m_piste_utilise_fin;}
        void setPisteUtiliseFin(int a){m_piste_utilise_fin = a;}

        int getStationUtiliseFin(){return m_station_utilise_fin;}
        void setStationUtiliseFin(int a){m_station_utilise_fin = a;}

        float Get_angle_alleg() {return m_angle_alleg;}
        void Set_angle_alleg(float val) {m_angle_alleg = val;}

        int getToutFini(){return m_tout_fini;}
        void setToutFini(int a){m_tout_fini = a;}

        std::vector<std::vector<unsigned>> GetIDgraphe() { return m_IDgraphe;}
        void SetIDgraphe(std::vector<std::vector<unsigned>> IDgraphe) { m_IDgraphe = IDgraphe;}

        int GetOrdre() { return m_ordre ;}
        int GetTaille() { return m_taille; }

        void loadAeroportMoyen();

        int getGood() { return m_good ;}
        void setGood(int a) { m_good = a; }



    protected:

    private:
        bool m_fuite = false;
        int m_good = 0;
        std::vector<int> m_distance;
        std::vector<std::vector<unsigned>> m_IDgraphe;
        int m_ordre;
        int m_taille;

        std::string m_type;
        Coordonnes m_gps;
        float m_consommation;
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


        Liaison m_liaisonActuelle;

        int m_a_aeroport_arrivee=0; ///juste des 0 et 1 les conditions de decol
        int m_a_aeroport_station_depart=0;
        int m_a_aeroport_piste_depart=0;
        int m_a_aeroport_piste_arrivee=0;///juste des 0 et 1 les conditions de decol

        int m_piste_utilise = -1; ///au depart
        int m_station_utilise = -1;

        int m_piste_utilise_fin;
        int m_station_utilise_fin;///au fin

        int m_choisi = 0;

        int m_tempsAttentePourPiste = 0;
        int m_DijDone = 0;

        float m_angle_alleg;

        int m_tout_fini = 0;


        ///en fonction de l'état de l'avion, il faut quand meme faire avancer d'un ut






};

#endif // AVION_H
