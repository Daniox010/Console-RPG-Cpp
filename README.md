# ⚔️ Konsolowe RPG w C++

Pierwsza wersja tekstowej gry RPG napisanej w C++. Projekt stworzony jako poligon doświadczalny do nauki programowania obiektowego i podstaw architektury gier.

## 👾 O projekcie
To klasyczne podejście do tematu RPG w terminalu. Gra pozwala na starcia między Twoim bohaterem a przeciwnikami generowanymi przez program. 

Projekt kładzie mocny nacisk na:
* **Programowanie Obiektowe (OOP):** Kod został logicznie podzielony na współpracujące ze sobą klasy (m.in. `Bohater`, `Potwor`).
* **Czystą strukturę:** Oddzielono pliki nagłówkowe (`.h`) definiujące strukturę od plików źródłowych (`.cpp`) z logiką.
* **Hermetyzację danych:** Statystyki postaci i potworów są bezpiecznie zamknięte wewnątrz klas.

## 📁 Struktura plików
```text
Gra_RPG/
├── Bohater.h     / Bohater.cpp  # Definicja i logika gracza
├── Potwor.h      / Potwor.cpp   # Definicja i logika przeciwników
├── main.cpp                     # Punkt wejścia aplikacji, główna pętla gry
└── README.md                    # Ten plik
🚀 Jak to odpalić?
Jeśli masz zainstalowany kompilator (np. g++ lub clang na macOS/Linuxie), możesz szybko odpalić grę prosto z terminala.

Pobierz repozytorium na dysk.

Otwórz terminal w folderze z grą.

Skompiluj wszystkie pliki źródłowe do jednego programu o nazwie gra:

Bash
g++ main.cpp Bohater.cpp Potwor.cpp -o gra
Uruchom gotową grę:

Bash
./gra
Projekt tworzony w celach edukacyjnych, jako wstęp do bardziej zaawansowanych mechanik w C++. 🎮