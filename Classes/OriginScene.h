#ifndef __ORIGINSCENE_H__
#define __ORIGINSCENE_H__

#include "cocos2d.h"
#include "VLCPlayer.h"

USING_NS_CC;

class OriginScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	void playVideo();

	virtual void onSkip(Ref* ref);

	virtual void update(float dt) override;

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(OriginScene);

private:

	bool isVplay = false;

	VLCPlayer* vcp;

	MenuItemImage* skipButton;


};

#endif // __HELLOWORLD_SCENE_H__
