#ifndef STATION_H
#define STATION_H
#include <Avion.h>
#include <iostream>


class Station
{
    public:
        Station();
        ~Station();

        int getRempli(){return m_rempli;}
        void setRempli(int a){m_rempli=a;}


        void setAvion(std::string a);


    protected:

    private:

        int m_rempli ;


        std::string m_avionDansStation;

};

#endif // STATION_H
