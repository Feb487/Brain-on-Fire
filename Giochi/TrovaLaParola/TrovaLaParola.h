#ifndef TROVALAPAROLA_H_INCLUDED
#define TROVALAPAROLA_H_INCLUDED

class TrovaLaParola {

    public:
        void game(); //Funzione contenente il secondo minigioco (Trova La Parola)

    private:
        void parolaSbagliata(); //Funzione che controlla se la parola inserita � corretta o meno
        void parolaUsata(); //Funzione che controlla se la parola � stata gi� utilizzata o meno
        void generazioneLettere(); //Funzione che genera le lettere casuali

};

#endif // TROVALAPAROLA_H_INCLUDED
