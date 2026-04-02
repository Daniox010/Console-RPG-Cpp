#include "Bohater.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Bohater::Bohater(string imiegracza) {
    imie = imiegracza;
    poziom = 1;
    hp = 100;
    maxHp = 100;
    kondycja = 150;
    sila = 20;
}

void Bohater::pokazStatystyke() {
    cout << "Poziom: " << poziom << endl;
    cout << "Zdrowie: " << hp << endl;
    cout << "Kondycja: " << kondycja << endl;
    cout << "Sila: " << sila << endl;
}

void Bohater::atakSzybki(Potwor & cel) {
    cout << "\nWykonujesz szybki atak!" << endl;
    int losowa = rand() % 6;
    int dmg = sila + losowa;
    cout << "Wylosowales bonus " << losowa << " do ataku" << endl;
    cel.Otrzymujobrazenia(dmg);
    cout << "\n--------------------------------------------------------------------------------------------------------------------" << endl;
}

void Bohater::atakCiezki(Potwor & cel) {
    cout << "\nWykonujesz ciezki atak!" << endl;
    int losowa = rand() % 20;
    int dmg = (sila - 5) + losowa;
    if (dmg < 0) dmg = 0;
    cout << "Wylosowales bonus " << losowa << " do ataku" << endl;
    cel.Otrzymujobrazenia(dmg);
    cout << "\n--------------------------------------------------------------------------------------------------------------------" << endl;
}

void Bohater::awansuj() {
    poziom++;
    maxHp += 15;
    hp = maxHp;
    kondycja = kondycja + 25;
    sila = sila + 7;
    cout << "\nAwansujesz na poziom: " << poziom << "!" << endl;
    cout << "Twoje aktualne statystyki to: " << endl;
    cout << "Zdrowie: " << maxHp << endl;
    cout << "Kondycja: " << kondycja << endl;
    cout << "Sila: " << sila << endl;
}

void Bohater::otrzymujObrazenia(int dmg) {
    hp -= dmg;
    if (hp > 0) {
        cout << "Zostalo Ci " << hp << " punktow zdrowia!" << endl;
    } else {
        cout << "Nie zyjesz!" << endl;
    }
}

void Bohater::podniesPrzedmiot(string nazwaPrzedmiotu) {
    ekwipunek.push_back(nazwaPrzedmiotu);
    cout << "\nPodnosisz przedmiot: " << nazwaPrzedmiotu << "!" << endl;
}

void Bohater::pokazEkwipunek() {
    cout << "\n--- TWOJ PLECAK ---" << endl;
    if (ekwipunek.empty()) {
        cout << "(Pusty)" << endl;
    } else {
        for (string p : ekwipunek) {
            cout << "1. " << p << endl;
        }
    }
    cout << "--------------------" << endl;
}

void Bohater::usunPrzedmiot(string nazwaDoUsuniecia) {
    for (int i = 0; i < ekwipunek.size(); i++) {
        if (ekwipunek[i] == nazwaDoUsuniecia) {
            ekwipunek.erase(ekwipunek.begin() + i);
            return;
        }
    }
}