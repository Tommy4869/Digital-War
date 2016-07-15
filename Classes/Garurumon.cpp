#include "Garurumon.h"
#include "Gabumon.h"
#include "WereGarurumon.h"

Digimon* Garurumon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Gabumon();
	}
	if (et == EVOL)
	{
		return new WereGarurumon();
	}
}

int Garurumon::evoConsume(enum evolType et)
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

char* Garurumon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Garuru2WereGaruru.mp4";
	}
}

