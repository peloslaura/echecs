#include "../include/echiquier.hpp"
#include "../include/piece.hpp"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// Constructeur
Echiquier::Echiquier()
{
  // Création des pièces blanches
  pieces[Blanc] = {shared_ptr<Piece>(new Tour(Blanc, 56)),
                   shared_ptr<Piece>(new Cavalier(Blanc, 57)),
                   shared_ptr<Piece>(new Fou(Blanc, 58)),
                   shared_ptr<Piece>(new Dame(Blanc, 59)),
                   shared_ptr<Piece>(new Roi(Blanc, 60)),
                   shared_ptr<Piece>(new Fou(Blanc, 61)),
                   shared_ptr<Piece>(new Cavalier(Blanc, 62)),
                   shared_ptr<Piece>(new Tour(Blanc, 63))};

  for (int i = 0; i < 8; i++)
    pieces[Blanc].push_back(shared_ptr<Piece>(new Pion(Blanc, 48 - i)));

  // Faire les pièces noires
}

// Affichage de l'échiquier
void Echiquier::affiche() const
{
  string space5 = string(5, ' ');
  cout << endl;
  cout << "     a     b     c     d     e     f     g     h    " << endl;
  cout << "  +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;

  for (int i = 0; i < 8; i++)
  {
    cout << i + 1 << " "; // numérotation ligne
    for (int j = 0; j < 8; j++)
    {
      cout << "|";
      if (get_piece(i * 8 + j) != nullptr)
        std::cout << get_piece(i * 8 + j)->nom();
      else
        cout << space5;
    }
    cout << "|\n  +-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
  }
}

// Récupération d'une pièce
shared_ptr<Piece> Echiquier::get_piece(int position) const
{
  int ligne_var   = ligne(position);
  int colonne_var = colonne(position);

  if (ligne_var < 0 || ligne_var >= 8 || colonne_var < 0 || colonne_var >= 8)
    throw out_of_range("Coordonnées en dehors de l'échiquier");

  for (auto& p : pieces[Blanc])
    if (p->get_position() == position) return p;

  // Faire les pièces noires

  return nullptr;
}

void Echiquier::supprimer_position(int position)
{
  int ligne_var   = ligne(position);
  int colonne_var = colonne(position);

  if (ligne_var < 0 || ligne_var >= 8 || colonne_var < 0 || colonne_var >= 8)
    throw out_of_range("Coordonnées en dehors de l'échiquier");

  shared_ptr<Piece> p;

  for (int i = 0; i < (int)this->pieces[Blanc].size(); i++)
  {
    p = this->pieces[Blanc][i];
    if (p->get_position() == position)
      this->pieces[Blanc].erase(this->pieces[Blanc].begin() + i);
  }

  // Faire les pièces noires

  return;
}

void deplace_piece(int org, int dest){
  get_piece(org)->set_position(dest);

}
