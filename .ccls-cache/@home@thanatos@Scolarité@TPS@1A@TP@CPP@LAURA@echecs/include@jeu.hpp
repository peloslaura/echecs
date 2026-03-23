#ifndef JEU_HPP
#define JEU_HPP

#include "echiquier.hpp"
#include <string>

class Jeu {
public:
    Jeu();
    void affiche();
    bool coup();
    bool deplace(const std::string& orig_str, const std::string& dest_str);

private:
    Echiquier echiquier;
    Couleur joueur_courant;  // Utilisation de l'énumération Couleur définie ailleurs
    bool partie_terminee;
};

#endif