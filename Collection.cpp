//
// Created by sebyc on 5/29/2024.
//
#include "Collection.h"
#include <iostream>
#include <map>
using namespace std;

Collection::Collection() {
    elements = new VectorDinamic<Pair<TElem, int>>(5);
}

Collection::Collection(const Collection &c) {
    this -> elements = c.elements;
}

Collection::~Collection(){

}

void Collection::add(TElem elem) {
    bool exist = false;
    int position;
    for (int i = 0; i < elements->get_nrElems(); i++)
        if (elem == elements->getAt(i).get_valoare()) {
            exist = true;
            position = i;
        }

    if (exist){
        Pair<TElem , int> pair(elem, elements->getAt(position).get_numar() + 1);
        elements->setAt(position, pair);
    }
    else {
        Pair<TElem , int> pair(elem, 1);
        elements->push_back(pair);
    }
}

bool Collection::remove(TElem elem) {
    bool exist = false;
    int position;
    for (int i = 0; i < elements->get_nrElems(); i++)
        if (elem == elements->getAt(i).get_valoare()) {
            exist = true;
            position = i;
        }

    if (exist) {
        if (elements->getAt(position).get_numar() > 1) {
            Pair<TElem , int> pair(elem, elements->getAt(position).get_numar() - 1);
            elements->setAt(position, pair);
        } else {
            Pair<TElem , int> pair(elem, elements->getAt(position).get_numar());
            elements->remove(pair);
        }
        return true;
    }
    return false;
}


bool Collection::search(TElem elem) {
    for (int i = 0; i < elements->get_nrElems(); i++)
        if (elem == elements->getAt(i).get_valoare())
            return true;
    return false;
}

int Collection::size() {
    return elements->get_nrElems();
}

int Collection::nroccurrences(TElem elem) {
    for (int i = 0; i< elements->get_nrElems(); i++)
        if (elements->getAt(i).get_valoare() == elem)
            return elements->getAt(i).get_numar();
    return 0;
}

void Collection::destroy() {
    delete[] elements;
}

Pair<TElem , int> Collection::getAt(int position) {
    return elements->getAt(position);
}


VectorDinamic<Pair<TElem, int>>* Collection::get_elements() {
    return elements;
}






