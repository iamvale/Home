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


using namespace std;
//Articol *articole[20];


char run_again;

//std::istream& getline( std::istream& ins, int& n )
//{
//}

Biblioteca::Biblioteca()
{
    //ctor
}

Biblioteca::~Biblioteca()
{
    //dtor
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
        << " 4 - Inchiriaza articole.\n"
        << " 5 - Listare articole biblioteca.\n"
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
           // meniu_returnare();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 0:
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
    bool repet = true;
    int opt;
    string ti;
    string ed;
    int b;
    char alta;
    double dur;


    do
    {
        system("cls");

        cout << endl;
        cout << "Doriti sa adaugati: \n";
        cout << endl
        << " 1 - Carte.\n"
        << " 2 - Carte audio\n"
        << " 4 - Disc.\n"
        << " 5 - Revista.\n"
        << " 0 - Revenire la ecranul anterior.\n";
        cin >> opt;

        while(opt > 5)
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
            cin >> b;

            if(b<0){
                cout << endl;
                cout << " Va rugam introduceti un numar intreg si pozitiv " << " : ";
                cout << " Introduceti numarul de bucati pentru " << ti <<" : ";
                cin >> b;
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
                    cin>>b;
                }
                if(!cin.fail())
                break;
            }

            cout << " Introduceti editura pentru " << ti <<" : ";
            cin >> ed;



            Carte* mCarte = new Carte(ti,b,ed);
            mCarte ->setTitlu(ti);
            mCarte ->setBucati(b);
            mCarte ->setEditura(ed);



            bool este = false;

            for(auto& index:lista)
            {
                lista.push_back(*mCarte);


               // if(index.getAll() == "carte"){
                   if(index.getTitlu() == mCarte ->getTitlu())
                   {
                        cout<<">>>>>> EXISTA DEJA " << index.getTitlu();
                        int bc = index.getBucati() + mCarte ->getBucati();
                        index.setBucati(bc);
                       este = true;
                    }
                   break;
                }





//            if(!este){
//                index = mCarte;
//                index++;;
//            }
//
//
//            cout<<endl;
//            cout<<"should be titlu: " << index.getAll();
//            system("pause>nul");

            }

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 0:
            system("cls");
            meniu_principal();
           // repet = false;
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
        bool repet = true;
        int opt;
    do
    {
        system("cls");

        cout << endl;
        cout << "Doriti sa returnati: \n"
        << " 1 - Carte.\n"
        << " 2 - Carte audio\n"
        << " 4 - Disc.\n"
        << " 5 - Revista.\n"
        << " 0 - Revenire la ecranul anterior.\n";
        cin >> opt;

        switch (opt)
        {
        case 1:
            system("cls");
            system("pause>nul");


            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 0:
            repet = false;
            system("cls");
            break;


        default:
        cout << "Optiunea nu este valida. \n"
        << "Alegeti din nou.\n";

        }
    }while (repet);
}
