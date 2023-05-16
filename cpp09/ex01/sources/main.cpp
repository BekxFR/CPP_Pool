#include "RPN.hpp"

	// Parcourir l'expression de gauche à droite, en traitant chaque élément (nombre ou opérateur) un par un.
	// Si l'élément est un nombre, empiler-le sur la pile.
	// Si l'élément est un opérateur, dépiler les deux derniers éléments de la pile, effectuer l'opération correspondante et empilez le résultat.
	// Répéter les étapes 2 et 3 jusqu'à ce que tous les éléments de l'expression soient traités.
	// Le résultat final se trouve sur la pile. Dépilez-le pour obtenir le résultat du calcul.
	// Exemple : "8 9 * 9 - 9 - 9 - 4 - 1 +"

	// 1 2 * 2 / 2 * 2 4 - +
	// 1 * 2 = 2
	// 2 / 2 = 1
	// 1 * 2 = 2
	// 2 - 4 = -2
	// -2 + 2 = 0

	// 8 9 * 9 - 9 - 9 - 4 - 1 +
	// 8 * 9 = 72
	// 72 - 9 = 63
	// 63 - 9 = 54
	// 54 - 9 = 45
	// 45 - 4 = 41
	// 41 + 1 = 42

	// 1 4 2 2 / + *
	// 1	1
	// 4	1 4
	// 2	1 4 2
	// 2	1 4 2 2
	// /	1 4 1
	// +	1 5
	// *	5
	// NbrOpe :  7

int main (int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Error: wrong number of arguments." << std::endl;
		return (1);
	}
	if (std::strlen(argv[1]) <= 0)
	{
		std::cout << "Error: empty string." << std::endl;
		return (1);
	}
	RPN rpn(argv[1]);
	if (rpn.getArgStatus() == false) {
		std::cout << "Error: bad input." << std::endl;
		return (1);
	}
	rpn.Reverse_Polish_Notation();
	return (0);
}
