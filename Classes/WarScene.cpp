#include "WarScene.h"
#include "SimpleAudioEngine.h"
#include <stdlib.h>
#include <math.h>
#include "HelloWorldScene.h"

using namespace CocosDenshion;

USING_NS_CC;

float warPosX[12] = { 240, 240, 240, 90, 90, 90, 720, 720, 720, 870, 870, 870 };
float warPosY[12] = { 460, 320, 180, 460, 320, 180, 460, 320, 180, 460, 320, 180 };
float hpPosX[12] = { 240, 240, 240, 90, 90, 90, 720, 720, 720, 870, 870, 870 };
float hpPosY[12] = { 400, 260, 120, 400, 260, 120, 400, 260, 120, 400, 260, 120 };

int attMax = 10;
int evoMax = 10;
int defMax = 10;

Scene* WarScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = WarScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool WarScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music/war.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/war.mp3", true);

	fxLayer = Layer::create();
	fxLayer->setAnchorPoint(ccp(0, 0));
	fxLayer->setPosition(0, 0);
	addChild(fxLayer, 4);

	for (int i = 0; i < 12; i++) {
		frontSin[i] = false;
		frontAll[i] = false;
		backSin[i] = false;
		backAll[i] = false;
		allAll[i] = false;
		colum[i] = false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	srand((int)time(NULL));

	isVplay = false;

	hci = 0;
	hcc = 0;

	attPower = 3;
	evoPower = 3;
	defPower = 3;

	preXros = 0;
	xrosPair[0] = -1;
	xrosPair[1] = -1;

	Sprite* background = Sprite::create("warback2.png");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(background, 0);

	qt[0] = new Agumon();
	qt[1] = new Agumon();
	qt[2] = new Agumon();
	qt[3] = new Agumon();
	qt[4] = new Agumon();
	qt[5] = new Agumon();

	/*qt[0] = new Agumon();

	wp[0] = new WarPos(qt[0], warPosX[0], warPosY[0], hpPosX[0], hpPosY[0]);
	wp[0]->getDgm()->getSprite()->setScale(0.5, 0.5);
	wp[0]->getDgm()->getSprite()->setPosition(wp[0]->getPosX(), wp[0]->getPosY());
	addChild(wp[0]->getDgm()->getSprite(), 1);
	wp[0]->getDgm()->getHpbar()->setPosition(wp[0]->getHpPosX(), wp[0]->getHpPosY());
	addChild(wp[0]->getDgm()->getHpbar(), 2);

	wp[1] = new WarPos();
	wp[2] = new WarPos();
	wp[3] = new WarPos();
	wp[4] = new WarPos();
	wp[5] = new WarPos();*/

	qt[6] = new MetalSeadramon();
	qt[7] = new Pinochimon();
	qt[8] = new Etemon();
	qt[9] = new Vamdemon();
	qt[10] = new Mugendramon();
	qt[11] = new Piemon();

	for (int i = 6; i < 12; i++)
	{
		wp[i] = new WarPos(qt[i], warPosX[i], warPosY[i], hpPosX[i], hpPosY[i]);
		wp[i]->getDgm()->getSprite()->setScale(0.4, 0.4);
		wp[i]->getDgm()->getSprite()->setPosition(wp[i]->getPosX(), wp[i]->getPosY());
		addChild(wp[i]->getDgm()->getSprite(), 2);
		wp[i]->getDgm()->getHpbar()->setPosition(wp[i]->getHpPosX(), wp[i]->getHpPosY());
		addChild(wp[i]->getDgm()->getHpbar(), 3);
		wp[i]->getDgm()->getHpBB()->setPosition(wp[i]->getHpPosX(), wp[i]->getHpPosY());
		addChild(wp[i]->getDgm()->getHpBB(), 4);
	}


	//wp[7] = new WarPos();
	/*wp[8] = new WarPos();
	wp[9] = new WarPos();
	wp[10] = new WarPos();
	wp[11] = new WarPos();*/

	attBar = ProgressTimer::create(Sprite::create("attPower.png"));
	attBar->setType(ProgressTimer::Type::BAR);
	attBar->setMidpoint(Point(0, 0));
	attBar->setBarChangeRate(Point(0, 1));
	attBar->setPercentage((double)attPower / attMax * 100);
	attBar->setPosition(60, 50);
	attBar->setScale(0.18, 0.18);
	addChild(attBar, 1);

	Sprite* attBB = Sprite::create("PowerBar.png");
	attBB->setScale(0.18, 0.18);
	attBB->setPosition(60, 50);
	addChild(attBB, 2);

	evoBar = ProgressTimer::create(Sprite::create("evoPower.png"));
	evoBar->setType(ProgressTimer::Type::BAR);
	evoBar->setMidpoint(Point(0, 0));
	evoBar->setBarChangeRate(Point(0, 1));
	evoBar->setPercentage((double)evoPower / evoMax * 100);
	evoBar->setPosition(150, 50);
	evoBar->setScale(0.18, 0.18);
	addChild(evoBar, 1);

	Sprite* evoBB = Sprite::create("PowerBar.png");
	evoBB->setScale(0.18, 0.18);
	evoBB->setPosition(150, 50);
	addChild(evoBB, 2);

	defBar = ProgressTimer::create(Sprite::create("defPower.png"));
	defBar->setType(ProgressTimer::Type::BAR);
	defBar->setMidpoint(Point(0, 0));
	defBar->setBarChangeRate(Point(0, 1));
	defBar->setPercentage((double)defPower / defMax * 100);
	defBar->setPosition(240, 50);
	defBar->setScale(0.18, 0.18);
	addChild(defBar, 1);

	Sprite* defBB = Sprite::create("PowerBar.png");
	defBB->setScale(0.18, 0.18);
	defBB->setPosition(240, 50);
	addChild(defBB, 2);



	aed[0] = Sprite::create("noIcon.png");
	aed[0]->setScale(0.3, 0.3);
	aed[0]->setPosition(650, 50);
	addChild(aed[0], 2);

	aed[1] = Sprite::create("noIcon.png");
	aed[1]->setScale(0.3, 0.3);
	aed[1]->setPosition(730, 50);
	addChild(aed[1], 2);

	aed[2] = Sprite::create("noIcon.png");
	aed[2]->setScale(0.3, 0.3);
	aed[2]->setPosition(810, 50);
	addChild(aed[2], 2);



	attButton = MenuItemImage::create("attack_button.png", "attack_button_click.png", CC_CALLBACK_1(WarScene::onAtt, this));
	Node* att_dis = Sprite::create("attack_button_unable.png");
	attButton->setDisabledImage(att_dis);
	attButton->setScale(0.7, 0.7);
	attButton->setPosition(400, 70);
	auto attButtonm = Menu::create(attButton, NULL);
	attButtonm->setPosition(Point::ZERO);
	addChild(attButtonm, 1);

	evoButton = MenuItemImage::create("evolute_button.png", "evolute_button_click.png", CC_CALLBACK_1(WarScene::onEvo, this));
	Node* evo_dis = Sprite::create("evolute_button_unable.png");
	evoButton->setDisabledImage(evo_dis);
	evoButton->setScale(0.7, 0.7);
	evoButton->setPosition(400, 30);
	auto evoButtonm = Menu::create(evoButton, NULL);
	evoButtonm->setPosition(Point::ZERO);
	addChild(evoButtonm, 1);

	xrosButton = MenuItemImage::create("xros_button.png", "xros_button_click.png", CC_CALLBACK_1(WarScene::onXros, this));
	Node* xros_dis = Sprite::create("xros_button_unable.png");
	xrosButton->setDisabledImage(xros_dis);
	xrosButton->setScale(0.7, 0.7);
	xrosButton->setPosition(530, 70);
	auto xrosButtonm = Menu::create(xrosButton, NULL);
	xrosButtonm->setPosition(Point::ZERO);
	addChild(xrosButtonm, 1);

	//xrosButton->setEnabled(false);

	endButton = MenuItemImage::create("end_button.png", "end_button_click.png", CC_CALLBACK_1(WarScene::onEnd, this));
	Node* end_dis = Sprite::create("end_button_unable.png");
	endButton->setDisabledImage(end_dis);
	endButton->setScale(0.7, 0.7);
	endButton->setPosition(530, 30);
	auto endButtonm = Menu::create(endButton, NULL);
	endButtonm->setPosition(Point::ZERO);
	addChild(endButtonm, 1);

	///////////////////////////////////////////////////

	norAttButton = MenuItemImage::create("norAtt.png", "norAtt.png", CC_CALLBACK_1(WarScene::onNorAtt, this));
	Node* nau = Sprite::create("norAtt_un.png");
	norAttButton->setDisabledImage(nau);
	norAttButton->setPosition(visibleSize.width / 2, 350);
	auto norAttButtonm = Menu::create(norAttButton, NULL);
	norAttButtonm->setPosition(Point::ZERO);
	addChild(norAttButtonm, 1);
	norAttButton->setOpacity(0);
	norAttButton->setEnabled(false);

	bigAttButton = MenuItemImage::create("bigAtt.png", "bigAtt.png", CC_CALLBACK_1(WarScene::onBigAtt, this));
	Node* bau = Sprite::create("bigAtt_un.png");
	bigAttButton->setDisabledImage(bau);
	bigAttButton->setPosition(visibleSize.width / 2, 270);
	auto bigAttButtonm = Menu::create(bigAttButton, NULL);
	bigAttButtonm->setPosition(Point::ZERO);
	addChild(bigAttButtonm, 1);
	bigAttButton->setOpacity(0);
	bigAttButton->setEnabled(false);
	
	////////////////////////////////////////////////////////


	norEvoButton = MenuItemImage::create("norAtt.png", "norAtt.png", CC_CALLBACK_1(WarScene::onNorEvo, this));
	Node* neu = Sprite::create("norAtt_un.png");
	norEvoButton->setDisabledImage(neu);
	norEvoButton->setPosition(visibleSize.width / 2, 470);
	auto norEvoButtonm = Menu::create(norEvoButton, NULL);
	norEvoButtonm->setPosition(Point::ZERO);
	addChild(norEvoButtonm, 1);
	norEvoButton->setOpacity(0);
	norEvoButton->setEnabled(false);

	ultEvoButton = MenuItemImage::create("ultimate.png", "ultimate.png", CC_CALLBACK_1(WarScene::onUltEvo, this));
	Node* ueu = Sprite::create("ultimate_un.png");
	ultEvoButton->setDisabledImage(ueu);
	ultEvoButton->setPosition(visibleSize.width / 2, 390);
	auto ultEvoButtonm = Menu::create(ultEvoButton, NULL);
	ultEvoButtonm->setPosition(Point::ZERO);
	addChild(ultEvoButtonm, 1);
	ultEvoButton->setOpacity(0);
	ultEvoButton->setEnabled(false);

	arfEvoButton = MenuItemImage::create("arm_one.png", "arm_one.png", CC_CALLBACK_1(WarScene::onArfEvo, this));
	Node* afu = Sprite::create("arm_one_un.png");
	arfEvoButton->setDisabledImage(afu);
	arfEvoButton->setPosition(visibleSize.width / 2, 310);
	auto arfEvoButtonm = Menu::create(arfEvoButton, NULL);
	arfEvoButtonm->setPosition(Point::ZERO);
	addChild(arfEvoButtonm, 1);
	arfEvoButton->setOpacity(0);
	arfEvoButton->setEnabled(false);

	arsEvoButton = MenuItemImage::create("arm_two.png", "arm_two.png", CC_CALLBACK_1(WarScene::onArsEvo, this));
	Node* asu = Sprite::create("arm_two_un.png");
	arsEvoButton->setDisabledImage(asu);
	arsEvoButton->setPosition(visibleSize.width / 2, 230);
	auto arsEvoButtonm = Menu::create(arsEvoButton, NULL);
	arsEvoButtonm->setPosition(Point::ZERO);
	addChild(arsEvoButtonm, 1);
	arsEvoButton->setOpacity(0);
	arsEvoButton->setEnabled(false);

	unEvoButton = MenuItemImage::create("de_evol.png", "de_evol.png", CC_CALLBACK_1(WarScene::onUnEvo, this));
	Node* uuu = Sprite::create("de_evol_un.png");
	unEvoButton->setDisabledImage(uuu);
	unEvoButton->setPosition(visibleSize.width / 2, 150);
	auto unEvoButtonm = Menu::create(unEvoButton, NULL);
	unEvoButtonm->setPosition(Point::ZERO);
	addChild(unEvoButtonm, 1);
	unEvoButton->setOpacity(0);
	unEvoButton->setEnabled(false);

	////////////////////////////////////////////////////////

	xrosUpButton = MenuItemImage::create("xros_up.png", "xros_up.png", CC_CALLBACK_1(WarScene::onXrosUp, this));
	Node* xuu = Sprite::create("xros_cf.png");
	xrosUpButton->setDisabledImage(xuu);
	xrosUpButton->setPosition(visibleSize.width / 2, 300);
	auto xrosUpButtonm = Menu::create(xrosUpButton, NULL);
	xrosUpButtonm->setPosition(Point::ZERO);
	addChild(xrosUpButtonm, 1);
	xrosUpButton->setOpacity(0);
	xrosUpButton->setEnabled(false);

	skipButton = MenuItemImage::create("skip.png", "skip.png", CC_CALLBACK_1(WarScene::onSkip, this));
	skipButton->setPosition(800, 50);
	skipButton->setScale(0.3, 0.3);
	auto skipButtonm = Menu::create(skipButton, NULL);
	skipButtonm->setPosition(Point::ZERO);
	addChild(skipButtonm, 6);
	skipButton->setOpacity(0);
	skipButton->setEnabled(false);

	////////////////////////////////////////////////////////

	MenuItemImage* back = MenuItemImage::create("selGod.png", "selGod.png", CC_CALLBACK_1(WarScene::onBack, this));
	back->setScale(0.4, 0.4);
	back->setPosition(900, 50);
	back->setRotation(180);
	auto backm = Menu::create(back, NULL);
	backm->setPosition(Point::ZERO);
	addChild(backm, 2);

	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);
	listener->onTouchBegan = CC_CALLBACK_2(WarScene::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	scheduleUpdate();

	return true;
}

