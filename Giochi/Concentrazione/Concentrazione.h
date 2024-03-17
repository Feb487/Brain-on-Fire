#ifndef CONCENTRAZIONE_H_INCLUDED
#define CONCENTRAZIONE_H_INCLUDED

class Concentrazione {

    public:
        void game(); //Funzione contenente il primo minigioco (Concentrazione)
    private:
		//bool flag; //flag per interruzione del gioco
		int *matrice; //puntatore ad intero per array dinamici
        void caricamento(int,int); //Funzione che esegue il caricamento dei numeri all'interno della matrice
        void stampa(int,int); //Funzione che esegue la stampa della matrice a video

};

#endif // CONCENTRAZIONE_H_INCLUDED

