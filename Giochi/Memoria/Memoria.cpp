#include <iostream>
#include <thread>
#include <unistd.h>
#include <windows.h>
#include "Memoria.h"
#include "../../Banners/Banners.h"
#include "../../Core/Colors/Colors.h"
#include "../Crono/crono.h"

//Tempo massimo per il cronometro
#define MAX_TEMPO 100

using namespace std;

bool flag = true;

void task(Crono& cronometro) {
	do {
		cronometro.incrementa();
	} while(flag);
}

void Memoria::game() {

    //Sezione dichiarativa
    int i = 0; //Contatore locale
    int numRand; //Numero random della sequenza
    int bas; //Numero di appoggio per controllo sequenza
    int sceltaDiff; //Variabile utilizzata per scegliere la difficoltà
    int score = 0; //Variabile utilizzata per tenere il punteggio
    int* controllo; //Array per controllare la sequenza inserita
    int mode; //Lunghezza della sequenza in base alla modalità scelta dall'utente
    Crono cronometro;

    //Sezione di Input

        //Inizializzazione della barra del tempo
        char progressBar[MAX_TEMPO + 1];
        progressBar[MAX_TEMPO] = '\0';

        for (int i=0; i<MAX_TEMPO; i++) {
            progressBar[i] = '-';
        }

        //Scelta della difficoltà
        do {
            system("cls");
            difficolta(); // Mostro a video il menù contenente le difficoltà
            cin >> sceltaDiff;

            switch (sceltaDiff) {
                //Facile
                case 1:
                    mode = 6;
                    break;

                //Intermedio
                case 2:
                    mode = 8;
                    break;

                //Difficile
                case 3:
                    mode = 10;
                    break;

                //Torna indietro
                case 4:
                    return 0;
                    break;
            }
        } while (sceltaDiff < 1 || sceltaDiff > 4);

    //Sezione di calcoli/Output

        //Allocazione dinamica dell'array
        controllo = new int[mode];

        //Inizio del videogame
        system("cls");
        inizioGame(); // Mostro a video la scritta di inizio gioco
        getchar();

        //Inizia il tempo
        thread tid1(task,ref(cronometro));

        //Videogame
        do {
            system("cls");

            //Controllo se il giocatore ha vinto
            //Vince se ha indovinato tante sequenze quanti sono la met� dei numeri mostrati rientrando nel tempo massimo
            if (score == mode / 2 && cronometro.leggi() <= MAX_TEMPO) {
                youWin(); //Mostro a video la scritta YouWin
                flag = false; //Ferma il gioco
            }
            //Controllo se il giocatore ha perso
            //Perde se NON ha indovinato tante sequenze quanti sono la met� dei numeri mostrati rientrando nel tempo massimo
            else if (score < mode / 2 && cronometro.leggi() <= MAX_TEMPO) {
                gameOver(); //Mostro a video la scritta GameOver
                flag = false; //Ferma il gioco
            }
            // Altrimenti il gioco si ripete
            else {

                //Ferma l'avanzamento del tempo
                fm = false;

                //Stampa la sequenza da indovinare
                for (i = 0; i < mode; i++) {

                    //Quando i numeri della sequenza arrivano alla met� di essa, pulisce lo schermo
                    if (i == mode / 2) {
                        system("cls");
                    }

                    numRand = rand() % 10;
                    controllo[i] = numRand;

                    //Stampa del numero random generato
                    switch (numRand) {

                        //Stampa del numero 0
                        case 0:
                            num0();
                            Sleep(1);
                            break;

                        //Stampa del numero 1
                        case 1:
                            num1();
                            Sleep(1);
                            break;

                        //Stampa del numero 2
                        case 2:
                            num2();
                            Sleep(1);
                            break;

                        //Stampa del numero 3
                        case 3:
                            num3();
                            Sleep(1);
                            break;

                        //Stampa del numero 4
                        case 4:
                            num4();
                            Sleep(1);
                            break;

                        //Stampa del numero 5
                        case 5:
                            num5();
                            Sleep(1);
                            break;

                        //Stampa del numero 6
                        case 6:
                            num6();
                            Sleep(1);
                            break;

                        //Stampa del numero 7
                        case 7:
                            num7();
                            Sleep(1);
                            break;

                        //Stampa del numero 8
                        case 8:
                            num8();
                            Sleep(1);
                            break;

                        //Stampa del numero 9
                        case 9:
                            num9();
                            Sleep(1);
                            break;
                    }
                }

                // Riparte l'avanzamento del tempo
                fm = true;

                //Stampa del tempo rimanente
                system("cls");
                cout << "Tempo rimanente: [" << YELLOW << progressBar << RESET << "] " << MAX_TEMPO - cronometro.incrementa << " s\r";
                cout.flush();

                //Input della sequenza e controllo
                cout << endl << endl << "--> INSERISCI DI NUOVO LA SEQUENZA" << endl << endl;

                for (i = 0; i < mode; i++) {
                    cout << "NUMERO " << CYAN << "[" << i + 1 << "]" << RESET << " : ";
                    cin >> bas;

                    if (bas == controllo[i]) {
                        cout << BLUE << "\t<<CORRETTO>>\n" << RESET;

                        if (i == mode - 1) {
                            cout << endl << GREEN << "<<BRAVISSIMO !!! >>" << RESET;
                            cout << endl << "TROVA ALTRE " << CYAN << mode / 2 - score << RESET << " SEQUENZE PER " << YELLOW << "VINCERE !" << RESET;
                            cout << endl << endl << "Caricamento prossima sequenza..." << MAGENTA << "[premere invio per continuare]" << RESET;
                            getchar();
                        }
                    }
                    else {
                        cout << YELLOW << "\t<<ERRORE>>" << endl << RESET;
                        cout << endl << endl << RED << "-->HAI SBAGLIATO :(,concentrati di piu'..." << RESET;
                        cout << endl << "TROVA ALTRE " << CYAN << mode / 2 - score << RESET << " SEQUENZE PER " << YELLOW << "VINCERE !" << RESET;
                        cout << endl << endl << "Caricamento prossima sequenza..." << MAGENTA << "[premere invio per continuare]" << RESET;
                        getchar();
                        break;
                    }
                }

                //Progressione della barra del tempo
                for (i = 0; i < cronometro.incrementa; i++) {
                    progressBar[i] = '>';
                }
            }
    } while (flag);

    Sleep(1);

    tid1.join();

    // Fine della partita
    fineGame(); //Mostro a video la scritta di fine videogioco
    getchar();

    // Libera la memoria allocata dinamicamente
    delete[] controllo;
}

