#include "../../include/piece.hpp"
#include <cmath> // Pour abs()

using namespace std;

// Constructeur
Dame::Dame(Couleur couleur, int position)
    : Piece(couleur, position,D) {}


// Vérification du mouvement légal
bool Dame::est_mouvement_legal(int case_destination) const {
    int delta_ligne = abs(ligne(case_destination) -ligne(position));
    int delta_col = abs(colonne(case_destination) - colonne(position));

    // Mouvement de tour (même ligne ou même colonne)
    bool mouvement_tour = (ligne(position) == ligne(case_destination)) || 
                         (colonne(position) == colonne(case_destination));

    // Mouvement de fou (diagonale)
    bool mouvement_fou = (delta_ligne == delta_col);

    return (mouvement_tour || mouvement_fou) && (delta_ligne > 0 || delta_col > 0);
}

std::string Dame::nom() const{
    if(couleur == Blanc) return "♕";
    else return "♛";
}

string Dame::serialize() const { return Piece::serialize() + "Q";}

Dame* Dame::clone()const{
    return new Dame(*this);
}

/*bool Dame::chemin_libre(int case_destination, Echiquier e){
    int orig_ligne = ligne(this->get_position());
    int orig_col = colonne(this->get_position());
        int dest_ligne = ligne(case_destination);
        int dest_col = colonne(case_destination);
        int delta_ligne = dest_ligne - orig_ligne;
        int delta_col = dest_col - orig_col;

        if(delta_ligne == delta_col){

            int lor = (dest_col > orig_col) ? 1 : -1; // 1 si on va a droite -1 sinon
            int hob = (dest_ligne > orig_ligne) ? 1 : -1; // 1 si on va en haut -1 sinon
            for(int i=1; i<abs(orig_ligne-dest_ligne); i++){
                if(e.get_piece(this->get_position()+lor*i+7*hob*i)!=nullptr){
                    return false;
                }
            }
            return true;
        }

        else{
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
        }
    
    }*/