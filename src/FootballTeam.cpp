#include "FootballTeam.hpp"

// cerinta 3 - constructorul
FootballTeam::FootballTeam(const std::string& name, int size) 
    : teamName(name), squadSize(size) {
    players = new std::string[squadSize]; // alocare pe heap
    std::cout << "[Constructor] Echipa '" << teamName << "' a fost infiintata (Lot: " << squadSize << " jucatori).\n";
}

// cerinta 4 -  destructorul
FootballTeam::~FootballTeam() {
    std::cout << "[Destructor] Echipa '" << teamName << "' este desfiintata. Eliberam memoria lotului.\n";
    delete[] players;
}

// cerinta 5 -  copy constructor
// DE CE ESTE NEVOIE: Daca un obiect "FootballTeam" este copiat in altul si folosim copierea default (Shallow Copy),
// ambele obiecte ar avea pointerul "players" indreptat spre aceeasi zona de memorie. Cand se apeleaza destructorii, 
// programul va încerca sa stearga aceeasi memorie de doua ori (Double Free) si va crapa.
FootballTeam::FootballTeam(const FootballTeam& other) 
    : teamName(other.teamName + " (Echipa Secunda)"), squadSize(other.squadSize) {
    
    std::cout << "[Copy Constructor] Copiem tactica si lotul de la '" << other.teamName << "' in '" << teamName << "'.\n";
    
    // Alocam memorie noua (Deep Copy)
    players = new std::string[squadSize];
    for(int i = 0; i < squadSize; ++i) {
        players[i] = other.players[i];
    }
}

// cerinta 6 - move constructor
// DE CE ESTE NEVOIE: Daca intoarcem o echipa dintr-o functie (obiect temporar), copierea intregului array pe heap ar
// consuma mult timp si memorie degeaba. Move Constructor-ul muta direct "proprietatea" memoriei, fiind foarte eficient.
FootballTeam::FootballTeam(FootballTeam&& other) noexcept 
    : teamName(other.teamName + " (Relocata)"), squadSize(other.squadSize), players(other.players) {
    
    std::cout << "[Move Constructor] Mutam lotul echipei '" << other.teamName << "' fara a re-aloca memorie.\n";
    
    // anulam pointerul sursei ca sa nu stearga datele in destructorul ei
    other.players = nullptr;
    other.squadSize = 0;
    other.teamName = "Echipa Fantoma (Desfiintata)";
}

// incapsulare
void FootballTeam::setPlayer(int index, const std::string& playerName) {
    if (index >= 0 && index < squadSize && players != nullptr) {
        players[index] = playerName;
    }
}

void FootballTeam::printRoster() const {
    std::cout << "--- Lot " << teamName << " ---\n";
    if (players == nullptr) {
        std::cout << "  Echipa nu are jucatori (memorie mutata sau stearsa).\n";
        return;
    }
    for (int i = 0; i < squadSize; ++i) {
        std::cout << "  " << i + 1 << ". " << (players[i].empty() ? "[Liber]" : players[i]) << "\n";
    }
}

std::string FootballTeam::getName() const {
    return teamName;
}