#include "stdafx.h"
#include "PrincipalBigBullet.h"


CPrincipalBigBullet::CPrincipalBigBullet(int x, int y, BulletType bulletType, float angle)
    : CPrincipalBullet(x, y, bulletType, angle)
{
    m_nFrameStartY = 0;
}


CPrincipalBigBullet::~CPrincipalBigBullet(void)
{
}

void CPrincipalBigBullet::Update()
{
    int row = m_nCurrentFrame / 3;
    int col = m_nCurrentFrame % 3;
    m_nFrameStartX = col * 224 + col / 1;
    m_nFrameStartY = row * 320 + (row + 1) / 1;
    m_nCurrentFrame++;
    return;
}

bool CPrincipalBigBullet::IsVisible()
{
    if (m_nCurrentFrame > 11)
    {
        return false;
    }
    return true;
}

void CPrincipalBigBullet::Render(HDC hDC)
{
    CPicturePool::GetPicture(emPicTypeBullet)[m_nBulletType]->DrawBitmap(
        hDC,
        m_nPosX, m_nPosY,
        m_nWidth, m_nHeight,
        m_nFrameStartX, m_nFrameStartY);
}
