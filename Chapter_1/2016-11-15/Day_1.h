// ����Cocos2dͷ�ļ�
#include "cocos2d.h"
// cocos2d�������ռ�
using namespace std;
using namespace cocos2d;
class Day_1 : public Layer
{
public:
	// ����һ����̬��Ա����������һ��������
	static Scene* createScene();

	// ��д����ĳ�Ա���������죩
	virtual bool init();

	//(�궨��)��̬�ĳ�Ա������������ǰ��Ķ���
	// Day_1::create(); ����Day_1�Ķ���
	CREATE_FUNC(Day_1);

	// ����¼�
	void Click();

	// ��ʱ��
	void callfunc(float d);

	// ��������
	int i;

	// ��������������
	void func_progress();
	// ��������ʱ��
	void moveProgress(float d);
	// ȫ�ֽ�����
	ProgressTimer* progress;
};