#ifndef DISC_H
#define DISC_H

#include <Articol.h>


class Disc : public Articol
{
    public:
        Disc();
        Disc(std::string, int, std::string);
        virtual ~Disc();

    protected:

    private:
        std::string program;
};

#endif // DISC_H
