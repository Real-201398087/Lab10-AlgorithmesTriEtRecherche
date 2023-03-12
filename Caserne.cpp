#include <fstream>

#include "Caserne.h"

using namespace std;

Caserne::Caserne() {
	// rien à faire
}

Caserne::Caserne(vector<string> const rangee)
{
	_numero = rangee[0];
	_noCivique = rangee[1];
	_rue = rangee[2];
	_latitude = rangee[3];
	_longitude = rangee[4];
	_arrondissement = rangee[5];
	_ville = rangee[6];
	_dateDebut = rangee[7];
	_dateFin = rangee[8];
}

std::string Caserne::getNumero() const
{
	return _numero;
}



std::string Caserne::getLocalisation() const
{
	if (_ville == "")
	{
		return _arrondissement;
	}
	else
	{
		return _ville;
	}
}

std::string Caserne::getRue() const
{
	return _rue;
}

void Caserne::afficher() const
{

	cout << "#" << _numero << ", " << _noCivique << ", " << _rue << ", " << _arrondissement << _ville << std::endl;

}







