#include "HelloWorldScene.h"
#include "OriginScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* OriginScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = OriginScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool OriginScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	isVplay = false;

	skipButton = MenuItemImage::create("skip.png", "skip.png", CC_CALLBACK_1(OriginScene::onSkip, this));
	skipButton->setPosition(800, 50);
	skipButton->setScale(0.3, 0.3);
	auto skipButtonm = Menu::create(skipButton, NULL);
	skipButtonm->setPosition(Point::ZERO);
	addChild(skipButtonm, 6);
	skipButton->setOpacity(0);
	skipButton->setEnabled(false);

	scheduleUpdate();

	playVideo();

	return true;
}

void OriginScene::playVideo()
{
	isVplay = true;
	vcp = VLCPlayer::create(Size(960, 540));
	vcp->setPosition(480, 270);
	addChild(vcp, 5);
	vcp->o_play("video/Open.mp4");

	skipButton->setOpacity(255);
	skipButton->setEnabled(true);
}

void OriginScene::update(float dt)
{
	if (isVplay && vcp->isEndReached())
	{
		Director::getInstance()->replaceScene(HelloWorld::createScene());
		/*removeChild(vcp);
		isVplay = false;
		skipButton->setOpacity(0);
		skipButton->setEnabled(false);*/
	}
}

void OriginScene::onSkip(Ref* ref)
{
	vcp->o_stop();
}
