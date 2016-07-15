#ifndef __METALSEADRAMON_H__
#define __METALSEADRAMON_H__

#include "Digimon.h"
#include "cocos2d.h"

USING_NS_CC;

class MetalSeadramon : public Digimon {
public:
	MetalSeadramon() {
		setHpDa(20, -2, -3);
		setHpBar();
		enum attRange n = FRONT_SIN;
		enum attRange b = FRONT_ALL;
		setRan(n, b);
		mon = Sprite::create("Texture/MetalSeadra.png");
	}
	void normalAttack();
	void bigAttack();
	Sprite* getSprite() {
		return mon;
	}
	Digimon* createDigi()
	{
		Digimon* dm = new MetalSeadramon();
		return dm;
	}
	//void getTest11() { log("kk"); }
private:
	Sprite* mon;
};

#endif