#pragma once
#include <string>

using namespace std;

class Bohater; 

class Potwor {
public:
    int poziom;
    string nazwa;
    long int hp;
    int sila;

    Potwor(string n, long int h, int s);
    void Otrzymujobrazenia(int dmg);
    bool czyZyje();

    virtual void atakuj(Bohater& cel); 
};