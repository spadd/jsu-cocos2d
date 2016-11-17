#include "Day_3.h"
#include "MenuScene.h"

Scene* Day_3::createScene()
{
	Scene* scene = Scene::create();
	Day_3* layer = Day_3::create();
	scene->addChild(layer);
	return scene;
}


bool Day_3::init()
{
	if(!Layer::init())
	{
		return false;
	}
	// 设置可触摸
	this->setTouchEnabled(true);
	// 设置单点触摸
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	// 获取事件分发对象
	EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();  
	// 获得单点触摸事件对象
	auto listen = EventListenerTouchAllAtOnce::create();  
	listen->onTouchesBegan = CC_CALLBACK_2(Day_3::onTouchesBegan,this);  
	listen->onTouchesMoved = CC_CALLBACK_2(Day_3::onTouchesMoved,this);  
	listen->onTouchesEnded = CC_CALLBACK_2(Day_3::onTouchesEnded,this);  
	listen->onTouchesCancelled = CC_CALLBACK_2(Day_3::onTouchesCancelled,this);  
	// 将触摸事件对象加入事件分发进行注册
	eventDispatcher->addEventListenerWithSceneGraphPriority(listen,this);  

	// 背景
	Sprite* bg = Sprite::create("bg.png");
	bg->setPosition(Vec2(480,320));
	this->addChild(bg);

	MenuItemFont* item = MenuItemFont::create("qie huan");
	item->setColor(Color3B::GREEN);
	item->setPosition(Vec2(840,60));
	item->setCallback(CC_CALLBACK_0(Day_3::Click,this));
	Menu* menu = Menu::create(item,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	SpriteAnimation();

	return true;

}

void Day_3::SpriteAnimation()
{
	// 获得精灵帧管理对象
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	// 从图片文件读取精灵帧放到缓存中
	cache->addSpriteFramesWithFile("10001_walk.plist","10001_walk.png");
	// 通过缓存中的精灵帧创建精灵（精灵帧名字plist）
	Sprite* hero = Sprite::createWithSpriteFrameName("10001_walk_0000.png");
	// 设置全局或者TAG值
	hero->setTag(111);
	hero->setPosition(Vec2(480,320));
	this->addChild(hero);

	// 容器(存放精灵帧)
	Vector<SpriteFrame*> vector;
	for (int i = 0; i < 7; i++)
	{
		// 格式化字符串拼接图片完整名字
		//String* name = String::createWithFormat("10001_walk_000%d.png",i);
		std::string str = StringUtils::format("10001_walk_000%d.png",i);
		// 通过名字获取精灵帧
		//SpriteFrame* frames = cache->getSpriteFrameByName(name->getCString());
		SpriteFrame* frames = cache->getSpriteFrameByName(str);
		vector.pushBack(frames);
	}
	// 创建动画（容器，间隔时间）
	Animation* ani = Animation::createWithSpriteFrames(vector,0.2);
	// 动画转化为动作
	Animate* animate = Animate::create(ani);
	// 重复动作
	// Spawn和Sequence组合运动时，不可以有永久动作，必须为限时动作
	auto RF = RepeatForever::create(animate);
	hero->runAction(RF);
	auto mt1 = MoveTo::create(5,Vec2(720,320));
	auto mt2 = MoveTo::create(10,Vec2(120,320));
	auto mt3 = MoveTo::create(5,Vec2(480,320));
	auto fx1 = FlipX::create(true);
	auto fx2 = FlipX::create(false);

	auto seq = Sequence::create(mt1,fx1,mt2,fx2,mt3,NULL);
	auto RF2 = RepeatForever::create(seq);
	RF2->setTag(110);
	hero->runAction(RF2);
}
void Day_3::Click()
{
	Director::getInstance()->replaceScene(MenuScene::createScene());

}

bool Day_3::onTouchBegan(Touch* touch,Event* unused_event)
{
	Sprite* hero = (Sprite*)this->getChildByTag(111);
	// 停止英雄的某一个动作tag值为110的值
	hero->stopActionByTag(110);
	// 停止英雄的所有动作
	// hero->stopAllActions();
	Vec2 pos1 = touch->getLocation();  
	auto pos2 = touch->getLocationInView();  
	auto pos3 = Director::getInstance()->convertToUI(pos2);  

	log("pos1 x: %f, y: %f",pos1.x,pos1.y);  
	log("pos2 x: %f, y: %f",pos2.x,pos2.y);  
	log("pos2 x: %f, y: %f",pos3.x,pos3.y);  

	// 计算触摸点与英雄的距离/速度
	float t = pos1.distance(hero->getPosition())/100;
	auto mt1 = MoveTo::create(t,pos1);
	auto fx1 = FlipX::create(true);
	auto fx2 = FlipX::create(false);

	auto fy1 = FlipY::create(true);
	auto fy2 = FlipY::create(false);

	auto seq = Sequence::create(fx2,mt1,NULL);
	seq->setTag(110);
	auto seq2 = Sequence::create(fx1,mt1,NULL);
	seq2->setTag(110);

	if(hero->getPositionX()<pos1.x)
	{
		hero->runAction(seq);
	}
	else
	{
		hero->runAction(seq2);
	}


	return true;
}
void Day_3::onTouchMoved(Touch* touch,Event* unused_event)
{
	auto pos = touch->getLocation();
	Sprite* hero = (Sprite*)this->getChildByTag(111);
	hero->setPosition(pos);
	log("TouchTest onTouchesMoved");  
}
void Day_3::onTouchEnded(Touch* touch,Event* unused_event)
{
	log("TouchTest onTouchesEnded");  
}
void Day_3::onTouchCancelled(Touch* touch,Event* unused_event)
{
	log("TouchTest onTouchesCancelled");  
}