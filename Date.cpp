// Programmeur: Dylane 
// Date: 8 octobre 2024
// Bût: Classe Personne

#include "Date.h"

Date::Date(int pJour, int pMois, int pAnnee)
{
	if (!setJour(pJour) || !setMois(pMois)) dateSysteme();
	setAnnee(pAnnee);
}

tm Date::dateActuelle()
{
	time_t seconds = time(NULL);    // Nombre de secondes depuis le 1er janvier 1970
	struct tm today;                // Objet tm pour stocker la date et l'heure
	localtime_s(&today, &seconds);  // Convertit en struct tm (version sécurisée)

	return today;
}


Date::Date()
{
	dateSysteme();
}

Date::~Date()
{
	cout << "\nBOOM! - Date\n";
}

int Date::getJour() const
{
	return jour;
}

bool Date::setJour(int pJour)
{
	if (pJour >= 1 && pJour <= dernierJourDuMois(mois, annee)) {
		jour = pJour;

		return true;
	}
	return false;
}

int Date::getMois() const
{
	return mois;
}

bool Date::setMois(int pMois)
{
	if (pMois >= 1 && pMois <= 12) {
		mois = pMois;
		if (jour > dernierJourDuMois(mois, annee)) {
			jour = dateActuelle().tm_mday;
		}
		return true;
	}
	return false;
}

int Date::getAnnee() const
{
	return annee;
}

bool Date::setAnnee(int pAnnee)
{
	if (pAnnee >= 1950 && pAnnee <= 2050) {
		annee = pAnnee;
		return true;
	}

	annee = dateActuelle().tm_year + 1900;

	return false;
}

void Date::afficher()const
{
	cout << jour << "/" << mois << "/" << annee;
}

void Date::dateSysteme()
{
	jour = dateActuelle().tm_mday;           // Récupère le jour du mois
	mois = dateActuelle().tm_mon + 1;        // Récupère le mois (0-11, donc on ajoute 1)
	annee = dateActuelle().tm_year + 1900;   // Récupère l'année (année depuis 1900)
}

bool Date::isBissextile(int pAnnee)
{
	return (pAnnee % 4 == 0 && pAnnee % 100 != 0) || (pAnnee % 400 == 0);
}

int Date::dernierJourDuMois(int pMois, int pAnnee)
{
	if (pMois == 2) {
		return isBissextile(pAnnee) ? 29 : 28; // Février
	}

	// Les mois de 30 jours : Avril (4), Juin (6), Septembre (9), Novembre (11)
	if (pMois == 4 || pMois == 6 || pMois == 9 || pMois == 11) {
		return 30;
	}

	// Les mois de 31 jours : Janvier (1), Mars (3), Mai (5), Juillet (7), Août (8), Octobre (10), Décembre (12)
	return 31;
}