void WarScene::onEnter()
{
	Layer::onEnter();
	for (int i = 0; i < 6; i++)
	{
		wp[i] = new WarPos(qt[i], warPosX[i], warPosY[i], hpPosX[i], hpPosY[i]);
		//wp[i]->getDgm()->getSprite()->setScale(0.5, 0.5);
		wp[i]->getDgm()->getSprite()->setPosition(wp[i]->getPosX(), wp[i]->getPosY());
		wp[i]->getDgm()->getSprite()->setScale(0.4, 0.4);
		addChild(wp[i]->getDgm()->getSprite(), 2);
		wp[i]->getDgm()->getHpbar()->setPosition(wp[i]->getHpPosX(), wp[i]->getHpPosY());
		addChild(wp[i]->getDgm()->getHpbar(), 3);
		wp[i]->getDgm()->getHpBB()->setPosition(wp[i]->getHpPosX(), wp[i]->getHpPosY());
		addChild(wp[i]->getDgm()->getHpBB(), 4);
	}
}


void WarScene::onBack(Ref* ref) {
	Director::getInstance()->replaceScene(TransitionSlideInL::create(1.0f, HelloWorld::createScene()));
}


bool WarScene::onTouchBegan(Touch *touch, Event *unused_event) {
	Vec2 point = touch->getLocation();
	//log("%f %f", point.x, point.y);
	int xx = point.x;
	int yy = point.y;
	int currrentPosTemp = getPosByTouch(xx, yy);
	if (sta == INVALID || currrentPosTemp == -1) {}
	else if (sta == ATTACKING) 
	{
		currrentPos = currrentPosTemp;
		delFX();
		delButton();
		attLight();
		updateAttStatus();
		norAttButton->setOpacity(255);
		if (attPower >= 1)
		{
			norAttButton->setEnabled(true);
		}
		bigAttButton->setOpacity(255);
		if (attPower >= 3)
		{
			bigAttButton->setEnabled(true);
		}
	}
	else if (sta == EVORUTING)
	{
		currrentPos = currrentPosTemp;
		delFX();
		delButton();
		evoLight();
		/*evoFX = ParticleFire::create();
		evoFX->setPosition(warPosX[currrentPos], warPosY[currrentPos]-50);
		evoFX->setOpacity(50);
		fxLayer->addChild(evoFX, 1);*/

		setEvoEnable();
		norEvoButton->setOpacity(255);
		ultEvoButton->setOpacity(255);
		arfEvoButton->setOpacity(255);
		arsEvoButton->setOpacity(255);
		unEvoButton->setOpacity(255);
	}
	else if (sta == XROSING)
	{
		currrentPos = currrentPosTemp;
		delButton();
		if (preXros == 1 && ableXros())
		{
			if (wp[currrentPos]->getDgm()->evoConsume(XROS) != -10 && wp[currrentPos]->getDgm()->evoConsume(XROS) <= evoPower)
			{
				xrosUpButton->setEnabled(true);
			}
			xrosUpButton->setOpacity(255);
		}
		else if (preXros == 0)
		{
			ableXros();
		}
	}
	//int pointx = (point.x - 30) / 64;
	//int pointy = (point.y - 30) / 64;
	return true;
}

