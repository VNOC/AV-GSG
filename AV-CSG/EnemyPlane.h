#pragma once
/*
*	add by hels	2012-5-13
*	�л��࣬��¼�������ṩ��Ⱦ��������ײ��⣬��¼�ӵ����͵ȡ�
*/
#include "IPlane.h"
#include "Picture.h"

class CEnemyPlane : public PlaneBase
{
public:
	CEnemyPlane(EnemyType enemyType);
	virtual ~CEnemyPlane(void);

	//��ײ���
	bool CheckCollision(int x, int y, int width, int height, int power);

	static void CreateEnemy();

	//��Ⱦ
	void Render(HDC hDC);

	//���¾��麯����λ�ã��Ƕȵ����ԣ�
	void Update();

	//���طɻ�ͼƬ
	static void LoadBimap();
	static void FreeBitmap();

	bool IsVisible();

	static CEnemyPlane *spEnemyHead;
	CEnemyPlane * m_pEmnemyNext;

private:
	static CPicture * spPictureEnemy[6];
	static int snEnemyCount;
	static float sfLastCreateTime;
	float	m_fFireTime;
	int		m_nHP;
	EnemyType	m_nEnemyType;
};

