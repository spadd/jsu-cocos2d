# 获取当前屏幕的尺寸
```
// 头文件声明
Size WinSize;
// cpp文件
WinSize = Director::getInstance()->getVisibleSize();
// 宽高
WinSize.width
WinSize.height
```
# 循环播放背景音乐
```
// 头文件和命名空间
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
// 循环播放背景音乐
SimpleAudioEngine::getInstance()->playBackgroundMusic("backMusic.mp3",true);
// 暂停
SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
// 继续
SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
```
# 菜单选择器
```
// 头文件全局声明
MenuItemToggle* toggle;
void soundClick();
// 代码
MenuItemImage* itemSoundOn = MenuItemImage::create("soundController.png","soundController2.png");
MenuItemImage* itemSoundOFF = MenuItemImage::create("soundController2.png","soundController1.png");
toggle = MenuItemToggle::createWithCallback(CC_CALLBACK_0(StartScene::soundClick,this),itemSoundOn,itemSoundOFF,NULL);
toggle->setPosition(Vec2(Vec2(WinSize.width-40,40)));
Menu* menu2 = Menu::create(toggle,NULL);
menu2->setPosition(Vec2::ZERO);
// 回调
void StartScene::soundClick()
{
	
	if(toggle->getSelectedIndex() == 0)
	{
		// 恢复播放背景音乐
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
		log("sound on");
	}
	else
	{
		// 暂停播放背景音乐
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		log("sound off");
	}
	
}
```

