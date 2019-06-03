#ifndef REVISTA_H
#define REVISTA_H

#include <Articol.h>


class Revista : public Articol
{
    public:
        Revista(std::string, int, int, std::string);
        virtual ~Revista();
       void setTip(std::string);

    protected:

    private:
        std::string tipRev;
};

#endif // REVISTA_H
