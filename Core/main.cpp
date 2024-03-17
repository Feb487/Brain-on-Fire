#include <iostream>
#include "../Banners/Banners.h"
#include "../Giochi/Concentrazione/Concentrazione.h"
#include "../Giochi/TrovaLaParola/TrovaLaParola.h"
#include "../Giochi/Memoria/Memoria.h"
#include "../Users/Users.h"
#include "Colors/Colors.h" 

/*
-------------------------------------------------------------
- Authors: Davide Longo, Giancarlo Mosca, Matteo Zerillo	-
- Data: 14/03/2022  			 							-
- Program: Brain_on_Fire C++                                -
- Version: 2.8												-
-------------------------------------------------------------
*/

using namespace std;

int main()
{

    //Prove per vedere se funge
    Banners banner;
    Concentrazione concentrazione;
    Memoria memoria;
    TrovaLaParola trovalaparola;
    Users user;

    cout << RED << "TEST VIDEO GAME 1" << RESET << endl;
	getchar();
    concentrazione.game();

	cout << "fine programma...[premere un tasto per terminare]" << endl;
	getchar();
    return 0;
}
