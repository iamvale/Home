#ifndef ARTICOL_H
#define ARTICOL_H
#include<stdlib.h>
#include<string>
#include<vector>




class Articol
{
    public:
        Articol();
        Articol(std::string, int, int);
        virtual ~Articol();
//        std::string titlu;
//        int bucati;

         std::string getTitlu();
         void setTitlu(std::string);
         int getBucExist();
         void setBucExist(int);
         int getBucDisp();
         void setBucDisp(int);
         virtual std::string getAll();
         virtual bool operator>(Articol& sortAlfa);


    protected:

    private:
        std::string titlu;
        int bucExist;
        int bucDisponibile;




};

#endif // ARTICOL_H
