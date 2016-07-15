#include "Greymon.h"
#include "Agumon.h"
#include "MetalGreymon.h"

Digimon* Greymon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Agumon();
	}
	if (et == EVOL)
	{
		return new MetalGreymon();
	}
}

int Greymon::evoConsume(enum evolType et)
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

char* Greymon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Grey2MetalGrey.mp4";
	}
}

