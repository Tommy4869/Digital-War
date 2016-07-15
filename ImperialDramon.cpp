#include "ImperialDramon.h"
#include "ImperialDramonX.h"

Digimon* ImperialDramon::evolution(enum evolType et)
{
	if (et == EVOL)
	{
		return new ImperialDramonX();
	}
}

int ImperialDramon::evoConsume(enum evolType et)
{
	if (et == EVOL)
	{
		return 0;
	}
	return -10;
}

char* ImperialDramon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/Imp2ImpX.mp4";
	}
}

