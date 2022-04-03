#ifndef LIAISON_H
#define LIAISON_H

class Aeroport;

class Liaison
{
    public:
        Liaison();
        ~Liaison();

        Aeroport* Get_aeroport1() { return m_aeroport1; }
        void Set_aeroport1(Aeroport* val) { m_aeroport1 = val; }
        Aeroport* Get_aeroport2() { return m_aeroport2; }
        void Set_aeroport2(Aeroport* val) { m_aeroport2 = val; }
        int Get_distance() { return m_distance; }
        void Set_distance(int val) { m_distance = val; }

    protected:

    private:
        Aeroport* m_aeroport1;
        Aeroport* m_aeroport2;
        int m_distance;
};

#endif // LIAISON_H
