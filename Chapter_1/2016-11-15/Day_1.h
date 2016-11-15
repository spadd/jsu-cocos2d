// 包含Cocos2d头文件
#include "cocos2d.h"
// cocos2d的命名空间
using namespace std;
using namespace cocos2d;
class Day_1 : public Layer
{
public:
	// 创建一个静态成员函数（返回一个场景）
	static Scene* createScene();

	// 重写父类的成员函数（构造）
	virtual bool init();

	//(宏定义)静态的成员函数（创建当前类的对象）
	// Day_1::create(); 创建Day_1的对象
	CREATE_FUNC(Day_1);

	// 点击事件
	void Click();

	// 定时器
	void callfunc(float d);

	// 计数变量
	int i;

	// 创建进度条方法
	void func_progress();
	// 进度条计时器
	void moveProgress(float d);
	// 全局进度条
	ProgressTimer* progress;
};