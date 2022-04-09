#include <iostream>

#include "Munkatarsak.h"
#include "Foldek.h"


//Makrók a kívánt mennyiségû adat generálásához

#define MT 5 
#define F 50
int main() {

	//munkatársak generálása//
	Munkatarsak munkatarsak[MT];
	munkatars_start(munkatarsak, MT);

	//Földek generálása//
	Foldek foldek[F];
	fold_start(foldek, F);

	return 0;
}