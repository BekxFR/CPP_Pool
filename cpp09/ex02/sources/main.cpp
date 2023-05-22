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

const int TAILLE_SEUIL = 10;  // Taille seuil pour utiliser le tri par insertion

template <typename T>
void myPrintTemplate(const T& arr) {
	if (arr.begin() == arr.end())
		std::cout << "Data is actually empty" << std::endl;
	// std::cout << "Container type: " << typeid(T).name() << std::endl;
	std::cout << "Vector print :" << std::endl;
	typename T::const_iterator it = arr.begin();
	for (; it != arr.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "Vector end!" << std::endl;
}

template <typename T>
void myOneLinePrintTemplate(const T& arr, const std::string& text) {
	if (arr.begin() == arr.end())
		std::cout << "Data is actually empty" << std::endl;
	if (DEBUG)
		std::cout << "Container type: " << typeid(T).name() << std::endl;
	std::cout << text;
	typename T::const_iterator it = arr.begin();
	for (; it != arr.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename T>
void myItPrintTemplate(T b, T e) {
	std::cout << "ITERATOR PRinT" << std::endl;
	if (e == b)
		std::cout << "2Data is actually empty" << std::endl;
	// std::cout << "Container type: " << typeid(T).name() << std::endl;
	std::cout << "2Data print :" << std::endl;
	for (; b != e; b++)
		std::cout << *b << std::endl;
	std::cout << "2Data end!" << std::endl;
}

time_t getTime()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	if (DEBUG) {
		std::cout << "sec = " << tv.tv_sec << " usec = " << tv.tv_usec << std::endl;
		std::cout << "sec = " << (tv.tv_sec * 1000) << " usec = " << (tv.tv_usec / 1000) << " total = " << ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) << std::endl;
	}
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	printSortStatus(size_t size, std::string type, float time)
{
	std::cout << "Time to process a range of " << size << " elements with " << type << " : " << time << " us" << std::endl;
}

// Implémentation de l'algorithme de tri par fusion-insertion
void merge_Insertion_Sort(std::vector<int>& arr, int debut, int fin) {
    if (fin - debut <= TAILLE_SEUIL) {
        std::sort(arr.begin() + debut, arr.begin() + fin + 1);
    } else {
        int milieu = debut + (fin - debut) / 2;

        // Tri récursif des sous-tableaux
        merge_Insertion_Sort(arr, debut, milieu);
        merge_Insertion_Sort(arr, milieu + 1, fin);

        // Fusion des sous-tableaux triés
        std::vector<int> temp(fin - debut + 1);
        int i = debut, j = milieu + 1, k = 0;

		// tant que debut++ < milieu et milieu++ < fin
		// si value[debut] <= value[milieu]
		// 	tmp[k++] = value[debut++];
		// sinon
		// 	tmp[k++] = value[milieu++];
        while (i <= milieu && j <= fin) {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }

		// tant que debut++ < milieu
		// 	tmp[k] = value[debut];
        while (i <= milieu)
            temp[k++] = arr[i++];

		// tant que milieu++ < fin
		// 	tmp[k] = value[fin];
        while (j <= fin)
            temp[k++] = arr[j++];

		if (DEBUG)
			std::cout << " debut = " << debut << " milieu = " << milieu << " fin = " << fin << " K = " << k << std::endl;

		// tant que k < taille
		// 	value[debut + k] = tmp[k];
        for (int m = 0; m < k; m++)
            arr[debut + m] = temp[m];
    }
}

// // Implémentation de l'algorithme de tri par fusion-insertion
// void mergeListInsertionSort(std::list<int>& arr, int debut, int fin) {
//     if (fin - debut <= TAILLE_SEUIL) {
//         std::sort(arr.rbegin() + debut, arr.rbegin() + fin + 1);
//     } else {
//         int milieu = debut + (fin - debut) / 2;

//         // Tri récursif des sous-tableaux
//         mergeListInsertionSort(arr, debut, milieu);
//         mergeListInsertionSort(arr, milieu + 1, fin);

//         // Fusion des sous-tableaux triés
//         std::list<int> temp(fin - debut + 1);
//         int i = debut, j = milieu + 1, k = 0;

// 		// tant que debut++ < milieu et milieu++ < fin
// 		// si value[debut] <= value[milieu]
// 		// 	tmp[k++] = value[debut++];
// 		// sinon
// 		// 	tmp[k++] = value[milieu++];
//         while (i <= milieu && j <= fin) {
//             if (arr[i] <= arr[j])
//                 temp[k++] = arr[i++];
//             else
//                 temp[k++] = arr[j++];
//         }

// 		// tant que debut++ < milieu
// 		// 	tmp[k] = value[debut];
//         while (i <= milieu)
//             temp[k++] = arr[i++];

// 		// tant que milieu++ < fin
// 		// 	tmp[k] = value[fin];
//         while (j <= fin)
//             temp[k++] = arr[j++];

// 		if (DEBUG)
// 			std::cout << " debut = " << debut << " milieu = " << milieu << " fin = " << fin << " K = " << k << std::endl;

// 		// tant que k < taille
// 		// 	value[debut + k] = tmp[k];
//         for (int m = 0; m < k; m++)
//             arr[debut + m] = temp[m];
//     }
// }

int onlyPositiveArgv(char *arg)
{
	if (strlen(arg) < 1)
		return (1);
	for (int i = 0; arg[i]; i++) {
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
	}
	return (0);
}



int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: Wrong number of argument.\n";
		std::cout << "Usage: ./PmergeMe `shuf -i 1-100000 -n 3000 | tr \"\\n\" \" \"`" << std::endl;
		return (1);
	}
	int tab[argc - 1];
	PmergeMe test;
	// int *tab;
	test.ParseData(argv, argc, tab);
	// int ivect[] = { 9999, 9, 8, 5, 0, 7 , 6, 2, 3, 1, 4, 4, 8, 9, 10, 11, 8, 9, 9, 8, 5, 0, 7 , 6, 2, 3, 1, 4, 4, 8, 9, 10, 11, 8, 9, 9, 8, 5, 0, 7 , 6, 2, 3, 1, 4, 4, 8, 9, 10, 11, 8, 9, 9, 8, 5, 0, 7 , 6, 2, 3, 1, 4, 4, 8, 9, 10, 11, 8, 9, 9, 8, 5, 0, 7 , 6, 2, 3, 1, 4, 4, 8, 9, 10, 11, 8, 9, 0 };
	// int n = sizeof(ivect) / sizeof(ivect[0]);
	int n = sizeof(tab) / sizeof(tab[0]);

	// std::vector<int> myvect(ivect , ivect + n);
	// std::list<int> mylist(ivect , ivect + n);
	std::vector<int> myvect(tab , tab + n);
	std::list<int> mylist(tab , tab + n);

	myOneLinePrintTemplate(myvect, "Before:\t");
	if (DEBUG)
		myPrintTemplate(myvect);

	time_t deltaIn = getTime();
	merge_Insertion_Sort(myvect, 0, n - 1);
	time_t deltaOut = getTime();

	if (DEBUG)
		myPrintTemplate(myvect);

	myOneLinePrintTemplate(myvect, "After:\t");
	printSortStatus(myvect.size(), "std::vector", static_cast<float>(deltaOut - deltaIn));

	if (DEBUG)
		myPrintTemplate(mylist);
	deltaIn = getTime();
	// merge_Insertion_Sort(mylist, 0, n - 1);
	deltaOut = getTime();
	printSortStatus(mylist.size(), "std::list", static_cast<float>(deltaOut - deltaIn));
	if (DEBUG)
		myPrintTemplate(mylist);
	return (0);
}