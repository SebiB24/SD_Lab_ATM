//
// Created by sebyc on 5/29/2024.
//

#ifndef SD_LAB_ATM_ATM_H
#define SD_LAB_ATM_ATM_H

#include <vector>
#include "Collection.h"
#include "Tranzactie.h"

class Atm {

private:
    Collection* c;
    VectorDinamic<Tranzactie>* tranzactii;
    bool retragereRec(int suma, map<int, int>& MyMap, vector<Pair<int, int>>& currentCombination, vector<vector<Pair<int, int>>>& resultCombinations);
public:
    Atm();
    Atm(const Collection& c);
    ~Atm();

    vector<vector<Pair<int, int>>> retragere(int suma);
    void eliminare_monezi(vector<Pair<int,int>> vector_monezi);
    void adauga_tranzactie(int sum, vector<Pair<int, int>> vector_monezi);

    Collection* get_collection();
    VectorDinamic<Tranzactie> *get_tranzactii();

    bool Exista_id(int id);

};

#endif //SD_LAB_ATM_ATM_H
