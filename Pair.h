//
// Created by sebyc on 5/29/2024.
//

#ifndef SD_LAB_ATM_PAIR_H
#define SD_LAB_ATM_PAIR_H

template <typename V, typename N>
class Pair {
private:
    V valoare;
    N numar;
public:
    Pair() : valoare(V()), numar(N()) {

    }
    Pair(V valoare, N numar) : valoare(valoare), numar(numar) {

    }
    Pair(const Pair<V, N>& p) : valoare(p.valoare), numar(p.numar) {

    }
    ~Pair() {

    }

    void set_valoare(V valoare) {
        this->valoare = valoare;
    }
    void set_numar(N numar) {
        this->numar = numar;
    }

    V get_valoare() const {
        return valoare;
    }

    N get_numar() const {
        return numar;
    }

    void operator=(const Pair<V, N>& p) {
        this->valoare = p.valoare;
        this->numar = p.numar;
    }

    bool operator==(const Pair<V, N>& p) const {
        return (this->valoare == p.valoare && this->numar == p.numar);
    }
};
#endif //SD_LAB_ATM_PAIR_H
