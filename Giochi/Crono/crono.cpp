#include <iostream>
#include <unistd.h>
#include <thread>
#include "crono.h"

using namespace std;

//Funzione costruttore - imposta ad ogni istanza dell'oggetto tempo il valore 0
Crono::Crono(){
	tempo = 0;
}

//Incrementa di 1 la variabile tempo
void Crono::incrementa() {
	tempo++;
	sleep(1);
}

//Permette la lettura all'esterno della variabile tempo
int Crono::leggi() {
	return tempo;
}
