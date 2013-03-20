#include "StdAfx.h"
#include "EnemyPlane.h"
#include "SelfPlane.h"
#include "Explosion.h"
#include "EnemyGenerate.h"
#include "Score.h"

CEnemyPlane::CEnemyPlane(EnemyType enemyType, IEmitter* piEmitter, int nPosX /* = -1 */ )
    : PlaneBase(0, 0, piEmitter)
    , m_nEnemyType(enemyType)
{
    m_fFireTime = 0.0f;

    switch (m_nEnemyType)
    {
    case emEnemyTypeENEMY0:
        m_nWidth = 32;
        m_nHeight = 48;
        m_nHP = 4;
        m_nSpeed = 150;
        break;
    case emEnemyTypeENEMY1:
        m_nWidth = 32;
        m_nHeight = 48;
        m_nHP = 10;
        m_nSpeed = 100;
        break;
    case emEnemyTypeENEMY2:
        m_nWidth = 32;
        m_nHeight = 48;
        m_nHP = 10;
        m_nSpeed = 90;
        break;
    case emEnemyTypeENEMY3:
        m_nWidth = 32;
        m_nHeight = 48;
        m_nHP = 6;
        m_nSpeed = 80;
        break;
    case emEnemyTypeENEMY4:
        m_nWidth = 32;
        m_nHeight = 48;
        m_nHP = 8;
        m_nSpeed = 100;
        break;
    }

    if (nPosX == -1)
    {
        int nRandom = rand() % 100;
        if (nRandom == 0)
        {
            m_nPosX = 0;
        }
        else
        {
            m_nPosX = nRandom * SCREEN_WIDTH / 100 - m_nWidth / 2;
        }
    }
    else
    {
        m_nPosX = nPosX * SCREEN_WIDTH / 100 - m_nWidth / 2;
    }

    m_nPosY = -m_nHeight + 2; 
}

CEnemyPlane::CEnemyPlane() : PlaneBase(0, 0)
{

}

CEnemyPlane::~CEnemyPlane(void)
{
    CEnemyGenerate::ReleaseEnemy(this);
}

bool CEnemyPlane::IsVisible()
{
    if(m_nPosX < - m_nWidth	||
        m_nPosX > SCREEN_WIDTH + m_nWidth	||
        m_nPosY < -m_nHeight	||
        m_nPosY > SCREEN_HEIGHT + m_nHeight)
    {
        m_bIsVisible = false;
        return false;
    }
    return m_bIsVisible;
}

void CEnemyPlane::Update()
{
    m_nPosY += (int)(ElapsedTime * m_nSpeed);
    m_fFireTime += ElapsedTime;
    if (m_fFireTime > m_piEmitter->GetFireTimeMax())
    {
        m_fFireTime = 0.0f;
        m_piEmitter->Emit(m_nPosX + m_nWidth / 2 - 8,
            m_nPosY + m_nHeight,
            (BulletType)(m_nEnemyType % 4));
    }

    if (CSelfPlane::GetInstance()->CheckCollision(m_nPosX, m_nPosY, m_nWidth, m_nHeight, 20))
    {
        m_bIsVisible = false;
        new CExplosion(m_nPosX + m_nWidth / 2, m_nPosY + m_nHeight / 2, emBlastTypeBullet);
        return;
    }
}

void CEnemyPlane::Render(HDC hDC)
{
    CPicturePool::GetInstance()->GetPicture(emPicTypePlane)[m_nEnemyType]->DrawBitmap(
        hDC,
        m_nPosX, m_nPosY,
        m_nWidth, m_nHeight,
        m_nFrameStartX, 0);
}

bool CEnemyPlane::CheckCollision(int x, int y, int width, int height, int power)
{
    int Xa3 = m_nPosX + m_nWidth / 2;
    int Ya3 = m_nPosY + m_nHeight / 2;
    int Xb3 = x + width / 2;
    int Yb3 = y + height / 2;

    //����ͼƬ�ĳߴ����⣬��΢����
    if ( (abs( Xb3 - Xa3 ) + m_nWidth / 5) <= (m_nWidth + width)/2 &&
        ( abs( Yb3 - Ya3 ) + m_nHeight / 5) <= (m_nHeight + height)/2)
    {
        m_nHP -= power;
        if (m_nHP <= 0)
        {
            CScore::AddScore(m_nSpeed);
            m_bIsVisible = false;
            new CExplosion(m_nPosX + m_nWidth / 2, m_nPosY + m_nHeight / 2, emBlastTypePlane);
        }
        return true;
    }
    return false;
}
