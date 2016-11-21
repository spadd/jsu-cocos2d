#include "StartScene.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
Scene* StartScene::createScene()
{
	Scene* scene = Scene::create();
	StartScene* layer = StartScene::create();
	scene->addChild(layer);
	return scene;

}

bool StartScene::init()
{
	if(!Layer::init())
	{
		return false;
	}
	// »ñÈ¡µ±Ç°ÆÁÄ»µÄ³ß´ç
	WinSize = Director::getInstance()->getVisibleSize();
	// ±³¾°
	Sprite* bg = Sprite::create("minerMainMenu.png");
	bg->setPosition(Vec2(WinSize.width/2,WinSize.height/2));
	this->addChild(bg);
	// ¿ªÊ¼°´Å¥
	MenuItemImage* itemPlay = MenuItemImage::create("PlayMenu.png","PlayMenu.png",CC_CALLBACK_0(StartScene::menuClick,this));
	itemPlay->setScale(0.7);
	itemPlay->setPosition(Vec2(WinSize.width/3,WinSize.height/2+20));
	Menu* menu = Menu::create(itemPlay,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
	// Ìí¼ÓÒôÀÖ¿ØÖÆ²Ëµ¥
	MenuItemImage* itemSoundOn = MenuItemImage::create("soundController.png","soundController2.png");
	MenuItemImage* itemSoundOFF = MenuItemImage::create("soundController2.png","soundController1.png");
	toggle = MenuItemToggle::createWithCallback(CC_CALLBACK_0(StartScene::soundClick,this),itemSoundOn,itemSoundOFF,NULL);
	toggle->setPosition(Vec2(Vec2(WinSize.width-40,40)));
	Menu* menu2 = Menu::create(toggle,NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2);
	// Ñ­»·²¥·Å±³¾°ÒôÀÖ
	SimpleAudioEngine::getInstance()->playBackgroundMusic("backMusic.mp3",true);
	return true;
}

void StartScene::menuClick()
{
	log("play game");
}

void StartScene::soundClick()
{
	
	if(toggle->getSelectedIndex() == 0)
	{
		// »Ö¸´²¥·Å±³¾°ÒôÀÖ
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		log("sound on");
	}
	else
	{
		// ÔÝÍ£²¥·Å±³¾°ÒôÀÖ
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		log("sound off");
	}
	
}