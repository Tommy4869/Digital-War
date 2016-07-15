#include "Garudamon.h"
#include "Piyomon.h"

Digimon* Garudamon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Piyomon();
	}
}

int Garudamon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}

char* Garudamon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "AguToGrey.mp4";
	}
}


