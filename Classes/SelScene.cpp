#include "SelScene.h"
#include "WarScene.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

using namespace CocosDenshion;

USING_NS_CC;

float posMX[8] = { 260, 480, 700, -500, -501, -502, -503, -504 };
float posMY[8] = { 300, 300, 300, 300, 300, 300, 300, 300 };
float posDX[6] = { 50, 154, 258, 362, 466, 570 };
float posDY[6] = { 50, 50, 50, 50, 50, 50 };
int digiNum = 8;

Scene* SelScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = SelScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SelScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/ssel.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/ssel.mp3", true);

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* background = Sprite::create("back_sel.png");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(background, 0);

	Sprite* square[6];
	for (int i = 0; i < 6; i++)
	{
		square[i] = Sprite::create("place.png");
		square[i]->setPosition(posDX[i], posDY[i]);
		addChild(square[i], 1);
	}

	selPos = 0;

	allDigi[0] = new Agumon();
	allDigi[1] = new Takyamon();
	allDigi[2] = new Gabumon();
	allDigi[3] = new Piyomon();
	allDigi[4] = new Tentomon();
	allDigi[5] = new Gomamon();
	allDigi[6] = new Vmon();
	allDigi[7] = new Wormmon();

	for (int i = 0; i < digiNum; i++) {
		allDigi[i]->getSprite()->setPosition(posMX[i], posMY[i]);
		allDigi[i]->getSprite()->setScale(0.4, 0.4);
		addChild(allDigi[i]->getSprite(), 1);
	}

	currentDigi = 1;
	allDigi[currentDigi]->getSprite()->setScale(0.8, 0.8);

	MenuItemImage* leftArrow = MenuItemImage::create("left.png", "left.png", CC_CALLBACK_1(SelScene::onLeft, this));
	leftArrow->setPosition(50, 300);
	auto leftArrowm = Menu::create(leftArrow, NULL);
	leftArrowm->setPosition(Point::ZERO);
	addChild(leftArrowm, 2);

	MenuItemImage* rightArrow = MenuItemImage::create("right.png", "right.png", CC_CALLBACK_1(SelScene::onRight, this));
	rightArrow->setPosition(910, 300);
	auto rightArrowm = Menu::create(rightArrow, NULL);
	rightArrowm->setPosition(Point::ZERO);
	addChild(rightArrowm, 2);

	confirmButton = MenuItemImage::create("add_button.png", "add_button_click.png", CC_CALLBACK_1(SelScene::onConfirm, this));
	confirmButton->setPosition(480, 135);
	auto confirmButtonm = Menu::create(confirmButton, NULL);
	confirmButtonm->setPosition(Point::ZERO);
	addChild(confirmButtonm, 2);

	startButton = MenuItemImage::create("selGo.png", "selGod.png", CC_CALLBACK_1(SelScene::onGo, this));
	Node* sbu = Sprite::create("selGou.png");
	startButton->setDisabledImage(sbu);
	startButton->setScale(0.5, 0.5);
	startButton->setPosition(850, 80);
	auto startButtonm = Menu::create(startButton, NULL);
	startButtonm->setPosition(Point::ZERO);
	addChild(startButtonm, 2);
	startButton->setEnabled(false);

	MenuItemImage* back = MenuItemImage::create("selGod.png", "selGod.png", CC_CALLBACK_1(SelScene::onBack, this));
	back->setScale(0.5, 0.5);
	back->setPosition(750, 80);
	back->setRotation(180);
	auto backm = Menu::create(back, NULL);
	backm->setPosition(Point::ZERO);
	addChild(backm, 2);

	return true;
}

void SelScene::onLeft(Ref* ref) {
	for (int i = 0; i < digiNum; i++) {
		allDigi[i]->getSprite()->setPosition(posMX[(getPos(allDigi[i]->getSprite()->getPosition().x) + 1) % digiNum], posMY[(getPos(allDigi[i]->getSprite()->getPosition().x) + 1) % digiNum]);
	}
	allDigi[currentDigi]->getSprite()->setScale(0.4, 0.4);
	currentDigi = (currentDigi + (digiNum - 1)) % digiNum;
	allDigi[currentDigi]->getSprite()->setScale(0.8, 0.8);
}

