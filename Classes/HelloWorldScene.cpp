#include "HelloWorldScene.h"
#include "SelScene.h"
#include "SimpleAudioEngine.h"
#include "EvolGuide.h"
#include "HelpScene.h"
#include "EvolVideo.h"
#include "AboutUs.h"
#include "StaffScene.h"
#include "MoreScene.h"

using namespace CocosDenshion;

USING_NS_CC;

float posX[8] = {950, 950, 950, 950, 950, 950, 950, 950};
float posY[8] = {515, 450, 365, 303, 241, 179, 117, 55};
int menuNum = 8;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/mainScene2.mp3");
	if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying() == false)
	{
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/mainScene2.mp3", true);
	}
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* background = Sprite::create("background.png");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(background, 0);

	butt[0] = MenuItemImage::create("Help_un.png", "Help.png", CC_CALLBACK_1(HelloWorld::onHelp, this));
	butt[0]->setAnchorPoint(Vec2(1, 1));
	butt[0]->setPosition(posX[0], posY[0]);
	auto butt0m = Menu::create(butt[0], NULL);
	butt0m->setPosition(Point::ZERO);
	addChild(butt0m, 2);

	butt[1] = MenuItemImage::create("GameStart_un.png", "GameStart.png", CC_CALLBACK_1(HelloWorld::onStart, this));
	butt[1]->setScale(0.75, 0.75);
	butt[1]->selected();
	butt[1]->setAnchorPoint(Vec2(1, 1));
	butt[1]->setPosition(posX[1], posY[1]);
	auto butt1m = Menu::create(butt[1], NULL);
	butt1m->setPosition(Point::ZERO);
	addChild(butt1m, 2);
	setCurrent(butt[1]);

	butt[2] = MenuItemImage::create("EvolGuide_un.png", "EvolGuide.png", CC_CALLBACK_1(HelloWorld::onEG, this));
	butt[2]->setAnchorPoint(Vec2(1, 1));
	butt[2]->setPosition(posX[2], posY[2]);
	auto butt2m = Menu::create(butt[2], NULL);
	butt2m->setPosition(Point::ZERO);
	addChild(butt2m, 2);

	butt[3] = MenuItemImage::create("EvolVideo_un.png", "EvolVideo.png", CC_CALLBACK_1(HelloWorld::onEV, this));
	butt[3]->setAnchorPoint(Vec2(1, 1));
	butt[3]->setPosition(posX[3], posY[3]);
	auto butt3m = Menu::create(butt[3], NULL);
	butt3m->setPosition(Point::ZERO);
	addChild(butt3m, 2);

	butt[4] = MenuItemImage::create("Staff_un.png", "Staff.png", CC_CALLBACK_1(HelloWorld::onStaff, this));
	butt[4]->setAnchorPoint(Vec2(1, 1));
	butt[4]->setPosition(posX[4], posY[4]);
	auto butt4m = Menu::create(butt[4], NULL);
	butt4m->setPosition(Point::ZERO);
	addChild(butt4m, 2);

	butt[5] = MenuItemImage::create("AboutUs_un.png", "AboutUs.png", CC_CALLBACK_1(HelloWorld::onABU, this));
	butt[5]->setAnchorPoint(Vec2(1, 1));
	butt[5]->setPosition(posX[5], posY[5]);
	auto butt5m = Menu::create(butt[5], NULL);
	butt5m->setPosition(Point::ZERO);
	addChild(butt5m, 2);

	butt[6] = MenuItemImage::create("More_un.png", "More.png", CC_CALLBACK_1(HelloWorld::onMore, this));
	butt[6]->setAnchorPoint(Vec2(1, 1));
	butt[6]->setPosition(posX[6], posY[6]);
	auto butt6m = Menu::create(butt[6], NULL);
	butt6m->setPosition(Point::ZERO);
	addChild(butt6m, 2);

	butt[7] = MenuItemImage::create("Exit_un.png", "Exit.png", CC_CALLBACK_1(HelloWorld::onExit, this));
	butt[7]->setAnchorPoint(Vec2(1, 1));
	butt[7]->setPosition(posX[7], posY[7]);
	auto butt7m = Menu::create(butt[7], NULL);
	butt7m->setPosition(Point::ZERO);
	addChild(butt7m, 2);

	for (int i = 0; i < menuNum; i++)
	{
		if (i != 1)
		{
			butt[i]->setScale(0.55, 0.55);
		}
	}
    
    return true;
}

