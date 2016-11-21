#include "cocos2d.h"
using namespace cocos2d;

class StartScene:public Layer
{
public:
	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(StartScene);

	Size WinSize;

	void menuClick();

	MenuItemToggle* toggle;
	void soundClick();
};