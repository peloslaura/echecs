#include "../../include/piece.hpp"
#include <string>

using namespace std;

// Constructeur
Tour::Tour(Couleur couleur, int position) 
    : Piece(couleur, position,T) {}

// Vérification du mouvement légal
bool Tour::est_mouvement_legal(int case_destination) const{
    // Récupération des coordonnées
    int orig_ligne = ligne(position);
    int orig_col = colonne(position);
    int dest_ligne = ligne(case_destination);
    int dest_col = colonne(case_destination);



    // Mouvement horizontal (même ligne) ou vertical (même colonne)
    return (orig_ligne == dest_ligne && orig_col != dest_col) || 
           (orig_col == dest_col && orig_ligne != dest_ligne);
}

std::string Tour::nom() const{
    if(couleur == Blanc) return "♖";
    else return "♜";
}

string Tour::serialize() const { return Piece::serialize() + "R";}

Tour* Tour::clone()const{
    return new Tour(*this);
}

/*bool Tour::chemin_libre(int case_destination, Echiquier e){
    int orig_ligne = ligne(this->get_position());
    int orig_col = colonne(this->get_position());
    int dest_ligne = ligne(case_destination);
    int dest_col = colonne(case_destination);
    int directionh = (dest_ligne > orig_ligne) ? 1 : -1;
    int directionv = (dest_col > orig_col) ? 1 : -1;
    if(abs(orig_ligne-dest_ligne) == 0){// donc mouvement horizontal
        for(int i=1; i<abs(orig_col-dest_col);i++){
            if(e.get_piece(this->get_position() + i*directionh)!=nullptr){
                return false;
            }
        }
        return true;
    }
    if(abs(orig_col - dest_col)== 0){ //mouvement vertical
        for(int i =1; i<abs(orig_ligne - dest_ligne); i++){
            if(e.get_piece(this->get_position() + 7*i*directionv)!= nullptr){
                return false;
            }
        }
        return true;
    }

}*/