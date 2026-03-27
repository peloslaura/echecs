**PELOS LAURA 1A IR**


Ce code contient : 

Un dossier include contenant tous les fichiers .hpp

Un dossier src contenant tous les fichiers .cpp . Il existe un fichier .cpp par pièce, ils sont regroupés dans un dossier piece à l'intérieur du dossier src.

Ce code passe les tests 1. Cela signifie que le code crée correctement l'échiquer et les pièces, lit correctement une partie coup par coup et produit la bonne position finale et le bon résultat.

**Dans jeu.cpp une section est commentée: c'est ma tentative de passer les tests 2 (détection de l'échec).** Les tests qui échouent : 2, 3 et 4.

Pour compiler : make.
Pour vérifier les tests : ./test-level.sh 1 build/target/echecs


Conception du programme : 
- Une classe piece et ses sous classes
- Une classe echiquier
- Une classe jeu
- Un main = la boucle de jeu

**Il n'y a pas de classe square** 
Plutôt que de représenter l'échiquier comme un ensemble de cases, je le représente comme un ensemble de 64 positions. 
