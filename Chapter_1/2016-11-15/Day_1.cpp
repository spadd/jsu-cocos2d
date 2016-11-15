#include "Day_1.h"
Scene* Day_1::createScene()
{
	Scene* scene = Scene::create();
	Layer* layer = Day_1::create();
	scene->addChild(layer);
	return scene;
}

bool Day_1::init()
{
	if (!Layer::init())
		return false;

	i = 0;

	Sprite* bg = Sprite::create("HelloWorld.png");
	bg->setPosition(Vec2(480,320));
	this->addChild(bg);

	MenuItemImage* item = MenuItemImage::create("CloseNormal.png","CloseSelected.png");
	item->setPosition(Vec2(720,60));
	item->setCallback(CC_CALLBACK_0(Day_1::Click,this));
	Menu* menu = Menu::create(item,NULL);
	menu->setPosition(Vec2(0,0));
	this->addChild(menu);

	MenuItemFont* itemFont = MenuItemFont::create("ON");
	MenuItemFont* itemFont2 = MenuItemFont::create("OFF");
	// 创建菜单组
	MenuItemToggle* toggle = MenuItemToggle::create();
	toggle->addSubItem(itemFont);
	toggle->addSubItem(itemFont2);
	// 初始显示的菜单
	toggle->setSelectedIndex(0);
	toggle->setCallback(CC_CALLBACK_0(Day_1::Click,this));
	toggle->setPosition(Vec2(480,500));
	Menu* menu2 = Menu::create(toggle,NULL);
	menu2->setPosition(Vec2(0,0));
	this->addChild(menu2);

	// 进度条
	func_progress();
	schedule(CC_CALLBACK_1(Day_1::moveProgress,this),0.1,"moveProgress");

	return true;
}

void Day_1::Click()
{
	Label* lab = Label::createWithSystemFont("aaaaa","",22);
	lab->setPosition(Vec2(120,300));

	// 设置Tag
	lab->setTag(111);

	this->addChild(lab);

	// 开启一个定时器（1/60调用一次）（回调函数、定时器的名字）
	// schedule(CC_CALLBACK_1(Day_1::callfunc,this),"callfunc");

	// 每1秒调用一次定时器
	// schedule(CC_CALLBACK_1(Day_1::callfunc,this),1,"callfunc");

	// 每1秒调用一次定时器,调用5次，延时3秒
	schedule(CC_CALLBACK_1(Day_1::callfunc,this),1,5,3,"callfunc");
}

void Day_1::callfunc(float d)
{
	i++;
	// int转string
	String * str = String::createWithFormat("%d",i);

	// 获取Tag
	Label* lab = (Label*)this->getChildByTag(111);

	// 设置文字
	lab->setString(str->getCString());
	
	if(i==500)
	{
		unschedule("callfunc");
		lab->setString("finish");
	}

	log("%d",i);
}

void Day_1::func_progress()
{
	Sprite* sprite = Sprite::create("HelloWorld.png");
	
	// 通过精灵创建一个进度条
	progress  = ProgressTimer::create(sprite);
	// 设置进度条类型为条形进度条
	//progress->setType(ProgressTimer::Type::BAR);
	// 设置进度条类型为圆形进度条
	progress->setType(ProgressTimer::Type::RADIAL);
	// 缩小0.2倍
	progress->setScaleY(0.2);
	// 设置进度条的基准点（运动的中心点）
	//progress->setMidpoint(Vec2(0,0.5));
	progress->setMidpoint(Vec2(0.5,0.5));
	// 设置运动方向(X轴运动)
	progress->setBarChangeRate(Vec2(1,0));
	// 设置位置
	progress->setPosition(Vec2(480,100));
	// 设定进度条百分比（0%）
	progress->setPercentage(0);

	this->addChild(progress);
}

void Day_1::moveProgress(float d)
{
	static int j = 0;
	j++;
	progress->setPercentage(j);
	if(j==100)
		unschedule("moveProgress");
}