// Programmeur: Dylane 
// Date: 8 octobre 2024
// Bût: Classe Personne

#pragma once
#include <iostream>
#include <ctime>
using namespace std;

class Date
{
private:
	int jour;
	int mois;
	int annee;


public:
	Date();
	Date(int pJour, int pMois, int pAnnee);
	~Date();

	struct tm dateActuelle();

	int getJour() const;
	bool setJour(int pJour);

	int getMois() const;
	bool setMois(int pMois);

	int getAnnee() const;
	bool setAnnee(int pAnnee);

	void afficher()const;

	void dateSysteme();
	bool isBissextile(int pAnnee);
	int dernierJourDuMois(int pMois, int pAnnee);
};

