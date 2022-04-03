#ifndef AEROPORT_H
#define AEROPORT_H
#include <iostream>
#include <vector>

class Coordonnes;
class Piste;
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

    protected:

    private:
        std::string m_name;
        Coordonnes* m_gps;
        int m_delaiAntiCol;
        int m_tempsAccesPiste;
        int m_tempsDecAtt;
        int m_dureeBoucleAtt;
        std::vector<Piste*> m_pistes;
        std::vector<Station*> m_stations;
};

#endif // AEROPORT_H
