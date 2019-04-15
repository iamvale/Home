#ifndef BECREGLABIL_H
#define BECREGLABIL_H


class BecReglabil
{
    public:
        BecReglabil(unsigned short, unsigned short);
        virtual ~BecReglabil();
        void Aprinde();
        void Stinge();
        void MaresteLumina(unsigned short);
        void ReduceLumina(unsigned short);
        void StareBec();


    protected:

    private:
        unsigned short _putereMaxima;
        unsigned short _putereCurenta;
        bool _aprins;
};

#endif // BECREGLABIL_H
