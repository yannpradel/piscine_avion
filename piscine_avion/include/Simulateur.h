#ifndef SIMULATEUR_H
#define SIMULATEUR_H
#include <vector>

class Simulateur
{
    public:
        Simulateur();
        ~Simulateur();
        std::vector<int> Dijkstra();

    protected:

    private:
        int m_crise;
};

#endif // SIMULATEUR_H
