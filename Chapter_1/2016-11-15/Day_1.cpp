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
	// �����˵���
	MenuItemToggle* toggle = MenuItemToggle::create();
	toggle->addSubItem(itemFont);
	toggle->addSubItem(itemFont2);
	// ��ʼ��ʾ�Ĳ˵�
	toggle->setSelectedIndex(0);
	toggle->setCallback(CC_CALLBACK_0(Day_1::Click,this));
	toggle->setPosition(Vec2(480,500));
	Menu* menu2 = Menu::create(toggle,NULL);
	menu2->setPosition(Vec2(0,0));
	this->addChild(menu2);

	// ������
	func_progress();
	schedule(CC_CALLBACK_1(Day_1::moveProgress,this),0.1,"moveProgress");

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

void Day_1::func_progress()
{
	Sprite* sprite = Sprite::create("HelloWorld.png");
	
	// ͨ�����鴴��һ��������
	progress  = ProgressTimer::create(sprite);
	// ���ý���������Ϊ���ν�����
	//progress->setType(ProgressTimer::Type::BAR);
	// ���ý���������ΪԲ�ν�����
	progress->setType(ProgressTimer::Type::RADIAL);
	// ��С0.2��
	progress->setScaleY(0.2);
	// ���ý������Ļ�׼�㣨�˶������ĵ㣩
	//progress->setMidpoint(Vec2(0,0.5));
	progress->setMidpoint(Vec2(0.5,0.5));
	// �����˶�����(X���˶�)
	progress->setBarChangeRate(Vec2(1,0));
	// ����λ��
	progress->setPosition(Vec2(480,100));
	// �趨�������ٷֱȣ�0%��
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