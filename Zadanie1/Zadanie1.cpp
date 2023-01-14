#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class tablicaInt {
    int *tab;
    int rozmiar;
public:
    tablicaInt(int);
    int roz();
    void losuj();
    void wypisz();
    void sZamiana();
    void sZamianaZmodyfikowana();
    void sWybor();
    void quickSort(int, int);
    void reverseQuickSort(int, int);
};
tablicaInt::tablicaInt(int r) {
    tab = new int[r];
    rozmiar = r;
}
int tablicaInt::roz() {
    return this->rozmiar;
}

void tablicaInt::losuj() {
    srand(time(NULL));
    for (int i = 0; i < rozmiar; i++) {
        this->tab[i] = rand() % 1000 + 1;
    }
}

void tablicaInt::wypisz() {
    for (int i = 0; i < this->rozmiar; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void tablicaInt::sZamiana() {
    clock_t start = clock();
    for (int i = 0; i < this->rozmiar - 1; i++) {
        for (int j = 0; j < this->rozmiar - 1 - i; j++) {
            if (this->tab[j] > this->tab[j + 1]) {
                int temp = this->tab[j];
                this->tab[j] = this->tab[j + 1];
                this->tab[j + 1] = temp;
            }
        }
    }
    float result = (clock() - static_cast<float>(start)) / CLOCKS_PER_SEC;
    cout <<  result << " sek" << endl;
}

void tablicaInt::sZamianaZmodyfikowana() {
    clock_t start = clock();
    bool flaga;
    for (int i = 0; i < this->rozmiar - 1; i++) {
        flaga = true;
        for (int j = 0; j < this->rozmiar - 1 - i; j++) {
            if (this->tab[j] > this->tab[j + 1]) {
                int temp = this->tab[j];
                this->tab[j] = this->tab[j + 1];
                this->tab[j + 1] = temp;
                flaga = false;
            }
        }
        if (flaga) {
            float result = (clock() - static_cast<float>(start)) / CLOCKS_PER_SEC;
            cout << result << " sek" << endl;
            return; 
        }
    }
}

void tablicaInt::sWybor() {
    clock_t start = clock();
    int min_index, temp;
    for (int i = 0; i < rozmiar - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < rozmiar; j++) {
            if (*(tab + j) < *(tab + min_index)) {
                min_index = j;
            }
        }
        temp = *(tab + i);
        *(tab + i) = *(tab + min_index);
        *(tab + min_index) = temp;
    }
    float result = (clock() - static_cast<float>(start)) / CLOCKS_PER_SEC;
    cout << result << " sek" << endl;
}

void tablicaInt::quickSort(int l, int p) {
    int i = l, j = p;
    int pivot = tab[(l + p) / 2];
    while (i <= j) {

        while (tab[i] < pivot) {
            i++;
        }

        while (tab[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++;
            j--;
        }
    }
    if (l < j) quickSort(l, j);
    if (i < p) quickSort(i, p);
}

void tablicaInt::reverseQuickSort(int l, int p) {
    int i = l, j = p;
    int pivot = tab[(l + p) / 2];
    while (i <= j) {

        while (tab[i] > pivot) {
            i++;
        }

        while (tab[j] < pivot) {
            j--;
        }
        if (i <= j) {
            int temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
            i++;
            j--;
        }
    }
    if (l < j) reverseQuickSort(l, j);
    if (i < p) reverseQuickSort(i, p);
}

int main()
{
    setlocale(LC_CTYPE, "Polish");
    tablicaInt t1(20000);
    t1.losuj();
    t1.quickSort(0, t1.roz() - 1);
    tablicaInt t2(40000);
    t2.losuj();
    t2.quickSort(0, t2.roz() - 1);
    tablicaInt t3(60000);
    t3.losuj();
    t3.quickSort(0, t3.roz() - 1);

    cout << "Program sprawdzający czas sortowania algorytmów." << endl << endl;
    cout << "Dla tablicy posortowanej:" << endl;
    cout << "Sortowanie przez prostą zamianę:" << endl;
    cout << "- 20000 elementów: ";
    t1.sZamiana();
    cout << "- 40000 elementów: ";
    t2.sZamiana();
    cout << "- 60000 elementów: ";
    t3.sZamiana();
    cout << endl;

    cout << "Zmodyfikowane sortowanie przez zamianę:" << endl;
    cout << "- 20000 elementów: ";
    t1.sZamianaZmodyfikowana();
    cout << "- 40000 elementów: ";
    t2.sZamianaZmodyfikowana();
    cout << "- 60000 elementów: ";
    t3.sZamianaZmodyfikowana();
    cout << endl;

    cout << "Sortowanie przez wybór:" << endl;
    cout << "- 20000 elementów: ";
    t1.sWybor();
    cout << "- 40000 elementów: ";
    t2.sWybor();
    cout << "- 60000 elementów: ";
    t3.sWybor();
    cout << endl;

    cout << "Sortowanie szybkie:" << endl;
    cout << "- 20000 elementów: ";
    clock_t start = clock();
    t1.quickSort(0, t1.roz() - 1);
    cout << (clock() - static_cast<float>(start)) / CLOCKS_PER_SEC << " sek" << endl;
    cout << "- 40000 elementów: ";
    start = clock();
    t2.quickSort(0, t2.roz() - 1);
    cout << (clock() - static_cast<float>(start)) / CLOCKS_PER_SEC << " sek" << endl;
    cout << "- 60000 elementów: ";
    start = clock();
    t3.quickSort(0, t3.roz() - 1);
    cout << (clock() - static_cast<float>(start)) / CLOCKS_PER_SEC << " sek" << endl;
    cout << endl;

    cout << "Dla tablicy odwrotnie posortowanej:" << endl;
    cout << "Sortowanie przez prostą zamianę:" << endl;
    cout << "- 20000 elementów: ";
    t1.reverseQuickSort(0, t1.roz() - 1);
    t1.sZamiana();
    cout << "- 40000 elementów: ";
    t2.reverseQuickSort(0, t2.roz() - 1);
    t2.sZamiana();
    cout << "- 60000 elementów: ";
    t3.reverseQuickSort(0, t3.roz() - 1);
    t3.sZamiana();
    cout << endl;

    cout << "Zmodyfikowane sortowanie przez zamianę:" << endl;
    cout << "- 20000 elementów: ";
    t1.reverseQuickSort(0, t1.roz() - 1);
    t1.sZamianaZmodyfikowana();
    cout << "- 40000 elementów: ";
    t2.reverseQuickSort(0, t2.roz() - 1);
    t2.sZamianaZmodyfikowana();
    cout << "- 60000 elementów: ";
    t3.reverseQuickSort(0, t3.roz() - 1);
    t3.sZamianaZmodyfikowana();
    cout << endl;

    cout << "Sortowanie przez wybór:" << endl;
    cout << "- 20000 elementów: ";
    t1.reverseQuickSort(0, t1.roz() - 1);
    t1.sWybor();
    cout << "- 40000 elementów: ";
    t2.reverseQuickSort(0, t2.roz() - 1);
    t2.sWybor();
    cout << "- 60000 elementów: ";
    t3.reverseQuickSort(0, t3.roz() - 1);
    t3.sWybor();
    cout << endl;

    cout << "Sortowanie szybkie:" << endl;
    cout << "- 20000 elementów: ";
    t1.reverseQuickSort(0, t1.roz() - 1);
    start = clock();
    t1.quickSort(0, t1.roz() - 1);
    cout << (clock() - static_cast<float>(start)) / CLOCKS_PER_SEC << " sek" << endl;
    cout << "- 40000 elementów: ";
    t2.reverseQuickSort(0, t2.roz() - 1);
    start = clock();
    t2.quickSort(0, t2.roz() - 1);
    cout << (clock() - static_cast<float>(start)) / CLOCKS_PER_SEC << " sek" << endl;
    cout << "- 60000 elementów: ";
    t3.reverseQuickSort(0, t3.roz() - 1);
    start = clock();
    t3.quickSort(0, t3.roz() - 1);
    cout << (clock() - static_cast<float>(start)) / CLOCKS_PER_SEC << " sek" << endl;
    cout << endl;

    cout << "Dla tablicy losowej:" << endl;
    cout << "Sortowanie przez prostą zamianę:" << endl;
    cout << "- 20000 elementów: ";
    t1.losuj();
    t1.sZamiana();
    cout << "- 40000 elementów: ";
    t2.losuj();
    t2.sZamiana();
    cout << "- 60000 elementów: ";
    t3.losuj();
    t3.sZamiana();
    cout << endl;

    cout << "Zmodyfikowane sortowanie przez zamianę:" << endl;
    cout << "- 20000 elementów: ";
    t1.losuj();
    t1.sZamianaZmodyfikowana();
    cout << "- 40000 elementów: ";
    t2.losuj();
    t2.sZamianaZmodyfikowana();
    cout << "- 60000 elementów: ";
    t3.losuj();
    t3.sZamianaZmodyfikowana();
    cout << endl;

    cout << "Sortowanie przez wybór:" << endl;
    cout << "- 20000 elementów: ";
    t1.losuj();
    t1.sWybor();
    cout << "- 40000 elementów: ";
    t2.losuj();
    t2.sWybor();
    cout << "- 60000 elementów: ";
    t3.losuj();
    t3.sWybor();
    cout << endl;

    cout << "Sortowanie szybkie:" << endl;
    cout << "- 20000 elementów: ";
    t1.losuj();
    start = clock();
    t1.quickSort(0, t1.roz() - 1);
    cout << (clock() - static_cast<float>(start)) / CLOCKS_PER_SEC << " sek" << endl;
    cout << "- 40000 elementów: ";
    t2.losuj();
    start = clock();
    t2.quickSort(0, t2.roz() - 1);
    cout << (clock() - static_cast<float>(start)) / CLOCKS_PER_SEC << " sek" << endl;
    cout << "- 60000 elementów: ";
    t3.losuj();
    start = clock();
    t3.quickSort(0, t3.roz() - 1);
    cout << (clock() - static_cast<float>(start)) / CLOCKS_PER_SEC << " sek" << endl;
    cout << endl;

    return 0;
}