void Memoria::num0() {

    //Codice num0
    cout << ".----------------." << endl;
    cout << "| .--------------. |" << endl;
    cout << "| |     " << RED << "____" << RESET << "     | |" << endl;
    cout << "| |   " << RED << ".'    '." << RESET << "   | |" << endl;
    cout << "| |  " << RED << "|  .--.  |" << RESET << "  | |" << endl;
    cout << "| |  " << RED << "| |    | |" << RESET << "  | |" << endl;
    cout << "| |  " << RED << "|  `--'  |" << RESET << "  | |" << endl;
    cout << "| |   " << RED << "'.____.'" << RESET << "   | |" << endl;
    cout << "| |              | |" << endl;
    cout << "| '--------------' |" << endl;
    cout << " '----------------' " << endl;

}

void Memoria::num1() {

    //Codice num1
    cout << " .----------------. " << endl;
    cout << "| .--------------. |" << endl;
    cout << "| |     " << GREEN << "__" << RESET << "       | |" << endl;
    cout << "| |    " << GREEN << "/  |" << RESET << "      | |" << endl;
    cout << "| |    " << GREEN << "`| |" << RESET << "      | |" << endl;
    cout << "| |     " << GREEN << "| |" << RESET << "      | |" << endl;
    cout << "| |    " << GREEN << "_| |_" << RESET << "     | |" << endl;
    cout << "| |   " << GREEN << "|_____|" << RESET << "    | |" << endl;
    cout << "| |              | |" << endl;
    cout << "| '--------------' |" << endl;
    cout << " '----------------' " << endl;

}

void Memoria::num2() {

    //Codice num2
    cout << ".----------------." << endl;
    cout << "| .--------------. |" << endl;
    cout << "| |    " << YELLOW << "_____" << RESET << "     | |" << endl;
    cout << "| |   " << YELLOW << "/ ___ `." << RESET << "   | |" << endl;
    cout << "| |  " << YELLOW << "|_/___) |" << RESET << "   | |" << endl;
    cout << "| |   " << YELLOW << ".'____.'" << RESET << "   | |" << endl;
    cout << "| |  " << YELLOW << "/ /____" << RESET << "     | |" << endl;
    cout << "| |  " << YELLOW << "|_______|" << RESET << "   | |" << endl;
    cout << "| |              | |" << endl;
    cout << "| '--------------' |" << endl;
    cout << " '----------------' " << endl;

}

void Memoria::num3() {

    //Codice num3
    cout << ".----------------." << endl;
    cout << "| .--------------. |" << endl;
    cout << "| |   " << BLUE << "______" << RESET << "    | |" << endl;
    cout << "| |   " << BLUE << "/ ____ `." << RESET << "  | |" << endl;
    cout << "| |   " << BLUE << "`'  __) |" << RESET << "  | |" << endl;
    cout << "| |   " << BLUE << "_  |__ '." << RESET << "  | |" << endl;
    cout << "| |  " << BLUE << "| \\____) |" << RESET << "  | |" << endl;
    cout << "| |   " << BLUE << "\\______.'" << RESET << "  | |" << endl;
    cout << "| |              | |" << endl;
    cout << "| '--------------' |" << endl;
    cout << " '----------------' " << endl;

}

