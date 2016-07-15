#include "MetalGreymon.h"
#include "Agumon.h"

Digimon* MetalGreymon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Agumon();
	}
}

int MetalGreymon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}

char* MetalGreymon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "AguToGrey.mp4";
	}
}


