#include "Paildoramon.h"
#include "ImperialDramon.h"


Digimon* Paildoramon::evolution(enum evolType et)
{
	if (et == EVOL)
	{
		return new ImperialDramon();
	}
}

int Paildoramon::evoConsume(enum evolType et)
{
	if (et == EVOL)
	{
		return 0;
	}
	return -10;
}

char* Paildoramon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Pali2Imp.mp4";
	}
}

