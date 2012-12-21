#include "StdAfx.h"
#include "Bullet.h"

CBullet::CBullet(int x, int y)
    : CSprite(x, y)
{

}

CBullet::~CBullet(void)
{

}

bool CBullet::IsVisible()
{
    if(m_bIsVisible == false)
    {
        return m_bIsVisible;
    }
    if (m_nPosX < -50               ||
        m_nPosY < -50               ||
        m_nPosX > SCREEN_WIDTH + 50 ||
        m_nPosY > SCREEN_HEIGHT + 50)
    {
        return false;
    }
    return true;
}
