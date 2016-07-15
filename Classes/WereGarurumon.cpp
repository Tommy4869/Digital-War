#include "WereGarurumon.h"
#include "Gabumon.h"

Digimon* WereGarurumon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Gabumon();
	}
}

int WereGarurumon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}

char* WereGarurumon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "AguToGrey.mp4";
	}
}


