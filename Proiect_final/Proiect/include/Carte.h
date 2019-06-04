#ifndef CARTE_H
#define CARTE_H
#include<string>

#include <Articol.h>


class Carte : public Articol
{
    public:
        //std::string titlu;
        //int bucati;
        Carte();
        Carte(std::string, int, int, std::string);
        virtual ~Carte();
        void setEditura(std::string);


    protected:

    private:
        std::string editura;
};

#endif // CARTE_H
