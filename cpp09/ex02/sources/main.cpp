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

#include <vector>
#include <list>
#include <algorithm>

const int TAILLE_SEUIL = 10;  // Taille seuil pour utiliser le tri par insertion


#include <typeinfo>

template <typename T>
void myPrintTemplate(const T& arr) {
	if (arr.begin() == arr.end())
		std::cout << "Vector is actually empty" << std::endl;
	// std::cout << "Container type: " << typeid(T).name() << std::endl;
	std::cout << "Vector print :" << std::endl;
	typename T::const_iterator it = arr.begin();
	for (; it != arr.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "Vector end!" << std::endl;
}

template <typename T>
void myPrintTemplate(T b, T e) {
	std::cout << "ITERATOR PRinT" << std::endl;
	if (e == b)
		std::cout << "2Vector is actually empty" << std::endl;
	// std::cout << "Container type: " << typeid(T).name() << std::endl;
	std::cout << "2Vector print :" << std::endl;
	for (; b != e; b++)
		std::cout << *b << std::endl;
	std::cout << "2Vector end!" << std::endl;
}

// Implémentation de l'algorithme de tri par fusion-insertion
void mergeInsertionSort(std::vector<int>& arr, int debut, int fin) {
    if (fin - debut <= TAILLE_SEUIL) {
		 
		std::cout << "TRI" << " debut = " << debut << " fin = " << fin << std::endl;
        // Utilisation du tri par insertion pour les sous-tableaux de petite taille
		// myPrintTemplate(arr.begin() + debut, arr.begin() + fin + 1);
        std::sort(arr.begin() + debut, arr.begin() + fin + 1);
		// myPrintTemplate(arr.begin() + debut, arr.begin() + fin + 1);
    } else {
        int milieu = debut + (fin - debut) / 2;
		std::cout << "ELSE" << " debut = " << debut << " MiLieu = " << milieu << " fin = " << fin << std::endl;
        
        // Tri récursif des sous-tableaux
        mergeInsertionSort(arr, debut, milieu);
        mergeInsertionSort(arr, milieu + 1, fin);
        
		std::cout << "FUFU" << " debut = " << debut << " MiLieu = " << milieu << " fin = " << fin << std::endl;
        // Fusion des sous-tableaux triés
        std::vector<int> temp(fin - debut + 1);
        int i = debut, j = milieu + 1, k = 0;
		// 
		std::cout << "i = " << i << " j = " << j << " k = " << k << std::endl;
        while (i <= milieu && j <= fin) {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
        // myPrintTemplate(temp);
        
        while (i <= milieu)
            temp[k++] = arr[i++];
        // myPrintTemplate(temp);
        
        while (j <= fin)
            temp[k++] = arr[j++];
        // myPrintTemplate(temp);
        
		std::cout << "debut = " << debut << " et k = " << k << std::endl;
        for (int m = 0; m < k; m++)
            arr[debut + m] = temp[m];
    }
}

// void mergeInsertionSort(std::list<int>& arr, int debut, int fin) {
//     if (fin - debut <= TAILLE_SEUIL) {
//         // Utilisation du tri par insertion pour les sous-tableaux de petite taille
//         std::sort(arr.begin() + debut, arr.begin() + fin + 1);
//     } else {
//         int milieu = debut + (fin - debut) / 2;
        
//         // Tri récursif des sous-tableaux
//         mergeInsertionSort(arr, debut, milieu);
//         mergeInsertionSort(arr, milieu + 1, fin);
        
//         // Fusion des sous-tableaux triés
//         std::vector<int> temp(fin - debut + 1);
//         int i = debut, j = milieu + 1, k = 0;
        
//         while (i <= milieu && j <= fin) {
//             if (arr[i] <= arr[j])
//                 temp[k++] = arr[i++];
//             else
//                 temp[k++] = arr[j++];
//         }
        
//         while (i <= milieu)
//             temp[k++] = arr[i++];
        
//         while (j <= fin)
//             temp[k++] = arr[j++];
        
//         for (int m = 0; m < k; m++)
//             arr[debut + m] = temp[m];
//     }
// }

// template <typename T>
// void mergeInsertionSort(T& arr) {
//     mergeInsertionSort(arr, 0, arr.size() - 1);
// }

// void mergeInsertionSort(T& arr) {
//     if (arr.size() <= TAILLE_SEUIL) {
//         // Utilisation du tri par insertion pour les sous-tableaux de petite taille
//         std::sort(arr.begin(), arr.end());
//     } else {
//         int milieu = arr.size() / 2;
        
//         // Tri récursif des sous-tableaux
//         mergeInsertionSort(arr, 0, milieu);
//         mergeInsertionSort(arr, milieu + 1, arr.size() - 1);
        
//         // Fusion des sous-tableaux triés
//         std::vector<int> temp(arr.size());
//         int i = 0, j = milieu + 1, k = 0;
        
//         while (i <= milieu && j <= arr.size() - 1) {
//             if (arr[i] <= arr[j])
//                 temp[k++] = arr[i++];
//             else
//                 temp[k++] = arr[j++];
//         }
        
//         while (i <= milieu)
//             temp[k++] = arr[i++];
        
//         while (j <= arr.size() - 1)
//             temp[k++] = arr[j++];
        
//         for (int m = 0; m < k; m++)
//             arr[m] = temp[m];
//     }
// }

// void printVector(const std::vector<int>& vec) {
// 	if (vec.begin() == vec.end())
// 		std::cout << "Vector is actually empty" << std::endl;
// 	std::cout << "Vector print :" << std::endl;
// 	std::vector<int>::const_iterator it = vec.begin();
// 	for (; it != vec.end(); it++)
// 		std::cout << *it << std::endl;
// 	std::cout << "Vector end!" << std::endl;
// }

// void printVector(const std::list<int>& vec) {
// 	if (vec.begin() == vec.end())
// 		std::cout << "Vector is actually empty" << std::endl;
// 	std::cout << "Vector print :" << std::endl;
// 	std::list<int>::const_iterator it = vec.begin();
// 	for (; it != vec.end(); it++)
// 		std::cout << *it << std::endl;
// 	std::cout << "Vector end!" << std::endl;
// }

int	main()
{
	int ivect[] = { 9, 8, 5, 0, 7 , 6, 2, 3, 1, 4, 4, 8, 9, 10, 11, 8, 9, 9, 8, 5, 0, 7 , 6, 2, 3, 1, 4, 4, 8, 9, 10, 11, 8, 9, 9, 8, 5, 0, 7 , 6, 2, 3, 1, 4, 4, 8, 9, 10, 11, 8, 9, 9, 8, 5, 0, 7 , 6, 2, 3, 1, 4, 4, 8, 9, 10, 11, 8, 9, 9, 8, 5, 0, 7 , 6, 2, 3, 1, 4, 4, 8, 9, 10, 11, 8, 9 };
	int n = sizeof(ivect) / sizeof(ivect[0]);

	std::vector<int> myvect(ivect , ivect + n);
	std::list<int> mylist(ivect , ivect + n);

	// myPrintTemplate(myvect);
	mergeInsertionSort(myvect, 0, n - 1);
	myPrintTemplate(myvect);
	// myPrintTemplate(mylist);
	return (0);
}