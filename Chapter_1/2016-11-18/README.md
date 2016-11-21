# 音乐播放 SimpleAudioEngine
```
// 播放音乐头文件
#include "SimpleAudioEngine.h"
// 音乐的命名空间
using namespace CocosDenshion;
void Day_3::PlayAudio()
{
	// 音乐管理对象
	auto simple  = SimpleAudioEngine::getInstance();
	// 播放音乐（名字，循环）
	simple->playBackgroundMusic("backMusic.mp3",true);
	// 设置音量（）
	simple->setBackgroundMusicVolume(10);
	// 暂停音乐
	simple->pauseBackgroundMusic();
	// 恢复音乐
	simple->resumeBackgroundMusic();
}
```
# 画板 DrawNode
```
// 创建一个画板对象
DrawNode* draw = DrawNode::create();

this->addChild(draw);
// 画点（位置，大小，颜色）
draw->drawPoint(Vec2(480,320),50,Color4F::RED);
// 画线（起点，终点，大小，颜色）
draw->drawSegment(Vec2(480,320),Vec2(480,500),10,Color4F::WHITE);
// 清空画板
draw->clear();
```
# 数组 Array
```
// 数组声明
__Array* monsterArray;
// 初始化
monsterArray = __Array::create();
// 析构
monsterArray->retain();
// 从数组中移除 2种方法
bulltArray->removeObjectAtIndex(i);
//bulltArray->removeObject(bullt);
```
# 碰撞矩形框检测
```
Sprite* bullt = (Sprite*)bulltArray->getObjectAtIndex(i);
// 子弹的矩形框
Rect bulltRect = bullt->getBoundingBox();
Sprite* monster = (Sprite*)monsterArray->getObjectAtIndex(j);
Rect mReact = monster->getBoundingBox();
// 判断2个矩形框是否重合
if(bulltRect.intersectsRect(mReact))
{
}
```
# 随机生成1-16（取余）
```
int i = 1+rand()%15;
```
# int转string
```
String* name = String::createWithFormat("boss_%d.png",i);
```
# 结束整个程序
```
return;
```