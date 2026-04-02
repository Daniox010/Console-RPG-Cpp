#include "Potwor.h" 
#include <iostream>
#include "Bohater.h"

using namespace std;

Potwor::Potwor(string n, long int h, int s) {
    nazwa = n;
    hp = h;
    sila = s;
}

void Potwor::Otrzymujobrazenia(int dmg) {
    hp = hp - dmg;

    if (hp <= 0) {
        hp = 0;
        cout << "Potwor obrywa za " << dmg << " i zostaje pokonany!" << endl;
    }
    else {
        cout << "Potwor obrywa za " << dmg << ", zostalo mu " << hp << " punktow zdrowia. " << endl;
    }
}

void Potwor::atakuj(Bohater& cel) {
    cout << nazwa << " uderza!" << endl;
    cel.otrzymujObrazenia(sila);
}

bool Potwor::czyZyje() {
    if (hp > 0) return true;
    else return false;
}
