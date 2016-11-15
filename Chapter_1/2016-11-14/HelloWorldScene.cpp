#include "HelloWorldScene.h"
#include "Day_1.h"
USING_NS_CC;

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

	// 1.����һ���յĳ���
	//Scene* scene = Scene::create();
	// 2.����һ�����飨ͨ��һ��ͼƬ�����֣�
	Sprite* bg = Sprite::create("HelloWorld.png");

	// Layer��һ��͸���Ĳ�
	Layer* lay = Layer::create();

	// 3.�趨�����λ��
	bg->setPosition(Vec2(480,320));
	// 4.�趨ê��(Ĭ��0.5��0.5)
	//bg->setAnchorPoint(Vec2(0,0));
	bg->setScale(2.0f);


	// 5.�Ѿ���ŵ�scene��
	//this->addChild(bg);
	lay->addChild(bg);
	this->addChild(lay);

	// 1.����һ����ǩ��ʹ��ϵͳĬ������ķ�ʽ������
	Label* la = Label::createWithSystemFont("Hello","",20);
	la->setPosition(Vec2(320,480));
	la->setTextColor(Color4B::RED);

	this->addChild(la);

	// ����һ������¼�(��Ҫ��ͷ�ļ�����)
	MenuItemImage* item = MenuItemImage::create("CloseNormal.png","CloseSelected.png");
	item->setPosition(Vec2(900,60));
	item->setCallback(CC_CALLBACK_0(HelloWorld::Click,this));
	Menu* menu = Menu::create(item,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
	num = 0;
	return true;
}

void HelloWorld::Click()
{

	num++;
	log("Click %d",num);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
