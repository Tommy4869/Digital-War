#include "HelloWorldScene.h"
#include "HelpScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelpScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = HelpScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelpScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* background = Sprite::create("HelpBack.png");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(background, 0);


	back = MenuItemImage::create("selGod.png", "selGod.png", CC_CALLBACK_1(HelpScene::onBack, this));
	back->setScale(0.4, 0.4);
	back->setPosition(900, 40);
	back->setRotation(180);
	auto backm = Menu::create(back, NULL);
	backm->setPosition(Point::ZERO);
	addChild(backm, 1);


	return true;
}

void HelpScene::onBack(Ref* ref) {
	Director::getInstance()->replaceScene(TransitionSlideInL::create(1.0f, HelloWorld::createScene()));
}
