#include "FootballTeam.hpp"

// cerinta 3 / Item 4: Constructor folosind lista de initializare
FootballTeam::FootballTeam(const std::string& name, int size) 
    : teamName(name), squadSize(size) {
    players = new std::string[squadSize]; // alocare pe heap
    std::cout << "[Constructor] Echipa '" << teamName << "' a fost infiintata (Lot: " << squadSize << " jucatori).\n";
}

// cerinta 4 / Item 5: Destructorul silentios
FootballTeam::~FootballTeam() {
    std::cout << "[Destructor] Echipa '" << teamName << "' este desfiintata. Eliberam memoria lotului.\n";
    delete[] players;
}

// cerinta 5 / Item 12: Copy constructor (Deep Copy pt a evita Double Free)
FootballTeam::FootballTeam(const FootballTeam& other) 
    : teamName(other.teamName + " (Echipa Secunda)"), squadSize(other.squadSize) {
    
    std::cout << "[Copy Constructor] Copiem tactica si lotul de la '" << other.teamName << "' in '" << teamName << "'.\n";
    
    players = new std::string[squadSize];
    for(int i = 0; i < squadSize; ++i) {
        players[i] = other.players[i];
    }
}


// ================= NOILE CERINTE (L5) =================

// Item 10, 11, 12 implementate in operatorul =
FootballTeam& FootballTeam::operator=(const FootballTeam& rhs) {
    std::cout << "[Copy Assignment] Transferam datele din '" << rhs.teamName << "' in '" << teamName << "'.\n";

    // Item 11: Protectie la auto-atribuire (self-assignment)
    if (this == &rhs) {
        std::cout << "  -> [Item 11] Auto-atribuire ignorata. Nu se sterge memoria.\n";
        return *this; // Item 10
    }

    // Eliberam memoria lotului curent inainte de a suprascrie
    delete[] players;

    // Item 12: Copiere completa a tuturor atributelor
    teamName = rhs.teamName + " (Transferat)";
    squadSize = rhs.squadSize;
    
    players = new std::string[squadSize];
    for (int i = 0; i < squadSize; ++i) {
        players[i] = rhs.players[i];
    }

    // Item 10: Returnam *this pentru a permite inlantuiri (a = b = c)
    return *this;
}

// ======================================================


// cerinta 6: Move constructor (Steal the memory)
FootballTeam::FootballTeam(FootballTeam&& other) noexcept 
    : teamName(other.teamName + " (Relocata)"), squadSize(other.squadSize), players(other.players) {
    
    std::cout << "[Move Constructor] Mutam lotul echipei '" << other.teamName << "' fara a re-aloca memorie.\n";
    
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