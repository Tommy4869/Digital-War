#include "Wormmon.h"
#include "Stingmon.h"

Digimon* Wormmon::evolution(enum evolType et)
{
	if (et == EVOL)
	{
		return new Stingmon();
	}
}

int Wormmon::evoConsume(enum evolType et)
{
	if (et == EVOL)
	{
		return 1;
	}
	return -10;
}

char* Wormmon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Worm2Sting.mp4";
	}
}
