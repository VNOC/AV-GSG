#pragma once
#include "Sprite.h"
#include "Picture.h"

///> �ӵ����࣬����Ϊ�ҷ��ӵ��͵з��ӵ�
class CBullet : public CSprite
{
public:
    CBullet(int x, int y);
    virtual ~CBullet(void);

protected:
    int                 m_nPower;           //����
    BulletType          m_nBulletType;      //�ӵ�����
};

