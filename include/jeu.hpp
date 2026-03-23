#ifndef JEU_HPP
#define JEU_HPP

#include "echiquier.hpp"
#include <string>

class Jeu {
public:
    Jeu();
    ~Jeu()=default;

    void affiche();
    int coup();
    bool deplace(std::string orig_str, std::string dest_str);
    Echiquier getEchiquier();
private:
    Echiquier echiquier;
    Couleur joueur_courant;  // Utilisation de l'énumération Couleur définie ailleurs
    bool partie_terminee;
};

#endif