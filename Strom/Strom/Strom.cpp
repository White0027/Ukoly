// Strom.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

void Koruna(int vyska) {
    for (int i = 0; i < vyska; ++i) {
        for (int j = 0; j < vyska - i; ++j) {
            std::cout << " ";
        }
        for (int k = 0; k <= i; k++) {
            std::cout << " *";
        }
        std::cout << std::endl;
    }
}

void Kmen(int vyska, int sirka) {
    for (int i = 0; i < vyska; ++i) {
        for (int j = 0; j < sirka; ++j)
            std::cout << " ";
        std::cout << "##" << std::endl;
    }
}

int main() {
    int koruna, kmen;

    std::cout << "Vyska koruny: ";
    std::cin >> koruna;
 
    std::cout << "Vyska kmene: ";
    std::cin >> kmen;

    Koruna(koruna);
    Kmen(kmen, koruna);

    return 0;
}