void Memoria::num4() {

    //Codice num4
    cout << ".----------------." << endl;
    cout << "| .--------------. |" << endl;
    cout << "| |   " << MAGENTA << "_    _" << RESET << "     | |" << endl;
    cout << "| |  " << MAGENTA << "| |  | |" << RESET << "    | |" << endl;
    cout << "| |  " << MAGENTA << "| |__| |_" << RESET << "   | |" << endl;
    cout << "| |  " << MAGENTA << "|____   _|" << RESET << "  | |" << endl;
    cout << "| |      " << MAGENTA << "_| |_" << RESET << "   | |" << endl;
    cout << "| |     " << MAGENTA << "|_____|" << RESET << "  | |" << endl;
    cout << "| |              | |" << endl;
    cout << "| '--------------' |" << endl;
    cout << " '----------------' " << endl;

}

void Memoria::num5() {

    //Codice num5
    cout << ".----------------." << endl;
    cout << "| .--------------. |" << endl;
    cout << "| |   " << CYAN << "_______" << RESET << "    | |" << endl;
    cout << "| |  " << CYAN << "|  _____|" << RESET << "   | |" << endl;
    cout << "| |  " << CYAN << "| |____" << RESET << "     | |" << endl;
    cout << "| |  " << CYAN << "'_.____''." << RESET << "  | |" << endl;
    cout << "| |  " << CYAN << "| \\____) |" << RESET << "  | |" << endl;
    cout << "| |   " << CYAN << "\\______.'" << RESET << "  | |" << endl;
    cout << "| |              | |" << endl;
    cout << "| '--------------' |" << endl;
    cout << " '----------------' " << endl;

}

void Memoria::num6() {

    //Codice num6
    cout << ".----------------." << endl;
    cout << "| .--------------. |" << endl;
    cout << "| |    ______    | |" << endl;
    cout << "| |  .' ____ \\   | |" << endl;
    cout << "| |  | |____\\_|  | |" << endl;
    cout << "| |  | '____`'.  | |" << endl;
    cout << "| |  | (____) |  | |" << endl;
    cout << "| |  '.______.'  | |" << endl;
    cout << "| |              | |" << endl;
    cout << "| '--------------' |" << endl;
    cout << " '----------------' " << endl;

}

void Memoria::num7() {

    //Codice num7
    cout << ".----------------." << endl;
    cout << "| .--------------. |" << endl;
    cout << "| |  " << RED << "_______" << RESET << "    | |" << endl;
    cout << "| |  " << RED << "|  ___  |" << RESET << "   | |" << endl;
    cout << "| |  " << RED << "|_/  / /" << RESET << "    | |" << endl;
    cout << "| |      " << RED << "/ /" << RESET << "     | |" << endl;
    cout << "| |     " << RED << "/ /" << RESET << "      | |" << endl;
    cout << "| |    " << RED << "/_/" << RESET << "       | |" << endl;
    cout << "| |              | |" << endl;
    cout << "| '--------------' |" << endl;
    cout << " '----------------' " << endl;

}

void Memoria::num8() {

    //Codice num8
    cout << ".----------------." << endl;
    cout << "| .--------------. |" << endl;
    cout << "| |    " << GREEN << "____" << RESET << "     | |" << endl;
    cout << "| |   " << GREEN << ".' __ '." << RESET << "   | |" << endl;
    cout << "| |   " << GREEN << "| (__) |" << RESET << "   | |" << endl;
    cout << "| |   " << GREEN << ".`____'." << RESET << "   | |" << endl;
    cout << "| |  " << GREEN << "| (____) |" << RESET << "  | |" << endl;
    cout << "| |  " << GREEN << "`.______.'" << RESET << "  | |" << endl;
    cout << "| |              | |" << endl;
    cout << "| '--------------' |" << endl;
    cout << " '----------------' " << endl;

}

void Memoria::num9() {

    //Codice num9
    cout << ".----------------." << endl;
    cout << "| .--------------. |" << endl;
    cout << "| |    " << YELLOW << "______" << RESET << "    | |" << endl;
    cout << "| |  " << YELLOW << ".' ____ '." << RESET << "  | |" << endl;
    cout << "| |  " << YELLOW << "| (____) |" << RESET << "  | |" << endl;
    cout << "| |  " << YELLOW << "'_.____. |" << RESET << "  | |" << endl;
    cout << "| |   " << YELLOW << "_______||" << RESET << "  | |" << endl;
    cout << "| |   " << YELLOW << "\\______'" << RESET << "   | |" << endl;
    cout << "| |              | |" << endl;
    cout << "| '--------------' |" << endl;
    cout << " '----------------' " << endl;

}