void HelloWorld::onHelp(Ref* ref) {
	if (getPos(butt[0]->getPosition().y) == 1) {
		Director::getInstance()->replaceScene(TransitionSlideInR::create(1.0f, HelpScene::createScene()));
		return;
	}
	butt[0]->setScale(0.75, 0.75);
	butt[0]->selected();
	getCurrent()->setScale(0.55, 0.55);
	getCurrent()->unselected();
	setCurrent(butt[0]);
	if (getPos(butt[0]->getPosition().y) < 1) {
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + 1) % menuNum], posY[(getPos(butt[i]->getPosition().y) + 1) % menuNum]);
		}
		/*butt[0]->setPosition(posX[(getPos(butt[0]->getPosition().y) + 1) % menuNum], posY[(getPos(butt[0]->getPosition().y) + 1) % menuNum]);
		butt[1]->setPosition(posX[(getPos(butt[1]->getPosition().y) + 1) % menuNum], posY[(getPos(butt[1]->getPosition().y) + 1) % menuNum]);
		butt[2]->setPosition(posX[(getPos(butt[2]->getPosition().y) + 1) % menuNum], posY[(getPos(butt[2]->getPosition().y) + 1) % menuNum]);*/
	}
	else {
		int dist = getPos(butt[0]->getPosition().y) - 1;
		dist = menuNum - dist;
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + dist) % menuNum], posY[(getPos(butt[i]->getPosition().y) + dist) % menuNum]);
		}
		/*butt[0]->setPosition(posX[(getPos(butt[0]->getPosition().y) + dist) % menuNum], posY[(getPos(butt[0]->getPosition().y) + dist) % menuNum]);
		butt[1]->setPosition(posX[(getPos(butt[1]->getPosition().y) + dist) % menuNum], posY[(getPos(butt[1]->getPosition().y) + dist) % menuNum]);
		butt[2]->setPosition(posX[(getPos(butt[2]->getPosition().y) + dist) % menuNum], posY[(getPos(butt[2]->getPosition().y) + dist) % menuNum]);*/
	}
}

void HelloWorld::onStart(Ref* ref) {
	if (getPos(butt[1]->getPosition().y) == 1) {
		Director::getInstance()->replaceScene(TransitionSlideInR::create(1.0f, SelScene::createScene()));
		return;
	}
	butt[1]->setScale(0.75, 0.75);
	butt[1]->selected();
	getCurrent()->setScale(0.55, 0.55);
	getCurrent()->unselected();
	setCurrent(butt[1]);
	if (getPos(butt[1]->getPosition().y) < 1) {
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + 1) % menuNum], posY[(getPos(butt[i]->getPosition().y) + 1) % menuNum]);
		}
	}
	else {
		int dist = getPos(butt[1]->getPosition().y) - 1;
		dist = menuNum - dist;
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + dist) % menuNum], posY[(getPos(butt[i]->getPosition().y) + dist) % menuNum]);
		}
	}
}

void HelloWorld::onEG(Ref* ref) {
	if (getPos(butt[2]->getPosition().y) == 1) {
		Director::getInstance()->replaceScene(TransitionSlideInR::create(1.0f, EvolGuide::createScene()));
		return;
	}
	butt[2]->setScale(0.75, 0.75);
	butt[2]->selected();
	getCurrent()->setScale(0.55, 0.55);
	getCurrent()->unselected();
	setCurrent(butt[2]);
	if (getPos(butt[2]->getPosition().y) < 1) {
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + 1) % menuNum], posY[(getPos(butt[i]->getPosition().y) + 1) % menuNum]);
		}
	}
	else {
		int dist = getPos(butt[2]->getPosition().y) - 1;
		dist = menuNum - dist;
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + dist) % menuNum], posY[(getPos(butt[i]->getPosition().y) + dist) % menuNum]);
		}
	}
}

void HelloWorld::onEV(Ref* ref) {
	if (getPos(butt[3]->getPosition().y) == 1) {
		Director::getInstance()->replaceScene(TransitionSlideInR::create(1.0f, EvolVideo::createScene()));
		return;
	}
	butt[3]->setScale(0.75, 0.75);
	butt[3]->selected();
	getCurrent()->setScale(0.55, 0.55);
	getCurrent()->unselected();
	setCurrent(butt[3]);
	if (getPos(butt[3]->getPosition().y) < 1) {
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + 1) % menuNum], posY[(getPos(butt[i]->getPosition().y) + 1) % menuNum]);
		}
	}
	else {
		int dist = getPos(butt[3]->getPosition().y) - 1;
		dist = menuNum - dist;
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + dist) % menuNum], posY[(getPos(butt[i]->getPosition().y) + dist) % menuNum]);
		}
	}
}

