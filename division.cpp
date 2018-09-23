#include "division.hpp"

#include <assert.h>

void division(const Polynome& dividende, // Le polynome qui est divise
	      const Polynome& diviseur,  // Le polynome qui divise
	      Polynome& quotient,	   // Parametre de sortie: le resultat de la division
	      Polynome& reste) {	   // Parametre de sortie: le reste de la division

  assert(diviseur.degre() > 0 || diviseur.coefficient(0).numerateur() != 0); // Pas de division par zero
  assert(dividende >= diviseur); // Le degré du dividende doit être plus grand que celui du diviseur

  auto degre_dividende = (unsigned) dividende.degre();
  auto degre_diviseur = (unsigned) diviseur.degre();

  // Coéfficient du terme à ajouter au quotient de retour
  Rationnel coeff_terme = dividende.coefficient(degre_dividende) / diviseur.coefficient(degre_diviseur);

  // Degré du terme à ajouter au quotient de retour
  unsigned int degre_terme = degre_dividende - degre_diviseur;

  quotient = quotient + Polynome(coeff_terme, degre_terme);

  // Résultat du produit entre le diviseur et le terme trouvé
  Polynome produit_terme = diviseur.multiplication_par_monome(coeff_terme, degre_terme);

  // Résultat de la soustraction du produit au dividende
  Polynome resultat_soustraction = dividende - produit_terme;

  int degre_resultat = resultat_soustraction.degre();

  if (degre_diviseur > degre_resultat) {
      reste = resultat_soustraction;
  }
  else if (degre_resultat != -1) {
      division(resultat_soustraction, diviseur, quotient, reste);
  }
}

Polynome plus_grand_commun_diviseur(const Polynome& a, const Polynome& b) {
  assert(a >= b);
  assert(a.degre() > 0 || a.coefficient(0).numerateur() != 0);

  auto m = Polynome(a);
  auto n = Polynome(b);

  while(n.degre() != -1) {
      auto quotient = Polynome();
      auto reste = Polynome();

      division(m, n, quotient, reste);

      m.swap(n);
      n.swap(reste);
  }

  return m;
}
