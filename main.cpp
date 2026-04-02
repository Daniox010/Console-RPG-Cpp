#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Potwor.h"
#include "Bohater.h"

using namespace std;


class Boss : public Potwor {
public:
	int iloscsuperatakow = 1;

    Boss() : Potwor("Shrek", 200, 12) {}

    void atakuj(Bohater& cel) override {
        if(hp < 100 && iloscsuperatakow > 0) {
            cout << "\n" << nazwa << " wpada w szal i wyprowadza super atak!" << endl;
            cel.otrzymujObrazenia(sila * 2);
            iloscsuperatakow--;
        } else {
            cout << nazwa << " uderza potezna piescia!" << endl;
            cel.otrzymujObrazenia(sila);
        }
    }
};

class Megaboss : public Potwor {
public:
    int iloscOgnia = 1;

    Megaboss() : Potwor("Smok", 300, 12) {}

    void atakuj(Bohater& cel) override {
        if (hp < 150 && iloscOgnia > 0) {
            cout << "\n" << nazwa << " uzywa ognistego oddechu!" << endl;
            cel.otrzymujObrazenia(sila * 2);
            iloscOgnia--;
        } else {
            cout << nazwa << " uderza ciezkim ogonem!" << endl;
            cel.otrzymujObrazenia(sila);
        }
    }
};

void rozpocznijWalke(Bohater& gracz, Potwor* wrog) {
    cout << "\n--- Rozpoczyna sie walka z " << wrog->nazwa << " ---" << endl;
    while (wrog->czyZyje() && gracz.hp > 0){
        cout << "\n" << wrog->nazwa << " ma: " << wrog->hp << " HP." << endl;
        cout << "1. Szybki atak (Pewny)\n2. Mocny atak (Ryzykowny)\nWybor: ";

        int wybor;
        cin >> wybor;

        if (wybor == 1) {
            gracz.atakSzybki(*wrog); 
        }
        else if (wybor == 2) {
            gracz.atakCiezki(*wrog);
        }
        else {
            cout << "Pudlo, tracisz ture!" << endl;
        }

        if (wrog->czyZyje()) {
            wrog->atakuj(gracz);    
        }
    }
}
    

