#include "XVmon.h"
#include "Vmon.h"
#include "Paildoramon.h"

Digimon* XVmon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Vmon();
	}
	if (et == XROS)
	{
		return new Paildoramon();
	}
}

int XVmon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	if (et == XROS)
	{
		return 1;
	}
	return -10;
}

char* XVmon::getVideo(enum evolType et)
{
	if (et == UNEVOL)
	{
		return "AguToGrey.mp4";
	}
	if (et == XROS)
	{
		return "video/XV5Sting.mp4";
	}
}

