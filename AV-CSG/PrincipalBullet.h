#pragma once

#include "Bullet.h"

///> �ҷ��ɻ��ӵ�
class CPrincipalBullet : public CBullet
{
public:
    CPrincipalBullet(int x, int y, BulletType bulletType, float angle);
    virtual ~CPrincipalBullet(void);

    void Render(HDC hDC);
    void Update();

    bool IsVisible();
private:
    int m_nFrameStartY;
};

