#include "Gabumon.h"
#include "Garurumon.h"
#include "MetalGarurumon.h"

Digimon* Gabumon::evolution(enum evolType et)
{
	if (et == EVOL)
	{
		return new Garurumon();
	}
	if (et == ULTIM_EVOL)
	{
		return new MetalGarurumon();
	}
}

int Gabumon::evoConsume(enum evolType et)
{
	if (et == EVOL)
	{
		return 1;
	}
	if (et == ULTIM_EVOL)
	{
		return 3;
	}
	return -10;
}

char* Gabumon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Gabu2Garuru.mp4";
	}
	if (et == ULTIM_EVOL)
	{
		return "video/Gabu2MetalGaruru.mp4";
	}
}
