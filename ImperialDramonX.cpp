#include "ImperialDramonX.h"

Digimon* ImperialDramonX::evolution(enum evolType et)
{
	return new ImperialDramonX();
}

int ImperialDramonX::evoConsume(enum evolType et)
{
	return -10;
}

char* ImperialDramonX::getVideo(enum evolType et)
{
	return "video/Toge2Lily.mp4";
}

