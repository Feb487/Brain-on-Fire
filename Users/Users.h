#ifndef USERS_H_INCLUDED
#define USERS_H_INCLUDED

class Users {

    public:
        void credenzialiRegistrazioneUtente(); //Funzione che acquisisce le credenziali dell'utente per la registrazione
        void credenzialiAccessoUtente(); //Funzione che acquisisce le credenzili dell'utente per l'accesso
        void registrazione(); //Funzione che registra l'utente in base alle credenziali precedentemente acquisite
        void accesso(); //Funzione che fa accedere l'utente in base alle credenziali precedentemente acquisite
        void salvaEdEsci(); //Funzione che esegue il salvataggio e l'uscita dal gioco

};

#endif // USERS_H_INCLUDED