void WarScene::onAtt(Ref* ref) {
	delFX();
	delButton();
	sta = ATTACKING;
}

void WarScene::onXros(Ref* ref) {
	delFX();
	delButton();
	preXros = 0;
	sta = XROSING;
}

void WarScene::onEvo(Ref* ref) {
	delFX();
	delButton();
	sta = EVORUTING;
}

void WarScene::onEnd(Ref* ref) {
	delFX();
	delButton();
	blackButton();

	Sprite* turnBackg = Sprite::create("comTurn.png");
	turnBackg->setPosition(480, 270);
	addChild(turnBackg, 10);
	turnBackg->setOpacity(0);
	FadeIn* fi = FadeIn::create(0.3f);
	FadeOut* fo = FadeOut::create(0.3f);
	DelayTime* ddt = DelayTime::create(0.5f);
	Sequence* sq = Sequence::create(fi, ddt, fo, NULL);
	turnBackg->runAction(sq);

	computerTime();
	sta = INVALID;
}

void WarScene::onNorAtt(Ref* ref) {
	delFX();
	attPower -= 1;
	attBar->setPercentage((double)attPower / attMax * 100);

	hcc = 0;
	hci = 0;
	for (int i = 0; i < 12; i++) {
		if (isTarget(i, wp[currrentPos]->getDgm()->getNorRan())) {

			norAttFx(i);

			hurtCout[hcc] = i;
			hcc++;

			this->scheduleOnce(schedule_selector(WarScene::delayHp), 0.8f);
			/*wp[i]->getDgm()->changeHp(wp[currrentPos]->getDgm()->getDam());
			if (wp[i]->getDgm()->getHp() <= 0)
			{
				removeDigimon(i);
			}*/
		}
	}
	gameOver();
	delButton();
}

void WarScene::onBigAtt(Ref* ref) {
	delFX();
	attPower -= 3;
	attBar->setPercentage((double)attPower / attMax * 100);

	hcc = 0;
	hci = 0;
	for (int i = 0; i < 12; i++) {
		if (isTarget(i, wp[currrentPos]->getDgm()->getBigRan())) {

			bigAttFx(i);

			hurtCout[hcc] = i;
			hcc++;

			this->scheduleOnce(schedule_selector(WarScene::delayHpX), 1.2f);
			/*wp[i]->getDgm()->changeHp(wp[currrentPos]->getDgm()->getDamX());
			if (wp[i]->getDgm()->getHp() <= 0)
			{
				removeDigimon(i);
			}*/
		}
	}
	gameOver();
	delButton();
}

void WarScene::onNorEvo(Ref* ref)
{
	//evoPower -= wp[currrentPos]->getDgm()->evoConsume(EVOL);
	//evoBar->setPercentage((double)evoPower / evoMax * 100);

	playVideo(currrentPos, EVOL);

	evolutionGhange(currrentPos, EVOL);

	delButton();
}

void WarScene::onUltEvo(Ref* ref)
{
	//evoPower -= wp[currrentPos]->getDgm()->evoConsume(ULTIM_EVOL);
	//evoBar->setPercentage((double)evoPower / evoMax * 100);

	playVideo(currrentPos, ULTIM_EVOL);

	evolutionGhange(currrentPos, ULTIM_EVOL);

	delButton();
}

void WarScene::onArfEvo(Ref* ref)
{
	//evoPower -= wp[currrentPos]->getDgm()->evoConsume(ARMORF);
	//evoBar->setPercentage((double)evoPower / evoMax * 100);

	playVideo(currrentPos, ARMORF);

	evolutionGhange(currrentPos, ARMORF);

	delButton();
}

