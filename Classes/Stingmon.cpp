#include "Stingmon.h"
#include "Wormmon.h"
#include "Paildoramon.h"

Digimon* Stingmon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Wormmon();
	}
	if (et == XROS)
	{
		return new Paildoramon();
	}
}

int Stingmon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	if (et == XROS)
	{
		return 1;
	}
	return -10;
}

char* Stingmon::getVideo(enum evolType et)
{
	if (et == UNEVOL)
	{
		return "AguToGrey.mp4";
	}
	if (et == XROS)
	{
		return "video/XV5Sting.mp4";
	}
}

