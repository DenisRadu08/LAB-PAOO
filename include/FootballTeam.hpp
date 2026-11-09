#pragma once
#include <string>
#include <iostream>

class FootballTeam {
private:
    std::string teamName;
    int squadSize;
    std::string* players;

public:
    // --- Lucrarea 4 ---
    
    // Item 6: Interzicem explicit constructorul default generat de compilator
    // Nu vrem sa existe o echipa fara nume si fara dimensiune de lot.
    FootballTeam() = delete;

    // Item 4 & 5: Constructor (initializat corect) si Destructor
    FootballTeam(const std::string& name, int size);
    ~FootballTeam();

    // cerinta 5 / Item 12: suprascrierea copy constructorului
    FootballTeam(const FootballTeam& other);

    // cerinta 6: crearea unui move constructor
    FootballTeam(FootballTeam&& other) noexcept;


    // --- Lucrarea 5 ---
    
    // Item 10, Item 11, Item 12: Operatorul de atribuire
    FootballTeam& operator=(const FootballTeam& rhs);


    // Metode pentru incapsulare
    void setPlayer(int index, const std::string& playerName);
    void printRoster() const;
    std::string getName() const;
};