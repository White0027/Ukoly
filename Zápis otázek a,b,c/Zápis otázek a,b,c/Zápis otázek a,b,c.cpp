#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

struct Otazka {
	string otazka;
	string a;
	string b;
	string c;
	char spravnaOdpoved;
};

struct Dotaznik {
	Otazka* otazky;
	int delka;
};

Dotaznik* buildDotaznik(string path);
int runDotaznik(Dotaznik* kviz);
void reallocate(Otazka** old_arr, int old_size, int new_size);
void vymazOtazky(Dotaznik* kviz);

int main()
{
	string path;
	cout << "Zadejte cestu k souboru s otazkami (nazev souboru): ";
	cin >> path;
	Dotaznik* kviz = buildDotaznik(path);
	cout << "Tve skore je: " << runDotaznik(kviz);
	vymazOtazky(kviz);
	delete kviz;
}

Dotaznik* buildDotaznik(string path)
{
	ifstream file;
	string line;
	Dotaznik* kviz = new Dotaznik{ new Otazka[1], 0 };

	file.open(path);
	if (!file.is_open()) {
		cout << "Soubor se nepodarilo otevrit!" << endl;
		return nullptr;
	}

	while (getline(file, line)) {
		if (kviz->delka != 0) {
			reallocate(&kviz->otazky, kviz->delka, kviz->delka + 1);
		}

		stringstream ss(line);
		getline(ss, kviz->otazky[kviz->delka].otazka, ';');
		getline(ss, kviz->otazky[kviz->delka].a, ';');
		getline(ss, kviz->otazky[kviz->delka].b, ';');
		getline(ss, kviz->otazky[kviz->delka].c, ';');
		ss >> kviz->otazky[kviz->delka].spravnaOdpoved;
		kviz->delka++;
	}

	file.close();

	return kviz;
}

int runDotaznik(Dotaznik* kviz)
{
	int skore = 0;
	char odpoved;
	for (int i = 0; i < kviz->delka; i++) {
		cout << kviz->otazky[i].otazka << endl;
		cout << "A: " << kviz->otazky[i].a << endl;
		cout << "B: " << kviz->otazky[i].b << endl;
		cout << "C: " << kviz->otazky[i].c << endl;
		cout << "Zadejte odpoved: ";
		cin >> odpoved;

		if (odpoved == kviz->otazky[i].spravnaOdpoved) {
			skore++;
			cout << "Spravne!" << endl << endl;
		}

		else {
			cout << "Spatne!" << endl << endl;
		}
	}

	return skore;
}

void reallocate(Otazka** old_arr, int old_size, int new_size)
{
	Otazka* new_arr = new Otazka[new_size];
	copy(*old_arr, *old_arr + old_size, &new_arr[0]);
	delete[] * old_arr;
	*old_arr = new_arr;
}

void vymazOtazky(Dotaznik* kviz)
{
	delete[] kviz->otazky;
	kviz->otazky = nullptr;
}