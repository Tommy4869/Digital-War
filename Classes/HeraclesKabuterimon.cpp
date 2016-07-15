#include "HeraclesKabuterimon.h"
#include "Tentomon.h"

Digimon* HeraclesKabuterimon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Tentomon();
	}
}

int HeraclesKabuterimon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}

char* HeraclesKabuterimon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "AguToGrey.mp4";
	}
}


