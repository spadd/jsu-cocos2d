# 获取精灵帧
```
SpriteFrameCache* cache = SpriteFrameCache::getInstance();
// 从图片文件读取精灵帧放到缓存中
cache->addSpriteFramesWithFile("10001_walk.plist","10001_walk.png");
// 通过缓存中的精灵帧创建精灵（精灵帧名字plist）
Sprite* hero = Sprite::createWithSpriteFrameName("10001_walk_0000.png");
```
# 从精灵帧读取全部图片
```
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
```
# 创建精灵动画
```
// 创建动画（容器，间隔时间）
Animation* ani = Animation::createWithSpriteFrames(vector,0.2);
// 动画转化为动作
Animate* animate = Animate::create(ani);
// 重复动作
// Spawn和Sequence组合运动时，不可以有永久动作，必须为限时动作
auto RF = RepeatForever::create(animate);
hero->runAction(RF);
```
# 重写父类触摸方法
```
virtual bool onTouchBegan(Touch* touch,Event* unused_event);
virtual void onTouchMoved(Touch* touch,Event* unused_event);
virtual void onTouchEnded(Touch* touch,Event* unused_event);
virtual void onTouchCancelled(Touch* touch,Event* unused_event);
```
# 获取触摸事件并注册
```
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
```
# 获取触摸点
```
bool Day_3::onTouchBegan(Touch* touch,Event* unused_event)
{
Vec2 pos1 = touch->getLocation();  
auto pos2 = touch->getLocationInView();  
auto pos3 = Director::getInstance()->convertToUI(pos2);  
}
```
# 停止英雄的动作
```
Sprite* hero = (Sprite*)this->getChildByTag(111);
// 停止英雄的某一个动作tag值为110的值
hero->stopActionByTag(110);
// 停止英雄的所有动作
// hero->stopAllActions();
```
