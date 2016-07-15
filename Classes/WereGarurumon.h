#ifndef __WEREGARURUMON_H__
#define __WEREGARURUMON_H__

#include "Digimon.h"

class WereGarurumon : public Digimon {
public:
	WereGarurumon() {
		setHpDa(100, -50, -10);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = FRONT_ALL;
		setRan(n, b);
		setIsXros(false);
		mon = Sprite::create("Texture/WereGaruru.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite()
	{
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new WereGarurumon();
		return dm;
	}
	Digimon* evolution(enum evolType et);
	int evoConsume(enum evolType et);
	char* getVideo(enum evolType et);

private:
	Sprite* mon;
};

#endif