#include <iostream>
#include <stdio.h>
#include <string>
#include  <cstdio> 
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
// Programme permettant de saisr une variable entière et ceux entre les bornes choisi
//  entré : le message souhaitant être afficher, les deux borne (borne inférieur borneinf et 
//   borne supérieur bornesup 
// Sorti : le nombre souhaitant être saisi 
///////////////////////////////////////////////////////////////////////////////////////////////

void saisirControleEntierBorne(string message, int borneinf, int bornesup, int& nombre)
{
	cout << message << endl;
	cin >> nombre;
	while (nombre < borneinf || nombre > bornesup)
	{
		cout << "Erreur, " << message << endl;
		cin >> nombre;
	}
}
typedef struct maillon  {
	int numero;
	maillon *suivant;
};


typedef struct FileAttente {
	maillon *tete;
	maillon *queue;
};





void ajouterEnQueue( FileAttente &li , int numero) {
	maillon *sp;
	sp = new maillon;
	if (li.tete != NULL) {
		sp->numero = numero;
		if (li.queue != NULL){
			li.queue->suivant = sp;
			li.queue = sp;
		}
		else {
			li.tete->suivant = sp;
			li.queue = sp;
		}

		sp->suivant = NULL;
	}
	else {
		li.tete = new maillon;
		li.tete->numero = numero;
		li.tete->suivant = NULL;
	}

}
void Sup_tete(FileAttente &li) {
	if (li.tete != NULL) {
		maillon *ap = li.tete->suivant;
		delete li.tete;
		li.tete = ap;
	}
}


int Longueur(FileAttente li) {
	int l;
	maillon *sp = new maillon;
	l = 0;
	if (li.tete != NULL) {
		l++;
		sp = li.tete;
		while (sp->suivant != NULL) {
			sp = sp->suivant;
			l = l + 1;
		}
	}
	return l;
}
void Consulter(FileAttente li) {
	if (li.tete != NULL)
		cout <<"le premier element est "<< li.tete->numero<<endl;
	else
		cout << "il n y a pas d element dans la file" << endl;
}

/*int main() {
	int exo;
	FileAttente li ;
	li.tete = NULL;
	li.queue = NULL;
	do {
		saisirControleEntierBorne("\n1 ajouter \n2 -retirer \n3 -consulter \n4 longueur \n5 quitter", 0, 5, exo);
		switch (exo)
		{
		case 1:
			int element;
			cout << " tapez un entier " << endl;
			cin >> element;
			ajouterEnQueue(li , element);
			break;
		case 2:
			Sup_tete(li);
			break;
		case 3:
			Consulter(li);
			break;
		case 4: cout <<"la longeur est de "<< Longueur(li) << endl;
		default:
			cout << "Quitter" << endl;
			break;
		}
	} while (exo != 5);

	system("pause");

	return 0;
}*/



