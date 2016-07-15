#ifndef __KABUTERIMON_H__
#define __KABUTERIMON_H__

#include "Digimon.h"

class Kabuterimon : public Digimon {
public:
	Kabuterimon() {
		setHpDa(100, -50, -10);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = FRONT_ALL;
		setRan(n, b);
		setIsXros(false);
		mon = Sprite::create("Texture/Kabuteri.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite() {
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new Kabuterimon();
		return dm;
	}
	Digimon* evolution(enum evolType et);
	int evoConsume(enum evolType et);
	char* getVideo(enum evolType et);

private:
	Sprite* mon;
};

#endif