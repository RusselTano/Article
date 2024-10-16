// Programmeur: Dylane 
// Date: 16 octobre 2024
// Bût: Classe Article

#include "Article.h"

int Article::nombreArticle = 0;

Article::Article(int numero)
{
	setNumero(numero);
	Article::nombreArticle++;
}

Article::~Article()
{
	nombreArticle--;
}

const int Article::getNombreArticle()
{
	return Article::nombreArticle;
}

void Article::setNumero(int numero)
{
	this->numero = numero;
}

int Article::getNumero() const
{
	return numero;
}

void Article::afficherArticle() const
{
	cout << "\nNumero : " << getNumero(); 
	cout << "\nDate d'achat : "; afficherDate();
	cout << endl;
}

void Article::afficherDate() const
{
	dateAchat.afficher();
}
