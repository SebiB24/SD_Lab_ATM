#include <iostream>
#include "Tests.h"
#include <iostream>
#include "Except.h"
#include <limits>
#include "Atm.h"
using namespace std;


//============================================================ retragere main

void retragere(Atm MyAtm) {
    int sum;
    cout << "Introduceti suma dorita: " << endl;
    cin >> sum;
    if (cin.fail() || sum < 0)
        throw Except("Suma invalida");
    else {
        vector<vector<Pair<int,int>>> optiuni = MyAtm.retragere(sum);
        if (optiuni.size() != 0) {
            cout << "OPTIUNILE DE PLATA SUNT: " << endl;
            for (int i = 0; i < optiuni.size(); i++) {
                cout << i + 1 << ". ";
                for (int j = 0; j < optiuni[i].size(); j++)
                    cout << optiuni[i][j].get_numar() <<"x"<<optiuni[i][j].get_valoare()<<" ";
                cout << endl;
            }
            int n;
            cout << "Introduceti numarul optiunii de plata dorite: " << endl;
            cin >> n;
            if(n <= 0 || n > optiuni.size())
                throw Except("Optiuna nu exista");
            MyAtm.eliminare_monezi(optiuni[n - 1]);
            MyAtm.adauga_tranzactie(sum, optiuni[n -1]);
        } else
            throw Except("Suma nu poate fi retrasa");
    }
}

//=================================================== preadaugare monezi colectie
void adaugare_monezi(Collection &c){
    c.add(200);
    c.add(100);
    c.add(100);
    c.add(100);
    c.add(50);
    c.add(50);
    c.add(50);
    c.add(50);
    c.add(10);
    c.add(10);
    c.add(10);
    c.add(10);
    c.add(10);
}

//=================================================== preadauga tranzactii vector
void adaugare_tranzactii(Atm MyAtm){
    Pair<int, int> p1(100, 2);
    Pair<int, int> p2(50, 1);
    vector<Pair<int,int>> monezi;
    monezi.push_back(p1);
    monezi.push_back(p2);

    Pair<int, int> p3(10, 2);
    Pair<int, int> p4(50, 3);
    Pair<int, int> p5(5,1);
    vector<Pair<int,int>> monezi2;
    monezi2.push_back(p3);
    monezi2.push_back(p4);
    monezi2.push_back(p5);

    MyAtm.adauga_tranzactie(250, monezi);
    MyAtm.adauga_tranzactie(175, monezi2);
}

//============================================================= afisare colectie
void afisare_monezi(Atm MyAtm){
    Collection* colectie = MyAtm.get_collection();
    for(int i = 0; i< colectie->get_elements()->get_nrElems(); i++)
    {
        Pair<int, int> p = colectie->get_elements()->getAt(i);
        cout<<p.get_numar()<<" x "<<p.get_valoare()<<endl;
    }
}

//========================================================== afiseaza tranzactii
void afisare_tranzactii(Atm MyAtm){
    VectorDinamic<Tranzactie>* tr = MyAtm.get_tranzactii();
    for(int i = 0; i< tr->get_nrElems(); i++){
        cout<<tr->getAt(i)<<endl;
    }

}

//===================================================================== program
void program() {

    Collection MyCollection;
    adaugare_monezi(MyCollection);
    Atm MyAtm(MyCollection);
    adaugare_tranzactii(MyAtm);

    cout << "MENIU\n"
            "1. Retrage suma\n"
            "2. Afisare monezi disponibile\n"
            "3. Afisare lista tranzactii\n"
            "0. Exit\n";

    bool run = true;
    int comanda;
    while (run) {
        try{
            cout << "Introduceti numarul comenzii:";
            cin >> comanda;
            if(cin.fail())
                throw Except("comanda invalida");
            cout << endl;
            switch (comanda) {
                case 0:
                    run = false;
                    break;
                case 1:
                    retragere(MyAtm);
                    break;
                case 2:
                    afisare_monezi(MyAtm);
                    break;
                case 3:
                    afisare_tranzactii(MyAtm);
                    break;
                default:
                    throw Except("comanda nu exista");
            }
        }
        catch (Except exc){
            cout<<"ERROR: "<<exc.what()<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    Tests();
    program();

    return 0;
}
