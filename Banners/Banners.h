#ifndef BANNERS_H_INCLUDED
#define BANNERS_H_INCLUDED

class Banners {

    public:
        void logoIniziale(); //Funzione che mostra il logo iniziale con il caricamento
        void uscitaFinale(); //Funzione che mostra il menù dell'uscita finale
        void inizioGame(); //Funzione che mostra la scritta pre-game
        fineGame(); //Funzione che mostra la scritta post-game
        youWin(); //Funzione che mostra la scritta "You Win" quando il giocatore vince
        gameOver(); //Funzione che mostra la scritta "GameOver" quando il giocatore perde
        menuIniziale(); //Funzione che mostra il menù iniziale con le varie azioni del programma
        menuAccesso(); //Funzione che mostra il menù di accesso/registrazione dell'utente all'interno del sistema
        menuImpostazioni(); //Funzione che mostra il menù delle impostazioni del gioco (ancora da implementare)
        menuGiochi(); //Funzione che mostra il menù con i 3 giochi presenti all'interno del sistema
        sceltePartita(); //Funzione che mostra le scelte che può effettuare l'utente all'interno del menù di gioco
        difficolta(); //Funzione che mostra le difficoltà di gioco che può selezionare l'utente
        recordGioco(); //Funzione che mostra i record di gioco nelle varie difficoltà
        accountCreato(); //Funzione che avverte l'utente della creazione dell'account tramite un menù
        accountEsistente(); //Funzione che avverte l'utente dell'esistenza dell'account tramite un menù
        caratteriVietati(); //Funzione che avverte l'utente dell'errato utilizzo dei caratteri non consentiti
        regoleConcentrazione(); //Funzione che mostra il menù delle regole del primo gioco
        regoleTrovaLaParola(); //Funzione che mostra il menù delle regole del secondo gioco
        regoleMemoria(); //Funzione che mostra il menù delle regole del terzo gioco

};


#endif // BANNERS_H_INCLUDED
