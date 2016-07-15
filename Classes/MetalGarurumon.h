#ifndef _METALGARURUMON_H__
#define _METALGARURUMON_H__

#include "Digimon.h"

class MetalGarurumon : public Digimon {
public:
	MetalGarurumon() {
		setHpDa(100, -50, -10);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = FRONT_ALL;
		setRan(n, b);
		setIsXros(false);
		mon = Sprite::create("Texture/MetalGaruru.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite() {
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new MetalGarurumon();
		return dm;
	}
	Digimon* evolution(enum evolType et);
	int evoConsume(enum evolType et);

private:
	Sprite* mon;
};

#endif