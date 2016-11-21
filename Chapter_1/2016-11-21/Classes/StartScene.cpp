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
	// ��ȡ��ǰ��Ļ�ĳߴ�
	WinSize = Director::getInstance()->getVisibleSize();
	// ����
	Sprite* bg = Sprite::create("minerMainMenu.png");
	bg->setPosition(Vec2(WinSize.width/2,WinSize.height/2));
	this->addChild(bg);
	// ��ʼ��ť
	MenuItemImage* itemPlay = MenuItemImage::create("PlayMenu.png","PlayMenu.png",CC_CALLBACK_0(StartScene::menuClick,this));
	itemPlay->setScale(0.7);
	itemPlay->setPosition(Vec2(WinSize.width/3,WinSize.height/2+20));
	Menu* menu = Menu::create(itemPlay,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
	// ������ֿ��Ʋ˵�
	MenuItemImage* itemSoundOn = MenuItemImage::create("soundController.png","soundController2.png");
	MenuItemImage* itemSoundOFF = MenuItemImage::create("soundController2.png","soundController1.png");
	toggle = MenuItemToggle::createWithCallback(CC_CALLBACK_0(StartScene::soundClick,this),itemSoundOn,itemSoundOFF,NULL);
	toggle->setPosition(Vec2(Vec2(WinSize.width-40,40)));
	Menu* menu2 = Menu::create(toggle,NULL);
	menu2->setPosition(Vec2::ZERO);
	this->addChild(menu2);
	// ѭ�����ű�������
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
		// �ָ����ű�������
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		log("sound on");
	}
	else
	{
		// ��ͣ���ű�������
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		log("sound off");
	}
	
}