#include "Takyamon.h"
#include "Agnimon.h"
#include "Vritramon.h"
#include "Ardhamon.h"

Digimon* Takyamon::evolution(enum evolType et)
{
	if (et == ARMORF)
	{
		return new Agnimon();
	}
	if (et == ARMORS)
	{
		return new Vritramon();
	}
	if (et == ULTIM_EVOL)
	{
		return new Ardhamon();
	}
}

int Takyamon::evoConsume(enum evolType et)
{
	if (et == ARMORF)
	{
		return 2;
	}
	if (et == ARMORS)
	{
		return 2;
	}
	if (et == ULTIM_EVOL)
	{
		return 5;
	}
	return -10;
}

char* Takyamon::getVideo(enum evolType et)
{
	if (et == ARMORF)
	{
		return "video/Takya2Agni.mp4";
	}
	if (et == ARMORS)
	{
		return "video/Takya2Vritra.mp4";
	}
	if (et == ULTIM_EVOL)
	{
		return "video/Takya2Ardha.mp4";
	}
}