void WarScene::onArsEvo(Ref* ref)
{
	//evoPower -= wp[currrentPos]->getDgm()->evoConsume(ARMORS);
	//evoBar->setPercentage((double)evoPower / evoMax * 100);

	playVideo(currrentPos, ARMORS);

	evolutionGhange(currrentPos, ARMORS);

	delButton();
}

void WarScene::onUnEvo(Ref* ref)
{
	//evoPower -= wp[currrentPos]->getDgm()->evoConsume(UNEVOL);
	//if (evoPower > 10) evoPower = 10;
	//evoBar->setPercentage((double)evoPower / evoMax * 100);

	evolutionGhange(currrentPos, UNEVOL);

	delButton();
}

void WarScene::onXrosUp(Ref* ref) 
{
	//evoPower -= wp[xrosPair[0]]->getDgm()->evoConsume(XROS);
	//evoBar->setPercentage((double)evoPower / evoMax * 100);
	currrentPos = xrosPair[0];

	removeChild(xrosFX1);
	removeChild(xrosFX2);

	playVideo(xrosPair[0], XROS);

	evolutionGhange(xrosPair[0], XROS);

	removeDigimon(xrosPair[1]);

	delButton();
}

void WarScene::computerTime() {
	schTime = 0;
	for (int i = 6; i < 12; i++)
	{
		if (wp[i]->getDgm() != NULL)
		{
			schTime++;
		}
	}
	timeCout = 6;
	this->schedule(schedule_selector(WarScene::comTimeSch), 1.3f);
	/*for (int i = 6; i < 12; i++) {
		if (wp[i]->getDgm() != NULL) {
			currrentPos = i;
			updateAttStatus();
			int attSel = Random(1, 10);
			if (attSel <= 7) { comNorAtt(); }
			else { comBigAtt(); }
		}
	}*/
	//gameOver();
	//getPower();
}

void WarScene::comTimeSch(float dt)
{
	while (wp[timeCout]->getDgm() == NULL) timeCout++;
	currrentPos = timeCout;
	timeCout++;
	updateAttStatus();
	int attSel = Random(1, 10);
	if (attSel <= 7) { comNorAtt(); }
	else { comBigAtt(); }
	gameOver();
	schTime--;
	if (schTime == 0)
	{
		this->unschedule(schedule_selector(WarScene::comTimeSch));
		this->scheduleOnce(schedule_selector(WarScene::whiteButton), 1.3f);
	}
}

void WarScene::comNorAtt()
{
	hcc = 0;
	hci = 0;
	for (int i = 0; i < 12; i++) {
		if (isTarget(i, wp[currrentPos]->getDgm()->getNorRan())) {

			comNorAttFx(i);

			hurtCout[hcc] = i;
			hcc++;

			this->scheduleOnce(schedule_selector(WarScene::delayHp), 0.7f);
		}
	}
}

void WarScene::comBigAtt()
{
	hcc = 0;
	hci = 0;
	for (int i = 0; i < 12; i++) {
		if (isTarget(i, wp[currrentPos]->getDgm()->getBigRan())) {

			comBigAttFx(i);

			hurtCout[hcc] = i;
			hcc++;

			this->scheduleOnce(schedule_selector(WarScene::delayHpX), 0.7f);
		}
	}
}

int WarScene::getPosByTouch(int x, int y) {
	if (x >= 185 && x <= 285 && y >= 413 && y <= 503)
	{
		return 0;
	}
	else if (x >= 185 && x <= 285 && y >= 270 && y <= 367)
	{
		return 1;
	}
	else if (x >= 185 && x <= 285 && y >= 137 && y <= 232)
	{
		return 2;
	}
	else if (x >= 45 && x <= 129 && y >= 413 && y <= 503)
	{
		return 3;
	}
	else if (x >= 45 && x <= 129 && y >= 270 && y <= 367)
	{
		return 4;
	}
	else if (x >= 45 && x <= 129 && y >= 137 && y <= 232)
	{
		return 5;
	}
	else
	{
		return -1;
	}
}

bool WarScene::isTarget(int t, enum attRange ar) {
	if (ar == FRONT_SIN) { return frontSin[t]; }
	if (ar == FRONT_ALL) { return frontAll[t]; }
	if (ar == BACK_SIN) { return backSin[t]; }
	if (ar == BACK_ALL) { return backAll[t]; }
	if (ar == COLUM) { return colum[t]; }
	if (ar == ALL_ALL) { return allAll[t]; }
	return false;
}

