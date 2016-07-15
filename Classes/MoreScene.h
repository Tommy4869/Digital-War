#ifndef __MORESCENE_H__
#define __MORESCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class MoreScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void onBack(Ref* ref);

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(MoreScene);

private:
	MenuItemImage* back;

	int pos;
};

#endif // __HELLOWORLD_SCENE_H__
