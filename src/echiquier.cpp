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
    pieces[Blanc].push_back(shared_ptr<Piece>(new Pion(Blanc, 48 + i)));

  // Faire les pièces noires
  pieces[Noir] = {shared_ptr<Piece>(new Tour(Noir, 0)),
    shared_ptr<Piece>(new Cavalier(Noir, 1)),
    shared_ptr<Piece>(new Fou(Noir, 2)),
    shared_ptr<Piece>(new Dame(Noir, 3)),
    shared_ptr<Piece>(new Roi(Noir, 4)),
    shared_ptr<Piece>(new Fou(Noir, 5)),
    shared_ptr<Piece>(new Cavalier(Noir, 6)),
    shared_ptr<Piece>(new Tour(Noir, 7))};

  for (int i = 8; i < 16; i++)
    pieces[Noir].push_back(shared_ptr<Piece>(new Pion(Noir, i)));
}

Echiquier::Echiquier(const Echiquier& copie) {
  for(auto p : copie.pieces[Blanc]) {
    this->pieces[Blanc].push_back(shared_ptr<Piece>(p->clone()));
  }
  for(auto p : copie.pieces[Noir]) {
    this->pieces[Noir].push_back(shared_ptr<Piece>(p->clone()));
  }
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
    cout << 8 - i << " "; // numérotation ligne
    for (int j = 0; j < 8; j++)
    {
      cout << "|";
      if (get_piece(i * 8 + j) != nullptr)
        std::cout << "  " << get_piece(i * 8 + j)->nom() << "  ";
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
    if (p!=nullptr && p->get_position() == position) return p;

  for (auto& p : pieces[Noir])
    if (p!=nullptr && p->get_position() == position) return p;

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

  for (int i = 0; i < (int)this->pieces[Noir].size(); i++)
  {
    p = this->pieces[Noir][i];
    if (p->get_position() == position)
      this->pieces[Noir].erase(this->pieces[Noir].begin() + i);
  }
  return;
}

void Echiquier::deplace_piece(int org, int dest){
  shared_ptr<Piece> piece = get_piece(org);
  piece->set_position(dest);
  return;
}

bool Echiquier::chemin_libre(int org, int dest){

  int orig_ligne = ligne(org);
  int orig_col = colonne(org);
  int dest_ligne = ligne(dest);
  int dest_col = colonne(dest);
  

  char id =  get_piece(org)->serialize()[1];
  if(id == 'N' || id == 'K'){
    return true;
  }
  int ligne_inter  = ligne(org) + (ligne(org)< ligne(dest) ? 1 : -1);

  if(id == 'P') {
    if((abs(ligne(dest) - ligne(org)) == 1 && (orig_col-dest_col==0)) && get_piece(ligne(dest)* 8 + colonne(dest)) == nullptr){
      return true;
    }
    if(abs(colonne(dest) - colonne(org)) != 0 && get_piece(ligne(dest)*8 + colonne(dest)) != nullptr){
      return true;
    }

    else{
      return (get_piece(ligne_inter * 8 + colonne(org)) == nullptr );
    }
  }


  int delta_ligne = abs(ligne(dest) - ligne(org));
  int delta_col   = abs(colonne(dest) - colonne(org));
  int directionLigne = ligne(org)< ligne(dest) ? 1 : -1; // 1 si vers le bas, -1 si vers le haut

  int directionColonne = colonne(org) < colonne(dest) ? 1 : -1; // 1 si vers la droite, -1 si vers la gauche


  ligne_inter = ligne(org) + directionLigne;
  int colonne_inter = colonne(org) + directionColonne;
  int idx = 1;
  if(id == 'B' || (id == 'Q' && delta_ligne == delta_col && delta_ligne > 0)){
    while(ligne_inter * 8 + colonne_inter != dest){
      if(get_piece(ligne_inter * 8 + colonne_inter)) return false;
      idx++;
      ligne_inter = ligne(org) + idx * directionLigne;
      colonne_inter = colonne(org) + idx * directionColonne;
    }
  }

  directionLigne = ligne(org) < ligne(dest) ? 1 : -1;
  directionColonne = colonne(org) < colonne(dest) ? 1 : -1;
  directionLigne *= ligne(org) != ligne(dest);
  directionColonne *= colonne(org) != colonne(dest);

  

  ligne_inter = ligne(org) + directionLigne;
  colonne_inter = colonne(org) + directionColonne;
  idx = 1;
  if(id == 'R' || (id == 'Q' && ((orig_ligne == dest_ligne && orig_col != dest_col) || 
  (orig_col == dest_col && orig_ligne != dest_ligne)))){
    while(ligne_inter * 8 + colonne_inter != dest){
      if(get_piece(ligne_inter * 8 + colonne_inter)) return false;
      idx++;
      ligne_inter = ligne(org) + idx * directionLigne;
      colonne_inter = colonne(org) + idx * directionColonne;
    }
  }

  return true;

}

//nouveau (nécessaire va savoir)
Echiquier& Echiquier::operator=(const Echiquier& autre){
  if (this != &autre) {
    // Vider les vecteurs existants
    this->pieces[Blanc].clear();
    this->pieces[Noir].clear();

    // Cloner les pièces de l'autre échiquier
    for (auto& p : autre.pieces[Blanc]) {
      this->pieces[Blanc].push_back(shared_ptr<Piece>(p->clone()));
    }
    for (auto& p : autre.pieces[Noir]) {
      this->pieces[Noir].push_back(shared_ptr<Piece>(p->clone()));
    }
  }
  return *this;
}

bool Echiquier::est_en_echec(Couleur c){
  int posRoi;
  for(int i=0;i<64;i++){
    shared_ptr<Piece> p=this->get_piece(i);
    if(p!=nullptr && p->get_type()==R && p->get_couleur()==c){
      posRoi=i;
      break;
    }
  }

  for(auto piece : this->pieces[(c==Blanc) ? Noir : Blanc]){
    if(piece!=nullptr && piece->est_mouvement_legal(posRoi)==true && this->chemin_libre(piece->get_position(),posRoi))
      return true;
  }
  return false;
}

//nouveau
bool Echiquier::echec_et_mat(Couleur c){
  //si pas d'echec au départ, pas de mat
  if(!this->est_en_echec(c))
    return false;

  //teste tous les coups possibles
  for(int i=0;i<64;i++){
    for(auto p : this->pieces[c]){
      shared_ptr<Piece> cible=this->get_piece(i);

      //vérifie si le coup est valide
      if(p->get_position()==i)
        continue;
      if(cible!=nullptr && cible->get_couleur()==c)
        continue;
      if(p!=nullptr && p->est_mouvement_legal(i)==true && this->chemin_libre(p->get_position(),i)==true){
        Echiquier temp(*this);
        temp.deplace_piece(p->get_position(),i);

        //vérifie si le coup sort de l'echec
        if(!temp.est_en_echec(c))
          return false;
      }
    }
  }
  return true;  
}

//nouveau
bool Echiquier::pat(Couleur c){
  //si echec au départ, pas de pat
  if(!this->est_en_echec(c))
    return false;

  //teste tous les coups possibles
  for(int i=0;i<64;i++){
    for(auto p : this->pieces[c]){
      shared_ptr<Piece> cible=this->get_piece(i);

      //vérifie si le coup est valide
      if(p->get_position()==i)
        continue;
      if(cible!=nullptr && cible->get_couleur()==c)
        continue;
      if(p!=nullptr && p->est_mouvement_legal(i)==true && this->chemin_libre(p->get_position(),i)==true){
        Echiquier temp(*this);
        temp.deplace_piece(p->get_position(),i);

        //si le coup met en echec, il n'est pas legal : on continue
        if(!temp.est_en_echec(c))
          return false;
      }
    }
  }
  return true;
}