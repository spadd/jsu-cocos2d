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

	// 1.创建一个空的场景
	//Scene* scene = Scene::create();
	// 2.创建一个精灵（通过一个图片的名字）
	Sprite* bg = Sprite::create("HelloWorld.png");

	// Layer是一个透明的层
	Layer* lay = Layer::create();

	// 3.设定精灵的位置
	bg->setPosition(Vec2(480,320));
	// 4.设定锚点(默认0.5，0.5)
	//bg->setAnchorPoint(Vec2(0,0));
	bg->setScale(2.0f);


	// 5.把精灵放到scene上
	//this->addChild(bg);
	lay->addChild(bg);
	this->addChild(lay);

	// 1.创建一个标签（使用系统默认字体的方式创建）
	Label* la = Label::createWithSystemFont("Hello","",20);
	la->setPosition(Vec2(320,480));
	la->setTextColor(Color4B::RED);

	this->addChild(la);

	// 创建一个点击事件(需要在头文件声明)
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
