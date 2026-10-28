#include "FootballTeam.hpp"
#include <iostream>
#include <utility>

// Functie care primeste prin valoare -> declanseaza copy constructorul
void organizeFriendlyMatch(FootballTeam awayTeam) {
    std::cout << "\n[Functie] Meci amical organizat cu:\n";
    awayTeam.printRoster();
    // La finalul functiei, `awayTeam` (copia) este distrusa. 
    // Daca nu aveam Deep Copy, se stergea si lotul echipei originale!
}

// Functie care creeaza o echipa si o returneaza -> declanseaza move constructorul
FootballTeam createDreamTeam() {
    FootballTeam dt("Dream Team", 2);
    dt.setPlayer(0, "Salah");
    dt.setPlayer(1, "Szoboszlai");
    return dt; 
}

int main() {
    std::cout << "=== SCENARIUL 1: Creare si Incapsulare ===\n";
    FootballTeam realMadrid("Real Madrid", 2);
    realMadrid.setPlayer(0, "Vinicius Jr.");
    realMadrid.setPlayer(1, "Bellingham");
    realMadrid.printRoster();

    std::cout << "\n=== SCENARIUL 2: Testam Copy Constructorul ===\n";
    // `realMadrid` este copiata in interiorul functiei
    organizeFriendlyMatch(realMadrid); 
    
    std::cout << "\n[Inapoi in main] Echipa originala inca exista:\n";
    realMadrid.printRoster(); 

    std::cout << "\n=== SCENARIUL 3: Testam Move Constructorul ===\n";
    // Functia creeaza o echipa temporara, iar proprietatea asupra array-ului
    // din heap este mutata (nu copiata) in 'myUltimateTeam'.
    FootballTeam myUltimateTeam = createDreamTeam();
    myUltimateTeam.printRoster();

    std::cout << "\n=== SCENARIUL 4: Mutare explicita (std::move) ===\n";
    // Vrem sa transferam jucatorii de la Real Madrid la o alta entitate, fara a-i clona
    FootballTeam galacticos = std::move(realMadrid);
    
    std::cout << "\nDupa std::move:\n";
    realMadrid.printRoster(); // Nu mai are memorie valida
    galacticos.printRoster(); // A primit memoria
    
    std::cout << "\n=== SFARSIT (Se apeleaza destructorii) ===\n";
    return 0;
}