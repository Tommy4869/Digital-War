#ifndef __XVMON_H__
#define __XVMON_H__

#include "Digimon.h"

class XVmon : public Digimon {
public:
	XVmon() {
		setHpDa(100, -50, -10);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = FRONT_ALL;
		setRan(n, b);
		setIsXros(true);
		setXrosNum(0);
		setXrosObj(1);
		mon = Sprite::create("Texture/XV.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite() {
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new XVmon();
		return dm;
	}
	Digimon* evolution(enum evolType et);
	int evoConsume(enum evolType et);
	char* getVideo(enum evolType et);

private:
	Sprite* mon;
};

#endif