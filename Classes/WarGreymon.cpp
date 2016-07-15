#include "WarGreymon.h"
#include "Agumon.h"

Digimon* WarGreymon::evolution(enum evolType et)
{
	if (et == UNEVOL)
	{
		return new Agumon();
	}
}

int WarGreymon::evoConsume(enum evolType et)
{
	if (et == UNEVOL)
	{
		return -1;
	}
	return -10;
}
