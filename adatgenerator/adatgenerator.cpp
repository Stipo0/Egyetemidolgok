#include <iostream>

#include "Munkatarsak.h"
#include "Foldek.h"


//Makr�k a k�v�nt mennyis�g� adat gener�l�s�hoz

#define MT 5 
#define F 50
int main() {

	//munkat�rsak gener�l�sa//
	Munkatarsak munkatarsak[MT];
	munkatars_start(munkatarsak, MT);

	//F�ldek gener�l�sa//
	Foldek foldek[F];
	fold_start(foldek, F);

	return 0;
}