#pragma once
#include "Sprite.h"
#include "Picture.h"

/*
*	add by hels	2012-5-11
*	����ӵ����࣬����Ϊ�ҷ��ӵ��͵з��ӵ����ӵ���Ҫ���������ͺ���Ϊ�������õ���һ��������
*	��������ǲο����˵���ƣ�Ԥ�Ƚ������ӵ�ͼƬȫ�������������������뵽������1.����Ӵ����м���ͼƬ���ڴ�������Ǻ�ʱ�ģ�
*	�������ǰ���ػ᷽��ܶࡣ2.�ӵ�ͼƬ����С��һֱ�������ڴ��п��Խ���
*/

class CBullet : public CSprite
{
public:
	CBullet(int x, int y);
	virtual ~CBullet(void);

	//��Ⱦ
	virtual void Render(HDC hdc) = 0;

	//���¾��麯����λ�ã��Ƕȵ����ԣ�
	virtual void Update() = 0;

	static void LoadBullet();
	static void FreeBullet();
protected:
	int					m_nPower;//����
	BulletType			m_nBulletType;
	static CPicture *	m_pPictureAmmo[8];
};

