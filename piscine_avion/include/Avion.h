#ifndef AVION_H
#define AVION_H
#include <iostream>
#include <vector>
#include <Aeroport.h>

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

    protected:

    private:
        std::string m_type;
        int m_consommation;
        std::vector<Aeroport> m_trajet; ///je suis pas sur
        std::string m_couleur;
        std::string m_nom;
        int m_vitesse;
        int m_capacite;
        int m_altitude;
        bool m_situationUrgence;
        bool m_fuite;
};

#endif // AVION_H
