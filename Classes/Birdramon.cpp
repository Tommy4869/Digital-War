#include "Birdramon.h"
#include "Piyomon.h"
#include "Garudamon.h"

Digimon* Birdramon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Piyomon();
	}
	if (et == EVOL)
	{
		return new Garudamon();
	}
}

int Birdramon::evoConsume(enum evolType et)
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

char* Birdramon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Birdra2Garuda.mp4";
	}
}

