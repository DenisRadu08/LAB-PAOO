#include "FootballTeam.hpp"
#include <iostream>
#include <utility>

void organizeFriendlyMatch(FootballTeam awayTeam) {
    std::cout << "\n[Functie] Meci amical organizat cu:\n";
    awayTeam.printRoster();
}

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
    organizeFriendlyMatch(realMadrid); 
    
    std::cout << "\n[Inapoi in main] Echipa originala inca exista:\n";
    realMadrid.printRoster(); 

    std::cout << "\n=== SCENARIUL 3: Testam Move Constructorul ===\n";
    FootballTeam myUltimateTeam = createDreamTeam();
    myUltimateTeam.printRoster();

    std::cout << "\n=== SCENARIUL 4: Mutare explicita (std::move) ===\n";
    FootballTeam galacticos = std::move(realMadrid);
    
    std::cout << "\nDupa std::move:\n";
    realMadrid.printRoster(); 
    galacticos.printRoster(); 


    // ==========================================================
    // ============ ADAUGARI LUCRARILE 4 SI 5 ===================
    // ==========================================================

    std::cout << "\n=== SCENARIUL 5: Item 6 (Fara constructor default) ===\n";
    std::cout << "Linia 'FootballTeam echipaGoala;' ar da eroare la compilare din cauza '= delete'.\n";
    // FootballTeam echipaGoala; 

    std::cout << "\n=== SCENARIUL 6: Item 11 (Auto-atribuire) ===\n";
    FootballTeam liverpool("Liverpool", 2);
    liverpool.setPlayer(0, "Salah");
    liverpool.setPlayer(1, "Van Dijk");
    
    std::cout << "Executam: liverpool = liverpool;\n";
    liverpool = liverpool; 
    liverpool.printRoster();

    std::cout << "\n=== SCENARIUL 7: Item 10 & 12 (Atribuire inlantuita) ===\n";
    FootballTeam chelsea("Chelsea", 2);
    chelsea.setPlayer(0, "Palmer");
    
    FootballTeam arsenal("Arsenal", 2);
    
    std::cout << "Executam: arsenal = chelsea = liverpool;\n";
    arsenal = chelsea = liverpool;

    std::cout << "\n[Status dupa transferuri]\n";
    liverpool.printRoster();
    chelsea.printRoster();
    arsenal.printRoster();

    std::cout << "\n=== SFARSIT (Se apeleaza destructorii) ===\n";
    return 0;
}