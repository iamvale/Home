#include "Biblioteca.h"
#include <iostream>
#include<stdlib.h>
#include<Carte.h>
#include<Audio.h>
#include<Disc.h>
#include<Revista.h>
#include<typeinfo>
#include<vector>
#include<limits>
#include <algorithm>
#include <fstream>
#include <typeinfo>
#include <string>


using namespace std;


char run_again;

Biblioteca::Biblioteca()
{
    //ctor
}

Biblioteca::~Biblioteca()
{
    for (auto& index:lista)
    {
//        delete mCarte;
//        delete mAudio;
//        delete mDisc;
//        delete mRevista;
    }

}


int Biblioteca::meniu_principal()
{
    bool repet = true;
    int opt;

    do
    {
        cout << endl
        << " Optiuni disponibile:\n";
        cout << endl
        << " 1 - Adauga articol inchiriabil.\n"
        << " 2 - Returneaza articole.\n"
        << " 3 - Inchiriaza articole.\n"
        << " 4 - Listare articole biblioteca.\n"
        << " 0 - Iesire.\n";
        cout << endl
        << " Introdu optiunea dorita: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            //repet = 0;
            meniu_adaugare();
            break;
        case 2:
            meniu_returnare();
            break;
        case 3:
            meniu_inchiriere();

            break;
        case 4:
            meniu_listare();
            break;
        case 0:
            Salvare();
            Citire();
            return 0;
           break;

        default:
        cout << endl;
        cout << "Optiunea nu este valida. \n"
        << "Alegeti din nou:\n";
        }

    }while (repet);

}




