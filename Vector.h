//
// Created by sebyc on 5/29/2024.
//

#ifndef SD_LAB_ATM_VECTOR_H
#define SD_LAB_ATM_VECTOR_H
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class VectorDinamic{
private:
    int capacity;
    int nrElems;
    T* elems;

    void resize(int cap);

public:
    VectorDinamic();
    VectorDinamic (int capacitate);
    VectorDinamic(VectorDinamic<T> &v);
    ~VectorDinamic();

    void push_back(T e);
    void remove(T e);

    T getAt(int i) const;
    int get_capacity();
    int get_nrElems();

    void setAt(int i, T elems);


    void operator = (const VectorDinamic<T> &v)
    {
        this -> capacity = v.capacity;
        this -> nrElems = v.nrElems;
        for(int i = 0; i < nrElems; i++)
            this -> elems[i] = v.elems[i];
    }


};

template <typename T>
VectorDinamic<T>::VectorDinamic() {
    this->elems=new T [5];
    this->nrElems=0;
    this->capacity=5;
}

template <typename T>
VectorDinamic<T>::VectorDinamic(int capacitate) {
    if (capacitate<1){
        throw "capacitate negativa";
    }
    this->elems=new T [capacitate];
    this->nrElems=0;
    this->capacity=capacitate;
}

template <typename T>
VectorDinamic<T>::VectorDinamic(VectorDinamic<T> &v) {

    this->elems= v.elems;
    this->nrElems=v.nrElems;
    this->capacity=v.capacity;
}

template <typename T>
void VectorDinamic<T>::push_back(T e) {
    if(nrElems==capacity){
        resize(capacity*2);
    }
    this->elems[nrElems++] = e;
}

template <typename T>
void VectorDinamic<T>::resize(int cap) {
    T * aux = new T [cap];
    for(int i=0; i<capacity; i++)
        aux[i] = this->elems[i];
    delete[] elems;
    this->elems = aux;
    this->capacity = cap;
}

template <typename T>
void VectorDinamic<T>::setAt(int i, T elems) {
    this -> elems[i] = elems;
}

template <typename T>
T VectorDinamic<T>::getAt(int i) const {
    if((i>=0) && (i<nrElems)){
        return this->elems[i];
    }
    else{
        throw "pozitia nu este valida ";
    }
}

template <typename T>
int VectorDinamic<T>::get_capacity(){
    return this -> capacity;
}

template <typename T>
int VectorDinamic<T>::get_nrElems(){
    return this -> nrElems;
}

template <typename T>
void VectorDinamic<T>::remove(T element) {
    int index = -1;
    for (int i = 0; i < nrElems; ++i) {
        if (elems[i] == element) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < nrElems - 1; ++i) {
            elems[i] = elems[i + 1];
        }
        --nrElems;
    }

}

template <typename T>
VectorDinamic<T>::~VectorDinamic(){
    delete [] elems;
}



#endif //SD_LAB_ATM_VECTOR_H
