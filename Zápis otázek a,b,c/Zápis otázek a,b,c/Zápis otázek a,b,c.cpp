#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Otazka {
	string otazka;
	string a;
	string b;
	string c;
	char spravnaOdpoved;
};

struct Dotaznik {
	vector<Otazka> otazky;
};

Dotaznik buildDotaznik(string path);
int runDotaznik(Dotaznik kviz);

int main()
{
	string path;
	cout << "Zadejte cestu k souboru s otazkami: ";
	cin >> path;
	Dotaznik kviz = buildDotaznik(path);
	cout << "Tve skore je: " << runDotaznik(kviz);
}

Dotaznik buildDotaznik(string path)
{
	ifstream file;
	string line;
	Dotaznik kviz;

	file.open(path);
	if (!file.is_open()) {
		cout << "Soubor se nepodarilo otevrit!" << endl;
		exit(1);
	}

	while (getline(file, line)) {
		Otazka novaOtazka;
		stringstream ss(line);
		getline(ss, novaOtazka.otazka, ';');
		getline(ss, novaOtazka.a, ';');
		getline(ss, novaOtazka.b, ';');
		getline(ss, novaOtazka.c, ';');
		ss >> novaOtazka.spravnaOdpoved;
		kviz.otazky.push_back(novaOtazka);
	}

	file.close();

	return kviz;
}

int runDotaznik(Dotaznik kviz)
{
	int skore = 0;
	char odpoved;
	for (size_t i = 0; i < kviz.otazky.size(); i++) {
		cout << kviz.otazky[i].otazka << endl;
		cout << "A: " << kviz.otazky[i].a << endl;
		cout << "B: " << kviz.otazky[i].b << endl;
		cout << "C: " << kviz.otazky[i].c << endl;
		cout << "Zadejte odpoved: ";
		cin >> odpoved;

		if (odpoved == kviz.otazky[i].spravnaOdpoved) {
			skore++;
			cout << "Spravne!" << endl << endl;
		}
		else {
			cout << "Spatne!" << endl << endl;
		}
	}

	return skore;
}