int Biblioteca::meniu_adaugare()
{
    int opt;
    string ti;
    string ed;
    int bucEx;
    int bucDisp;
    char alta;
    double dur;
    string prog;
    string tp;
    int total, dispo;


    do
    {
        system("cls");

        cout << endl;
        cout << "Doriti sa adaugati: \n";
        cout << endl
        << " 1 - Carte.\n"
        << " 2 - Carte audio\n"
        << " 3 - Disc.\n"
        << " 4 - Revista.\n"
        << " 0 - Revenire la ecranul anterior.\n";
        cin >> opt;

        while(opt > 4)
        {
            cout << "Optiunea nu este valida. \n"
            << "Alegeti din nou: ";
            cin >> opt;
        }

        switch (opt)
        {

        case 1:
            {
            system("cls");
            cout << " Introduceti titlul: ";
            cin >> ti;
            cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
            cin >> bucEx;

            if(bucEx<0){
                cout << endl;
                cout << " Va rugam introduceti un numar intreg si pozitiv " << " : ";
                cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
                cin >> bucEx;
            }
            while(1)
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << endl;
                    cout << " Va rugam introduceti un numar intreg si pozitiv " << endl;
                    cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
                    cin>>bucEx;
                }
                if(!cin.fail())
                break;
            }

            cout << " Introduceti editura pentru " << ti <<" : ";
            cin >> ed;

            bucDisp = bucEx;

            Carte* mCarte = new Carte(ti, bucEx, bucDisp, ed);
            mCarte ->setTitlu(ti);
            mCarte ->setBucExist(bucEx);
            mCarte ->setBucDisp(bucDisp);
            mCarte ->setEditura(ed);



            bool este = false;

//            for(auto mCarte:lista){
//                if(typeid(mCarte)== typeid(Carte))
                for(auto& index:lista)
                {

                   if(index->getTitlu() == mCarte ->getTitlu())
                   {
                        cout<<">>>>>> EXISTA DEJA ARTICOLUL <<<<<< " << index->getTitlu();
                        bucEx = index->getBucExist() + mCarte ->getBucExist();
                        index->setBucExist(bucEx);
                        bucDisp = index->getBucDisp() + mCarte ->getBucDisp();
                        index->setBucDisp(bucDisp);
                       este = true;
                    }
                   break;
                }


            if(!este){
               lista.push_back(mCarte);
               bucEx = mCarte ->getBucExist();
               bucDisp = mCarte ->getBucDisp();

            }


            cout<<endl;


    }
            break;

        case 2:
        {

            system("cls");
            cout << " Introduceti titlul: ";
            cin >> ti;
            cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
            cin >> bucEx;

            if(bucEx<0){
                cout << endl;
                cout << " Va rugam introduceti un numar intreg si pozitiv " << " : ";
                cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
                cin >> bucEx;
            }
            while(1)
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << endl;
                    cout << " Va rugam introduceti un numar intreg si pozitiv " << endl;
                    cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
                    cin>>bucEx;
                }
                if(!cin.fail())
                break;
            }

            cout << " Introduceti durata pentru " << ti <<" : ";
            cin >> dur;

            bucDisp = bucEx;

            Audio* mAudio = new Audio(ti, bucEx, bucDisp, dur);
            mAudio ->setTitlu(ti);
            mAudio ->setBucExist(bucEx);
            mAudio ->setBucDisp(bucDisp);
            mAudio ->setDurata(dur);



            bool este = false;

                for(auto& index:lista)
                {

                   if(index->getTitlu() == mAudio ->getTitlu())
                   {
                        cout<<">>>>>> EXISTA DEJA ARTICOLUL <<<<<< " << index->getTitlu();
                        bucEx = index->getBucExist() + mAudio ->getBucExist();
                        index->setBucExist(bucEx);
                        bucDisp = index->getBucDisp() + mAudio ->getBucDisp();
                        index->setBucDisp(bucDisp);
                       este = true;
                    }
                   break;
                }


            if(!este){
               lista.push_back(mAudio);
               bucEx = mAudio ->getBucExist();
               bucDisp = mAudio ->getBucDisp();

            }
            cout<<endl;
        }
            break;


        case 3:
             {

            system("cls");
            cout << " Introduceti titlul: ";
            cin >> ti;
            cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
            cin >> bucEx;

            if(bucEx<0){
                cout << endl;
                cout << " Va rugam introduceti un numar intreg si pozitiv " << " : ";
                cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
                cin >> bucEx;
            }
            while(1)
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << endl;
                    cout << " Va rugam introduceti un numar intreg si pozitiv " << endl;
                    cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
                    cin>>bucEx;
                }
                if(!cin.fail())
                break;
            }

            cout << " Introduceti programul pentru " << ti <<" : ";
            cin >> prog;

            bucDisp = bucEx;

            Disc* mDisc = new Disc(ti, bucEx, bucDisp, prog);
            mDisc ->setTitlu(ti);
            mDisc ->setBucExist(bucEx);
            mDisc ->setBucDisp(bucDisp);
            mDisc ->setProg(prog);



            bool este = false;


                for(auto& index:lista)
                {

                   if(index->getTitlu() == mDisc ->getTitlu())
                   {
                        cout<<">>>>>> EXISTA DEJA ARTICOLUL <<<<<< " << index->getTitlu();
                        bucEx = index->getBucExist() + mDisc ->getBucExist();
                        index->setBucExist(bucEx);
                        bucDisp = index->getBucDisp() + mDisc ->getBucDisp();
                        index->setBucDisp(bucDisp);
                       este = true;
                    }
                   break;
                }


            if(!este){
               lista.push_back(mDisc);
               bucEx = mDisc ->getBucExist();
               bucDisp = mDisc ->getBucDisp();

            }

            cout<<endl;
        }
            break;


        case 4:
        {

            system("cls");
            cout << " Introduceti titlul: ";
            cin >> ti;
            cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
            cin >> bucEx;

            if(bucEx<0){
                cout << endl;
                cout << " Va rugam introduceti un numar intreg si pozitiv " << " : ";
                cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
                cin >> bucEx;
            }
            while(1)
            {
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout << endl;
                    cout << " Va rugam introduceti un numar intreg si pozitiv " << endl;
                    cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
                    cin>>bucEx;
                }
                if(!cin.fail())
                break;
            }

            cout << " Introduceti tipul pentru " << ti <<" : ";
            cin >> tp;

            bucDisp = bucEx;

            Revista* mRevista = new Revista(ti, bucEx, bucDisp, tp);
            mRevista ->setTitlu(ti);
            mRevista ->setBucExist(bucEx);
            mRevista ->setBucDisp(bucDisp);
            mRevista ->setTip(tp);



            bool este = false;


                for(auto& index:lista)
                {

                   if(index->getTitlu() == mRevista ->getTitlu())
                   {
                        cout<<">>>>>> EXISTA DEJA ARTICOLUL <<<<<< " << index->getTitlu();
                        bucEx = index->getBucExist() + mRevista ->getBucExist();
                        index->setBucExist(bucEx);
                        bucDisp = index->getBucDisp() + mRevista ->getBucDisp();
                        index->setBucDisp(bucDisp);
                       este = true;
                    }
                   break;
                }


            if(!este){
               lista.push_back(mRevista);
               bucEx = mRevista ->getBucExist();
               bucDisp = mRevista ->getBucDisp();

            }


            cout<<endl;
        }

            break;

        case 0:
            system("cls");
            meniu_principal();

           return 0;

            break;