/////////////////////////////////////////// EXERCICE 2 ///////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Structure de données représentant un maillon (avec chaine)
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct Personne {
	string name;
	Personne *suivant;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Structure de données représentantla file d'attente
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct FileAttentePerso {
	Personne *tete;
	Personne *queue;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Procédure permettant d'ajouter un entier en queue de file c'est-à-dire à la fin de la file d'attente
//	ENTREE : une variable numero de type entier qui est la valeur à insérer dans la file
//	SORTIE : une variable li de type FileAttente qui représente la file d'attente
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ajouterEnQueuePerso(FileAttentePerso &li, string name) {
	Personne *sp;
	sp = new Personne;
	if (li.tete != NULL) {
		sp->name = name;
		if (li.queue != NULL) {
			li.queue->suivant = sp;
			li.queue = sp;
		}
		else {
			li.tete->suivant = sp;
			li.queue = sp;
		}

		sp->suivant = NULL;
	}
	else {
		li.tete = new Personne;
		li.tete->name = name;
		li.tete->suivant = NULL;
		li.queue = li.tete;
		li.queue->suivant = NULL;

	}

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Procédure permettant de supprimer l'élement en tete de file c'est-à-dire en première position
//	ENTREE : rien
//	SORTIE : une variable li de type FileAttente
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Sup_tetePerso(FileAttentePerso &li) {
	if (li.tete != NULL) {
		Personne *ap = li.tete->suivant;
		delete li.tete;
		li.tete = ap;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Procédure permettant de calculer la longueur de la liste
//	ENTREE : une variable li de type FileAttente
//	RETOUR :une varaible l de type entier qui correspond à la longueur de la liste
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int LongueurPerso(FileAttentePerso li) {
	int l;
	Personne *sp = new Personne;
	l = 0;
	if (li.tete != NULL) {
		l++;
		sp = li.tete;
		while (sp->suivant != NULL) {
			sp = sp->suivant;
			l = l + 1;
		}
	}
	return l;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Procédure permettant de consulter le premier élément de la liste c'est -à-dire voir le contenu de li.tete
//	ENTREE : une variable li de type FileAttente
//	SORTIE : rien
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ConsulterPerso(FileAttentePerso li) {
	if (li.tete != NULL)
		cout << "le premier element est " << li.tete->name << endl;
	else
		cout << "il n y a pas d element dans la file" << endl;
}




/////////////////////////////////////////// TP 4 /////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Structure de données représentant le maillon d un Undo
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct maillonUndo {
	char DerniereAction;
	Personne *personne;
	maillonUndo *suivant;
	maillonUndo *prec;
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	Structure de données représentant la chaine d undo
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct Undo {
	maillonUndo *tete;
	maillonUndo *queue;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AjouterUndo(Undo &u, Personne *p ,  char modif ) {
	maillonUndo *sp;
	sp = new maillonUndo;
	sp->personne = p;
	sp->DerniereAction = modif;
	sp->suivant = NULL;
	if (u.queue != NULL) {
		sp->prec = u.queue;
		u.queue->suivant = sp;
		sp = u.queue;
		u.queue = sp;	
	}
	else {
		u.tete = new maillonUndo;
		u.queue = new maillonUndo;
		sp->prec = NULL;
		u.tete = sp;
		u.tete->suivant = NULL;
		u.queue = sp;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void AjouterEnTete(FileAttentePerso &f, Personne *p) {
	if (f.tete != NULL) {
		p->suivant = f.tete;
		f.tete = p;
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SuppEnqueuePers(FileAttentePerso &f) {
	Personne *sp;
	if (f.tete != NULL) {
		sp = f.tete;
		if (LongueurPerso(f) >= 2) {
			while (sp->suivant->suivant != NULL) {
				sp = sp->suivant;
			}
			delete sp->suivant;
			sp->suivant = NULL;
		}
		else {
			delete f.tete;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int LongueurUndo(Undo u) {
	int l;
	maillonUndo *sp = new maillonUndo;
	l = 0;
	if (u.tete != NULL) {
		l++;
		sp = u.tete;
		while (sp->suivant != NULL) {
			sp = sp->suivant;
			l = l + 1;
		}
	}
	return l;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SuppEnqueueUndo(Undo &u) {
	maillonUndo *sp;
	if (u.tete != NULL) {
		sp = u.tete;
		if (LongueurUndo(u) >= 2) {
			while (sp->suivant->suivant != NULL) {
				sp = sp->suivant;
			}
			delete sp->suivant;
			sp->suivant = NULL;
		}
		else {
			delete u.tete;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void EffectuerUndo(Undo &u, FileAttentePerso &f) {
	if (u.queue != NULL) {
		if (u.queue->DerniereAction = 'A') {
			SuppEnqueuePers(f);
			SuppEnqueueUndo(u);
		}
		if (u.queue->DerniereAction = 'S') {
			AjouterEnTete(f, u.queue->personne);
			SuppEnqueueUndo(u);
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//			PROGRAMME PRINCIPAL DE L'EXO 2
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main() {
	int exo;
	string element;
	FileAttentePerso li;
	Undo u;
	u.tete = NULL;
	u.queue = NULL;
	li.tete = NULL;
	li.queue = NULL;

	do {
		saisirControleEntierBorne("\n1 ajouter \n2 -retirer \n3 -consulter \n4 longueur \n5 Undo \n6 quitter", 0, 6, exo);
		switch (exo)
		{
		case 1:

			cout << " tapez une chaine " << endl;
			cin >> element;
			ajouterEnQueuePerso(li, element);
			AjouterUndo(u, li.queue, 'A');
			break;
		case 2:
			AjouterUndo(u, li.tete, 'S');
			Sup_tetePerso(li);
			break;
		case 3:
			ConsulterPerso(li);
			break;
		case 4: cout << "la longeur est de " << LongueurPerso(li) << endl;
			break;
		case 5: 
			EffectuerUndo(u, li);
			break;
		default:
			cout << "Quitter" << endl;
			break;
		}
	} while (exo != 6);

	system("pause");

	return 0;
}
