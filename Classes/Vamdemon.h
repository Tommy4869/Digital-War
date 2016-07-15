#ifndef __VAMDERMON_H__
#define __VAMDERMON_H__

#include "Digimon.h"
#include "cocos2d.h"

USING_NS_CC;

class Vamdemon : public Digimon {
public:
	Vamdemon() {
		setHpDa(1000, -2, -3);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = FRONT_ALL;
		setRan(n, b);
		mon = Sprite::create("Texture/Vamde.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite() {
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new Vamdemon();
		return dm;
	}
	//void getTest11() { log("kk"); }
private:
	Sprite* mon;
};

#endif