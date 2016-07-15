#include "Gomamon.h"
#include "Ikkakumon.h"

Digimon* Gomamon::evolution(enum evolType et)
{
	if (et == EVOL)
	{
		return new Ikkakumon();
	}
}

int Gomamon::evoConsume(enum evolType et)
{
	if (et == EVOL)
	{
		return 1;
	}
	return -10;
}

char* Gomamon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Goma2Ikkaku.mp4";
	}
}
