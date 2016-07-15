#ifndef __PINOCHIMON_H__
#define __PINOCHIMON_H__

#include "Digimon.h"
#include "cocos2d.h"

USING_NS_CC;

class Pinochimon : public Digimon {
public:
	Pinochimon() {
		setHpDa(20, -2, -3);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = FRONT_ALL;
		setRan(n, b);
		mon = Sprite::create("Texture/Pinochi.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite() {
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new Pinochimon();
		return dm;
	}
	//void getTest11() { log("kk"); }
private:
	Sprite* mon;
};

#endif