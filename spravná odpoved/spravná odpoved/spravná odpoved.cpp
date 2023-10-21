#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	fstream myFile;
	vector<int> cisla;
	myFile.open("2000.txt", ios::in);
	if (myFile.is_open()) {
		string radek;
		while (getline(myFile, radek))
		{
			cisla.push_back(stoi(radek));
		}
		myFile.close();
	}
	for (int cislo : cisla) {
	//	cout << cislo << ", ";
	}
	

    int n = cisla.size();

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (cisla[i] + cisla[j] + cisla[k] == 2020) {
					std::cout << "Nalezeny cisla: " << cisla[i] << " + " << cisla[j] << " + " << cisla[k] << " = 2020 " << std::endl;
				}
			}
		}
	}

    return 0;
}