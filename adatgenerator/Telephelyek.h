#pragma once
#include <string>

struct Telephelyek
{
	int Telephely_ID;
	std::string Cim;
	int Erogepek_Max;
	int Eroforrasok_Max;
};

void telephely_start(Telephelyek telephelyek[], int db) {
	
	telephelyek[0].Telephely_ID = 0;
	telephelyek[0].Cim = "9232, Darn�zseli f� utca 42";
	telephelyek[0].Erogepek_Max = 10;
	telephelyek[0].Eroforrasok_Max = 20;

	telephelyek[1].Telephely_ID = 1;
	telephelyek[1].Cim = "9200, Mosonmagyar�v�r T�ncsics Mih�ly utca 67";
	telephelyek[1].Erogepek_Max = 20;
	telephelyek[1].Eroforrasok_Max = 10;

	telephelyek[2].Telephely_ID = 2;
	telephelyek[2].Cim = "9071, G�ny� Palot�s utca 12";
	telephelyek[2].Erogepek_Max = 5;
	telephelyek[2].Eroforrasok_Max = 5;
}