void WarScene::updateAttStatus() {
	for (int i = 0; i < 12; i++) {
		frontSin[i] = false;
		frontAll[i] = false;
		backSin[i] = false;
		backAll[i] = false;
		allAll[i] = false;
		colum[i] = false;
	}
	int team = 0;
	if (currrentPos <= 5) team = 6;
	else team = 0;

	for (int i = team; i < team+6; i++) {
		if (wp[i]->getDgm() != NULL) {
			allAll[i] = true;
		}
	}
	int countF = 0;
	for (int i = team; i < team+3; i++) {
		if (wp[i]->getDgm() != NULL) {
			frontAll[i] = true;
			countF++;
		}
	}
	if (countF == 0) {
		for (int i = team + 3; i < team+6; i++) {
			if (wp[i]->getDgm() != NULL) {
				frontAll[i] = true;
			}
		}
	}
	if (countF != 0) {
		if (frontAll[currrentPos % 3 + team]) frontSin[currrentPos % 3 + team] = true;
		else if (currrentPos % 3 + team-1 >= team && frontAll[currrentPos % 3 + team - 1]) frontSin[currrentPos % 3 + team - 1] = true;
		else if (currrentPos % 3 + team-2 >= team && frontAll[currrentPos % 3 + team - 2]) frontSin[currrentPos % 3 + team - 2] = true;
		else if (currrentPos % 3 + team+1 <= team + 2 && frontAll[currrentPos % 3 + team + 1]) frontSin[currrentPos % 3 + team + 1] = true;
		else frontSin[currrentPos % 3 + team + 2] = true;
	}
	else {
		if (frontAll[currrentPos % 3 + team + 3]) frontSin[currrentPos % 3 + team + 3] = true;
		else if (currrentPos % 3 + team+2 >= team + 3 && frontAll[currrentPos % 3 + team + 2]) frontSin[currrentPos % 3 + team + 2] = true;
		else if (currrentPos % 3 + team+1 >= team + 3 && frontAll[currrentPos % 3 + team + 1]) frontSin[currrentPos % 3 + team + 1] = true;
		else if (currrentPos % 3 + team+4 <= team + 5 && frontAll[currrentPos % 3 + team + 4]) frontSin[currrentPos % 3 + team + 4] = true;
		else frontSin[currrentPos % 3 + team + 5] = true;
	}


	int countB = 0;
	for (int i = team + 3; i < team+6; i++) {
		if (wp[i]->getDgm() != NULL) {
			backAll[i] = true;
			countB++;
		}
	}
	if (countB == 0) {
		for (int i = team; i < team+3; i++) {
			if (wp[i]->getDgm() != NULL) {
				backAll[i] = true;
			}
		}
	}
	if (countB == 0) {
		if (backAll[currrentPos % 3 + team]) backSin[currrentPos % 3 + team] = true;
		else if (currrentPos % 3 + team - 1 >= team && backAll[currrentPos % 3 + team - 1]) backSin[currrentPos % 3 + team - 1] = true;
		else if (currrentPos % 3 + team - 2 >= team && backAll[currrentPos % 3 + team - 2]) backSin[currrentPos % 3 + team - 2] = true;
		else if (currrentPos % 3 + team + 1 <= team + 2 && backAll[currrentPos % 3 + team + 1]) backSin[currrentPos % 3 + team + 1] = true;
		else backSin[currrentPos % 3 + team+2] = true;
	}
	else {
		if (backAll[currrentPos % 3 + team + 3]) backSin[currrentPos % 3 + team + 3] = true;
		else if (currrentPos % 3 + team + 2 >= team + 3 && backAll[currrentPos % 3 + team + 2]) backSin[currrentPos % 3 + team + 2] = true;
		else if (currrentPos % 3 + team + 1 >= team + 3 && backAll[currrentPos % 3 + team + 1]) backSin[currrentPos % 3 + team + 1] = true;
		else if (currrentPos % 3 + team + 4 <= team + 5 && backAll[currrentPos % 3 + team + 4]) backSin[currrentPos % 3 + team + 4] = true;
		else backSin[currrentPos % 3 + team+5] = true;
	}


	if (wp[currrentPos % 3 + team]->getDgm() != NULL || wp[currrentPos % 3 + team + 3]->getDgm() != NULL) 
	{
		if (wp[currrentPos % 3 + team]->getDgm() != NULL) colum[currrentPos % 3 + team] = true;
		if (wp[currrentPos % 3 + team + 3]->getDgm() != NULL) colum[currrentPos % 3 + team + 3] = true;
	}
	else if (currrentPos % 3 + team - 1 >= team && (wp[currrentPos % 3 + team - 1]->getDgm() != NULL || wp[currrentPos % 3 + team + 2]->getDgm() != NULL)) 
	{
		if (wp[currrentPos % 3 + team - 1]->getDgm() != NULL) colum[currrentPos % 3 + team - 1] = true;
		if (wp[currrentPos % 3 + team + 2]->getDgm() != NULL) colum[currrentPos % 3 + team + 2] = true;
	}
	else if (currrentPos % 3 + team - 2 >= team && (wp[currrentPos % 3 + team - 2]->getDgm() != NULL || wp[currrentPos % 3 + team + 1]->getDgm() != NULL))
	{
		if (wp[currrentPos % 3 + team - 2]->getDgm() != NULL) colum[currrentPos % 3 + team - 2] = true;
		if (wp[currrentPos % 3 + team + 1]->getDgm() != NULL) colum[currrentPos % 3 + team + 1] = true;
	}
	else if (currrentPos % 3 + team + 1 <= team + 2 && (wp[currrentPos % 3 + team + 1]->getDgm() != NULL || wp[currrentPos % 3 + team + 4]->getDgm() != NULL))
	{
		if (wp[currrentPos % 3 + team + 1]->getDgm() != NULL) colum[currrentPos % 3 + team + 1] = true;
		if (wp[currrentPos % 3 + team + 4]->getDgm() != NULL) colum[currrentPos % 3 + team + 4] = true;
	}
	else 
	{
		if (wp[currrentPos % 3 + team + 2]->getDgm() != NULL) colum[currrentPos % 3 + team + 2] = true;
		if (wp[currrentPos % 3 + team + 5]->getDgm() != NULL) colum[currrentPos % 3 + team + 5] = true;
	}
}

int WarScene::Random(int m, int n)
{
	int pos, dis;
	if (m == n)
	{
		return m;
	}
	else if (m > n)
	{
		pos = n;
		dis = m - n + 1;
		return rand() % dis + pos;
	}
	else
	{
		pos = m;
		dis = n - m + 1;
		return rand() % dis + pos;
	}
}

void WarScene::gameOver()
{
	if (isOver() == 1)
	{
		auto scene = OverScene::createScene();
		OverScene *temp = OverScene::create();
		temp->setWiner(1);
		scene->addChild(temp);
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5f, scene));
	}
	else if (isOver() == 2)
	{
		auto scene = OverScene::createScene();
		OverScene *temp = OverScene::create();
		temp->setWiner(2);
		scene->addChild(temp);
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.5f, scene));
	}
}

int WarScene::isOver()
{
	int liveP = 0;
	for (int i = 0; i < 6; i++) {
		if (wp[i]->getDgm() != NULL) 
		{
			liveP++;
		}
	}
	int liveC = 0;
	for (int i = 6; i < 12; i++)
	{
		if (wp[i]->getDgm() != NULL)
		{
			liveC++;
		}
	}
	if (liveP == 0)
	{
		return 2;
	}
	else if (liveC == 0)
	{
		return 1;
	}
	return 0;
}

void WarScene::removeDigimon(int d)
{
	removeChild(wp[d]->getDgm()->getSprite());
	removeChild(wp[d]->getDgm()->getHpBB());
	removeChild(wp[d]->getDgm()->getHpbar());
	wp[d]->delDigi();
}

void WarScene::update(float dt)
{
	if (isVplay && vcp->isEndReached())
	{
		removeChild(vcp);
		isVplay = false;
		skipButton->setOpacity(0);
		skipButton->setEnabled(false);
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
		afterEvoFx();
	}
}

void WarScene::getPower()
{
	int countA = 0;
	int countE = 0;
	int countD = 0;
	float posTemp[3] = {650, 730, 810};
	for (int i = 0; i < 3; i++)
	{
		removeChild(aed[i]);
		int temp = Random(0, 3);
		if (temp == 0)
		{
			countA++;
			attPower++;
			aed[i] = Sprite::create("attIcon.png");
		}
		else if (temp == 1)
		{
			countE++;
			evoPower++;
			aed[i] = Sprite::create("evoIcon.png");
		}
		else if (temp == 2)
		{
			countD++;
			defPower++;
			aed[i] = Sprite::create("defIcon.png");
		}
		else
		{
			aed[i] = Sprite::create("noIcon.png");
		}
		aed[i]->setScale(0.3, 0.3);
		aed[i]->setPosition(posTemp[i], 50);
		addChild(aed[i], 2);
	}
	if (countA == 2) attPower++;
	if (countE == 2) evoPower++;
	if (countD == 2) defPower++;
	if (countA == 3) attPower = 10;
	if (countE == 3) evoPower = 10;
	if (countD == 3) defPower = 10;
	attBar->setPercentage((double)attPower / attMax * 100);
	evoBar->setPercentage((double)evoPower / evoMax * 100);
	defBar->setPercentage((double)defPower / defMax * 100);
}

