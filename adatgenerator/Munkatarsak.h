#pragma once
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
	std::string csaladnev[] = {"Nagy","Kovács","Tóth","Szabó","Horváth",
							   "Varga","Kiss","Molnár","Németh","Farkas"};

	std::string keresztnev[] = { "Dániel","Dávid","Bence","Máté","Tamás",
								"Viktória","Vivien","Anna","Alexandra","Fanni" };

	std::string korzetszam[] = { "0620","0630","0670" };


	//Randomizálás és értékadás//
	munkatars.Munkatars_ID = id;
	munkatars.Nev = csaladnev[rand() % 10] + " " + keresztnev[rand() % 10];
	munkatars.Telefonszam = korzetszam[rand() % 3];
		for (int i = 0; i < 7; i++)
		{
			munkatars.Telefonszam += ((rand() % 10) + '0');
		}
	munkatars.munkaviszony = 1; 

	return munkatars;
};


//SQL -nek megfelelõ formázás//
void munkatars_print(std::ofstream &File, Munkatarsak munkatars) {

	File << "INSERT [Munkatarsak] ([Munkatars_ID], [Nev], [Telefonszam], [MunkaViszony]) VALUES ("
		<< munkatars.Munkatars_ID << ", N'" << munkatars.Nev << "', N'" << munkatars.Telefonszam << "', " << munkatars.munkaviszony << ")"
		<< std::endl
		<< "GO"
		<< std::endl;
}


//eggyezõ adatok esetén új adatot generálunk//
bool munkatars_hasonlit(Munkatarsak a, Munkatarsak b) {

	bool ertek = 0;
	if ((a.Nev == b.Nev) or (a.Telefonszam == b.Telefonszam)) { return 1; }
	 else { return 0; }

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

	std::ofstream File("adat/Munkatarsak.txt", std::ios::app);

	File << "USE [Mezogazdasag]" 
		 << std::endl 
		 << "GO" 
		 << std::endl 
		 << "SET IDENTITY_INSERT [Munkatarsak] ON " 
		 << std::endl 
		 << "GO" 
		 << std::endl;

	for (int i = 0; i < db; i++)
	{
		munkatars_print(File, munkatarsak[i]);
	}

	File << "SET IDENTITY_INSERT [Munkatarsak] OFF" 
		 << std::endl 
		 << "GO"
		 << std::endl;

	File.close();
}