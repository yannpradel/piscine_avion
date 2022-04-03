#ifndef PERTURBATION_METEO_H
#define PERTURBATION_METEO_H
#include <vector>

class Case;

class Perturbation_Meteo
{
    public:
        Perturbation_Meteo();
        ~Perturbation_Meteo();

    protected:

    private:
        std::vector<Case*> m_zone;
        int m_intensite;
};

#endif // PERTURBATION_METEO_H
