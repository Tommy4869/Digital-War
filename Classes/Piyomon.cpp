#include "Piyomon.h"
#include "Birdramon.h"

Digimon* Piyomon::evolution(enum evolType et)
{
	if (et == EVOL)
	{
		return new Birdramon();
	}
}

int Piyomon::evoConsume(enum evolType et)
{
	if (et == EVOL)
	{
		return 1;
	}
	return -10;
}

char* Piyomon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Piyo2Birdra.mp4";
	}
}
