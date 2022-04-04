#ifndef VOL_H
#define VOL_H
#include <iostream>
#include <Avion.h>
#include <Aeroport.h>

class Avion;
class Aeroport;

class Vol
{
    public:
        Vol();
        ~Vol();

        Avion Get_avion() { return m_avion; }
        void Set_avion(Avion val) { m_avion = val; }
        Aeroport Get_aerodepart() { return m_aerodepart; }
        void Set_aerodepart(Aeroport val) { m_aerodepart = val; }
        Aeroport Get_aeroarrivee() { return m_aeroarrivee; }
        void Set_aeroarrivee(Aeroport val) { m_aeroarrivee = val; }
        int Get_distance() { return m_distance; }
        void Set_distance(int val) { m_distance = val; }
        std::string Get_horaireDepart() { return m_horaireDepart; }
        void Set_horaireDepart(std::string val) { m_horaireDepart = val; }
        std::string Get_horaireArrivee() { return m_horaireArrivee; }
        void Set_horaireArrivee(std::string val) { m_horaireArrivee = val; }

    protected:

    private:
        Avion m_avion;
        Aeroport m_aerodepart;
        Aeroport m_aeroarrivee;
        int m_distance;
        std::string m_horaireDepart;
        std::string m_horaireArrivee;
};

#endif // VOL_H
