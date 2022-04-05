#ifndef STATION_H
#define STATION_H


class Station
{
    public:
        Station();
        ~Station();

        int getRempli(){return m_rempli;}
        void setRempli(int a){m_rempli=a;}

    protected:

    private:

        int m_rempli = 0;

};

#endif // STATION_H
