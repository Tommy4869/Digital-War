#ifndef __ZUDOMON_H__
#define __ZUDOMON_H__

#include "Digimon.h"

class Zudomon : public Digimon {
public:
	Zudomon() {
		setHpDa(100, -50, -10);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = FRONT_ALL;
		setRan(n, b);
		setIsXros(false);
		mon = Sprite::create("Texture/Zudo.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite()
	{
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new Zudomon();
		return dm;
	}
	Digimon* evolution(enum evolType et);
	int evoConsume(enum evolType et);
	char* getVideo(enum evolType et);

private:
	Sprite* mon;
};

#endif