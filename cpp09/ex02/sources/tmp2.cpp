void merge_Insertion_Sort_List(std::list<int>& arr, int debut, int fin) {
    if (fin - debut <= 1) {
        return;
    }

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

        lfin.merge(lbody);
        ldebut.merge(lfin);

        arr.erase(arr.begin(), end);
        arr.insert(arr.begin(), ldebut.begin(), ldebut.end());
    } else {
        int taille = fin - debut + 1;
        int milieu = debut + taille / 2;

        merge_Insertion_Sort_List(arr, debut, milieu);
        merge_Insertion_Sort_List(arr, milieu, fin);

        std::list<int> temp;
        std::list<int>::iterator it = arr.begin();
        std::advance(it, debut);
        std::list<int>::iterator middle = it;
        std::advance(middle, taille / 2);
        std::list<int>::iterator end = arr.begin();
        std::advance(end, fin + 1);

        // Fusion par insertion des deux moitiés triées
        while (it != middle && middle != end) {
            if (*middle < *it) {
                std::list<int>::iterator next = middle;
                ++next;
                temp.splice(it, arr, middle, next);
                middle = next;
            } else {
                ++it;
            }
        }

        // Insérer les éléments restants de la deuxième moitié
        temp.splice(temp.end(), arr, middle, end);

        // Mettre à jour la partie de fusion
        arr.insert(it, temp.begin(), temp.end());
    }
}