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


