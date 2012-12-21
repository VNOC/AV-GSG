#pragma once
/*
*	add by hels 2012-5-12
*	�����ӵ��ࣨ�ҷ��ɻ��ӵ���,ʵ���ӵ��߼��Լ���ʾ��
*/

#include "Bullet.h"

class CPrincipalBullet : public CBullet
{
public:
	CPrincipalBullet(int x, int y, BulletType bulletType, float angle);
	virtual ~CPrincipalBullet(void);

	//��Ⱦ
	void Render(HDC hDC);

	//���¾��麯����λ�ã��Ƕȵ����ԣ�
	void Update();

	bool IsVisible();
private:
	int m_nFrameStartY;
};

