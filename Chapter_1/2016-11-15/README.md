# 学习的模块如下
##图片菜单
```
MenuItemImage* item = MenuItemImage::create("CloseNormal.png","CloseSelected.png");
item->setPosition(Vec2(720,60));
item->setCallback(CC_CALLBACK_0(Day_1::Click,this));
Menu* menu = Menu::create(item,NULL);
menu->setPosition(Vec2(0,0));
this->addChild(menu);
```
##文字菜单组
```
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
```
##定时器（构造方法一定带参数）
```
// 头文件声明，定时器
void callfunc(float d);
// 每1秒调用一次定时器,调用5次，延时3秒
schedule(CC_CALLBACK_1(Day_1::callfunc,this),1,5,3,"callfunc");
unschedule("callfunc");
```
##进度条
```
Sprite* sprite = Sprite::create("HelloWorld.png");

// 通过精灵创建一个进度条
progress  = ProgressTimer::create(sprite);
// 设置进度条类型为条形进度条
//progress->setType(ProgressTimer::Type::BAR);
// 设置进度条类型为圆形进度条
progress->setType(ProgressTimer::Type::RADIAL);
// 缩小0.2倍(大于1是放大，小于1是缩小)
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
```
##Label
```
Label* lab = Label::createWithSystemFont("aaaaa","",22);
```

