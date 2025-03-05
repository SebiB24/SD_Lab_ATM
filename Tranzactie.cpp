//
// Created by sebyc on 6/1/2024.
//

#include "Tranzactie.h"

Tranzactie::Tranzactie()
: idTranzactie(0), suma(0) {

}

Tranzactie::Tranzactie(int id, int suma, const std::vector<Pair<int, int>>& monezi)
: idTranzactie(id), suma(suma), monezi(monezi) {

}

Tranzactie::Tranzactie(const Tranzactie &t)
: idTranzactie(t.idTranzactie), suma(t.suma), monezi(t.monezi) {

}

Tranzactie::~Tranzactie() {

}

int Tranzactie::get_id() const {
    return idTranzactie;
}

int Tranzactie::get_suma() const {
    return suma;
}

const std::vector<Pair<int, int>>& Tranzactie::get_monezi() const {
    return monezi;
}

void Tranzactie::set_id(int id) {
    idTranzactie = id;
}

void Tranzactie::set_suma(int suma) {
    this->suma = suma;
}

void Tranzactie::set_monezi(const std::vector<Pair<int, int>>& monezi) {
    this->monezi = monezi;
}

ostream& operator<<(ostream& os, const Tranzactie& tr){
    os<<"Id: "<<tr.get_id()<<" Suma: "<<tr.get_suma()<<" Monezi: ";
    for(int i = 0; i < tr.get_monezi().size(); i++)
        os<<tr.get_monezi().at(i).get_numar()<<"x"<<tr.get_monezi().at(i).get_valoare()<<" ";
    return os;
}

