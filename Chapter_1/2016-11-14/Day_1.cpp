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

	return true;
}

void Day_1::Click()
{
	Label* lab = Label::createWithSystemFont("aaaaa","",22);
	lab->setPosition(Vec2(120,300));

	// ����Tag
	lab->setTag(111);

	this->addChild(lab);

	// ����һ����ʱ����1/60����һ�Σ����ص���������ʱ�������֣�
	// schedule(CC_CALLBACK_1(Day_1::callfunc,this),"callfunc");

	// ÿ1�����һ�ζ�ʱ��
	// schedule(CC_CALLBACK_1(Day_1::callfunc,this),1,"callfunc");

	// ÿ1�����һ�ζ�ʱ��,����5�Σ���ʱ3��
	schedule(CC_CALLBACK_1(Day_1::callfunc,this),1,5,3,"callfunc");
}

void Day_1::callfunc(float d)
{
	i++;
	// intתstring
	String * str = String::createWithFormat("%d",i);

	// ��ȡTag
	Label* lab = (Label*)this->getChildByTag(111);

	// ��������
	lab->setString(str->getCString());
	
	if(i==500)
	{
		unschedule("callfunc");
		lab->setString("finish");
	}

	log("%d",i);
}