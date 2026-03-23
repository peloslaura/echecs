#include "../../include/piece.hpp"
#include <cmath> // Pour abs()

using namespace std;

// Constructeur
Fou::Fou(Couleur couleur, int position)
    : Piece(couleur,position,F) {}



// Vérification du mouvement légal
bool Fou::est_mouvement_legal(int case_destination) const {
    int delta_ligne = abs(ligne(case_destination) - ligne(position));
    int delta_col   = abs(colonne(case_destination) - colonne(position));

    // Le fou se déplace en diagonale : la différence doit être égale sur les deux axes
    return delta_ligne == delta_col && delta_ligne > 0;
}

std::string Fou::nom() const{
    if(couleur == Blanc) return "♗";
    else return "♝";
}

string Fou::serialize() const { return Piece::serialize() + "B";}

Fou* Fou::clone()const{
    return new Fou(*this);
}
      
/*bool Fou::chemin_libre(int case_destination, Echiquier e){
    int orig_ligne = ligne(this->get_position());
    int orig_col = colonne(this->get_position());
    int dest_ligne = ligne(case_destination);
    int dest_col = colonne(case_destination);
    int lor = (dest_col > orig_col) ? 1 : -1; // 1 si on va a droite -1 sinon
    int hob = (dest_ligne > orig_ligne) ? 1 : -1; // 1 si on va en haut -1 sinon
    for(int i=1; i<abs(orig_ligne-dest_ligne); i++){
        if(e.get_piece(this->get_position()+lor*i+7*hob*i)!=nullptr){
            return false;
        }
    }
    return true;
}*/