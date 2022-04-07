#ifndef AEROPORT_H
#define AEROPORT_H
#include <iostream>
#include <vector>
#include "Coordonnes.h"
#include "Piste.h"
#include <Station.h>



class Coordonnes;
class Station;


class Aeroport
{
    public:
        Aeroport();
        ~Aeroport();

        std::string Get_name() { return m_name; }
        void Set_name(std::string val) { m_name = val; }

        int Get_delaiAntiCol() { return m_delaiAntiCol; }
        void Set_delaiAntiCol(int val) { m_delaiAntiCol = val; }

        int Get_tempsAccesPiste() { return m_tempsAccesPiste; }
        void Set_tempsAccesPiste(int val) { m_tempsAccesPiste = val; }

        int Get_tempsDecAtt() { return m_tempsDecAtt; }
        void Set_tempsDecAtt(int val) { m_tempsDecAtt = val; }

        int Get_dureeBoucleAtt() { return m_dureeBoucleAtt; }
        void Set_dureeBoucleAtt(int val) { m_dureeBoucleAtt = val; }

        Coordonnes Get_gps() { return m_gps; }
        void Set_gps(Coordonnes val) { m_gps = val; }

        std::vector<Piste> Get_pistes() {return m_pistes;}
        void Set_pistes(std::vector<Piste> pistes) { m_pistes = pistes; }

        int Get_nbr_pistes() { return m_nbr_pistes; }
        void Set_nbr_pistes(int val) { m_nbr_pistes = val; }

        std::vector<Station> Get_stations() {return m_stations;}
        void Set_stations(std::vector<Station> stations) { m_stations = stations; }

        int Get_places_park() { return m_places_park; }
        void Set_places_park(int val) { m_places_park = val; }

        int Get_delai_att_grd() { return m_delai_att_grd; }
        void Set_delai_att_grd(int val) { m_delai_att_grd = val; }

        int getNombreStationDispo();

std::vector<Station> m_stations;


    protected:

    private:
        int id;
        int m_nbr_pistes;
        int m_places_park;
        int m_delai_att_grd;
        std::string m_name;
        Coordonnes m_gps;
        int m_delaiAntiCol;
        int m_tempsAccesPiste;
        int m_tempsDecAtt;
        int m_dureeBoucleAtt;
        std::vector<Piste> m_pistes;



};

#endif // AEROPORT_H
