#include "../include/piece.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Constructeur paramétré
Piece::Piece(Couleur couleur, int position)
    : couleur(couleur), position(position) // Liste d'initialisation
{
}

int Piece::get_position() { return position; }

void Piece::set_position(int position)
{
  if (0 > position || position >= 64)
    throw out_of_range("Coordonnées en dehors de l'échiquier");
  this->position = position;
  return;
}

Couleur Piece::get_couleur() { return couleur; }
