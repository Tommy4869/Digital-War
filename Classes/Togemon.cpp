#include "Togemon.h"
#include "Palmon.h"
#include "Lilymon.h"

Digimon* Togemon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Palmon();
	}
	if (et == EVOL)
	{
		return new Lilymon();
	}
}

int Togemon::evoConsume(enum evolType et)
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

char* Togemon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Toge2Lily.mp4";
	}
}

