#include "MesFonctions.h"

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
