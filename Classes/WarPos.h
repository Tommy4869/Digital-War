#ifndef __WARPOS_H__
#define __WARPOS_H__

#include "Digimon.h"

class WarPos {
public:
	WarPos() {
		dgm = NULL;
	}
	WarPos(Digimon* d, float px, float py, float ppx, float ppy) {
		dgm = d;
		posiX = px;
		posiY = py;
		hpPosiX = ppx;
		hpPosiY = ppy;
	}

	void setWarPos(Digimon* d, float px, float py, float ppx, float ppy) {
		dgm = d;
		posiX = px;
		posiY = py;
		hpPosiX = ppx;
		hpPosiY = ppy;
	}

	void setDgm(Digimon* d)
	{
		dgm = d;
	}

	Digimon* getDgm() {
		return dgm;
	}

	void delDigi()
	{
		delete dgm;
		dgm = NULL;
	}

	float getPosX() {
		return posiX;
	}

	float getPosY() {
		return posiY;
	}

	float getHpPosX() {
		return hpPosiX;
	}

	float getHpPosY() {
		return hpPosiY;
	}

private:
	Digimon* dgm;
	float posiX;
	float posiY;
	float hpPosiX;
	float hpPosiY;
};

#endif
