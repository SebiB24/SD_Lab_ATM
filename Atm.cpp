//
// Created by sebyc on 5/29/2024.
//

#include "Atm.h"
#include <vector>

//============================================= constructor ATM (param collectie)
Atm::Atm() {
    tranzactii = new VectorDinamic<Tranzactie>(5);
}

Atm::Atm(const Collection& c){
    this->c = new Collection(c);
    tranzactii = new VectorDinamic<Tranzactie>(5);
}

Atm::~Atm(){

}

//===================================================================== retragere

bool Exista_optiune(vector<vector<Pair<int, int>>> resultCombinations, vector<Pair<int, int>> currentCombination){
    int n = 0;
    int m;
    for(int i = 0 ;i<resultCombinations.size(); i++)
    {
        if(resultCombinations[i].size() == currentCombination.size())
        {
            m = 0;
            for(int j = 0; j <currentCombination.size(); j++)
                for(int h = 0; h <currentCombination.size(); h++)
                    if(currentCombination[j].get_numar() == resultCombinations[i][h].get_numar() && currentCombination[j].get_valoare() == resultCombinations[i][h].get_valoare()){
                        m++;
                        break;
                    }
            if(m >= currentCombination.size())
                n++;
        }

    }
    if(n == 0)
        return false;
    return true;
}

/// Returneaza prin parametru vector<vector<int>>& resultCombinations
bool Atm::retragereRec(int suma, std::map<int, int>& MyMap, vector<Pair<int, int>>& currentCombination, vector<vector<Pair<int, int>>>& resultCombinations) {
    if (suma == 0 && !Exista_optiune(resultCombinations, currentCombination)) {
        resultCombinations.push_back(currentCombination);
        return true;
    }

    bool found = false;
    for (auto it = MyMap.rbegin(); it != MyMap.rend(); ++it) {
        if (it->second > 0 && suma >= it->first) {
            it->second--;
            currentCombination.push_back(Pair<int, int>(it->first, 1));

            if (retragereRec(suma - it->first, MyMap, currentCombination, resultCombinations)) {
                found = true;
            }

            currentCombination.pop_back();
            it->second++;
        }
    }

    return found;
}

vector<vector<Pair<int, int>>> Atm:: retragere(int suma) {
    map<int, int> MyMap;
    vector<Pair<int, int>> currentCombination;
    vector<vector<Pair<int, int>>> resultCombinations;

    for (int i = 0; i < c->size(); ++i) {
        Pair<int, int> p = c->getAt(i);
        MyMap[p.get_valoare()] = p.get_numar();
    }

    retragereRec(suma, MyMap, currentCombination, resultCombinations);
    vector<vector<Pair<int, int>>> optiuni;
    for (int i = 0; i < resultCombinations.size(); ++i) {
        vector<Pair<int, int>> currentOptiuni;
        for (int j = 0; j < resultCombinations[i].size(); ++j) {
            bool found = false;
            for (int h = 0; h < currentOptiuni.size(); ++h) {
                if (resultCombinations[i][j].get_valoare() == currentOptiuni[h].get_valoare()) {
                    currentOptiuni[h].set_numar(currentOptiuni[h].get_numar() + 1);
                    found = true;
                    break;
                }
            }
            if (!found) {
                currentOptiuni.push_back(resultCombinations[i][j]);
            }
        }
        optiuni.push_back(currentOptiuni);
    }
    return optiuni;

}


//============================================================ eliminare monezi
void Atm::eliminare_monezi(vector<Pair<int,int>> vector_monezi) {
    for(int i = 0; i < vector_monezi.size(); i++)
        while(vector_monezi[i].get_numar() != 0){
            c->remove(vector_monezi[i].get_valoare());
            vector_monezi[i].set_numar(vector_monezi[i].get_numar() -1);
        }

}

//================================================ adaugare tranzactie in vector

void Atm::adauga_tranzactie(int sum, vector<Pair<int, int>> vector_monezi){
    int id = rand() % 100;
    while(Exista_id(id))
        id = rand() % 100;
    Tranzactie t(id, sum, vector_monezi);
    tranzactii->push_back(t);

}


//========================================================== returneaza colectia
Collection* Atm::get_collection() {
    return c;
}

//======================================================== returneaza tranzactii
VectorDinamic<Tranzactie>* Atm::get_tranzactii(){
    return tranzactii;
}

//=================================== verifica existenta id in vector tranzactii

bool Atm::Exista_id(int id) {
    for(int i = 0; i< tranzactii->get_nrElems(); i++)
        if(tranzactii->getAt(i).get_id() == id)
            return true;
    return false;
}