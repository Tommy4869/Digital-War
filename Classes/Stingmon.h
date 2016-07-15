#ifndef __STINGMON_H__
#define __STINGMON_H__

#include "Digimon.h"

class Stingmon : public Digimon {
public:
	Stingmon() {
		setHpDa(100, -50, -10);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = FRONT_ALL;
		setIsXros(true);
		setXrosNum(1);
		setXrosObj(0);
		setRan(n, b);
		mon = Sprite::create("Texture/Sting.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite() {
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new Stingmon();
		return dm;
	}
	Digimon* evolution(enum evolType et);
	int evoConsume(enum evolType et);
	char* getVideo(enum evolType et);

private:
	Sprite* mon;
};

#endif