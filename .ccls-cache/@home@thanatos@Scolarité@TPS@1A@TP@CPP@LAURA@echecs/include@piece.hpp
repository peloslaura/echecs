#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>

enum Couleur
{
  Blanc,
  Noir
};

// pos : 0 - 64
// i -> (x, y) : x = i % 8, y = i / 8;

class Piece
{
public:
  // Constructeur paramétré
  Piece(Couleur c, int pos);
  int get_position();
  void set_position(int position);
  Couleur get_couleur();
  virtual bool est_mouvement_legal(int case_origine,
                                   int case_destination) const = 0;
  virtual std::string nom() const                              = 0;

protected:
  Couleur couleur;
  int position;
};

class Cavalier : public Piece
{
public:
  Cavalier(Couleur couleur, int position);
  bool est_mouvement_legal(int case_origine,
                           int case_destination) const override;
  std::string nom() const override;
};

class Dame : public Piece
{
public:
  Dame(Couleur couleur, int position);
  bool est_mouvement_legal(int case_origine,
                           int case_destination) const override;
};

class Fou : public Piece
{
public:
  Fou(Couleur couleur, int position);
  bool est_mouvement_legal(int case_origine,
                           int case_destination) const override;
};

class Pion : public Piece
{
public:
  Pion(Couleur couleur, int position);
  bool est_mouvement_legal(int case_origine,
                           int case_destination) const override;

private:
  bool aBouge;
};

class Roi : public Piece
{
public:
  Roi(Couleur couleur, int position);
  bool est_mouvement_legal(int case_origine,
                           int case_destination) const override;
};

class Tour : public Piece
{
public:
  Tour(Couleur couleur, int position);
  bool est_mouvement_legal(int case_origine,
                           int case_destination) const override;
};

inline int ligne(int indice) { return indice / 8; }

inline int colonne(int indice) { return indice % 8; }

#endif