//        default:
//
//        cout << "Optiunea nu este valida. \n"
//        << "Alegeti din nou.\n";
        }

        cout << " Doriti sa alegeti alta optiune (d/n) ? ";
        cin>>alta;
        system("cls");

    }while (alta == 'd');
}






void Biblioteca::meniu_returnare()
    {
        int opt;
        char alta;
        string retur;
        int bucDisp;
        int bucExist;

        do
        {

        system("cls");

        cout << endl;
        cout << "Doriti sa returnati: \n";
        cout << endl
        << " 1 - Carte.\n"
        << " 2 - Carte audio\n"
        << " 3 - Disc.\n"
        << " 4 - Revista.\n"
        << " 0 - Revenire la ecranul anterior.\n";
        cin >> opt;

        while(opt > 4)
        {
            cout << "Optiunea nu este valida. \n"
            << "Alegeti din nou: ";
            cin >> opt;
        }


        switch (opt)
        {

        case 1:
        {
            system("cls");
            cout << endl;
            cout << "Lista articolelor  inchiriate: \n";
            cout << endl;
            cout << "  Titlu  " << "  Bucati existente  " << "  Bucati disponibile  " << '\n';
            cout << endl;

            for(auto index:lista)
            {
                if(typeid(*index) == typeid(Carte))
                {

                cout <<  "   " << index->getTitlu() << "       "
                     <<  "      " <<index->getBucExist() << " "
                     <<  "      " <<index->getBucDisp() << " \n";

                }

            }


            bool cond = true;
            while(cond)
            {

            cout << endl;
            cout << " Titlul articolului restituit este: "; // mai trebuie validat
            cin >> retur;

            //bool cond = false;

            for(auto index:lista)
            {

                if(retur == index->getTitlu())
                {
                    bucExist = index->getBucExist();
                    bucDisp = index->getBucDisp();

                    if(bucDisp < bucExist)
                        {
                            bucDisp = index->getBucDisp()+ 1;
                            index->setBucDisp(bucDisp);
                        }
                    meniu_principal();
                    cond = false;
                    break;

                }
            }

                    cout << " Articolul nu se afla in lista " << endl;

            }

        }

            break;

        case 2:
            {
            system("cls");
            cout << endl;
            cout << "Lista articolelor  inchiriate: \n";
            cout << endl;
            cout << "  Titlu  " << "  Bucati existente  " << "  Bucati disponibile  " << '\n';
            cout << endl;

            for(auto index:lista)
            {
                if(typeid(*index) == typeid(Audio))
                {
                cout <<  "   " << index->getTitlu() << "       "
                     <<  "      " <<index->getBucExist() << " "
                     <<  "      " <<index->getBucDisp() << "\n";
                }
            }


            bool cond = true;
            while(cond)
            {

            cout << endl;
            cout << " Titlul articolului restituit este: "; // mai trebuie validat
            cin >> retur;

            //bool cond = false;

            for(auto index:lista)
            {

                if(retur == index->getTitlu())
                {
                    bucExist = index->getBucExist();
                    bucDisp = index->getBucDisp();

                    if(bucDisp < bucExist)
                        {
                            bucDisp = index->getBucDisp()+ 1;
                            index->setBucDisp(bucDisp);
                        }
                    meniu_principal();
                    cond = false;
                    break;

                }
            }

                    cout << " Articolul nu se afla in lista " << endl;

            }

        }

            break;
        case 3:
        {
            system("cls");
            cout << endl;
            cout << "Lista articolelor  inchiriate: \n";
            cout << endl;
            cout << "  Titlu  " << "  Bucati existente  " << "  Bucati disponibile  " << '\n';
            cout << endl;

            for(auto index:lista)
            {
                if(typeid(*index) == typeid(Disc))
                {
                cout <<  "   " << index->getTitlu() << "       "
                     <<  "      " <<index->getBucExist() << " "
                     <<  "      " <<index->getBucDisp() << "\n";
                }
            }


            bool cond = true;
            while(cond)
            {

            cout << endl;
            cout << " Titlul articolului restituit este: "; // mai trebuie validat
            cin >> retur;

            //bool cond = false;

            for(auto index:lista)
            {

                if(retur == index->getTitlu())
                {
                    bucExist = index->getBucExist();
                    bucDisp = index->getBucDisp();

                    if(bucDisp < bucExist)
                        {
                            bucDisp = index->getBucDisp()+ 1;
                            index->setBucDisp(bucDisp);
                        }
                    meniu_principal();
                    cond = false;
                    break;

                }
            }

                    cout << " Articolul nu se afla in lista " << endl;

            }

        }

            break;
        case 4:
                    {
            system("cls");
            cout << endl;
            cout << "Lista articolelor  inchiriate: \n";
            cout << endl;
            cout << "  Titlu  " << "  Bucati existente  " << "  Bucati disponibile  " << '\n';
            cout << endl;

            for(auto index:lista)
            {
                if(typeid(*index) == typeid(Revista))
                {
                cout <<  "   " << index->getTitlu() << "       "
                     <<  "      " <<index->getBucExist() << " "
                     <<  "      " <<index->getBucDisp() << "\n";
                }
            }


            bool cond = true;
            while(cond)
            {

            cout << endl;
            cout << " Titlul articolului restituit este: "; // mai trebuie validat
            cin >> retur;

            //bool cond = false;

            for(auto index:lista)
            {

                if(retur == index->getTitlu())
                {
                    bucExist = index->getBucExist();
                    bucDisp = index->getBucDisp();

                    if(bucDisp < bucExist)
                        {
                            bucDisp = index->getBucDisp()+ 1;
                            index->setBucDisp(bucDisp);
                        }
                        meniu_principal();
                        cond = false;
                    break;

                }
            }

                    cout << " Articolul nu se afla in lista " << endl;

            }

        }

            break;

        case 0:
            system("cls");
            meniu_principal();
            break;

        }

        cout << " Doriti sa alegeti alta optiune (d/n) ? ";
        cin>>alta;
        system("cls");

    }while (alta == 'd');
}





