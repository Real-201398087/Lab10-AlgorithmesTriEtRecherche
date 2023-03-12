#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <conio.h>

#include "Caserne.h"

std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str);

void ouvrirFichier(std::ifstream& flux, std::string nomFichier);
void viderBuffer();
void ecritureTitre(std::string titre);
void ecritureLigne(std::string msg);
void ecriturePlusieursLignes(std::string msgs[], int& taille);
void afficherMenuTri();
void afficherTableau(int qtCaserne, Caserne tab[]);
void triABulle(int qtCaserne, Caserne tab[]);
void triASelection(int qtCaserne, Caserne tab[]);
void triParInsertion(int qtCaserne, Caserne tab[]);
void rechercheLineaire(int qtCaserne, Caserne tab[]);
std::string convertirEnMajuscule(std::string chaine);
void rechercheDichotomique(int qtCaserne, Caserne tab[]);


