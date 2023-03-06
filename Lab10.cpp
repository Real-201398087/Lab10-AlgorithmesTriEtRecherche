#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "MesFonctions.h"
#include "Caserne.h"

using namespace std;

int main(void)
{
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
    fichier.close();

    return 0;
}
