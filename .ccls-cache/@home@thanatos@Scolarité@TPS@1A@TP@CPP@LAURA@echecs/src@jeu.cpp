#include "../include/jeu.hpp"
#include "../include/echiquier.hpp"
#include "../include/piece.hpp"
#include <iostream>

using namespace std;

// Constructeur
Jeu::Jeu() : joueur_courant(Blanc), partie_terminee(false)
{
  // L'échiquier s'initialise automatiquement via son constructeur
}

// Affichage de l'échiquier
void Jeu::affiche() { echiquier.affiche(); }

// Gestion d'un coup
bool Jeu::coup()
{
  string origine, destination;

  cout << "Joueur " << (joueur_courant == Blanc ? "blanc" : "noir")
       << ", entrez votre coup (ex: e2 e4): ";
  cin >> origine >> destination;

  bool ok = deplace(origine, destination);
  if (!ok) cout << "Coup invalide, veuillez réessayer" << endl;

  return partie_terminee;
}

// Déplacement d'une pièce
bool Jeu::deplace(const string& orig_str, const string& dest_str)
{
  if (partie_terminee) return false;

  // orig et dest devraient renvoyer des entiers
  // penser à vérifier que orig_str et dest_str : [a-h][1-8][a-h][1-8] | O-O | O-O-O i.e match cette regex : `([a-h][1-9]){2}|O-O(-O)?`

  int orig(orig_str);
  int dest(dest_str);

  // Vérifie qu'il y a une pièce à l'origine
  Piece* piece = echiquier.get_piece(orig);
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
  if (piece->est_mouvement_legal(orig, dest))
  {

    // On ne mange pas une de nos pieces
    // get_piece(destination) != nullptr


    // Vérification des obstacles MAIS que pour une dame, une tour ou un fou ou un pion qui bouge de 2 cases
    if (!echiquier.chemin_libre(orig, dest))
    {
      return false;
    }

    // Effectue le déplacement
    Piece* piece_capturee = echiquier.get_piece(dest);
    if (piece_capturee != nullptr)
    {
      echiquier.delete_position(dest);
      // Gestion de la capture (à compléter selon vos besoins)
    }

    echiquier.deplace_piece(orig, dest);

    // Changement de joueur
    joueur_courant = (joueur_courant == Blanc) ? Noir : Blanc;

    return true;
  }
  else
  {
    return false;
  }
}
