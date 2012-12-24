#pragma once

#include "IPlane.h"

///> �л���
class CEnemyPlane : public PlaneBase
{
public:
    CEnemyPlane(EnemyType enemyType, int nPosX = -1);
    virtual ~CEnemyPlane(void);

    //��ײ���
    virtual bool CheckCollision(int x, int y, int width, int height, int power);

    virtual void Render(HDC hDC);
    virtual void Update();
    virtual bool IsVisible();

    CEnemyPlane * m_pEmnemyNext;

private:
    float   m_fFireTime;
    EnemyType   m_nEnemyType;
};
