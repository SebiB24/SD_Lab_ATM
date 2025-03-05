//
// Created by sebyc on 6/1/2024.
//

#ifndef SD_LAB_ATM_TRANZACTIE_H
#define SD_LAB_ATM_TRANZACTIE_H
#include "Pair.h"
#include "Vector.h"
#include <iostream>
#include <vector>
using namespace std;

class Tranzactie {
private:
    int idTranzactie;
    int suma;
    vector<Pair<int, int>> monezi;

public:
    Tranzactie();
    Tranzactie(int id, int suma, const std::vector<Pair<int, int>>& monezi);
    Tranzactie(const Tranzactie &t);
    ~Tranzactie();

    int get_id() const;
    int get_suma() const;
    const std::vector<Pair<int, int>>& get_monezi() const;

    void set_id(int id);
    void set_suma(int suma);
    void set_monezi(const vector<Pair<int, int>>& monezi);

    friend ostream& operator<<(ostream &, const Tranzactie &);
};


#endif //SD_LAB_ATM_TRANZACTIE_H
