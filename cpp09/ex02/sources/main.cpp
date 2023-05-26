#include "PmergeMe.hpp"

// prend une suite d'entier en argument
// utiliser un algorithme de tri par fusion-insertion pour tier la sequence d'entier positif
// si erreur lors de l'execution, ecrire un message sur lasortie standard
// utilisation obligatoire d'au moins deux conteneurs
// le programme doit pouvoir gerer au moins 3000 nombres differents
// conseil : implenter l'algo pour chaque conteneur
// Informations a afficher :
// 1 : "Before: (ARGV[1])" // liste de depart
// 2 : "After : (ARGV[1] trie)" // liste triee
// 3 : "Time to process a range of 5 elements with std::[..] : 0.00031 us" // conteneur 1
// 4 : "Time to process a range of 5 elements with std::[..] : 0.00031 us" // conteneur 2

// algoruthme de tri par fusion-insertion :
// 1 : Decomposer la sequence - decouper chaque element (ex : chaque entier dans un maillon d'une liste chainee)
// 2 : Tri par insertion des sous-sequences - parcourir chaque sous-sequence de gauche a droite 

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: Wrong number of argument.\n";
		std::cout << "Usage: ./PmergeMe `shuf -i 1-100000 -n 3000 | tr \"\\n\" \" \"`" << std::endl;
		return (1);
	}

	PmergeMe worker;

	worker.Routine_For_Vector_List_Tri(argc, argv);

	return (0);
}
