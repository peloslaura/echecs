#include "../../include/piece.hpp"
#include <cctype> // Pour tolower()
#include <string>

using namespace std;

// Constructeur
Pion::Pion(Couleur couleur, int position)
    : Piece(couleur, position,P) {}



// Vérification du mouvement légal
bool Pion::est_mouvement_legal(int case_destination) const {
    
    int orig_ligne = ligne(position);
    int orig_col = colonne(position);
    int dest_ligne = ligne(case_destination);
    int dest_col = colonne(case_destination);

    int diff = abs(orig_col - dest_col);
    
    int dir = (couleur == Blanc) ? -1 : 1; // Direction selon la couleur
    bool aPasBouge = (couleur == Blanc && position / 8 == 6) || (couleur == Noir && position / 8 == 1);
    return (aPasBouge && orig_col == dest_col && orig_ligne + 2 * dir == dest_ligne) || (diff <= 1 && orig_ligne + dir == dest_ligne);
}
    

string Pion::nom() const {
    if(couleur == Blanc) return "♙";
    else return "♟";
}

string Pion::serialize() const { return Piece::serialize() + "P";}

Pion* Pion::clone()const{
    return new Pion(*this);
}