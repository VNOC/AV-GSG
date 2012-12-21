#pragma once

#include "IPlane.h"
#include "Picture.h"

///> �л���
class CEnemyPlane : public PlaneBase
{
public:
    CEnemyPlane(EnemyType enemyType);
    virtual ~CEnemyPlane(void);

    //��ײ���
    virtual bool CheckCollision(int x, int y, int width, int height, int power);

    static void CreateEnemy();

    //��Ⱦ
    virtual void Render(HDC hDC);

    //���¾��麯����λ�ã��Ƕȵ����ԣ�
    virtual void Update();

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
    float   m_fFireTime;
    int     m_nHP;
    EnemyType   m_nEnemyType;
};
