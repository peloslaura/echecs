#ifndef ECHIQUIER_HPP
#define ECHIQUIER_HPP

#include "piece.hpp"
#include <string>
#include <vector>
#include <memory>

class Echiquier
{
private:
  std::vector<std::shared_ptr<Piece>> pieces[2] = {{nullptr}, {nullptr}}; // 0: Blanc, 1: Noir

public:
  Echiquier();

  void affiche() const;
  Piece* get_piece(int s) const;
  void pose_piece(Piece* p, int pos);
};

#endif
