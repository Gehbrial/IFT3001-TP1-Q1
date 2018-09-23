#include "division.hpp"

#include <assert.h>

void division(const Polynome& dividende, // Le polynome qui est divise
	      const Polynome& diviseur,  // Le polynome qui divise
	      Polynome& quotient,	   // Parametre de sortie: le resultat de la division
	      Polynome& reste) {	   // Parametre de sortie: le reste de la division

  assert(diviseur.degre() > 0 || diviseur.coefficient(0).numerateur() != 0); // Pas de division par zero
  assert(dividende > diviseur); // Le degré du dividende doit être plus grand que celui du diviseur

  Polynome q = Polynome(); // Quotient retourné
  Polynome r = Polynome(); // Reste retourné

  // Si nous avons terminé de simplifier la division
  bool termine = false;

  int i = 0;

  // Si le dividende est nul, alors forcément les paramètres de retour sont nuls
  if (dividende.degre() != -1) {
      auto copie_dividende = Polynome(dividende);
      auto degre_diviseur = (unsigned) diviseur.degre();

      while(!termine) {
          auto degre_dividende = (unsigned) copie_dividende.degre();

          // Coéfficient du terme à ajouter au quotient de retour
          Rationnel coeff_terme = copie_dividende.coefficient(degre_dividende) / diviseur.coefficient(degre_diviseur);

          // Degré du terme à ajouter au quotient de retour
          unsigned int degre_terme = degre_dividende - degre_diviseur;

          q = q + Polynome(coeff_terme, degre_terme);

          // Résultat du produit entre le diviseur et le terme trouvé
          Polynome produit_terme = diviseur.multiplication_par_monome(coeff_terme, degre_terme);

          // Résultat de la soustraction du produit au dividende actuel
          Polynome resultat_soustraction = copie_dividende - produit_terme;

          int degre_resultat = resultat_soustraction.degre();

          i++;

          // On ne peut plus simplifier -> On retourne le résultat de la soustraction comme reste
          if (degre_diviseur > degre_resultat) {
              r = resultat_soustraction;
              termine = true;
          }
          // Le résultat de la soustraction est nulle -> On a fini de simplifier
          else if (degre_resultat == -1) {
              termine = true;
          }
          // Le dividende devient le résultat de la soustraction et on poursuit le traitement
          else {
              copie_dividende = resultat_soustraction;
          }
      }
  }

  quotient = q;
  reste = r;
}

Polynome plus_grand_commun_diviseur(const Polynome& a, const Polynome& b) {
  assert(a >= b);
  assert(a.degre() > 0 || a.coefficient(0).numerateur() != 0);

  // INSEREZ VOTRE CODE ICI
  return Polynome();
}
