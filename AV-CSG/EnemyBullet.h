#pragma once

#include "Bullet.h"

///> �з��ӵ�
class CEnemyBullet : public CBullet
{
public:
    CEnemyBullet(int x, int y, BulletType bulletType, float angle);
    virtual ~CEnemyBullet(void);

    void Update();
};
