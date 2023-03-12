#include "MesFonctions.h"
#include <algorithm>

using namespace std;

vector<string> getNextLineAndSplitIntoTokens(istream& str)
{
	std::vector<std::string>   result;
	std::string                line;
	std::getline(str, line);

	std::stringstream          lineStream(line);
	std::string                cell;

	while (getline(lineStream, cell, ','))
	{
		replace(cell.begin(), cell.end(), '"', '\0');
		result.push_back(cell);
	}
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		result.push_back("");
	}
	return result;
}

void ouvrirFichier(std::ifstream& flux, std::string nomFichier) {
	flux.open(nomFichier);
	if (!flux) {
		cout << "Le fichier n'existe pas.";
		exit(1);
	}
	if (flux.peek() == EOF) {
		cout << "Le fichier est vide.";
		exit(0);
	}
}

//vide le buffer et remet le flux valide 
void viderBuffer()
{
	cin.clear();			//on reset le flux pour que la suite parte d’un flux valide
	cin.seekg(0, ios::end);	//se place à la fin, si ça marche, le flux est non vide

	if (!cin.fail()) //Le flux est valide, donc le buffer est non vide
	{
		cin.ignore(numeric_limits<streamsize>::max());
	}
	else //Le flux est invalide, donc le buffer est vide
	{
		cin.clear(); 		// Le flux est dans un état invalide donc on le remet en état valide
	}
}

void afficherMenuTri() {
	ecritureTitre("Menu de tri");
	ecritureLigne("1) Trier les casernes par numéro (tri par sélection)");
	ecritureLigne("2) Trier les casernes par rue (tri à bulle)");
	ecritureLigne("3) Trier les casernes par arrondissements / ville (tri par insertion)");
	ecritureLigne("4) Recherche Linéaire");
	ecritureLigne("5) Recherche Dichotomique");
	ecritureLigne("Q) Quitter");
	ecritureLigne("");

	std::cout << "Votre choix: ";


}

void ecritureTitre(std::string titre) {
	std::string textes[] = {
		"",
		titre,
		std::string(titre.size(), '-'),
		""
	};
	int taille = sizeof(textes) / sizeof(textes[0]);
	ecriturePlusieursLignes(textes, taille);
}

void ecriturePlusieursLignes(std::string msgs[], int& taille) {
	for (int i = 0; i < taille; i++) {
		ecritureLigne(msgs[i]);
	}
}

void ecritureLigne(std::string msg) {
	std::cout << msg << std::endl;
}

void afficherTableau(int qtCaserne, Caserne tab[])
{
	for (int i = 0; i < qtCaserne; i++)
		tab[i].afficher();

}

void triABulle(int qtCaserne, Caserne tab[])
{
	int j;
	Caserne temp;
	bool isChange(false);

	do
	{
		isChange = false;
		for (int i = 0; i < qtCaserne - 1; i++)
		{

			j = i + 1;
			if (tab[i].getRue() > tab[j].getRue()) {
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
				isChange = true;
			}


		}

	} while (isChange);
}

void triASelection(int qtCaserne, Caserne tab[])
{

	Caserne temp;

	for (int i = 0; i < qtCaserne - 1; i++)
	{
		for (int j = i + 1; j < qtCaserne; j++)
		{
			if (tab[i].getNumero() > tab[j].getNumero())
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
		}
	}
}

void triParInsertion(int qtCaserne, Caserne tab[])
{
	Caserne temp;
	int i, j;
	for (i = 1; i < qtCaserne; ++i) {
		temp = tab[i];
		for (j = i; j > 0 && tab[j - 1].getLocalisation() > temp.getLocalisation(); j--)
			tab[j] = tab[j - 1];
		tab[j] = temp;
	}
}

void rechercheLineaire(int qtCaserne, Caserne tab[])
{
	std::string recherche;
	std::vector<int> resultat;
	std::string rechercheMajuscule;
	std::string infoMajuscule;
	int p = 0;

	cout << "Quel est votre recherche ?" << std::endl;
	getline(cin, recherche);
	rechercheMajuscule = convertirEnMajuscule(recherche);

	for (int i = 0; i < qtCaserne; i++)
	{
		infoMajuscule = convertirEnMajuscule(tab[i].getLocalisation());
		if (infoMajuscule == ('\0' + rechercheMajuscule + '\0'))
		{
			resultat.push_back(i);
			p++;
		}
	}
	for (int j = 0; j < p; j++)
	{
		tab[resultat[j]].afficher();

	}

}

std::string convertirEnMajuscule(std::string chaine) {
	string resultat;

	for (auto caractere : chaine) {
		resultat += toupper(caractere);
	}
	return resultat;
}

void rechercheDichotomique(int qtCaserne, Caserne tab[])

{
	std::string recherche;
	int b(qtCaserne);
	int bi(0);
	int bs(qtCaserne - 1);
	int m(0);
	int p(0);


	triASelection(qtCaserne, tab);
	cout << "Quel est votre recherche ?" << std::endl;
	getline(cin, recherche);


	while (bs > bi + 1)
	{
		m = (bi + bs) / 2;
		if (tab[m].getNumero() > ('\0' + recherche + '\0'))
		{
			bs = m;

		}

		else
		{
			bi = m;
		}
	}
	if (tab[bi].getNumero() == ('\0' + recherche + '\0'))
	{
		tab[bi].afficher();
	}
	else
	{
		ecritureLigne("Recherche Introuvable!!!");
	}
}