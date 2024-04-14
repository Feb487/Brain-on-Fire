#ifndef BANNERS_H_INCLUDED
#define BANNERS_H_INCLUDED

class Banners {

    public:
        void logoIniziale(); //Funzione che mostra il logo iniziale con il caricamento
        void uscitaFinale(); //Funzione che mostra il menù dell'uscita finale
        void inizioGame(); //Funzione che mostra la scritta pre-game
        void fineGame(); //Funzione che mostra la scritta post-game
        void youWin(); //Funzione che mostra la scritta "You Win" quando il giocatore vince
        void gameOver(); //Funzione che mostra la scritta "GameOver" quando il giocatore perde
        void menuIniziale(); //Funzione che mostra il menù iniziale con le varie azioni del programma
        void menuAccesso(); //Funzione che mostra il menù di accesso/registrazione dell'utente all'interno del sistema
        void menuImpostazioni(); //Funzione che mostra il menù delle impostazioni del gioco (ancora da implementare)
        void menuGiochi(); //Funzione che mostra il menù con i 3 giochi presenti all'interno del sistema
        void sceltePartita(); //Funzione che mostra le scelte che può effettuare l'utente all'interno del menù di gioco
        void difficolta(); //Funzione che mostra le difficoltà di gioco che può selezionare l'utente
        void recordGioco(); //Funzione che mostra i record di gioco nelle varie difficoltà
        void accountCreato(); //Funzione che avverte l'utente della creazione dell'account tramite un menù
        void accountEsistente(); //Funzione che avverte l'utente dell'esistenza dell'account tramite un menù
        void caratteriVietati(); //Funzione che avverte l'utente dell'errato utilizzo dei caratteri non consentiti
        void regoleConcentrazione(); //Funzione che mostra il menù delle regole del primo gioco
        void regoleTrovaLaParola(); //Funzione che mostra il menù delle regole del secondo gioco
        void regoleMemoria(); //Funzione che mostra il menù delle regole del terzo gioco

};


#endif // BANNERS_H_INCLUDED
