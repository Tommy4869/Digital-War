#include "Agumon.h"
#include "Greymon.h"
#include "WarGreymon.h"

Digimon* Agumon::evolution(enum evolType et)
{
	if (et == EVOL)
	{
		return new Greymon();
	}
	if (et == ULTIM_EVOL)
	{
		return new WarGreymon();
	}
}

int Agumon::evoConsume(enum evolType et)
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

char* Agumon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Agu2Grey.mp4";
	}
	if (et == ULTIM_EVOL)
	{
		return "video/Agu2WarGrey.mp4";
	}
}
