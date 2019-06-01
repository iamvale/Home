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
        int Adauga_articol();
        int Returneaza_articol();
        int Inchiriaza_articol();
        int Listare_articol();
        void Iesire();

    protected:

    private:

        std::vector<Articol>lista;
};

#endif // BIBLIOTECA_H
