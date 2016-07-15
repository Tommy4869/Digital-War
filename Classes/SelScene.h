#ifndef __SEL_SCENE_H__
#define __SEL_SCENE_H__

#include "cocos2d.h"
#include "Agumon.h"
#include "Piemon.h"
#include "Gabumon.h"
#include "Piyomon.h"
#include "Palmon.h"
#include "Tentomon.h"
#include "Gomamon.h"
#include "Wormmon.h"
#include "Vmon.h"
#include "Takyamon.h"

USING_NS_CC;

class SelScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void onLeft(Ref* ref);

	virtual void onRight(Ref* ref);

	virtual void onConfirm(Ref* ref);

	virtual void onDiff(Ref* ref);

	virtual void onChapter(Ref* ref);

	virtual void onBack(Ref* ref);

	virtual void onGo(Ref* ref);

	int getPos(float x);

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(SelScene);


private:
	Digimon* allDigi[8];
	int selPos;
	Digimon* seledDigi[6];
	int currentDigi;

	MenuItemImage* startButton;
	MenuItemImage* confirmButton;
};

#endif // __HELLOWORLD_SCENE_H__