void Biblioteca::meniu_inchiriere()
    {
        int opt;
        char alta;
        int bucDisp;
        string retur;

        do
        {

        system("cls");

        cout << endl;
        cout << "Doriti sa inchiriati: \n";
        cout << endl
        << " 1 - Carte.\n"
        << " 2 - Carte audio\n"
        << " 3 - Disc.\n"
        << " 4 - Revista.\n"
        << " 0 - Revenire la ecranul anterior.\n";
        cin >> opt;

        while(opt > 4)
        {
            cout << "Optiunea nu este valida. \n"
            << "Alegeti din nou: ";
            cin >> opt;
        }


        switch (opt)
        {

        case 1:
        {

            system("cls");
            cout << endl;
            cout << "Lista articolelor de inchiriat: \n";
            cout << endl;
            cout << "  Titlu  " << "  Bucati existente  " << "  Bucati disonibile  " << '\n';
            cout << endl;

            for(auto index:lista)
            {
                if(typeid(*index) == typeid(Carte))
                {
                    if(bucDisp > 0)
                        cout <<  "   " << index->getTitlu() << "       "
                             <<  "      " << index->getBucExist() << "  "
                             <<  "      " << index->getBucDisp() << "\n";
                }
            }



            bool cond = true;

            while(cond)
            {

            cout << endl;
            cout << " Doriti sa inchiriati articolul: "; // mai trebuie validat
            cin >> retur;

            //bool cond = false;


            for(auto index:lista)
            {

                if(retur == index->getTitlu())
                {

                    bucDisp = index->getBucDisp()- 1;
                    index->setBucDisp(bucDisp);
                    meniu_principal();
                    cond = false;
                    break;

                }

            }
                    cout << " Articolul nu se afla in lista " << endl; ///?

            }

        }


            break;
        case 2:
        {

            system("cls");
            cout << endl;
            cout << "Lista articolelor de inchiriat: \n";
            cout << endl;
            cout << "  Titlu  " << "  Bucati existente  " << "  Bucati disonibile  " << '\n';
            cout << endl;

            for(auto index:lista)
            {
                if(typeid(*index) == typeid(Audio))
                {
                    if(bucDisp > 0)
                        cout <<  "   " << index->getTitlu() << "       "
                             <<  "      " << index->getBucExist() << "  "
                             <<  "      " << index->getBucDisp() << "\n";
                }
            }



            bool cond = true;

            while(cond)
            {

            cout << endl;
            cout << " Doriti sa inchiriati articolul: "; // mai trebuie validat
            cin >> retur;

            //bool cond = false;


            for(auto index:lista)
            {

                if(retur == index->getTitlu())
                {

                    bucDisp = index->getBucDisp()- 1;
                    index->setBucDisp(bucDisp);
                    meniu_principal();
                    cond = false;
                    break;

                }

            }
                    cout << " Articolul nu se afla in lista " << endl; ///?

            }

        }

            break;
        case 3:
        {

            system("cls");
            cout << endl;
            cout << "Lista articolelor de inchiriat: \n";
            cout << endl;
            cout << "  Titlu  " << "  Bucati existente  " << "  Bucati disonibile  " << '\n';
            cout << endl;

            for(auto index:lista)
            {
                if(typeid(*index) == typeid(Disc))
                {
                    if(bucDisp > 0)
                        cout <<  "   " << index->getTitlu() << "       "
                             <<  "      " << index->getBucExist() << "  "
                             <<  "      " << index->getBucDisp() << "\n";
                }
            }



            bool cond = true;

            while(cond)
            {

            cout << endl;
            cout << " Doriti sa inchiriati articolul: "; // mai trebuie validat
            cin >> retur;

            //bool cond = false;


            for(auto index:lista)
            {

                if(retur == index->getTitlu())
                {

                    bucDisp = index->getBucDisp()- 1;
                    index->setBucDisp(bucDisp);
                    meniu_principal();
                    cond = false;
                    break;

                }

            }
                    cout << " Articolul nu se afla in lista " << endl; ///?

            }

        }

            break;
        case 4:
        {

            system("cls");
            cout << endl;
            cout << "Lista articolelor de inchiriat: \n";
            cout << endl;
            cout << "  Titlu  " << "  Bucati existente  " << "  Bucati disonibile  " << '\n';
            cout << endl;

            for(auto index:lista)
            {
                if(typeid(*index) == typeid(Revista))
                {
                    if(bucDisp > 0)
                        cout <<  "   " << index->getTitlu() << "       "
                             <<  "      " << index->getBucExist() << "  "
                             <<  "      " << index->getBucDisp() << "\n";
                }
            }



            bool cond = true;

            while(cond)
            {

            cout << endl;
            cout << " Doriti sa inchiriati articolul: "; // mai trebuie validat
            cin >> retur;

            //bool cond = false;


            for(auto index:lista)
            {

                if(retur == index->getTitlu())
                {

                    bucDisp = index->getBucDisp()- 1;
                    index->setBucDisp(bucDisp);
                    meniu_principal();
                    cond = false;
                    break;

                }

            }
                    cout << " Articolul nu se afla in lista " << endl; ///?

            }

        }

            break;

        case 0:
            system("cls");
            meniu_principal();
            break;

        }

        cout << " Doriti sa alegeti alta optiune (d/n) ? ";
        cin>>alta;
        system("cls");

    }while (alta == 'd');

    }




    void Biblioteca::meniu_listare()
    {

        system("cls");


            sort( lista.begin( ), lista.end( ), [ ]( Articol* leftArt, Articol* rightArt)
            {
                return leftArt->getTitlu() < rightArt->getTitlu();
            });


            cout << endl;
            std::cout << "Lista articolelor din biblioteca: \n";
            cout << endl;
            std::cout << "  Titlu  " << "  Bucati existente  " << " Bucati disonibile " << '\n';
            cout << endl;


         for(auto index:lista)
            {
                cout <<  "   " << index->getTitlu() << "       "
                     <<  "      " <<index->getBucExist() << " "
                     <<  "      " <<index->getBucDisp() << "\n";

            }


  }

    void Biblioteca::Salvare()
    {
        ofstream streamSalvare("Biblioteca.txt");

        for (auto& index:lista)
        {
              streamSalvare << index->getTitlu() << "  "
                            << index->getBucExist() << "   "
                            << index->getBucDisp() << endl;
        }


    }

    void Biblioteca::Citire()
    {
//    string ti;
//    string ed;
//    int bucEx;
//    int bucDisp;
//        Articol* mArticol = new Articol(ti, bucEx, bucDisp);
//        ifstream streamCitire("Biblioteca.txt");
//
//        if(streamCitire.is_open())
//        {
//            while(streamCitire >> ti >> bucEx >> bucDisp)
//            {
//                std::cout << ti << bucEx << bucDisp;
//            }
//            streamCitire.close();
//        }


    }

