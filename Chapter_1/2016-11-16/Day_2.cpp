#include "Day_2.h"
Scene* Day_2::createScene()
{
	Scene* scene = Scene::create();
	Day_2* layer = Day_2::create();
	scene->addChild(layer);
	return scene;
}
bool Day_2::init()
{
	if(!Layer::init())
	{
		return false;
	}

	bg = Sprite::create("HelloWorld.png");
	bg->setPosition(Vec2(480,320));
	bg->setScale(2);
	this->addChild(bg);

	hero = Sprite::create("CloseNormal.png");
	hero->setPosition(Vec2(480,320));
	this->addChild(hero);

	MenuItemFont* itemMove = MenuItemFont::create("move");
	itemMove->setPosition(Vec2(480,580));
	itemMove->setColor(Color3B::RED);
	itemMove->setCallback(CC_CALLBACK_0(Day_2::Click,this));
	Menu* menu = Menu::create(itemMove,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);

	return true;
}

void Day_2::Click()
{
	// ����һ��������ʱ�䣬����λ�ã�
	MoveTo* moveTo = MoveTo::create(5,Vec2(960,320));
	//hero->runAction(moveTo);
	// ����һ��������ʱ�䣬���λ�ã�
	MoveBy* moveBy = MoveBy::create(5,Vec2(0,320));
	//hero->runAction(moveBy);

	// ����λ����ת
	RotateTo* RT = RotateTo::create(3,90);
	//hero->runAction(RT);

	// ����λ����ת�����ۼ�
	RotateBy* RB = RotateBy::create(1,90);
	//hero->runAction(RB);

	// ���ԷŴ�(ʱ�䣬����)
	ScaleTo* ST = ScaleTo::create(1,2);
	//hero->runAction(ST);
	// ��ԷŴ�(ʱ�䣬����)
	ScaleBy* SB = ScaleBy::create(1,2);
	//hero->runAction(SB);

	// ��������������ʱ�䣬����������λ�ã������߶ȣ�������
	JumpTo* JT = JumpTo::create(1,Vec2(480,320),25,2);
	//hero->runAction(JT);
	// ������������ۼӣ�����ʱ�䣬����������λ�ã������߶ȣ�����)
	JumpBy* JB = JumpBy::create(1,Vec2(50,0),25,2);
	//hero->runAction(JB);

	// ��˸��ʱ�䣬������
	Blink* b = Blink::create(2,4);
	//hero->runAction(b);

	// ȡһ�������ķ�����
	auto re = moveBy->reverse();
	//hero->runAction(re);
	// ���������ж������з�����(����To,Blink)
	auto re2 = moveTo->reverse();
	//hero->runAction(re2);

	// �ն�����ʱ�䣩�����ʹ��
	DelayTime* dt = DelayTime::create(4);
	//hero->runAction(dt);

	auto mt1 = MoveTo::create(2,Vec2(800,320));
	auto mt2 = MoveTo::create(2,Vec2(480,320));
	auto dt2 = DelayTime::create(4);

	// ���ж���(����...��NULL):������ӵ�˳��ִ�ж������
	auto seq = Sequence::create(mt1,dt2,mt2,NULL);
	//hero->runAction(seq);

	// ͬ������(����...��NULL)��ͬʱִ�ж��������������runAction�����������ʹ��Sequence,Spawn������ϣ�
	auto scaleTo = ScaleTo::create(2,2);
	auto spaw = Spawn::create(mt1,scaleTo,NULL);
	//hero->runAction(seq);

	// �ظ�����(����,����)
	auto rep = Repeat::create(RB,5);
	//hero->runAction(rep);

	//һֱ�ظ�����(����)
	auto RF = RepeatForever::create(RB);
	//hero->runAction(RF);

	auto hero2 = Sprite::create("CloseSelected.png");
	hero2->setPosition(Vec2(480,500));
	this->addChild(hero2);

	// �ı䶯������hero2->runAction() hero���˶���
	auto tar = TargetedAction::create(hero,rep);
	//hero2->runAction(tar);

	// ˲ʱ����(�ص���������)��ֻҪ�Ƕ����������
	auto callfunc = CallFunc::create(CC_CALLBACK_0(Day_2::Func,this));
	auto seq2 = Sequence::create(mt1,callfunc,NULL);
	//hero->runAction(seq2);

	// ˲ʱ��������������
	auto callfuncN = CallFuncN::create(CC_CALLBACK_1(Day_2::Func2,this));
	auto seq3 = Sequence::create(mt1,callfuncN,NULL);
	hero->setTag(111);
	//hero->runAction(seq3);

	// ��ʾ
	auto s = Show::create();
	// ����
	auto h = Hide::create();

	static int i = 0;
	i++;
	if(i%2 == 1)
	{
		//hero->runAction(h);
	}
	else
	{
		//hero->runAction(s);
	}

	//  �Ƴ�������
	auto remove = RemoveSelf::create();
	auto seq4 = Sequence::create(mt1,remove,NULL);
	//hero->runAction(seq4);

	// x�ᷭת��true��ת false�ָ�ԭ��״̬��
	auto f1 = FlipX::create(true);
	auto f2 = FlipX::create(false);

	auto fy1 = FlipY::create(true);
	auto fy2 = FlipY::create(false);
	if(i%2 == 1)
	{
		//hero->runAction(fy1);
	}
	else
	{
		//hero->runAction(fy2);
	}

	// λ�ö���(λ��)
	auto p = Place::create(Vec2(60,60));
	// hero->runAction(p);

	//���ٶ�������������������
	auto sp = Speed::create(mt1,10);
	//hero->runAction(sp);

	auto mb = MoveBy::create(100,Vec2(60,60));
	hero->runAction(mb);
	log("Click log");
}
void Day_2::Func()
{
	log("sport  over");
}

void Day_2::Func2(Ref* sender)
{
	Sprite* h = (Sprite*)sender;
	// ��Layer���Ƴ��ӽڵ�
	this->removeChild(h);
	log("%d",h->getTag());
}
