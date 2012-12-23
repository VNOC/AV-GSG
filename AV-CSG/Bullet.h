#pragma once
#include "Sprite.h"

///> �ӵ����࣬����Ϊ�ҷ��ӵ��͵з��ӵ�
class CBullet : public CSprite
{
public:
    CBullet(
        int x, int y,
        bool bFriend,
        int nPower,
        int nSpeed,
        BulletType bulletType,
        float fAngle);
    virtual ~CBullet(void);

    virtual bool IsVisible();
    virtual void Render(HDC hDC);
    virtual void Update();
protected:
    int                 m_nPower;           //����
    BulletType          m_nBulletType;      //�ӵ�����
    bool                m_bFriend;          //����
    int                 m_nSpeed;           //�ӵ��ٶ�
    float               m_fAngle;           //�Ƕ�
};

