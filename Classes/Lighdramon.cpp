#include "Lighdramon.h"
#include "Vmon.h"

Digimon* Lighdramon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Vmon();
	}
}

int Lighdramon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}

char* Lighdramon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "AguToGrey.mp4";
	}
}