bool WarScene::ableXros()
{
	if (wp[currrentPos]->getDgm()->isXrosAble() == false) return false;
	if (preXros == 0)
	{
		for (int i = 0; i < 6; i++)
		{
			if (wp[currrentPos]->getDgm()->getXrosObj() == wp[i]->getDgm()->getXrosNum())
			{
				xrosPair[preXros] = currrentPos;
				preXros++;
				xrosFX1 = ParticleGalaxy::create();
				xrosFX1->setPosition(warPosX[currrentPos], warPosY[currrentPos]);
				fxLayer->addChild(xrosFX1, 4);
				return true;
			}
		}
	}
	else if (preXros == 1)
	{
		if (wp[currrentPos]->getDgm()->getXrosObj() == wp[xrosPair[0]]->getDgm()->getXrosNum())
		{
			xrosPair[preXros] = currrentPos;
			preXros++;
			xrosFX2 = ParticleGalaxy::create();
			xrosFX2->setPosition(warPosX[currrentPos], warPosY[currrentPos]);
			fxLayer->addChild(xrosFX2, 4);
			return true;
		}
	}
	
	return false;
}

void WarScene::playVideo(int vi, int et)
{
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	isVplay = true;
	vcp = VLCPlayer::create(Size(960, 540));
	vcp->setPosition(480, 270);
	addChild(vcp, 5);
	if (et == EVOL) vcp->o_play(wp[vi]->getDgm()->getVideo(EVOL), false);
	else if (et == ULTIM_EVOL) vcp->o_play(wp[vi]->getDgm()->getVideo(ULTIM_EVOL), false);
	else if (et == ARMORF) vcp->o_play(wp[vi]->getDgm()->getVideo(ARMORF), false);
	else if (et == ARMORS) vcp->o_play(wp[vi]->getDgm()->getVideo(ARMORS), false);
	else if (et == XROS) vcp->o_play(wp[vi]->getDgm()->getVideo(XROS), false);

	skipButton->setOpacity(255);
	skipButton->setEnabled(true);
}

void WarScene::delButton()
{
	norAttButton->setOpacity(0);
	norAttButton->setEnabled(false);
	bigAttButton->setOpacity(0);
	bigAttButton->setEnabled(false);

	norEvoButton->setOpacity(0);
	norEvoButton->setEnabled(false);
	ultEvoButton->setOpacity(0);
	ultEvoButton->setEnabled(false);
	arfEvoButton->setOpacity(0);
	arfEvoButton->setEnabled(false);
	arsEvoButton->setOpacity(0);
	arsEvoButton->setEnabled(false);
	unEvoButton->setOpacity(0);
	unEvoButton->setEnabled(false);

	xrosUpButton->setOpacity(0);
	xrosUpButton->setEnabled(false);
}

void WarScene::evolutionGhange(int eg, int et)
{
	delFX();
	if (et == EVOL)
	{
		evoPower = evoPower - wp[eg]->getDgm()->evoConsume(EVOL);
		qt[eg] = wp[eg]->getDgm()->evolution(EVOL);
	}
	else if (et == ULTIM_EVOL)
	{
		evoPower = evoPower - wp[eg]->getDgm()->evoConsume(ULTIM_EVOL);
		qt[eg] = wp[eg]->getDgm()->evolution(ULTIM_EVOL);
	}
	else if (et == ARMORF)
	{
		evoPower = evoPower - wp[eg]->getDgm()->evoConsume(ARMORF);
		qt[eg] = wp[eg]->getDgm()->evolution(ARMORF);
	}
	else if (et == ARMORS)
	{
		evoPower = evoPower - wp[eg]->getDgm()->evoConsume(ARMORS);
		qt[eg] = wp[eg]->getDgm()->evolution(ARMORS);
	}
	else if (et == XROS)
	{
		evoPower = evoPower - wp[eg]->getDgm()->evoConsume(XROS);
		qt[eg] = wp[eg]->getDgm()->evolution(XROS);
	}
	else if (et == UNEVOL)
	{
		evoPower = evoPower - wp[eg]->getDgm()->evoConsume(UNEVOL);
		if (evoPower > 10) evoPower = 10;
		qt[eg] = wp[eg]->getDgm()->evolution(UNEVOL);
	}

	evoBar->setPercentage((double)evoPower / evoMax * 100);
	removeDigimon(eg);

	wp[eg]->setDgm(qt[eg]);
	wp[eg]->getDgm()->getSprite()->setScale(0.4, 0.4);
	wp[eg]->getDgm()->getSprite()->setPosition(wp[eg]->getPosX(), wp[eg]->getPosY());
	addChild(wp[eg]->getDgm()->getSprite(), 2);
	wp[eg]->getDgm()->getHpbar()->setPosition(wp[eg]->getHpPosX(), wp[eg]->getHpPosY());
	addChild(wp[eg]->getDgm()->getHpbar(), 3);
	wp[eg]->getDgm()->getHpBB()->setPosition(wp[eg]->getHpPosX(), wp[eg]->getHpPosY());
	addChild(wp[eg]->getDgm()->getHpBB(), 4);
}

void WarScene::onSkip(Ref* ref)
{
	vcp->o_stop();
}

void WarScene::setEvoEnable()
{
	if (wp[currrentPos]->getDgm()->evoConsume(EVOL) != -10 && wp[currrentPos]->getDgm()->evoConsume(EVOL) <= evoPower) norEvoButton->setEnabled(true);

	if (wp[currrentPos]->getDgm()->evoConsume(ULTIM_EVOL) != -10 && wp[currrentPos]->getDgm()->evoConsume(ULTIM_EVOL) <= evoPower) ultEvoButton->setEnabled(true);

	if (wp[currrentPos]->getDgm()->evoConsume(ARMORF) != -10 && wp[currrentPos]->getDgm()->evoConsume(ARMORF) <= evoPower) arfEvoButton->setEnabled(true);

	if (wp[currrentPos]->getDgm()->evoConsume(ARMORS) != -10 && wp[currrentPos]->getDgm()->evoConsume(ARMORS) <= evoPower) arsEvoButton->setEnabled(true);

	if (wp[currrentPos]->getDgm()->evoConsume(UNEVOL) != -10 && wp[currrentPos]->getDgm()->evoConsume(UNEVOL) <= evoPower) unEvoButton->setEnabled(true);
}

void WarScene::delFX()
{
	fxLayer->removeAllChildren();
}

void WarScene::evoLight()
{
	/////////////////
	evoLg = Sprite::create("fx/2/image  (1).png");
	evoLg->setPosition(warPosX[currrentPos] + 70, warPosY[currrentPos] - 60);
	evoLg->setScale(1.2, 1.2);
	//newSprite->setRotation(45);
	fxLayer->addChild(evoLg, 3);
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(12);
	animFrames.pushBack(SpriteFrame::create("fx/2/image  (1).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/2/image  (2).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/2/image  (3).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/2/image  (4).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/2/image  (5).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/2/image  (6).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/2/image  (7).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/2/image  (8).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/2/image  (9).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/2/image  (10).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/2/image  (11).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/2/image  (12).png", Rect(0, 0, 300, 300)));

	// create the animation out of the frames
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	animation->setLoops(1);
	animation->setRestoreOriginalFrame(false);
	auto animate = Animate::create(animation);
	//CCSequence* seq = CCSequence::create(RepeatForever::create(animate));
	evoLg->runAction(RepeatForever::create(animate));
	/////////////////
}

