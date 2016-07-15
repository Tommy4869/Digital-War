#include "Tentomon.h"
#include "Kabuterimon.h"

Digimon* Tentomon::evolution(enum evolType et)
{
	if (et == EVOL)
	{
		return new Kabuterimon();
	}
}

int Tentomon::evoConsume(enum evolType et)
{
	if (et == EVOL)
	{
		return 1;
	}
	return -10;
}

char* Tentomon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Tento2Kabuteri.mp4";
	}
}
