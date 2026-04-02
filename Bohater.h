#pragma once
#include <string>
#include <vector>
#include "Potwor.h" 

using namespace std;


class Bohater {
public:

	int poziom;
	string imie;
	long int hp;
	long int maxHp;
	long int kondycja;
	int sila;
	vector<string> ekwipunek;

    Bohater(string imiegracza);
    void pokazStatystyke();
    void atakSzybki(Potwor & cel);
    void atakCiezki(Potwor & cel);
    void awansuj();
    void otrzymujObrazenia(int dmg);
    void podniesPrzedmiot(string nazwaPrzedmiotu);
    void pokazEkwipunek();
    void usunPrzedmiot(string nazwaDoUsuniecia);
};