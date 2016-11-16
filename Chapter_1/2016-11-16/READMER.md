

##1.1移动动作（时间，绝对位置）

```
MoveTo* moveTo = MoveTo::create(5,Vec2(960,320));
```
##1.2移动动作（时间，相对位置）

```
MoveBy* moveTo = MoveBy::create(5,Vec2(960,320));
```
##1.3绝对位置旋转动作（时间，相对位置）

```
RotateTo* RT = RotateTo::create(3,90);
```
##1.4相对位置旋转动作（时间，可累加）

```
RotateBy* RB = RotateBy::create(3,90);
```
##1.5绝对放大(时间，倍数)
```
ScaleTo* ST = ScaleTo::create(1,2);
```
##1.6相对放大，可累加(时间，倍数)
```
ScaleTo* ST = ScaleTo::create(1,2);
```
##1.7绝对跳动（跳动时间，跳动的最终位置，跳动高度，次数）
```
JumpTo* JT = JumpTo::create(1,Vec2(480,320),25,2);
```
##1.8相对跳动，可累加（跳动时间，跳动的最终位置，跳动高度，次数)
```
JumpBy* JB = JumpBy::create(1,Vec2(50,0),25,2);
```
##1.9闪烁（时间，次数）
```
Blink* b = Blink::create(2,4);
```
##2.0取一个动作的反动作
```
auto re = moveBy->reverse();
// 并不是所有动作都有反动作(比如To,Blink)
auto re2 = moveTo->reverse();
```
##2.1空动作（时间），组合使用
```
DelayTime* dt = DelayTime::create(4);
```
##2.2序列动作(动作...，NULL):按照添加的顺序执行多个动作,不加NUll就崩溃
```
auto seq = Sequence::create(mt1,dt2,mt2,NULL);
```
##2.3同步动作(动作...，NULL):同时执行多个动作（不建议runAction多个动作，而使用Sequence,Spawn进行组合）
```
auto spaw = Spawn::create(mt1,scaleTo,NULL);
```
##2.4重复动作(动作,次数)
```
auto rep = Repeat::create(RB,5);
```
##2.5一直重复动作(动作)
```
auto RF = RepeatForever::create(RB);
```
##2.6改变动作对象（hero2->runAction() hero来运动）
```
auto hero2 = Sprite::create("CloseSelected.png");
hero2->setPosition(Vec2(480,500));
this->addChild(hero2);

// 改变动作对象（hero2->runAction() hero来运动）
auto tar = TargetedAction::create(hero,rep);
hero2->runAction(tar);
```
##2.7瞬时动作(回调函数动作)，只要是动作就能组合
```
auto callfunc = CallFunc::create(CC_CALLBACK_0(Day_2::Func,this));
auto seq2 = Sequence::create(mt1,callfunc,NULL);

// 回调函数
void Day_2::Func()
{
    log("sport  over");
}
```
##2.8瞬时动作(回调函数带参数)
```
auto callfuncN = CallFuncN::create(CC_CALLBACK_1(Day_2::Func2,this));
auto seq3 = Sequence::create(mt1,callfuncN,NULL);
hero->setTag(111);
hero->runAction(seq3);

// 带参数的回调函数
void Day_2::Func2(Ref* sender)
{
    Sprite* h = (Sprite*)sender;
    // 从Layer上移除子节点
    this->removeChild(h);
	log("%d",h->getTag());
}
```
##2.9显示隐藏动作
```
// 显示
auto s = Show::create();
// 隐藏
auto h = Hide::create();

static int i = 0;
i++;
if(i%2 == 1)
{
	hero->runAction(h);
}
else
{
	hero->runAction(s);
}
```
##3.0 移除自身动作
```
auto remove = RemoveSelf::create();
auto seq4 = Sequence::create(mt1,remove,NULL);
hero->runAction(seq4);
```
##3.1 x/y轴翻转（true翻转 false恢复原来状态）
```
auto f1 = FlipX::create(true);
auto f2 = FlipX::create(false);

auto fy1 = FlipY::create(true);
auto fy2 = FlipY::create(false);

if(i%2 == 1)
{
	hero->runAction(f1);
}
else
{
	hero->runAction(f2);
}
```
##3.2位置动作(位置),闪现
```
auto p = Place::create(Vec2(60,60));
```
##3.3加速动作（动作，加速数）
```
auto sp = Speed::create(mt1,10);
```
---
##4.让精灵运行动作
```
sprite->runAction(moveTo);
```