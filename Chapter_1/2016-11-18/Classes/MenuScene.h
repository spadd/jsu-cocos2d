#include "cocos2d.h"
using namespace cocos2d;

class MenuScene:public Layer
{
public:
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(MenuScene);
	void Click();
};