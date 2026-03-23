#include "../../include/piece.hpp"
#include <cmath>
using namespace std;

// Constructeur
Cavalier::Cavalier(Couleur couleur, int position)
    : Piece(couleur, nom, position)
{
}

// Vérification du mouvement légal
bool Cavalier::est_mouvement_legal(int case_origine, int case_destination) const
{
  int delta_ligne = abs(ligne(case_destination) - ligne(case_origine));
  int delta_col   = abs(colonne(case_destination) - colonne(case_origine));

  // Le cavalier se déplace en L : (2,1) ou (1,2)
  bool mouvement_en_L = (delta_ligne == 2 && delta_col == 1) ||
                        (delta_ligne == 1 && delta_col == 2);
  return mouvement_en_L;
}

std::string Cavalier::nom() const{
  if(couleur == Blanc) return "♜";
  else return "♖";
}
