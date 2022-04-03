#ifndef SIMULATEUR_H
#define SIMULATEUR_H
#include <vector>
#include <string>

class Simulateur
{
    public:
        Simulateur();
        ~Simulateur();
        std::vector<int> Dijkstra();
        void afficher();

    protected:

    private:
        int m_crise;
        std::vector<std::pair<int, std::string>> m_aero_name;

};

#endif // SIMULATEUR_H
