#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str);

void ouvrirFichier(std::ifstream& flux, std::string nomFichier);
void viderBuffer();
