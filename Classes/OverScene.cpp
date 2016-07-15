#include "OverScene.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

using namespace CocosDenshion;

USING_NS_CC;

Scene* OverScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = OverScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void OverScene::onEnter() {
	Layer::onEnter();

	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/win2.mp3");
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/lose2.mp3");

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* labe;
	if (winer == 1)
	{
		labe = Sprite::create("win.png");
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/win2.mp3", true);
	}
	else
	{
		labe = Sprite::create("lose.png");
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/lose2.mp3", true);
	}
	labe->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(labe, 1);
}

// on "init" you need to initialize your instance
bool OverScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* background = Sprite::create("back_over.png");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(background, 0);

	MenuItemImage* back = MenuItemImage::create("selGod.png", "selGod.png", CC_CALLBACK_1(OverScene::onBack, this));
	back->setScale(0.4, 0.4);
	back->setPosition(900, 40);
	back->setRotation(180);
	auto backm = Menu::create(back, NULL);
	backm->setPosition(Point::ZERO);
	addChild(backm, 2);

	return true;
}

void OverScene::onBack(Ref* ref) {
	Director::getInstance()->replaceScene(TransitionSlideInL::create(1.0f, HelloWorld::createScene()));
}
