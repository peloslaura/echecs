#ifndef ECHIQUIER_HPP
#define ECHIQUIER_HPP

#include "piece.hpp"
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Echiquier
{
private:
  vector<shared_ptr<Piece>> pieces[2] = {{nullptr}, {nullptr}}; // 0: Blanc, 1: Noir
public:
  Echiquier();
  Echiquier(const Echiquier& copie);
  ~Echiquier()=default;

  void affiche() const;
  shared_ptr<Piece> get_piece(int position) const;
  void pose_piece(Piece* p, int pos);
  void supprimer_position(int position);
  void deplace_piece(int org, int dest);
  bool chemin_libre(int org, int dest);

  bool est_en_echec(Couleur c);
  bool echec_et_mat(Couleur c);
  bool pat(Couleur c);
  Echiquier& operator=(const Echiquier& autre); //modif
};

#endif
