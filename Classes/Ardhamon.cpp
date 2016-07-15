#include "Ardhamon.h"
#include "Takyamon.h"

Digimon* Ardhamon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Takyamon();
	}
}

int Ardhamon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}

char* Ardhamon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "AguToGrey.mp4";
	}
}

