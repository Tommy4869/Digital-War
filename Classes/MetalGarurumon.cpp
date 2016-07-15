#include "MetalGarurumon.h"
#include "Gabumon.h"

Digimon* MetalGarurumon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Gabumon();
	}
}

int MetalGarurumon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}
