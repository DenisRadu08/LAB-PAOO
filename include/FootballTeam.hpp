#pragma once
#include <string>
#include <iostream>

class FootballTeam {
private:
    std::string teamName;
    int squadSize;
    std::string* players;

public:
    // cerinta 3 - initializare membri din constructor
    FootballTeam(const std::string& name, int size);

    // cerinta 4 - eliberare heap in destructor
    ~FootballTeam();

    // cerinta 5 - suprascrierea copy constructorului
    FootballTeam(const FootballTeam& other);

    // cerinta 6 - crearea unui move constructor
    FootballTeam(FootballTeam&& other) noexcept;

    // Metode pentru incapsulare
    void setPlayer(int index, const std::string& playerName);
    void printRoster() const;
    std::string getName() const;
};