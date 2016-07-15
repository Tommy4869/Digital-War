#include "Vritramon.h"
#include "Takyamon.h"

Digimon* Vritramon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Takyamon();
	}
}

int Vritramon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}

char* Vritramon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "AguToGrey.mp4";
	}
}

