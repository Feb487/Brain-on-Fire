#include <iostream>
#include "../Banners/Banners.h"
#include "../Giochi/Concentrazione/Concentrazione.h"
#include "../Giochi/TrovaLaParola/TrovaLaParola.h"
#include "../Giochi/Memoria/Memoria.h"
#include "../Users/Users.h"
#include "Colors/Colors.h"

using namespace std;

int main()
{

    //Prove per vedere se funge
    Banners banner;
    Concentrazione concentrazione;
    Memoria memoria;
    TrovaLaParola trovalaparola;
    Users user;

    cout << RED << "funziona: " << RESET << endl;
    banner.logoIniziale();
	banner.uscitaFinale();
	banner.inizioGame();
    concentrazione.game();
    memoria.game();
    trovalaparola.game();
    user.accesso();

	cout << "prima commit su GIT !" << endl;
    //Fine prove

	cout << "prova stampa" << endl;

	getchar();
    return 0;
}
