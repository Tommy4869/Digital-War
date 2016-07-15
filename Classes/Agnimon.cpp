#include "Agnimon.h"
#include "Takyamon.h"

Digimon* Agnimon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Takyamon();
	}
}

int Agnimon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}

char* Agnimon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "AguToGrey.mp4";
	}
}