void WarScene::attLight()
{
	/////////////////
	attLg = Sprite::create("fx/11/image  (23).png");
	attLg->setPosition(warPosX[currrentPos] + 30, warPosY[currrentPos] - 80);
	attLg->setScale(0.9, 0.9);
	//newSprite->setRotation(45);
	fxLayer->addChild(attLg, 3);
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(8);
	animFrames.pushBack(SpriteFrame::create("fx/11/image  (23).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/11/image  (24).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/11/image  (25).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/11/image  (26).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/11/image  (27).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/11/image  (28).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/11/image  (29).png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/11/image  (30).png", Rect(0, 0, 300, 300)));

	// create the animation out of the frames
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	animation->setLoops(1);
	animation->setRestoreOriginalFrame(false);
	auto animate = Animate::create(animation);
	//CCSequence* seq = CCSequence::create(RepeatForever::create(animate));
	attLg->runAction(RepeatForever::create(animate));
	/////////////////
}

void WarScene::norAttFx(int i)
{
	ScaleTo* st = ScaleTo::create(0.2f, 0.55);
	wp[currrentPos]->getDgm()->getSprite()->runAction(st);
	DelayTime* dt = DelayTime::create(1.0f);
	ScaleTo* std = ScaleTo::create(0.2f, 0.4);
	CCSequence* dtstd = CCSequence::create(dt, std, NULL);
	wp[currrentPos]->getDgm()->getSprite()->runAction(dtstd);
	/////////////////
	auto newSprite = Sprite::create("fx/1/image 1.png");
	newSprite->setPosition(warPosX[i] + 100, warPosY[i] - 30);
	newSprite->setScale(1.5, 1.5);
	//newSprite->setRotation(45);
	addChild(newSprite, 3);
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(8);
	animFrames.pushBack(SpriteFrame::create("fx/1/image 1.png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/1/image 2.png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/1/image 3.png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/1/image 4.png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/1/image 5.png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/1/image 6.png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/1/image 7.png", Rect(0, 0, 300, 300)));
	animFrames.pushBack(SpriteFrame::create("fx/1/image 8.png", Rect(0, 0, 300, 300)));

	// create the animation out of the frames
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	animation->setLoops(1);
	animation->setRestoreOriginalFrame(false);
	auto animate = Animate::create(animation);
	CCToggleVisibility *Tog = CCToggleVisibility::create();
	//CCSequence* seq = CCSequence::create(RepeatForever::create(animate));
	Repeat* rt = Repeat::create(animate, 1);
	//newSprite->runAction(Repeat::create(animate, 1));
	CCDelayTime* del = CCDelayTime::create(0.3f);
	CCSequence* seq = CCSequence::create(del, rt, Tog, NULL);
	newSprite->runAction(seq);
	/////////////////
}

void WarScene::bigAttFx(int i)
{
	ScaleTo* st = ScaleTo::create(0.2f, 0.55);
	wp[currrentPos]->getDgm()->getSprite()->runAction(st);
	DelayTime* dt = DelayTime::create(1.1f);
	ScaleTo* std = ScaleTo::create(0.2f, 0.4);
	CCSequence* dtstd = CCSequence::create(dt, std, NULL);
	wp[currrentPos]->getDgm()->getSprite()->runAction(dtstd);

	auto newSprite = Sprite::create("fx/9/image 1.png");
	newSprite->setPosition(warPosX[currrentPos] + 100, warPosY[currrentPos] - 30);
	newSprite->setScale(1.0, 1.0);
	newSprite->setRotation(-(atan((warPosY[i]-warPosY[currrentPos])/(warPosX[i]-warPosX[currrentPos])))/3.1416*180);
	addChild(newSprite, 3);
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(4);
	animFrames.pushBack(SpriteFrame::create("fx/9/image 1.png", Rect(0, 0, 300, 100)));
	animFrames.pushBack(SpriteFrame::create("fx/9/image 2.png", Rect(0, 0, 300, 100)));
	animFrames.pushBack(SpriteFrame::create("fx/9/image 3.png", Rect(0, 0, 300, 100)));
	animFrames.pushBack(SpriteFrame::create("fx/9/image 4.png", Rect(0, 0, 300, 100)));

	// create the animation out of the frames
	auto animation = Animation::createWithSpriteFrames(animFrames, 0.05f);
	animation->setLoops(1);
	animation->setRestoreOriginalFrame(false);
	auto animate = Animate::create(animation);
	CCToggleVisibility *Tog = CCToggleVisibility::create();
	DelayTime* del0 = DelayTime::create(0.3f);
	//newSprite->runAction(RepeatForever::create(animate));
	Repeat* rt = Repeat::create(animate, 4);
	MoveTo* mt = MoveTo::create(0.7f, Vec2(warPosX[i], warPosY[i]));
	CCSequence* seq0 = CCSequence::create(del0, mt, NULL);
	newSprite->runAction(seq0);
	CCDelayTime* del = CCDelayTime::create(0.3f);
	CCSequence* seq = CCSequence::create(del, rt, Tog, NULL);
	newSprite->runAction(seq);

	//---------------------------------------------------------------------------------------------//

	auto newSprite2 = Sprite::create("fx/3/image 3.png");
	newSprite2->setPosition(warPosX[i] + 50, warPosY[i] - 40);
	newSprite2->setScale(1.2, 1.2);
	//newSprite2->setRotation(-(atan((warPosY[i] - warPosY[currrentPos]) / (warPosX[i] - warPosX[currrentPos]))) / 3.1416 * 180);
	addChild(newSprite2, 3);
	Vector<SpriteFrame*> animFrames2;
	animFrames2.reserve(9);
	animFrames2.pushBack(SpriteFrame::create("fx/3/image 3.png", Rect(0, 0, 300, 300)));
	animFrames2.pushBack(SpriteFrame::create("fx/3/image 4.png", Rect(0, 0, 300, 300)));
	animFrames2.pushBack(SpriteFrame::create("fx/3/image 5.png", Rect(0, 0, 300, 300)));
	animFrames2.pushBack(SpriteFrame::create("fx/3/image 6.png", Rect(0, 0, 300, 300)));
	animFrames2.pushBack(SpriteFrame::create("fx/3/image 7.png", Rect(0, 0, 300, 300)));
	animFrames2.pushBack(SpriteFrame::create("fx/3/image 8.png", Rect(0, 0, 300, 300)));
	animFrames2.pushBack(SpriteFrame::create("fx/3/image 9.png", Rect(0, 0, 300, 300)));
	animFrames2.pushBack(SpriteFrame::create("fx/3/image 10.png", Rect(0, 0, 300, 300)));
	animFrames2.pushBack(SpriteFrame::create("fx/3/image 11.png", Rect(0, 0, 300, 300)));

	// create the animation out of the frames
	auto animation2 = Animation::createWithSpriteFrames(animFrames2, 0.07f);
	animation2->setLoops(1);
	animation2->setRestoreOriginalFrame(false);
	auto animate2 = Animate::create(animation2);
	CCToggleVisibility *Tog2 = CCToggleVisibility::create();
	//newSprite2->runAction(RepeatForever::create(animate2));
	Repeat* rp = Repeat::create(animate2, 1);
	//CCDelayTime* del = CCDelayTime::create(0.7f);
	CCDelayTime* del2 = CCDelayTime::create(1.0f);
	CCSequence* seq2 = CCSequence::create(Tog2, del2, Tog2, rp, Tog2, NULL);
	newSprite2->runAction(seq2);
}

