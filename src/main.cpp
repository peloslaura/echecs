#include "jeu.hpp"        
#include "echiquier.hpp"
#include "piece.hpp" 

int main() {
  Jeu monjeu;

  // boucle de jeu, s'arrete a la fin de la partie
  //modif
  int stop(0);
  do {
    monjeu.affiche();
    stop = monjeu.coup();
  } while (!stop);
  std::cout << "Partie terminée ^^\n";

  string space5 = string(5, ' ');
    
  for (int i = 7; i >= 0 ; i--)
  {
    for (int j = 0; j < 8; j++)
    {
      auto piece = monjeu.getEchiquier().get_piece(i * 8 + j);
      if (piece != nullptr)
        std::cout  << piece->serialize() << ",";
      else
        std::cout  << ",";
    }
  }
  //modif
  if(stop==1)
    std::cout<<" ?-?\n";
  else if(stop==2)
    std::cout << " 0-1\n";
  else if(stop==3)
    std::cout << " 1-0\n";
  else 
    std::cout << " 1/2-1/2";
  //fin modif
}