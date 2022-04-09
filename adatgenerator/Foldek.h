#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>


struct Foldek
{
	int Fold_ID;
	std::string HelyrajziSzam;
	int AranyKorona;
	float Meret;
	int Tulajdon;
};


Foldek fold_generate(int id) {

	Foldek fold;

	//Randomizálás és értékadás//
	fold.Fold_ID = id;
	fold.HelyrajziSzam = "0";

	int helyszhossz = (rand() % 3 + 2);
		for (int i = 0; i < helyszhossz; i++)
		{
			fold.HelyrajziSzam += ((rand() % 10 + 0 ) + '0');
		}
		if (rand() % 2) {
			fold.HelyrajziSzam += "/";
			fold.HelyrajziSzam += ((rand() % 6 + 1) + '0');
		}

	fold.AranyKorona = (rand() % 4 + 3);
	fold.Meret = ((rand() % 10 + 1) + ((rand() % 89 + 10) / 100));
	fold.Tulajdon = rand() % 2;

	return fold;
};


//SQL -nek megfelelõ formázás//
void fold_print(std::ofstream& File, Foldek fold) {

	File << "INSERT [Foldek] ([Fold_ID], [HelyrajziSzam], [AranyKorona], [Meret], [Tulajdon]) VALUES ("
		<< fold.Fold_ID <<", N'"<<fold.HelyrajziSzam<<"', " << fold.AranyKorona <<", "<< fold.Meret <<", "<< fold.Tulajdon<<")"
		<< std::endl
		<< "GO"
		<< std::endl;
}


//eggyezõ adatok esetén új adatot generálunk//
bool foldek_hasonlit(Foldek a, Foldek b) {

	bool ertek = 0;
	if ((a.HelyrajziSzam == b.HelyrajziSzam) or (a.Meret == b.Meret)) { return 1; }
	 else { return 0; }

}

//Majdnem main//
void fold_start(Foldek foldek[], int db) {

	for (int i = 0; i < db; i++)
	{
		foldek[i] = fold_generate(i);

		for (int j = 0; j < i; j++)
		{
			while (foldek_hasonlit(foldek[j], foldek[i])) {
				foldek[i] = fold_generate(i);
			}
		};
	}

	std::ofstream File("adat/Foldek.txt", std::ios::app);

	File << "USE [Mezogazdasag]"
		<< std::endl
		<< "GO"
		<< std::endl
		<< "SET IDENTITY_INSERT [Foldek] ON "
		<< std::endl
		<< "GO"
		<< std::endl;

	for (int i = 0; i < db; i++)
	{
		fold_print(File, foldek[i]);
	}

	File << "SET IDENTITY_INSERT [Foldek] OFF"
		<< std::endl
		<< "GO";

	File.close();
}