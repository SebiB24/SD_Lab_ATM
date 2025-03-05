//
// Created by sebyc on 5/30/2024.
//

#ifndef SD_LAB_ATM_EXCEPT_H
#define SD_LAB_ATM_EXCEPT_H
#include <stdexcept>
#include <iostream>
using namespace std;
class Except: public runtime_error{
private:
    char* mesaj;
public:
    Except(char* mesaj): runtime_error(mesaj), mesaj(mesaj){}
    char* what(){
        return mesaj;
    }
};
#endif //SD_LAB_ATM_EXCEPT_H
