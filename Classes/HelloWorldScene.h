#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "VLCPlayer.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	virtual void onHelp(Ref* ref);

	virtual void onStart(Ref* ref);

	virtual void onEG(Ref* ref);

	virtual void onEV(Ref* ref);

	virtual void onStaff(Ref* ref);

	virtual void onABU(Ref* ref);

	virtual void onMore(Ref* ref);

	virtual void onExit(Ref* ref);
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void setCurrent(MenuItemImage* ci);

	MenuItemImage* getCurrent();

	int getPos(float y);

private:
	MenuItemImage* butt[8];
	MenuItemImage* warmode;
	MenuItemImage* evolGuide;

	MenuItemImage* currentItem;
};

#endif // __HELLOWORLD_SCENE_H__
