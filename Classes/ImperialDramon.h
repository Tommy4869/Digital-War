#ifndef __IMPERIALDRAMON_H__
#define __IMPERIALDRAMON_H__

#include "Digimon.h"

class ImperialDramon : public Digimon {
public:
	ImperialDramon() {
		setHpDa(100, -50, -10);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = FRONT_ALL;
		setRan(n, b);
		setIsXros(false);
		mon = Sprite::create("Texture/ImperialDra.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite() {
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new ImperialDramon();
		return dm;
	}
	Digimon* evolution(enum evolType et);
	int evoConsume(enum evolType et);
	char* getVideo(enum evolType et);

private:
	Sprite* mon;
};

#endif