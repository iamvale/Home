#ifndef DISC_H
#define DISC_H

#include <Articol.h>


class Disc : public Articol
{
    public:
        Disc();
        Disc(std::string, int, int, std::string);
        virtual ~Disc();
        void setProg(std::string);

    protected:

    private:
        std::string program;
};

#endif // DISC_H
