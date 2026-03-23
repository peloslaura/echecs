#include "../include/jeu.hpp"
#include "../include/echiquier.hpp"
#include "../include/piece.hpp"
#include <iostream>

using namespace std;

// Constructeur
Jeu::Jeu() : joueur_courant(Blanc), partie_terminee(false)
{
  this->echiquier=Echiquier();
}

// Affichage de l'échiquier
void Jeu::affiche() { echiquier.affiche(); }
Echiquier Jeu::getEchiquier() { return echiquier; }
// Gestion d'un coup
//modif
int Jeu::coup()
{
  string mouvement;

  cout << "Joueur " << (joueur_courant == Blanc ? "blanc" : "noir")
       << ", entrez votre coup (ex: e2e4): ";
  cin >> mouvement;
  cout << mouvement << '\n';
  if(mouvement == "/quit"){
    return 1;
  }
  bool ok = deplace(mouvement.substr(0,2), mouvement.substr(2,2));
  if (!ok) cout << "Coup invalide, veuillez réessayer" << endl;
  

  //modif
  // ok=this->echiquier.echec_et_mat(joueur_courant);
  // if(ok){
  //   cout << "Echec et Mat !" << endl;
  //   return (joueur_courant==Blanc) ? 2 : 3;
  // } 

  // ok=this->echiquier.pat(joueur_courant);
  // if(ok){
  //   cout << "Pat! Egalité" << endl;
  //   return 4;
  // }
  //fin modif

  return 0;
}

int position_depuis_string(const string position){
  std::cout << position << '\n';
  int x = (position[0]) - 97;
  int y = 56 - position[1];
  return x + y * 8;
}

// Déplacement d'une pièce
bool Jeu::deplace(string orig_str, string dest_str)
{
  if (partie_terminee) return false;

  // orig et dest devraient renvoyer des entiers
  // penser à vérifier que orig_str et dest_str : [a-h][1-8][a-h][1-8] | O-O | O-O-O i.e match cette regex : `([a-h][1-9]){2}|O-O(-O)?`
  int orig = position_depuis_string(orig_str);
  int dest = position_depuis_string(dest_str);
  // Vérifie qu'il y a une pièce à l'origine
  shared_ptr<Piece> piece = echiquier.get_piece(orig);
  if (piece == nullptr)
  {
    cout << "Aucune pièce sur la case de départ" << endl;
    return false;
  }

  // Vérifie que c'est la bonne couleur
  if (piece->get_couleur() != joueur_courant)
  {
    cout << "Ce n'est pas votre pièce" << endl;
    return false;
  }

  // Vérification que le mouvement est légal
  if (piece->est_mouvement_legal(dest))
  {

    // On ne mange pas une de nos pieces
    if(echiquier.get_piece(dest) && echiquier.get_piece(dest)->get_couleur() == joueur_courant) return false;

    // Vérification des obstacles MAIS que pour une dame, une tour ou un fou ou un pion qui bouge de 2 cases
    if (!echiquier.chemin_libre(orig, dest))
    {
      cout << echiquier.chemin_libre(orig, dest) << '\n';
     return false;
    }

    // Effectue le déplacement
    shared_ptr<Piece> piece_capturee = echiquier.get_piece(dest);
    if (piece_capturee != nullptr)
      echiquier.supprimer_position(dest);

    
    Echiquier temp(echiquier);
    temp.deplace_piece(orig,dest);
    //Détection de l'echec
    if(temp.est_en_echec(joueur_courant) == true){
      cout << "Echec detecté !" << endl;
      return false;
    }

    echiquier.deplace_piece(orig, dest);

    // Changement de joueur
    joueur_courant = (joueur_courant == Blanc) ? Noir : Blanc;

    return true;
  }

  else
  {
    cout << "Mouvement pas légal\n";
    return false;
  }
}
