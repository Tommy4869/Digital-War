#ifndef __DIGIMON_H__
#define __DIGIMON_H__

#include "cocos2d.h"

USING_NS_CC;
extern enum attRange {FRONT_SIN, BACK_SIN, FRONT_ALL, BACK_ALL, COLUM, ALL_ALL};
extern enum evolType { EVOL, SUPER_EVOL, ULTIM_EVOL, SOULH_EVOL, SOULM_EVOL, SOULD_EVOL, TRAN_EVOL, UNEVOL, ARMORF, ARMORS, XROS };

class Digimon {
public:
	Digimon() {
		isSelItem = false;
	}
	void setHpBar() {
		hpBar = ProgressTimer::create(Sprite::create("life.png"));
		hpBar->setType(ProgressTimer::Type::BAR);
		hpBar->setMidpoint(Point(0, 0));
		hpBar->setBarChangeRate(Point(1, 0));
		hpBar->setPercentage((double)hp / maxHp * 100);
		hpBB = Sprite::create("lifeBar.png");
		hpBar->setScale(0.5, 0.3);
		hpBB->setScale(0.5, 0.3);
	}
	void changeHp(int ch) {
		hp += ch;
		hpBar->setPercentage((double)hp / maxHp * 100);
	}
	virtual Sprite* getSprite() {
		return NULL;
	}

	virtual Digimon* createDigi() 
	{
		return new Digimon();
	}

	virtual Digimon* evolution(enum evolType et)
	{
		return new Digimon();
	}

	virtual int evoConsume(enum evolType et)
	{
		return 0;
	}

	virtual char* getVideo(enum evolType et)
	{
		return "sb";
	}

	void setSel() 
	{
		isSelItem = true;
	}

	bool isSel()
	{
		return isSelItem;
	}

	//void getTest11() { log("da"); }
	ProgressTimer* getHpbar() {
		return hpBar;
	}

	Sprite* getHpBB() {
		return hpBB;
	}

	void setHpDa(int h, int d, int dx) { 
		hp = h; 
		maxHp = h;
		damage = d;
		damageX = dx;
	}
	int getHp() { return hp; }
	int getDam() { return damage; }
	int getDamX() { return damageX; }

	void setRan(enum attRange n, enum attRange b) {
		norRan = n;
		bigRan = b;
	}
	enum attRange getNorRan() {
		return norRan;
	}
	enum attRange getBigRan() {
		return bigRan;
	}
	void setIsXros(bool ix)
	{
		isXros = ix;
	}

	bool isXrosAble()
	{
		return isXros;
	}

	void setXrosObj(int xo)
	{
		xrosObj = xo;
	}

	int getXrosObj()
	{
		return xrosObj;
	}

	void setXrosNum(int xn)
	{
		xrosNum = xn;
	}

	int getXrosNum()
	{
		return xrosNum;
	}


private:
	int maxHp;
	int hp;
	int damage;
	int damageX;
	ProgressTimer* hpBar;
	Sprite* hpBB;
	enum attRange norRan;
	enum attRange bigRan;
	bool isSelItem;
	int xrosNum;
	bool isXros;
	int xrosObj;
};

#endif