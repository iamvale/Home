#ifndef REVISTA_H
#define REVISTA_H

#include <Articol.h>


class Revista : public Articol
{
    public:
        Revista(std::string, int, std::string);
        virtual ~Revista();

    protected:

    private:
        std::string tip;
};

#endif // REVISTA_H
