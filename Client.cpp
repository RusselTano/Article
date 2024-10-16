// Programmeur: Dylane 
// Date: 16 octobre 2024
// Bût: Classe Article

#include "Article.h"

int main(void)
{
	cout << "Article\n"
		 << "========\n";

	cout << "Il y a " << Article::getNombreArticle() << " article(s)" <<
		endl;
	//devrait afficher "Il y a 0 article(s)

	Article article1(4);
	Article article2(3);
	Article* article3 = new Article(2);

	cout << "\nTaille de mes objets\n"
		 << "====================\n"
		 << "Article1 : " << sizeof(article1) << " octets.\n"
		 << "Article2 : " << sizeof(article2) << " octets.\n"
		 << "Article3 : " << sizeof(*article3) << " octets.\n";

	cout << "\nTest afficher date\n";
	article1.afficherDate();
	cout << endl << endl;

	cout << "Il y a " << Article::getNombreArticle() << " article(s)" << endl;
	//devrait afficher "Il y a 2 article(s)

	cout << "Le numero de l'article1 est : " << article1.getNumero();

	cout << "\n\nInfos article 1 \n"
		 << "===============";
	article1.afficherArticle();

	delete article3;
	cout << "\nIl y a " << Article::getNombreArticle() << " article(s)" << endl;

	return 0;
}