void SelScene::onRight(Ref* ref) {
	for (int i = 0; i < digiNum; i++) {
		allDigi[i]->getSprite()->setPosition(posMX[(getPos(allDigi[i]->getSprite()->getPosition().x) + (digiNum - 1)) % digiNum], posMY[(getPos(allDigi[i]->getSprite()->getPosition().x) + (digiNum - 1)) % digiNum]);
	}
	allDigi[currentDigi]->getSprite()->setScale(0.4, 0.4);
	currentDigi = (currentDigi + 1) % digiNum;
	allDigi[currentDigi]->getSprite()->setScale(0.8, 0.8);
}

void SelScene::onConfirm(Ref* ref)
{
	if (allDigi[currentDigi]->isSel()) return;
	allDigi[currentDigi]->setSel();
	seledDigi[selPos] = allDigi[currentDigi]->createDigi();
	seledDigi[selPos]->getSprite()->setPosition(posDX[selPos], posDY[selPos]);
	seledDigi[selPos]->getSprite()->setScale(0.3, 0.3);
	addChild(seledDigi[selPos]->getSprite(), 1);
	if (selPos == 5)
	{
		startButton->setEnabled(true);
		confirmButton->setEnabled(false);
	}
	selPos++;
}

void SelScene::onGo(Ref* ref) 
{
	removeAllChildren();

	Sprite* background = Sprite::create("back_sel.png");
	background->setPosition(480, 270);
	addChild(background, 0);

	MenuItemImage* di_easy = MenuItemImage::create("easy.png", "easyd.png", CC_CALLBACK_1(SelScene::onDiff, this));
	di_easy->setPosition(480, 360);
	auto di_easym = Menu::create(di_easy, NULL);
	di_easym->setPosition(Point::ZERO);
	addChild(di_easym, 1);

	MenuItemImage* di_nor = MenuItemImage::create("normal.png", "normald.png", CC_CALLBACK_1(SelScene::onDiff, this));
	di_nor->setPosition(480, 270);
	auto di_norm = Menu::create(di_nor, NULL);
	di_norm->setPosition(Point::ZERO);
	addChild(di_norm, 1);

	MenuItemImage* di_hard= MenuItemImage::create("hard.png", "hardd.png", CC_CALLBACK_1(SelScene::onDiff, this));
	di_hard->setPosition(480, 180);
	auto di_hardm = Menu::create(di_hard, NULL);
	di_hardm->setPosition(Point::ZERO);
	addChild(di_hardm, 1);

}

int SelScene::getPos(float x) 
{
	for (int i = 0; i < digiNum; i++) {
		if (posMX[i] == x) {
			return i;
		}
	}
}

void SelScene::onDiff(Ref* ref)
{
	removeAllChildren();

	Sprite* background = Sprite::create("back_sel.png");
	background->setPosition(480, 270);
	addChild(background, 0);

	MenuItemImage* di_easy = MenuItemImage::create("c1.png", "c1d.png", CC_CALLBACK_1(SelScene::onChapter, this));
	di_easy->setPosition(480, 360);
	auto di_easym = Menu::create(di_easy, NULL);
	di_easym->setPosition(Point::ZERO);
	addChild(di_easym, 1);

	MenuItemImage* di_nor = MenuItemImage::create("c2.png", "c2d.png", CC_CALLBACK_1(SelScene::onChapter, this));
	di_nor->setPosition(480, 270);
	auto di_norm = Menu::create(di_nor, NULL);
	di_norm->setPosition(Point::ZERO);
	addChild(di_norm, 1);

	MenuItemImage* di_hard = MenuItemImage::create("c3.png", "c3d.png", CC_CALLBACK_1(SelScene::onChapter, this));
	di_hard->setPosition(480, 180);
	auto di_hardm = Menu::create(di_hard, NULL);
	di_hardm->setPosition(Point::ZERO);
	addChild(di_hardm, 1);
}

void SelScene::onChapter(Ref* ref)
{
	auto scene = WarScene::createScene();
	WarScene *temp = WarScene::create();
	for (int i = 0; i < 6; i++) {
		temp->setQt(seledDigi[i], i);
	}
	scene->addChild(temp);
	CCDirector::sharedDirector()->replaceScene(TransitionFade::create(1.5f, scene));
	//Director::getInstance()->replaceScene(TransitionPageTurn::create(1.0f, WarScene::createScene(), true));
}

void SelScene::onBack(Ref* ref) {
	Director::getInstance()->replaceScene(TransitionSlideInL::create(1.0f, HelloWorld::createScene()));
}
