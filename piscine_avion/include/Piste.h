#ifndef PISTE_H
#define PISTE_H


class Piste
{
    public:
        Piste();
        ~Piste();

        int getRempli(){return m_rempli;}
        void setRempli(int a){m_rempli=a;}

    protected:

    private:

        int m_rempli=0 ;

};

#endif // PISTE_H
