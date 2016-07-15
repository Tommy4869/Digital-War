#ifndef __IMPERIALDRAMONX_H__
#define __IMPERIALDRAMONX_H__

#include "Digimon.h"

class ImperialDramonX : public Digimon {
public:
	ImperialDramonX() {
		setHpDa(10000, -5, -1000);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = ALL_ALL;
		setRan(n, b);
		setIsXros(false);
		mon = Sprite::create("Texture/ImperialDraX.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite() {
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new ImperialDramonX();
		return dm;
	}
	Digimon* evolution(enum evolType et);
	int evoConsume(enum evolType et);
	char* getVideo(enum evolType et);

private:
	Sprite* mon;
};

#endif