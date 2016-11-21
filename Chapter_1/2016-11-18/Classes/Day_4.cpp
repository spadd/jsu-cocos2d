#include "Day_4.h"

Scene* Day_4::createScene()
{
	Scene* scene = Scene::create();
	Day_4* layer = Day_4::create();
	scene->addChild(layer);
	return scene;

}

bool Day_4::init()
{
	if(!Layer::init())
		return false;

	// �����ʼ��������
	monsterArray = __Array::create();
	monsterArray->retain();
	bulltArray = __Array::create();
	bulltArray->retain();

	Sprite* bg = Sprite::create("1.png");
	bg->setPosition(Vec2(480,320));
	this->addChild(bg);

	label = Label::createWithSystemFont("Count->0","",21);
	label->setPosition(Vec2(600,600));
	this->addChild(label);
	count = 0;

	auto event = Director::getInstance()->getEventDispatcher();
	auto listen = EventListenerTouchOneByOne::create();
	listen->onTouchBegan = CC_CALLBACK_2(Day_4::onTouchBegan,this);
	listen->onTouchMoved = CC_CALLBACK_2(Day_4::onTouchMoved,this);
	listen->onTouchEnded = CC_CALLBACK_2(Day_4::onTouchEnded,this);
	event->addEventListenerWithSceneGraphPriority(listen,this);

	hero = Sprite::create("boss_8.png");
	hero->setPosition(Vec2(100,320));
	hero->setScale(0.5);
	this->addChild(hero);

	// �ӵ����ɶ�ʱ��
	schedule(CC_CALLBACK_1(Day_4::BulltAnimation,this),1,"bullt");
	// �������ɶ�ʱ��
	schedule(CC_CALLBACK_1(Day_4::MosterUpdate,this),1,"moster");
	// ��ײ��ⶨʱ��
	schedule(CC_CALLBACK_1(Day_4::UpdateRemove,this),"updateRemove");
	//BulltAnimation();
	return true;
}

bool Day_4::onTouchBegan(Touch* touch,Event* unused_event)
{
	return true;
}
void Day_4::onTouchMoved(Touch* touch,Event* unused_event)
{
	Vec2 pos = touch->getLocation();
	
	if(pos.y >50 && pos.y<500)
	{
		hero->setPositionY(pos.y);
	}
	
}
void Day_4::onTouchEnded(Touch* touch,Event* unused_event){

}

void Day_4::BulltAnimation(float f)
{
	SpriteFrameCache* cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("roleArrow.plist","roleArrow.png");
	Vector<SpriteFrame*> vector;
	for(int i=0;i<=5;i++)
	{
		String* name = String::createWithFormat("roleArrow_000%d.png",i);
		SpriteFrame*  frame= cache->getSpriteFrameByName(name->getCString());
		vector.pushBack(frame);
	}
	// �ӵ�����
	Sprite* bullet = Sprite::createWithSpriteFrameName("roleArrow_0000.png");
	bullet->setPosition(hero->getPosition()+Point(70,0));
	bullet->setRotation(-90);
	this->addChild(bullet);
	// �ӵ�����
	Animation* ani = Animation::createWithSpriteFrames(vector,0.1,true);
	Animate* animate = Animate::create(ani);
	RepeatForever* RF = RepeatForever::create(animate);
	bullet->runAction(RF);
	// �ӵ�����ָ��λ�ú���ʧ(�ص�����ʵ��)
	auto call = CallFuncN::create(CC_CALLBACK_1(Day_4::BulltRemove,this));
	auto mt1 = MoveTo::create(8,Vec2(900,bullet->getPositionY()));
	// �Լ�ʵ��
	//RemoveSelf* RS = RemoveSelf::create();
	//auto a = Sequence::create(mt1,RS,NULL);
	auto a = Sequence::create(mt1,call,NULL);
	
	bullet->runAction(a);
	bulltArray->addObject(bullet);
	
}

void Day_4::BulltRemove(Ref* s)
{
	Sprite* b = (Sprite*)s;
	this->removeChild(b);
	
}

void Day_4::MosterUpdate(float f)
{
	// ��ȡ��õ�1~16����
	int i = 1+rand()%15;
	String* name = String::createWithFormat("boss_%d.png",i);
	Sprite* moster = Sprite::create(name->getCString());

	int y = 100 + rand()%500;

	moster->setScale(0.3);
	moster->setPosition(Vec2(900,y));
	this->addChild(moster);
	auto mt1 = MoveTo::create(8,Vec2(0,moster->getPositionY()));
	auto call = CallFuncN::create(CC_CALLBACK_1(Day_4::MosterRemove,this));
	auto a = Sequence::create(mt1,call,NULL);
	moster->runAction(a);
	
	monsterArray->addObject(moster);	
}

void Day_4::MosterRemove(Ref* s)
{
	Sprite* b = (Sprite*)s;
	this->removeChild(b);
	
}

void Day_4::UpdateRemove(float f)
{
	for (int i = 0; i < bulltArray->count(); i++)
	{
		Sprite* bullt = (Sprite*)bulltArray->getObjectAtIndex(i);
		// �ӵ��ľ��ο�
		Rect bulltRect = bullt->getBoundingBox();
		for (int j = 0; j < monsterArray->count(); j++)
		{
			Sprite* monster = (Sprite*)monsterArray->getObjectAtIndex(j);
			Rect mReact = monster->getBoundingBox();
			// �ж�2�����ο��Ƿ��غ�
			if(bulltRect.intersectsRect(mReact))
			{
				count++;
				String* c = String::createWithFormat("Count->%d",count);
				label-> setString(c->getCString());
				// ����Ļ���Ƴ�
				bullt->removeFromParent();
				monster->removeFromParent();
				// ���������Ƴ�
				bulltArray->removeObjectAtIndex(i);
				//bulltArray->removeObject(bullt);
				monsterArray->removeObjectAtIndex(j);
				//monsterArray->removeObject(monster);

				// �Ż�
				break;
			}

			if(monster->getPositionX()==0)
			{
				// �Ƴ���Ļ���е�����
				this->removeAllChildren();
				unschedule("updateRemove");
				unschedule("bullt");
				unschedule("moster");
				Label* l = Label::createWithSystemFont("Game Over","",25);
				l->setPosition(Vec2(480,320));
				this->addChild(l);
				//break;
				// ������������
				return;
			}
		}
		
	}
}