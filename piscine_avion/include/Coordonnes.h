#ifndef COORDONNES_H
#define COORDONNES_H
#include <iostream>


class Coordonnes
{
    public:
        Coordonnes();
        Coordonnes(int x, int y);
        ~Coordonnes();

        int Get_x() { return m_x; }
        void Set_x(int val) { m_x = val; }

        int Get_y() { return m_y; }
        void Set_y(int val) { m_y = val; }

        std::string Get_occupe() { return m_occupe; }
        void Set_occupe(std::string val) { m_occupe = val; }

        void afficherCoord();

    protected:

    private:
        int m_x;
        int m_y;
        int m_couleur;
        std::string m_occupe="vide"; ///vide aeroport ou avion
};

#endif // COORDONNES_H
