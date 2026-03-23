#include "../include/piece.hpp"
#include "../include/echiquier.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Constructeur paramétré
Piece::Piece(Couleur couleur, int position,Type t)
    : couleur(couleur), position(position),type(t){} // Liste d'initialisation

int Piece::get_position() { return position; }

void Piece::set_position(int position)
{
  if (0 > position || position >= 64)
    throw out_of_range("Coordonnées en dehors de l'échiquier");
  this->position = position;
  return;
}

Couleur Piece::get_couleur() { return couleur; }

string Piece::serialize() const { return couleur == Blanc ? "w" : "b";}

Type Piece::get_type()const{
  return this->type;
}
