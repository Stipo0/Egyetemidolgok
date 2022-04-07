#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>


struct Munkatarsak
{
	int Munkatars_ID;
	std::string Nev;
	std::string Telefonszam;
	int munkaviszony;
};


Munkatarsak munkatars_generate(int id) {

	Munkatarsak munkatars;

	//Minta adatok//
	std::string csaladnev[] = {"Nagy","Kov�cs","T�th","Szab�","Horv�th",
							   "Varga","Kiss","Moln�r","N�meth","Farkas"};

	std::string keresztnev[] = { "D�niel","D�vid","Bence","M�t�","Tam�s",
								"Vikt�ria","Vivien","Anna","Alexandra","Fanni" };

	std::string korzetszam[] = { "0620","0630","0670" };


	//Randomiz�l�s �s �rt�kad�s//
	munkatars.Munkatars_ID = id;
	munkatars.Nev = csaladnev[rand() % 10] + " " + keresztnev[rand() % 10];
	munkatars.Telefonszam = korzetszam[rand() % 3];
		for (int i = 0; i < 7; i++)
		{
			munkatars.Telefonszam += ((rand() % 10) + '0');
		}
	munkatars.munkaviszony = rand() % 2; 

	return munkatars;
};


//SQL -nek megfelel� form�z�s//
void munkatars_print(Munkatarsak munkatars,bool utolso) {

	std::ofstream File("adat/Munkatarsak.txt", std::ios::app);

	File << "INSERT INTO Munkatarsak VALUES ('" 
		<< munkatars.Munkatars_ID 
		<< "', '" << munkatars.Nev 
		<< "', '" << munkatars.Telefonszam 
		<< "', '" << munkatars.munkaviszony 
		<< "')" << std::endl;

	if (utolso == 1) { File.close();}
}


//eggyez� adatok eset�n �j adatot gener�lunk//
bool munkatars_hasonlit(Munkatarsak a, Munkatarsak b) {

	bool ertek = 0;
	if (a.Nev == b.Nev) return 1;
	if (a.Telefonszam == b.Telefonszam) return 1;
	return 0;

}

//Majdnem main//
void munkatars_start(Munkatarsak munkatarsak[],int db) {

	for (int i = 0; i < db; i++)
	{
		munkatarsak[i] = munkatars_generate(i);

		for (int j = 0; j < i; j++)
		{
			while (munkatars_hasonlit(munkatarsak[j], munkatarsak[i])) {
				munkatarsak[i] = munkatars_generate(i);
			}
		};
	}

	for (int i = 0; i < db - 1; i++)
	{
		munkatars_print(munkatarsak[i], 0);
	}

	munkatars_print(munkatarsak[db - 1], 1);
}

