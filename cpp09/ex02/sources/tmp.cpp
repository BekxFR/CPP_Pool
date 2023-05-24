void merge_Insertion_Sort_List(std::list<int>& arr, int debut, int fin) {
	if (fin - debut <= 10) {

		std::list<int>::iterator start = arr.begin();
		std::advance(start, debut);
		std::list<int>::iterator end = arr.begin();
		std::advance(end, fin);

		std::list<int> lfin;
		std::list<int> lbody;
		std::list<int> ldebut;

		if (start != arr.begin()) {
			ldebut.assign(arr.begin(), start);
		}

		if (end != arr.end()) {
			lfin.assign(end, arr.end());
		}

		lbody.assign(start, end);
		lbody.sort();


		lbody.merge(lfin);
		ldebut.merge(lbody);

		arr.assign(ldebut.begin(), ldebut.end());
	} else {
		int taille = fin - debut + 1;
		int milieu = debut + taille / 2;

		// Tri récursif des sous-listes
		merge_Insertion_Sort_List(arr, debut, milieu);
		merge_Insertion_Sort_List(arr, milieu, fin + 1);

		// Fusion des sous-listes triées
		std::list<int> temp;
		std::list<int>::iterator it = arr.begin();
		std::advance(it, debut);
		std::list<int>::iterator middle = it;
		std::advance(middle, taille / 2);
		std::list<int>::iterator end = arr.begin();
		std::advance(end, fin + 1);

		while (it != middle && middle != end) {
			if (*it < *middle) {
				temp.push_back(*it);
				++it;
			} else {
				temp.push_back(*middle);
				++middle;
			}
		}

		// Copie des éléments restants de la première sous-liste
		while (it != middle) {
			temp.push_back(*it);
			++it;
		}

		// Copie des éléments restants de la seconde sous-liste
		while (middle != end) {
			temp.push_back(*middle);
			++middle;
		}

		// Remplacement des éléments dans la liste originale
		it = arr.begin();
		std::advance(it, debut);
		std::list<int>::iterator tempIt = temp.begin();
		while (tempIt != temp.end()) {
			*it = *tempIt;
			++it;
			++tempIt;
		}
	}
}



void merge_Insertion_Sort(std::vector<int>& arr, int debut, int fin) {
    if (fin - debut <= 10) {
        std::sort(arr.begin() + debut, arr.begin() + fin + 1);
    } else {
        int milieu = debut + (fin - debut) / 2;

        merge_Insertion_Sort(arr, debut, milieu);
        merge_Insertion_Sort(arr, milieu + 1, fin);

        std::vector<int> temp(fin - debut + 1);
        int i = debut, j = milieu + 1, k = 0;

        while (i <= milieu && j <= fin) {
            if (arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }

        while (i <= milieu)
            temp[k++] = arr[i++];

        while (j <= fin)
            temp[k++] = arr[j++];

        for (int m = 0; m < k; m++)
            arr[debut + m] = temp[m];
    }
}