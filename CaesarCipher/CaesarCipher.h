#ifndef CAESARCIPHER_H_INCLUDED
#define CAESARCIPHER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CaesarCipher {
public:
    CaesarCipher(int _shift);
    void setShift(int _shift);
    int getShift();
    void encrypt(string filename);
    void decrypt(string filename);
private:
    int shift;
};

#endif // CAESARCIPHER_H_INCLUDED
