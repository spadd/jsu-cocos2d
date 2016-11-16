#include "cocos2d.h"
using namespace cocos2d;
class Day_2:public Layer
{
public:
	virtual bool init();
	static Scene* createScene();
	CREATE_FUNC(Day_2);

	Sprite* bg;
	Sprite* hero;

	void Click();

	void Func();

	void Func2(Ref* sender);
};