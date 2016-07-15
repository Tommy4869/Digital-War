#ifndef __LILYMON_H__
#define __LILYMON_H__

#include "Digimon.h"

class Lilymon : public Digimon {
public:
	Lilymon() {
		setHpDa(100, -50, -10);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = FRONT_ALL;
		setRan(n, b);
		setIsXros(false);
		mon = Sprite::create("Texture/Lily.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite()
	{
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new Lilymon();
		return dm;
	}
	Digimon* evolution(enum evolType et);
	int evoConsume(enum evolType et);
	char* getVideo(enum evolType et);

private:
	Sprite* mon;
};

#endif