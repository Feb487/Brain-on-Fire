#include <iostream>
#include <unistd.h>
#include "crono.h"

using namespace std;

Crono::Crono(){ //funzione costruttore - imposta ad ogni istanza dell'oggetto tempo, il valore di esso 0
	tempo = 0;
}

void Crono::incrementa() //incrementa di 1 la variabile tempo
{
	tempo++;
	sleep(1);
}

int Crono::leggi() //permette la lettura all'esterno della variabile
{
	return tempo;
}