int main() {

	srand((unsigned int)time(NULL));

	cout << "Witaj w krainie cieni wojowniku!" << endl;
	cout << "Przed toba dluga wyprawa, by sie stad wydostac." << endl;
	cout << "Powiedz mi wpierw jak masz na imie: ";

	string imiegracza;
	cin >> imiegracza;

	Bohater gracz(imiegracza);

	cout << "\nWitaj " << imiegracza << "! Twoja przygoda wlasnie sie zaczyna, ponizej znajdziesz statystki postaci:" << endl;

	gracz.pokazStatystyke();

	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

	cout << "W oddali zauwazyles swiatlo. Zaczynasz kierowac sie w jego strone. Po drodze napotykasz bandyte... " << endl;

	Potwor wrog("Goblin", 25, 5);

    rozpocznijWalke(gracz, &wrog);
	
	cout << "\nWlasnie pokonales swojego pierwszego przeciwnika, GRATULACJE!" << endl;

	gracz.awansuj();

	cout << "\nPo wielu godzinach wedrowki w oddali dostrzegasz cos przez gesta mgle. Nie jestes w stanie okreslic co to , wiec postanawiasz podejsc blizej. " << endl;
	cout << "Przypomina to bagno, które jest strzezone przez wielkiego ogra - Shreka, zeby dalej przejsc musisz stanac z nim do walki, lecz uwazaj, jest to potezny przeciwnik." << endl;

    bool czyPowtorzyc = true;

	string shrekArt = R"(
        .----.
       / .  . \
      (   __   )  
       \ '..' /
     _  \    /  _
    | |/`----`\| | 
    | |        | |
    |_|        |_|
   (  )________(  )
    )";

	cout << shrekArt << endl;

	do {
        Boss boss;
        if (gracz.hp < 120) gracz.hp = 115;

        rozpocznijWalke(gracz, &boss);

        if (gracz.hp > 0) {
            cout << "\nGratulacje wygranej!" << endl;
            gracz.awansuj();
            czyPowtorzyc = false;
        }
        else {
            cout << "\nCzy chcesz sprobowac ponownie? (t/n)" << endl;
            char decyzja;
            cin >> decyzja;
            if (decyzja == 't' || decyzja == 'T') czyPowtorzyc = true;
            else {
                czyPowtorzyc = false;
                cout << "\nKoniec gry." << endl;
            }
        }
    } while (czyPowtorzyc == true);

	cout << "Przeszukujesz zwloki Shreka...";
	gracz.podniesPrzedmiot(" Klucz do bagna");

	cout << " " << endl;
	gracz.pokazEkwipunek();

	cout << "\nPo wyczerpujacej przeprawie postanawiasz schronic sie w chacie ogra. Rozpalasz ognisko i idziesz spac..." << endl;
	cout << "Budzisz sie rano wypoczety, z pelnym, zregenerowanym zdrowiem." << endl;
	cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

	gracz.hp = gracz.maxHp;

	cout << "Jest juz jasno, wiec kieriujesz sie do wyjscia, lecz nagle cos przykuwa twoja uwage..." << endl;
	cout << "Zauwazasz dziwne, metalowe drzwi, postanawiasz otworzyc je wczesniej znalezionym kluczem.  " << endl;

	gracz.usunPrzedmiot(" Klucz do bagna");

	cout << "\nDrzwi otwieraja sie ze zgrzytem..." << endl;
	cout << "Wchodzisz do ciemnego korytarza. Powietrze jest stechle i zimne." << endl;
	cout << "Idziesz chwile przed siebie, az korytarz rozdziela sie na dwoje." << endl;

	bool czyPowtorzyc1 = true;

	do {
		if (gracz.hp < gracz.maxHp) gracz.hp = gracz.maxHp;

		cout << "\nSciezka po LEWEJ wyglada na opuszczona, ale widzisz tam jakas skrzynie." << endl;
		cout << "Sciezka po PRAWEJ tonie w mroku, slyszysz tam dziwne grzechotanie." << endl;

		cout << "\nGdzie idziesz?" << endl;
		cout << "1. W lewo (Do skrzyni)" << endl;
		cout << "2. W prawo (W strone dzwieku)" << endl;
		cout << "Wybor: ";

		int wyborLochy;
		cin >> wyborLochy;

		if (wyborLochy == 1) {
			cout << "\nIdziesz w strone skrzyni. Jestes juz prawie przy niej... " << endl;
			cout << "KLIK! Poczules jak plytka zapada sie pod toba!" << endl;

			int obrazeniaPulapki = 100 + (rand() % 50);
			gracz.otrzymujObrazenia(obrazeniaPulapki);

			if (gracz.hp > 0) {
				cout << "Uff... Przezyles pulapke z kolcami. Podchodzisz do skrzyni." << endl;
				gracz.podniesPrzedmiot("Starozytna Tarcza");
				czyPowtorzyc1 = false;
			}
			else {
				cout << "\nKONIEC GRY!" << endl;
				cout << "\nCzy chcesz sprobowac ponownie? (t/n)" << endl;

				char decyzja;
				cin >> decyzja;

				if (decyzja == 't' || decyzja == 'T') {
					czyPowtorzyc1 = true;
				}
				else {
					czyPowtorzyc1 = false;
					cout << "\nKoniec gry." << endl;
				}

			}
		}
		else {
			cout << "\nIdziesz w strone dzwieku. Z cienia wylania sie kupa kosci..." << endl;
			cout << "To ozywiony szkielet! Wyciaga zardzewialy miecz!" << endl;

			Potwor szkielet1("Szkielet", 80, 10);

			rozpocznijWalke(gracz, &szkielet1);

			if (gracz.hp > 0) {
				cout << "\nRozsypales szkieleta w pyl" << endl;
				gracz.podniesPrzedmiot("Mikstura Zycia");
				czyPowtorzyc1 = false;
			}
			else {
				cout << "\nCzy chcesz sprobowac ponownie? (t/n)" << endl;

				char decyzja;
				cin >> decyzja;

				if (decyzja == 't' || decyzja == 'T') {
					czyPowtorzyc1 = true;
				}
				else {
					czyPowtorzyc1 = false;
					cout << "\nKoniec gry." << endl;
				}

			}
		}
	} while (czyPowtorzyc1 == true);
    
	if (gracz.hp > 0) {
		gracz.hp = gracz.maxHp;
		cout << "\nWchodzisz po kretych schodach na gore..." << endl;
		cout << "Nagle uderza Cie swieze, nocne powietrze. Wyszedles na dziedziniec zamku!" << endl;

		string ognisko = R"(
           (
          . )
       )  (  (
      (  , )  )
     ._(__)__._
    |__________|
    )";
		cout << ognisko << endl;

		cout << "Na srodku dziedzinca pali sie ognisko. Siedzi przy nim zakapturzona postac." << endl;
		cout << "Postac spoglada na Ciebie: 'Widze, ze udalo Ci sie przetrwac lochy...'" << endl;
		cout << "'Moge Ci pomoc przed ostatecznym starciem, ale wybierz madrze.'" << endl;

		cout << "\n--- OFERTA WEDROWCA ---" << endl;
		cout << "1. Wypij Wywar z Ziol (Ulecz HP do pelna + zwieksz Max HP o 50)" << endl;
		cout << "2. Naostrz Miecz (Zwieksz Sile o 10)" << endl;
		cout << "3. Odpocznij (Zregeneruj sily i nic nie zmieniaj - dla odwaznych)" << endl;
		cout << "Wybor: ";

		int i;
		cin >> i;

		if (i == 1) {
			gracz.maxHp += 50;
			gracz.hp = gracz.maxHp;
		}
		else if (i == 2) {
			gracz.sila += 10;
		}
		else {
			cout << "Siły zregenerowane - powodzenia!" << endl;
		}
	}

    cout << "\n " << endl;
    cout << "Twoje aktualne statystyki to: " << endl;
    gracz.pokazStatystyke();

    cout << "\nNadszedl czas na ostateczne starcie..." << endl;
    cout << "Z oddali slyszysz glosne, rytmiczne odglosy krokow. To on - ostatni boss, ktory stoi Ci na drodze do wolnosci..." << endl;
    cout << "Z cienia wyłania sie ogromny smok! Jego łuski błyszczą w świetle księżyca, a oczy płoną czerwienią. To ostatnia przeszkoda, która stoi między tobą a wolnością." << endl;
    
    do {
        Megaboss megaboss;
        rozpocznijWalke(gracz, &megaboss);

            if (gracz.hp <= 0) {
                cout << "\nCzy chcesz sprobowac ponownie? (t/n)" << endl;

                char decyzja;
                cin >> decyzja;

                if (decyzja == 't' || decyzja == 'T') {
                    gracz.hp = gracz.maxHp;
                }
            else {
                cout << "\nKoniec gry." << endl;
                return 0;
                }
            }
            if (!megaboss.czyZyje()) {
                cout << "\nGratulacje! Pokonales smoka i wydostales sie z zamku!" << endl;
                break;
        }
    } while (true);

    cout << "\nNacisnij Enter, aby zakonczyc gre..." << endl;
    cin.ignore();
    cin.get();
    
    return 0;
}
