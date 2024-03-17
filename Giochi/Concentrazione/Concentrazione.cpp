#include <iostream>
#include <thread>
#include <unistd.h>
#include "../../Banners/Banners.h"
#include "Concentrazione.h"
#include "../../Core/Colors/Colors.h"
#include "../Crono/crono.h"

#define MAX_TEMPO 100

using namespace std;

bool flag = true;

void task(Crono& cronometro)
{
	do{
		cronometro.incrementa();
	}while(flag);

}

void Concentrazione::game() {

		//sezione dichiarativa
		int i,j;
		int sceltaDiff; //Scelta difficoltà
		int righe,colonne; //Variabile utilizzata per le righe e le colonne della matrice
		int c; //numero casuale generato dal programma
		int score=0; //Punteggio dell'utente
		Crono cronometro;

		//inizializzazione della barra del tempo
		char progressBar[MAX_TEMPO + 1];
		progressBar[MAX_TEMPO] = '\0';

		for (int i=0; i<MAX_TEMPO; i++){
			        progressBar[i] = '-';
			    }

		do{
			system("cls");
			cout << "scegli la difficolta' [1] [2] [3] : ";
			cin >> sceltaDiff;
			switch (sceltaDiff)
			{
				//semplice
				case 1:
				righe = 3;
				colonne =4;
				break;

				//intermedio
				case 2:
				righe = 6;
				colonne =7;
				break;

				//Difficile
				case 3:
				righe=7;
				colonne=8;
				break;

			}

		}while(sceltaDiff<1 || sceltaDiff>4);

		//Allocazione dinamica della matrice
		matrice=(int *)malloc(righe*colonne*sizeof(int));

		system("cls");
		caricamento(righe,colonne);
		cout << "sei pronto per iniziare...[premere un tasto per continuare]";
		getchar();

		thread tid1(task,ref(cronometro)); //inizia il tempo

		do{
			system("cls");
			if (score == righe*colonne && cronometro.leggi() <= MAX_TEMPO )
			{
				cout << "hai vinto" << endl;
				flag = false;
			}
			else if ( score < righe*colonne && cronometro.leggi() >= MAX_TEMPO )
			{
				cout << "hai perso" << endl;
				flag = false;
			}
			else
			{
				stampa(righe,colonne);
				cout << "Tempo rimanente: [" << YELLOW << progressBar << RESET << "]"<< MAX_TEMPO - cronometro.leggi() <<  "s\r" << endl << endl;

				do{
					c = matrice [rand()% (righe*colonne)];
				}while(c == -1);

				//Input del numero da trovare
				cout << "Trova il numero : " << GREEN << c << RESET;
				cout << endl << "riga: ";
				cin >> i;
				i--; //Decremento le variabili perché l'indice visualizzato parte da 1 e non da 0
				cout << "colonna: ";
				cin >> j;
				j--;

				//Numero trovato
				if (matrice[i* colonne + j] == c) {
					//sound = 1;
					matrice[i * colonne + j] = -1;
					score++;
					cout << endl << GREEN"-->BRAVISSIMO/A ;) !!! " << RESET;
					cout << endl << "TROVA ALTRI " << CYAN << (righe * colonne)-score << RESET << " NUMERI PER " << YELLOW << "VINCERE !" << RESET;
					cout << endl << endl << "caricamento prossima numero..." << MAGENTA << "[premere invio per continuare]" << RESET;
					getchar();
					getchar();
				}

				//Numero non trovato
				else {
					//sound = -1;
					cout << endl << RED << "HAI SBAGLIATO :(, sii piu concentrato..." << RESET << endl;
					cout << "TROVA ALTRI " << CYAN << (righe * colonne)-score << RESET << " NUMERI PER " << YELLOW << "VINCERE !" << RESET;
					cout << endl << endl << "caricamento prossima numero..." << MAGENTA << "[premere invio per continuare]" << RESET;
					getchar();
					getchar();
				}

				//Aggiornamento della barra del tempo a fine dell'esecuzione
				for ( i = 0; i < cronometro.leggi(); i++) {
					progressBar[i] = '>';
				}


			}
		}while (flag);

		tid1.join();
		cout << "fine videogame" << endl;

}

void Concentrazione::caricamento(int righe, int colonne) {

    //Sezione dichiarativa locale
	int i,j; //Contatori locali
	int numeri; //Variabile contenente i numeri casuali
	int usati[righe * colonne]; //Variabile utilizzata per contenere i numeri già utilizzati
	srand(time(NULL)); //Dichiarazione generatore di numeri casuali

	for (i=0; i<righe*colonne; i++) {
		usati[i]=0;
	}

	for (i=0; i<righe; i++) {
		for (j=0; j<colonne; j++) {

			//Ciclo per non creare numeri doppi all'interno della matrice
			do {
				numeri=rand() % (righe*colonne);
			} while (usati[numeri]==1);

			matrice[i*colonne+j]=numeri;
			usati[numeri]=1;
		}
	}

}

void Concentrazione::stampa(int righe, int colonne) {

    //Sezione dichiarativa locale
	int i,j; //Contatori locali

	//Stampa dell'indice delle colonne
	cout << "        ";
	for (i=0;i<colonne;i++) {
		cout << "(" << CYAN << i+1 << RESET << ")\t";
	}
	cout << endl << endl;

	//Stampa della matrice
	for (i = 0; i < righe; i++)
	{

		//Stampa dell'indice delle righe
		cout << "(" << CYAN << i+1 << RESET << ")\t";
		for (j = 0; j < colonne; j++)
		{
			if (matrice[i * colonne + j] == -1)
			{
					cout <<"|" << RED << "X" << RESET << "|\t"; // scrivi "X " se numero già indovinato
			}
			else
			{
				cout<< "|" << GREEN << matrice[i * colonne + j] << RESET << "|\t";
			}

		}
		cout << endl << endl;
	}


}
