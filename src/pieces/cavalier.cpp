#include "../../include/piece.hpp"
#include <cmath>
using namespace std;

// Constructeur
Cavalier::Cavalier(Couleur couleur, int position)
    : Piece(couleur, position,C)
{
}

// Vérification du mouvement légal
bool Cavalier::est_mouvement_legal(int case_destination) const
{
  int delta_ligne = abs(ligne(case_destination) - ligne(position));
  int delta_col   = abs(colonne(case_destination) - colonne(position));

  // Le cavalier se déplace en L : (2,1) ou (1,2)
  bool mouvement_en_L = (delta_ligne == 2 && delta_col == 1) ||
                        (delta_ligne == 1 && delta_col == 2);
  return mouvement_en_L;
}

std::string Cavalier::nom() const{
  if(couleur == Blanc) return "♘";
  else return "♞";
}

string Cavalier::serialize() const { return Piece::serialize() + "N";}

Cavalier* Cavalier::clone()const{
  return new Cavalier(*this);
}
