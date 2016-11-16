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
	// 创建一个动作（时间，绝对位置）
	MoveTo* moveTo = MoveTo::create(5,Vec2(960,320));
	//hero->runAction(moveTo);
	// 创建一个动作（时间，相对位置）
	MoveBy* moveBy = MoveBy::create(5,Vec2(0,320));
	//hero->runAction(moveBy);

	// 绝对位置旋转
	RotateTo* RT = RotateTo::create(3,90);
	//hero->runAction(RT);

	// 将对位置旋转，可累加
	RotateBy* RB = RotateBy::create(1,90);
	//hero->runAction(RB);

	// 绝对放大(时间，倍数)
	ScaleTo* ST = ScaleTo::create(1,2);
	//hero->runAction(ST);
	// 相对放大(时间，倍数)
	ScaleBy* SB = ScaleBy::create(1,2);
	//hero->runAction(SB);

	// 绝对跳动（跳动时间，跳动的最终位置，跳动高度，次数）
	JumpTo* JT = JumpTo::create(1,Vec2(480,320),25,2);
	//hero->runAction(JT);
	// 相对跳动，可累加（跳动时间，跳动的最终位置，跳动高度，次数)
	JumpBy* JB = JumpBy::create(1,Vec2(50,0),25,2);
	//hero->runAction(JB);

	// 闪烁（时间，次数）
	Blink* b = Blink::create(2,4);
	//hero->runAction(b);

	// 取一个动作的反动作
	auto re = moveBy->reverse();
	//hero->runAction(re);
	// 并不是所有动作都有反动作(比如To,Blink)
	auto re2 = moveTo->reverse();
	//hero->runAction(re2);

	// 空动作（时间），组合使用
	DelayTime* dt = DelayTime::create(4);
	//hero->runAction(dt);

	auto mt1 = MoveTo::create(2,Vec2(800,320));
	auto mt2 = MoveTo::create(2,Vec2(480,320));
	auto dt2 = DelayTime::create(4);

	// 序列动作(动作...，NULL):按照添加的顺序执行多个动作
	auto seq = Sequence::create(mt1,dt2,mt2,NULL);
	//hero->runAction(seq);

	// 同步动作(动作...，NULL)，同时执行多个动作（不建议runAction多个动作，而使用Sequence,Spawn进行组合）
	auto scaleTo = ScaleTo::create(2,2);
	auto spaw = Spawn::create(mt1,scaleTo,NULL);
	//hero->runAction(seq);

	// 重复动作(动作,次数)
	auto rep = Repeat::create(RB,5);
	//hero->runAction(rep);

	//一直重复动作(动作)
	auto RF = RepeatForever::create(RB);
	//hero->runAction(RF);

	auto hero2 = Sprite::create("CloseSelected.png");
	hero2->setPosition(Vec2(480,500));
	this->addChild(hero2);

	// 改变动作对象（hero2->runAction() hero来运动）
	auto tar = TargetedAction::create(hero,rep);
	//hero2->runAction(tar);

	// 瞬时动作(回调函数动作)，只要是动作就能组合
	auto callfunc = CallFunc::create(CC_CALLBACK_0(Day_2::Func,this));
	auto seq2 = Sequence::create(mt1,callfunc,NULL);
	//hero->runAction(seq2);

	// 瞬时动作（带参数）
	auto callfuncN = CallFuncN::create(CC_CALLBACK_1(Day_2::Func2,this));
	auto seq3 = Sequence::create(mt1,callfuncN,NULL);
	hero->setTag(111);
	//hero->runAction(seq3);

	// 显示
	auto s = Show::create();
	// 隐藏
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

	//  移除自身动作
	auto remove = RemoveSelf::create();
	auto seq4 = Sequence::create(mt1,remove,NULL);
	//hero->runAction(seq4);

	// x轴翻转（true翻转 false恢复原来状态）
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

	// 位置动作(位置)
	auto p = Place::create(Vec2(60,60));
	// hero->runAction(p);

	//加速动作（动作，加速数）
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
	// 从Layer上移除子节点
	this->removeChild(h);
	log("%d",h->getTag());
}
