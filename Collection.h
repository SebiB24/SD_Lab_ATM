//
// Created by sebyc on 5/29/2024.
//

#ifndef SD_LAB_ATM_COLLECTION_H
#define SD_LAB_ATM_COLLECTION_H
#include "Pair.h"
#include "Vector.h"
#include <map>
#include <iostream>
using namespace std;
typedef int TElem;

class Collection {
private:
    VectorDinamic<Pair<TElem, int>>* elements;
public:
    Collection();
    Collection(const Collection &c);
    ~Collection();
    void operator = (const Collection &c )
    {
        this ->elements = c.elements;
    }
    void add(TElem elem);
    bool remove(TElem elem);
    bool search(TElem elem);
    int size();
    int nroccurrences(TElem elem);
    void destroy();
    Pair<TElem, int> getAt(int position);
    VectorDinamic<Pair<TElem, int>>* get_elements();

};


#endif //SD_LAB_ATM_COLLECTION_H
