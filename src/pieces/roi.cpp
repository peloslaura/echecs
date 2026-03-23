#include "../../include/piece.hpp"
#include <cmath> // Pour abs()

using namespace std;

// Constructeur
Roi::Roi(Couleur couleur, int position)
    : Piece(couleur, position,R) {}


// Vérification du mouvement légal
bool Roi::est_mouvement_legal(int case_destination) const{
  
    int diff_ligne = abs(ligne(case_destination) - ligne(position));
    int diff_col = abs(colonne(case_destination) - colonne(position));

    // Le roi peut se déplacer d'une case dans toutes les directions
    // (différence de 0 ou 1 sur les deux axes, mais pas 0 sur les deux)
    return (diff_ligne <= 1 && diff_col <= 1) && !(diff_ligne == 0 && diff_col == 0);

}
std::string Roi::nom() const{
    if(couleur == Blanc) return "♔";
    else return "♚";
}

string Roi::serialize() const { return Piece::serialize() + "K";}

Roi* Roi::clone()const{
    return new Roi(*this);
}