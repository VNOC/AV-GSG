#pragma once
/*
*	add by hels 2012-5-12
*	�����ӵ��ࣨ�з��ӵ���,ʵ���ӵ��߼��Լ���ʾ��
*/

#include "Bullet.h"

class CEnemyBullet : public CBullet
{
public:
	CEnemyBullet(int x, int y, BulletType bulletType, float angle);
	virtual ~CEnemyBullet(void);

	//��Ⱦ
	void Render(HDC hDC);

	//���¾��麯����λ�ã��Ƕȵ����ԣ�
	void Update();

	bool IsVisible();
};

