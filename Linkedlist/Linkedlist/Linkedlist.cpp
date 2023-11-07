// Linkedlist.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>

using namespace std;

struct Uzel
{
    int hodnota;
    Uzel* dalsi;

    void vypisUzel()
    {
        cout << "[ ADRESA: " << this << ", hodnota: " << hodnota << ", dalsi: " << dalsi << " ]" << endl;
    }

    void vypisSeznam() {
        Uzel* aktualni = this;
        while (aktualni != nullptr)
        {
            aktualni->vypisUzel();
            aktualni = aktualni->dalsi;
        }
    }

    void pridatNaKonec(int hodnota) {
        Uzel* novyUzel = new Uzel;
        novyUzel->hodnota = hodnota;
        novyUzel->dalsi = nullptr;

        if (this == nullptr)
        {
            *this = *novyUzel;
            return;
        }

        Uzel* aktualni = this;
        while (aktualni->dalsi != nullptr)
        {
            aktualni = aktualni->dalsi;
        }

        aktualni->dalsi = novyUzel;
    }

    void vlozitNaIndex(int idx, int hodnota) {
        Uzel* novyUzel = new Uzel;
        novyUzel->hodnota = hodnota;

        if (idx == 0)
        {
            novyUzel->dalsi = this;
            *this = *novyUzel;
            return;
        }

        Uzel* aktualni = this;
        int pocitadlo = 0;
        while (aktualni != nullptr)
        {
            if (pocitadlo == idx - 1)
            {
                novyUzel->dalsi = aktualni->dalsi;
                aktualni->dalsi = novyUzel;
                return;
            }
            aktualni = aktualni->dalsi;
            pocitadlo++;
        }
    }

    Uzel* operator[](int index) {
        Uzel* aktualni = this;
        int pocitadlo = 0;
        while (aktualni != nullptr)
        {
            if (pocitadlo == index)
            {
                return aktualni;
            }
            aktualni = aktualni->dalsi;
            pocitadlo++;
        }
        return nullptr;
    }

    void smazatUzel(int idx) {
        if (idx == 0)
        {
            Uzel* dalsiUzel = dalsi;
            delete this;
            *this = *dalsiUzel;
            return;
        }

        Uzel* aktualni = this;
        int pocitadlo = 0;
        while (aktualni != nullptr)
        {
            if (pocitadlo == idx - 1)
            {
                Uzel* uzelKSmazani = aktualni->dalsi;
                aktualni->dalsi = uzelKSmazani->dalsi;
                delete uzelKSmazani;
                return;
            }
            aktualni = aktualni->dalsi;
            pocitadlo++;
        }
    }
};

int main()
{
    char lel;
    Uzel seznam;
    seznam.hodnota = 0;
    seznam.dalsi = nullptr;

    seznam.pridatNaKonec(1);
    seznam.pridatNaKonec(2);
    seznam.pridatNaKonec(3);

    seznam.vypisSeznam();
    seznam[1]->vypisUzel();

    seznam.vlozitNaIndex(2, 4);
    seznam.smazatUzel(3);
    seznam.vypisSeznam();
}