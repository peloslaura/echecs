#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include <string>

enum Couleur
{
  Blanc,
  Noir
};

enum Type{
  R,D,T,F,C,P
};

class Piece
{
public:
  // Constructeur paramétré
  Piece(Couleur c, int pos,Type t);
  virtual ~Piece()=default;

  int get_position();
  void set_position(int position);
  Couleur get_couleur();
  virtual bool est_mouvement_legal(int case_destination) const = 0;
  virtual std::string nom() const                              = 0;
  virtual std::string serialize() const;
  Type get_type()const;
  virtual Piece* clone()const=0;
  //virtual bool chemin_libre(int case_destination, Echiquier e) const = 0;

protected:
  Couleur couleur;
  int position;
  Type type;
};

class Cavalier : public Piece
{
public:
  Cavalier(Couleur couleur, int position);
  bool est_mouvement_legal(int case_destination) const override;
  std::string nom() const override;
  std::string serialize() const override;
  Cavalier* clone()const override;

  //bool chemin_libre(int case_destination, Echiquier e) const override;
};

class Dame : public Piece
{
public:
  Dame(Couleur couleur, int position);
  bool est_mouvement_legal(int case_destination) const override;
  std::string nom() const override;
  std::string serialize() const override;
  Dame* clone()const override;
  //bool chemin_libre(int case_destination, Echiquier e) const override;
};

class Fou : public Piece
{
public:
  Fou(Couleur couleur, int position);
  bool est_mouvement_legal(int case_destination) const override;
  std::string nom() const override;
  std::string serialize() const override;
  Fou* clone()const override;
  //bool chemin_libre(int case_destination, Echiquier e) const override;
};

class Pion : public Piece
{
public:
  Pion(Couleur couleur, int position);
  bool est_mouvement_legal(int case_destination) const override;
  std::string nom() const override;
  std::string serialize() const override;
  Pion* clone()const override;
  //bool chemin_libre(int case_destination, Echiquier e) const override;

};

class Roi : public Piece
{
public:
  Roi(Couleur couleur, int position);
  bool est_mouvement_legal(int case_destination) const override;
  std::string nom() const override;
  std::string serialize() const override;
  Roi* clone()const override;
  //bool chemin_libre(int case_destination, Echiquier e) const override;
};

class Tour : public Piece
{
public:
  Tour(Couleur couleur, int position);
  bool est_mouvement_legal(int case_destination) const override;
  std::string nom() const override;
  std::string serialize() const override;
  Tour* clone()const override;
  //bool chemin_libre(int case_destination, Echiquier e) const override;
};

inline int ligne(int indice) { return indice / 8; }

inline int colonne(int indice) { return indice % 8; }

#endif
