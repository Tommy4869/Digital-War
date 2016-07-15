#include "Zudomon.h"
#include "Gomamon.h"

Digimon* Zudomon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Gomamon();
	}
}

int Zudomon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}

char* Zudomon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "AguToGrey.mp4";
	}
}


