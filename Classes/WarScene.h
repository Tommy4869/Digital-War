#ifndef __WARSCENE_H__
#define __WARSCENE_H__

#include "cocos2d.h"
#include "Agumon.h"
#include "Piemon.h"
#include "Gabumon.h"
#include "Piyomon.h"
#include "Palmon.h"
#include "Tentomon.h"
#include "Gomamon.h"
#include "WarPos.h"
#include "OverScene.h"
#include "VLCPlayer.h"
#include "Pinochimon.h"
#include "Mugendramon.h"
#include "MetalSeadramon.h"
#include "Etemon.h"
#include "Vamdemon.h"

USING_NS_CC;

enum STATUS { INVALID, ATTACKING, EVORUTING, XROSING };

class WarScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual void onEnter();

	virtual bool init();

	virtual void onAtt(Ref* ref);

	virtual void onXros(Ref* ref);

	virtual void onEvo(Ref* ref);

	virtual void onEnd(Ref* ref);

	virtual void onBack(Ref* ref);

	virtual void onNorAtt(Ref* ref);

	virtual void onBigAtt(Ref* ref);

	virtual void onNorEvo(Ref* ref);

	virtual void onUltEvo(Ref* ref);

	virtual void onArfEvo(Ref* ref);

	virtual void onArsEvo(Ref* ref);

	virtual void onUnEvo(Ref* ref);

	virtual void onXrosUp(Ref* ref);

	virtual void update(float dt) override;

	bool onTouchBegan(Touch *touch, Event *unused_event);

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(WarScene);

	int getPosByTouch(int, int);

	bool isTarget(int, enum attRange);

	void updateAttStatus();

	int Random(int m, int n);

	void computerTime();

	void comNorAtt();

	void comBigAtt();

	void gameOver();

	int isOver();

	void removeDigimon(int d);

	void setQt(Digimon* d, int i)
	{
		qt[i] = d->createDigi();
	}

	void getPower();

	bool ableXros();

	void playVideo(int, int);

	void delButton();

	void evolutionGhange(int, int);

	virtual void onSkip(Ref* ref);

	void setEvoEnable();

	void delFX();

	void evoLight();

	void attLight();

	void norAttFx(int);

	void bigAttFx(int);

	void afterEvoFx();

	void comNorAttFx(int);

	void comBigAttFx(int);

	void comTimeSch(float dt);

	void blackButton();

	void whiteButton(float dt);

	void delayHp(float dt);

	void delayHpX(float dt);


private:
	MenuItemImage* attButton;
	MenuItemImage* evoButton;
	MenuItemImage* xrosButton;
	MenuItemImage* endButton;
	enum STATUS sta = INVALID;

	MenuItemImage* norAttButton;
	MenuItemImage* bigAttButton;

	MenuItemImage* norEvoButton;
	MenuItemImage* ultEvoButton;
	MenuItemImage* arfEvoButton;
	MenuItemImage* arsEvoButton;
	MenuItemImage* unEvoButton;

	MenuItemImage* xrosUpButton;

	MenuItemImage* skipButton;

	int currrentPos = -1;
	WarPos* wp[12];
	bool frontSin[12];
	bool frontAll[12];
	bool backSin[12];
	bool backAll[12];
	bool colum[12];
	bool allAll[12];
	Digimon* qt[12];
	VLCPlayer* vcp;
	bool isVplay = false;

	int attPower;
	int evoPower;
	int defPower;

	ProgressTimer* attBar;
	ProgressTimer* evoBar;
	ProgressTimer* defBar;

	Sprite* aed[3];

	int preXros;
	int xrosPair[2];

	ParticleFire* evoFX;
	ParticleGalaxy* xrosFX1;
	ParticleGalaxy* xrosFX2;

	Layer* fxLayer;

	Sprite* evoLg;
	Sprite* attLg;

	int schTime;
	int timeCout;

	int hurtCout[6];
	int hci;
	int hcc;
	
};

#endif