void HelloWorld::onStaff(Ref* ref) {
	if (getPos(butt[4]->getPosition().y) == 1) {
		Director::getInstance()->replaceScene(TransitionSlideInR::create(1.0f, StaffScene::createScene()));
		return;
	}
	butt[4]->setScale(0.75, 0.75);
	butt[4]->selected();
	getCurrent()->setScale(0.55, 0.55);
	getCurrent()->unselected();
	setCurrent(butt[4]);
	if (getPos(butt[4]->getPosition().y) < 1) {
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + 1) % menuNum], posY[(getPos(butt[i]->getPosition().y) + 1) % menuNum]);
		}
	}
	else {
		int dist = getPos(butt[4]->getPosition().y) - 1;
		dist = menuNum - dist;
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + dist) % menuNum], posY[(getPos(butt[i]->getPosition().y) + dist) % menuNum]);
		}
	}
}

void HelloWorld::onABU(Ref* ref) {
	if (getPos(butt[5]->getPosition().y) == 1) {
		Director::getInstance()->replaceScene(TransitionSlideInR::create(1.0f, AboutUs::createScene()));
		return;
	}
	butt[5]->setScale(0.75, 0.75);
	butt[5]->selected();
	getCurrent()->setScale(0.55, 0.55);
	getCurrent()->unselected();
	setCurrent(butt[5]);
	if (getPos(butt[5]->getPosition().y) < 1) {
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + 1) % menuNum], posY[(getPos(butt[i]->getPosition().y) + 1) % menuNum]);
		}
	}
	else {
		int dist = getPos(butt[5]->getPosition().y) - 1;
		dist = menuNum - dist;
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + dist) % menuNum], posY[(getPos(butt[i]->getPosition().y) + dist) % menuNum]);
		}
	}
}

void HelloWorld::onMore(Ref* ref) {
	if (getPos(butt[6]->getPosition().y) == 1) {
		Director::getInstance()->replaceScene(TransitionSlideInR::create(1.0f, MoreScene::createScene()));
		return;
	}
	butt[6]->setScale(0.75, 0.75);
	butt[6]->selected();
	getCurrent()->setScale(0.55, 0.55);
	getCurrent()->unselected();
	setCurrent(butt[6]);
	if (getPos(butt[6]->getPosition().y) < 1) {
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + 1) % menuNum], posY[(getPos(butt[i]->getPosition().y) + 1) % menuNum]);
		}
	}
	else {
		int dist = getPos(butt[6]->getPosition().y) - 1;
		dist = menuNum - dist;
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + dist) % menuNum], posY[(getPos(butt[i]->getPosition().y) + dist) % menuNum]);
		}
	}
}

void HelloWorld::onExit(Ref* ref) {
	if (getPos(butt[7]->getPosition().y) == 1) {
		Director::getInstance()->end();

        #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		    exit(0);
        #endif
			return;
	}
	butt[7]->setScale(0.75, 0.75);
	butt[7]->selected();
	getCurrent()->setScale(0.55, 0.55);
	getCurrent()->unselected();
	setCurrent(butt[7]);
	if (getPos(butt[7]->getPosition().y) < 1) {
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + 1) % menuNum], posY[(getPos(butt[i]->getPosition().y) + 1) % menuNum]);
		}
	}
	else {
		int dist = getPos(butt[7]->getPosition().y) - 1;
		dist = menuNum - dist;
		for (int i = 0; i < menuNum; i++)
		{
			butt[i]->setPosition(posX[(getPos(butt[i]->getPosition().y) + dist) % menuNum], posY[(getPos(butt[i]->getPosition().y) + dist) % menuNum]);
		}
	}
}

void HelloWorld::setCurrent(MenuItemImage* a) {
	currentItem = a;
}

MenuItemImage* HelloWorld::getCurrent() {
	return currentItem;
}

int HelloWorld::getPos(float y) {
	for (int i = 0; i < menuNum; i++) {
		if (posY[i] == y) {
			return i;
		}
	}
}
