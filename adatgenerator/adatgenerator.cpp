#include <iostream>

#include "Munkatarsak.h"
#include "Foldek.h"
#include "Telephelyek.h"


//Makr�k a k�v�nt mennyis�g� adat gener�l�s�hoz

#define MT 5 
#define F 50
#define TH 3

int main() {

	//munkat�rsak gener�l�sa//
	Munkatarsak munkatarsak[MT];
		munkatars_start(munkatarsak, MT);
		std::cout << munkatarsak[0].Nev;

	//F�ldek gener�l�sa//
	Foldek foldek[F];
		fold_start(foldek, F);

	//Nem gener�lt Telephelyek
	Telephelyek telephelyek[TH];
		telephely_start(telephelyek, TH);

	std::cout << "Generalas kesz/n";
	return 0;
}