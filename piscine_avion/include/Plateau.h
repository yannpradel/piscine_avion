#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include <vector>

class Coordonnes;
class Plateau
{
    public:
        Plateau();
        ~Plateau();

    protected:

    private:
        std::vector<Coordonnes*> m_plateau;
};

#endif // PLATEAU_H
