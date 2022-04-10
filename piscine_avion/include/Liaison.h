#ifndef LIAISON_H
#define LIAISON_H
#include <Aeroport.h>

class Aeroport;

class Liaison
{
    public:
        Liaison();
        Liaison(int un, int deux, int distance);
        Liaison(Aeroport un, Aeroport deux, int distance);
        Liaison(Aeroport* un, Aeroport* deux, int distance);
        ~Liaison();

         Aeroport* Get_aero1() { return m_aero1; }
        void Set_aero1(Aeroport* val) { m_aero1 = val; }
        Aeroport* Get_aero2() { return m_aero2; }
        void Set_aero2(Aeroport* val) { m_aero2 = val; }


        Aeroport Get_aeroport1() { return m_aeroport1; }
        void Set_aeroport1(Aeroport val) { m_aeroport1 = val; }
        Aeroport Get_aeroport2() { return m_aeroport2; }
        void Set_aeroport2(Aeroport val) { m_aeroport2 = val; }
        int Get_distance() { return m_distance; }
        void Set_distance(int val) { m_distance = val; }

        int get1(){return m_1_t;}
        int get2(){return m_2_t;}

    protected:

    private:


        Aeroport m_aeroport1;
        int m_1_t;
        Aeroport m_aeroport2;
        int m_2_t;

        Aeroport *m_aero1,*m_aero2;

        int m_distance;
};

#endif // LIAISON_H
