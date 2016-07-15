#include "Fladramon.h"
#include "Vmon.h"

Digimon* Fladramon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Vmon();
	}
}

int Fladramon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}

char* Fladramon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "AguToGrey.mp4";
	}
}

