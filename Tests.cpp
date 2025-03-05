//
// Created by sebyc on 5/29/2024.
//
#include "Pair.h"
#include <assert.h>
#include "Tests.h"
#include <iostream>
#include "Vector.h"
#include "Collection.h"
#include "Atm.h"
#include "Tranzactie.h"
using namespace std;
void Test_Pair(){

    Pair<int, int> p(100, 2);
    assert(p.get_valoare() == 100);
    assert(p.get_numar() == 2);


    Pair<int, double> p1;
    //assert(p1.get_valoare() == int());
    //assert(p1.get_numar() == double());

    // Test parameterized constructor
    Pair<string, int> p2("Test", 42);
    assert(p2.get_valoare() == "Test");
    assert(p2.get_numar() == 42);

    // Test copy constructor
    Pair<string, int> p3(p2);
    assert(p3.get_valoare() == "Test");
    assert(p3.get_numar() == 42);

    // Test set_valoare and set_numar
    p1.set_valoare(10);
    p1.set_numar(20.5);
    assert(p1.get_valoare() == 10);
    assert(p1.get_numar() == 20.5);

    // Test set_valoare and set_numar with different types
    p2.set_valoare("New Value");
    p2.set_numar(100);
    assert(p2.get_valoare() == "New Value");
    assert(p2.get_numar() == 100);

    Pair<string, int> p4;
    Pair<string, int> p5("caine", 3);
    p4 = p5;
    assert(p4 == p5);

}

void Test_Vector() {


    try {
        VectorDinamic<int> v(3);
        VectorDinamic<int> v1(-3);
        assert(false);

    }
    catch (const char* ex)
    {
        assert(true);
    }

    VectorDinamic<int> v(3);

    v.push_back(14);
    v.push_back(20);
    v.push_back(15);
    v.push_back(18);
    v.push_back(6);
    v.push_back(8);
    v.push_back(8);

    VectorDinamic<int> v1(3);
    v1.push_back(13);
    v1.push_back(2);
    v1.push_back(15);
    v1.push_back(8);
    v1.push_back(8);
    v1.push_back(8);
    v1.push_back(8);
    try{
        assert(v1.getAt(0) == 13);
        assert(v1.getAt(3) == 8);
        assert(v1.getAt(6) == 8);
        assert(v1.getAt(-4) == 6);
        assert(v1.getAt(11) == 4);
        assert(false);
    }
    catch(const char* ex){
        assert(true);
    }

    v = v1;
    try{
        assert(v1.getAt(0) == 13);
        assert(v1.getAt(3) == 8);
        assert(v1.getAt(6) == 8);
        assert(v1.getAt(-4) == 6);
        assert(v1.getAt(11) == 4);
        assert(false);
    }
    catch(const char* ex){
        assert(true);
    }

    assert(v.get_nrElems() == 7);
    v.remove(13);
    assert(v.get_nrElems() == 6);
    v.remove(8);
    assert(v.get_nrElems() == 5);



}

void Test_Tranzactie(){
    Tranzactie t1;
    assert(t1.get_id() == 0);
    assert(t1.get_suma() == 0);
    assert(t1.get_monezi().empty());

    std::vector<Pair<int, int>> monezi1 = {Pair<int, int>(1, 2), Pair<int, int>(3, 4)};
    Tranzactie t2(1, 100, monezi1);
    assert(t2.get_id() == 1);
    assert(t2.get_suma() == 100);
    assert(t2.get_monezi() == monezi1);

    Tranzactie t3(t2);
    assert(t3.get_id() == 1);
    assert(t3.get_suma() == 100);
    assert(t3.get_monezi() == monezi1);

    t1.set_id(2);
    t1.set_suma(200);
    std::vector<Pair<int, int>> monezi2 = {Pair<int, int>(5, 6)};
    t1.set_monezi(monezi2);
    assert(t1.get_id() == 2);
    assert(t1.get_suma() == 200);
    assert(t1.get_monezi() == monezi2);
}

void Test_Collection(){

    Collection c;
    c.add(100);
    assert(c.size() == 1);

    c.add(200);
    c.add(100);

    assert(c.size() == 2);

    assert(c.search(100));
    assert(!c.search(400));

    assert(c.nroccurrences(300) == 0);
    assert(c.nroccurrences(100) == 2);
    c.add(100);
    assert(c.nroccurrences(100) == 3);
    assert(c.nroccurrences(200) == 1);
    assert(c.size() == 2);

    Collection c2(c);
    assert(c2.size() == 2);

    assert(c2.search(100));
    assert(!c2.search(400));

    assert(c2.nroccurrences(300) == 0);
    assert(c2.nroccurrences(100) == 3);

    c2.remove(100);

    assert(c2.nroccurrences(100) == 2);
    assert(c2.size() == 2);
    c2.remove(200);
    assert(c2.size() == 1);

    Collection c3;
    c3.add(100);
    assert(c3.nroccurrences(100) == 1);
    Collection c4;
    assert(c4.nroccurrences(100) == 0);
    c4 = c3;
    assert(c4.nroccurrences(100) == 1);

}


void Test_Atm(){
    Collection c;
    Atm MyAtm(c);
}

void Tests(){
    Test_Pair();
    Test_Vector();
    Test_Collection();
    Test_Tranzactie();
    Test_Atm();
}
