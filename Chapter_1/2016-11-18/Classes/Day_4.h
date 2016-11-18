#include "cocos2d.h"
using namespace cocos2d;

class Day_4:public Layer{
public :
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Day_4);

	virtual bool onTouchBegan(Touch* touch,Event* unused_event);
	virtual void onTouchMoved(Touch* touch,Event* unused_event);
	virtual void onTouchEnded(Touch* touch,Event* unused_event);

	Sprite* hero;

	void BulltAnimation(float f);
	void BulltRemove(Ref* s);
	void MosterRemove(Ref* s);

	void MosterUpdate(float f);

};