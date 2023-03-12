#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "MesFonctions.h"
#include "Caserne.h"

using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_ALL, "fr_CA");
	system("chcp 1252");


	Caserne casernes[68];
	int nbCasernes = 0;
	vector<string> rangee;
	string entete;

	ifstream fichier;
	fichier.imbue(locale(""));
	cout.imbue(locale(""));

	ouvrirFichier(fichier, "casernes.csv");

	getline(fichier, entete);
	while (!fichier.eof() && nbCasernes < 68) {
		rangee = getNextLineAndSplitIntoTokens(fichier);
		casernes[nbCasernes] = Caserne(rangee);
		nbCasernes++;
	}


	afficherTableau(nbCasernes, casernes);
	fichier.close();


	char choix = 0;
	while (choix != 'Q') {
		afficherMenuTri();

		choix = toupper(_getche());
		system("cls");

		switch (choix) {
		case '1':
			triASelection(nbCasernes, casernes);
			afficherTableau(nbCasernes, casernes);
			break;
		case '2':
			triABulle(nbCasernes, casernes);
			afficherTableau(nbCasernes, casernes);
			break;
		case '3':
			triParInsertion(nbCasernes, casernes);
			afficherTableau(nbCasernes, casernes);
			break;
		case '4':
			rechercheLineaire(nbCasernes, casernes);
			break;
		case '5':
			rechercheDichotomique(nbCasernes, casernes);
			break;
		case 'Q':

			exit(0);
			break;
		default:
			std::cerr << "Option non-valide. Veuillez reessayer." << std::endl;
			break;
		}

	}

	system("pause");
	return 0;
}
