#include "cocos2d.h"
using namespace cocos2d;

class Day_3:public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Day_3);
	void SpriteAnimation();
	
	void Click();
	// ÖØÐ´¸¸ÀàµÄ´¥Ãþº¯Êý
	virtual bool onTouchBegan(Touch* touch,Event* unused_event);
	virtual void onTouchMoved(Touch* touch,Event* unused_event);
	virtual void onTouchEnded(Touch* touch,Event* unused_event);
	virtual void onTouchCancelled(Touch* touch,Event* unused_event);

	void DrawNodeFunc();

	// »­°å
	DrawNode* d;

	void PlayAudio();
};