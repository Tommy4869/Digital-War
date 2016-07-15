#include "Ikkakumon.h"
#include "Gomamon.h"
#include "Zudomon.h"

Digimon* Ikkakumon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Gomamon();
	}
	if (et == EVOL)
	{
		return new Zudomon();
	}
}

int Ikkakumon::evoConsume(enum evolType et)
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

char* Ikkakumon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Ikkaku2Zudo.mp4";
	}
}

