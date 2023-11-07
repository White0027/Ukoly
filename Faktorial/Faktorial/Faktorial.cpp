// Faktorial.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

int faktorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * faktorial(n - 1); 
    }
}

int main() {
    int cislo;

    std::cout << "Zadej cislo: ";
    std::cin >> cislo;

    if (cislo < 0) {
        std::cout << "Faktorial nelze spocitat pro zaporna cisla." << std::endl;
    }
    else {
        int vysledek = faktorial(cislo);
        std::cout << "Faktorial " << cislo << " je " << vysledek << std::endl;
    }

    return 0;
}