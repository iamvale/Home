#ifndef AUDIO_H
#define AUDIO_H
#include<stdlib.h>
#include<string>

#include <Articol.h>


class Audio : public Articol
{
    public:
        Audio(std::string, int, double);
        virtual ~Audio();
        void setDurata(double);


    protected:

    private:
        double durata;
};

#endif // AUDIO_H
