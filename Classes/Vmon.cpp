#include "Vmon.h"
#include "XVmon.h"
#include "Fladramon.h"
#include "Lighdramon.h"

Digimon* Vmon::evolution(enum evolType et)
{
	if (et == EVOL)
	{
		return new XVmon();
	}
	if (et == ARMORF)
	{
		return new Fladramon();
	}
	if (et == ARMORS)
	{
		return new Lighdramon();
	}
}

int Vmon::evoConsume(enum evolType et)
{
	if (et == EVOL)
	{
		return 1;
	}
	if (et == ARMORF)
	{
		return 2;
	}
	if (et == ARMORS)
	{
		return 2;
	}
	return -10;
}

char* Vmon::getVideo(enum evolType et)
{
	if (et == EVOL)
	{
		return "video/V2XV.mp4";
	}
	if (et == ARMORF)
	{
		return "video/V2Fladra.mp4";
	}
	if (et == ARMORS)
	{
		return "video/V2Lighdra.mp4";
	}
}
