#include "Lilymon.h"
#include "Palmon.h"

Digimon* Lilymon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Palmon();
	}
}

int Lilymon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}

char* Lilymon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "AguToGrey.mp4";
	}
}


