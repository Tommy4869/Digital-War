#ifndef __OVER_SCENE_H__
#define __OVER_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class OverScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual void onEnter();

	virtual bool init();

	virtual void onBack(Ref* ref);

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(OverScene);

	void setWiner(int w) 
	{
		winer = w;
	}


private:
	int winer;
	
};

#endif // __HELLOWORLD_SCENE_H__
