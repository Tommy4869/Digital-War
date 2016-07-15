#include "Kabuterimon.h"
#include "Tentomon.h"
#include "HeraclesKabuterimon.h"

Digimon* Kabuterimon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Tentomon();
	}
	if (et == EVOL)
	{
		return new HeraclesKabuterimon();
	}
}

int Kabuterimon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	if (et == EVOL)
	{
		return 2;
	}
	return -10;
}

char* Kabuterimon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Kabuteri2HeraclesKabuteri.mp4";
	}
}

