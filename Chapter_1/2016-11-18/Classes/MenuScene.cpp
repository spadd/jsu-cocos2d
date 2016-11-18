#include "MenuScene.h"
#include "Day_3.h"
Scene* MenuScene::createScene()
{
	Scene* scene = Scene::create();
	MenuScene* layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}


bool MenuScene::init()
{
	if(!Layer::init())
	{
		return false;
	}

	MenuItemFont* item = MenuItemFont::create("back");
	item->setColor(Color3B::GREEN);
	item->setPosition(Vec2(840,60));
	item->setCallback(CC_CALLBACK_0(MenuScene::Click,this));
	Menu* menu = Menu::create(item,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu);
	return true;
}

void MenuScene::Click()
{
	Director::getInstance()->replaceScene(Day_3::createScene());
}