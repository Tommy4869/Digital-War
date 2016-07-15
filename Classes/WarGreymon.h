#ifndef __WARGREYMON_H__
#define __WARGREYMON_H__

#include "Digimon.h"

class WarGreymon : public Digimon {
public:
	WarGreymon() {
		setHpDa(100, -50, -10);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = FRONT_ALL;
		setRan(n, b);
		setIsXros(false);
		mon = Sprite::create("Texture/WarGrey.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite() {
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new WarGreymon();
		return dm;
	}
	Digimon* evolution(enum evolType et);
	int evoConsume(enum evolType et);

private:
	Sprite* mon;
};

#endif