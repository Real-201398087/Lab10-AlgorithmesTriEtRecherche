#pragma once
#include <string>
#include <iostream>
#include <vector>


class Caserne
{
protected:
	std::string _numero;
	std::string _noCivique;
	std::string _rue;
	std::string _latitude;
	std::string _longitude;
	std::string _arrondissement;
	std::string _ville;
	std::string _dateDebut;
	std::string _dateFin;


public:
	Caserne();
	Caserne(std::vector<std::string> const rangee);

	std::string getNumero() const;
	std::string getLocalisation() const;
	std::string getRue() const;

	void afficher() const;

};


