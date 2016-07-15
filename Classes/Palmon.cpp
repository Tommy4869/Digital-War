#include "Palmon.h"
#include "Togemon.h"

Digimon* Palmon::evolution(enum evolType et)
{
	if (et == EVOL)
	{
		return new Togemon();
	}
}

int Palmon::evoConsume(enum evolType et)
{
	if (et == EVOL)
	{
		return 1;
	}
	return -10;
}

char* Palmon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Pal2Toge.mp4";
	}
}
