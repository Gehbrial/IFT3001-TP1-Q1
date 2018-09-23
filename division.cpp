#include "division.hpp"

#include <assert.h>

void division(const Polynome& dividende, // Le polynome qui est divise
	      const Polynome& diviseur,  // Le polynome qui divise
	      Polynome& quotient,	   // Parametre de sortie: le resultat de la division
	      Polynome& reste) {	   // Parametre de sortie: le reste de la division

  assert(diviseur.degre() > 0 || diviseur.coefficient(0).numerateur() != 0); // Pas de division par zero
  assert(dividende > diviseur); // Le degré du dividende doit être plus grand que celui du diviseur

  Polynome q = Polynome();
  Polynome r = Polynome();

  bool termine = false;

  if (dividende.degre() != -1) {
      Polynome copie_dividende = Polynome(dividende);

      while(!termine) {
          auto degre_dividende = (unsigned) copie_dividende.degre();
          auto degre_diviseur = (unsigned) diviseur.degre();

          Rationnel coeff_t = copie_dividende.coefficient(degre_dividende) / diviseur.coefficient(degre_diviseur);
          unsigned int degre_t = degre_dividende - degre_diviseur;
          Polynome t = Polynome(coeff_t, degre_t); // Premier terme du quotient

          q = q + Polynome(coeff_t, degre_t); // Ajout du premier terme au quotient de retour

          Polynome resultat_soustraction = copie_dividende - diviseur.multiplication_par_monome(coeff_t, degre_t);
          int degre_resultat = resultat_soustraction.degre();

          if (degre_diviseur > degre_resultat) {
              r = resultat_soustraction;
              termine = true;
          }
          else if (degre_resultat == -1) {
              termine = true;
          }
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
