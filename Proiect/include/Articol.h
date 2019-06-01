#ifndef ARTICOL_H
#define ARTICOL_H
#include<stdlib.h>
#include<string>
#include<vector>




class Articol
{
    public:
        Articol();
        Articol(std::string, int);
        virtual ~Articol();
//        std::string titlu;
//        int bucati;

        virtual std::string getTitlu();
        virtual void setTitlu(std::string);
        virtual int getBucati();
        virtual void setBucati(int);
        virtual std::string getAll();

    protected:

    private:
        std::string titlu;
        int bucati;



};

#endif // ARTICOL_H
