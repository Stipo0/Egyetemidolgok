#include <iostream>

#include "Munkatarsak.h"
#include "Foldek.h"
#include "Telephelyek.h"


//Makrók a kívánt mennyiségû adat generálásához

#define MT 5 
#define F 50
#define TH 3

int main() {

	//munkatársak generálása//
	Munkatarsak munkatarsak[MT];
		munkatars_start(munkatarsak, MT);
		std::cout << munkatarsak[0].Nev;

	//Földek generálása//
	Foldek foldek[F];
		fold_start(foldek, F);

	//Nem generált Telephelyek
	Telephelyek telephelyek[TH];
		telephely_start(telephelyek, TH);

	std::cout << "Generalas kesz/n";
	return 0;
}