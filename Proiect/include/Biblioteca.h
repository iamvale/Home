#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include<Articol.h>
#include<vector>


class Biblioteca
{
    public:
        Biblioteca();
        virtual ~Biblioteca();
        int meniu_principal();
        int meniu_adaugare();
        void meniu_returnare();
        void meniu_inchiriere();
        void meniu_listare();
        void Salvare();
        void Citire();


    protected:

    private:

        std::vector<Articol*>lista;
};

#endif // BIBLIOTECA_H