void WarScene::afterEvoFx()
{
	auto newSprite = Sprite::create("fx/6/image  (1).png");
	newSprite->setPosition(warPosX[currrentPos] + 70, warPosY[currrentPos] - 70);
	newSprite->setScale(0.7, 0.7);
	//newSprite->setRotation(-(atan((warPosY[i] - warPosY[currrentPos]) / (warPosX[i] - warPosX[currrentPos]))) / 3.1416 * 180);
	addChild(newSprite, 3);
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(11);
	animFrames.pushBack(SpriteFrame::create("fx/6/image  (1).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/6/image  (2).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/6/image  (3).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/6/image  (4).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/6/image  (5).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/6/image  (6).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/6/image  (7).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/6/image  (8).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/6/image  (9).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/6/image  (10).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/6/image  (11).png", Rect(0, 0, 500, 500)));

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.15f);
	animation->setLoops(1);
	animation->setRestoreOriginalFrame(false);
	auto animate = Animate::create(animation);
	CCToggleVisibility *Tog = CCToggleVisibility::create();
	Repeat* rp = Repeat::create(animate, 1);
	CCSequence* seq = CCSequence::create(rp, Tog, NULL);
	newSprite->runAction(seq);
}

void WarScene::comNorAttFx(int i)
{
	ScaleTo* st = ScaleTo::create(0.2f, 0.7);
	wp[currrentPos]->getDgm()->getSprite()->runAction(st);
	DelayTime* dt = DelayTime::create(1.0f);
	ScaleTo* std = ScaleTo::create(0.2f, 0.5);
	CCSequence* dtstd = CCSequence::create(dt, std, NULL);
	wp[currrentPos]->getDgm()->getSprite()->runAction(dtstd);

	auto newSprite = Sprite::create("fx/4/image  (1).png");
	newSprite->setPosition(warPosX[i] + 40, warPosY[i]);
	newSprite->setScale(0.5, 0.5);
	//newSprite->setRotation(-(atan((warPosY[i] - warPosY[currrentPos]) / (warPosX[i] - warPosX[currrentPos]))) / 3.1416 * 180);
	addChild(newSprite, 3);
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(8);
	animFrames.pushBack(SpriteFrame::create("fx/4/image  (1).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/4/image  (2).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/4/image  (3).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/4/image  (4).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/4/image  (5).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/4/image  (6).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/4/image  (7).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/4/image  (8).png", Rect(0, 0, 500, 500)));

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.08f);
	animation->setLoops(1);
	animation->setRestoreOriginalFrame(false);
	auto animate = Animate::create(animation);
	DelayTime* ddt = DelayTime::create(0.3f);
	CCToggleVisibility *Tog = CCToggleVisibility::create();
	Repeat* rp = Repeat::create(animate, 1);
	CCSequence* seq = CCSequence::create(Tog, ddt, Tog, rp, Tog, NULL);
	newSprite->runAction(seq);
}

void WarScene::comBigAttFx(int i)
{
	ScaleTo* st = ScaleTo::create(0.2f, 0.7);
	wp[currrentPos]->getDgm()->getSprite()->runAction(st);
	DelayTime* dt = DelayTime::create(1.0f);
	ScaleTo* std = ScaleTo::create(0.2f, 0.5);
	CCSequence* dtstd = CCSequence::create(dt, std, NULL);
	wp[currrentPos]->getDgm()->getSprite()->runAction(dtstd);

	auto newSprite = Sprite::create("fx/5/image  (1).png");
	newSprite->setPosition(warPosX[i] + 40, warPosY[i]);
	newSprite->setScale(0.5, 0.5);
	//newSprite->setRotation(-(atan((warPosY[i] - warPosY[currrentPos]) / (warPosX[i] - warPosX[currrentPos]))) / 3.1416 * 180);
	addChild(newSprite, 3);
	Vector<SpriteFrame*> animFrames;
	animFrames.reserve(7);
	animFrames.pushBack(SpriteFrame::create("fx/5/image  (1).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/5/image  (2).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/5/image  (3).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/5/image  (4).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/5/image  (5).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/5/image  (6).png", Rect(0, 0, 500, 500)));
	animFrames.pushBack(SpriteFrame::create("fx/5/image  (7).png", Rect(0, 0, 500, 500)));

	auto animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
	animation->setLoops(1);
	animation->setRestoreOriginalFrame(false);
	auto animate = Animate::create(animation);
	DelayTime* ddt = DelayTime::create(0.3f);
	CCToggleVisibility *Tog = CCToggleVisibility::create();
	Repeat* rp = Repeat::create(animate, 1);
	CCSequence* seq = CCSequence::create(Tog, ddt, Tog, rp, Tog, NULL);
	newSprite->runAction(seq);
}

void WarScene::blackButton()
{
	attButton->setEnabled(false);
	evoButton->setEnabled(false);
	xrosButton->setEnabled(false);
	endButton->setEnabled(false);
}

void WarScene::whiteButton(float dt)
{
	attButton->setEnabled(true);
	evoButton->setEnabled(true);
	xrosButton->setEnabled(true);
	endButton->setEnabled(true);
	getPower();
	Sprite* turnBackg = Sprite::create("youTurn.png");
	turnBackg->setPosition(480, 270);
	addChild(turnBackg, 10);
	turnBackg->setOpacity(0);
	FadeIn* fi = FadeIn::create(0.3f);
	FadeOut* fo = FadeOut::create(0.3f);
	DelayTime* ddt = DelayTime::create(0.5f);
	Sequence* sq = Sequence::create(fi, ddt, fo, NULL);
	turnBackg->runAction(sq);
}

void WarScene::delayHp(float dt)
{
	while (hci != hcc)
	{
		if (defPower == 0 || currrentPos < 6)
		{
			wp[hurtCout[hci]]->getDgm()->changeHp(wp[currrentPos]->getDgm()->getDam());
		}
		else
		{
			defPower -= 1;
			defBar->setPercentage((double)defPower / defMax * 100);
		}

		if (wp[hurtCout[hci]]->getDgm()->getHp() <= 0)
		{
			removeDigimon(hurtCout[hci]);
		}
		hci++;
	}
	gameOver();
}

void WarScene::delayHpX(float dt)
{
	//log("aaa");
	while (hci != hcc)
	{
		wp[hurtCout[hci]]->getDgm()->changeHp(wp[currrentPos]->getDgm()->getDamX());
		if (wp[hurtCout[hci]]->getDgm()->getHp() <= 0)
		{
			removeDigimon(hurtCout[hci]);
		}
		hci++;
	}
	gameOver();
}
