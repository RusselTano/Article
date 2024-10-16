// Programmeur: Dylane 
// Date: 16 octobre 2024
// Bût: Classe Article

#pragma once

#include <iostream>
#include <ctime>
#include "Date.h"

using namespace std;
class Article
{
private:
	int numero;
	Date dateAchat;
	static int nombreArticle;
public:
	Article(int numero);
	~Article();

	const static int getNombreArticle();

	void setNumero(int numero);
	int getNumero()const;
	void afficherArticle()const;
	void afficherDate()const;

};

