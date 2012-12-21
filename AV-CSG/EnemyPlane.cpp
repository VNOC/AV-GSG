#include "StdAfx.h"
#include "EnemyPlane.h"
#include "GameControler.h"
#include "PrincipalPlane.h"
#include "Explosion.h"
#include "Bullet.h"

float CEnemyPlane::sfLastCreateTime = 0.0;
int CEnemyPlane::snEnemyCount = 0;
CEnemyPlane * CEnemyPlane::spEnemyHead = NULL;

CEnemyPlane::CEnemyPlane(EnemyType enemyType)
    : PlaneBase(0, 0)
    , m_nEnemyType(enemyType)
{
    int nRandom = rand() % 5;//�����0-2�����ķɻ�����Ļ�Ϸ������ҳ���
    //5������л����·�����
    m_fFireTime = 1.0f;

    if (snEnemyCount < 10)
    {
        snEnemyCount++;
    }

    switch (m_nEnemyType)
    {
    case emEnemyTypeENEMY0:
        m_nWidth = 43;
        m_nHeight = 36;
        m_nHP = 4;
        m_nSpeed = 150;
        break;
    case emEnemyTypeENEMY1:
        m_nWidth = 76;
        m_nHeight = 94;
        m_nHP = 10;
        m_nSpeed = 100;
        break;
    case emEnemyTypeENEMY2:
        m_nWidth = 93;
        m_nHeight = 85;
        m_nHP = 10;
        m_nSpeed = 90;
        break;
    case emEnemyTypeENEMY3:
        m_nWidth = 100;
        m_nHeight = 47;
        m_nHP = 6;
        m_nSpeed = 80;
        break;
    case emEnemyTypeENEMY4:
        m_nWidth = 45;
        m_nHeight = 43;
        m_nHP = 8;
        m_nSpeed = 100;
        break;
    }

    if (nRandom == 0)
    {
        m_nPosX = 0;
    }
    else
    {
        m_nPosX = nRandom * SCREEN_WIDTH/5 - m_nWidth / 2;
    }
    m_nPosY = -m_nHeight + 2; 

    m_pEmnemyNext = spEnemyHead;
    spEnemyHead  = this;
}


CEnemyPlane::~CEnemyPlane(void)
{
    snEnemyCount--;
    if (spEnemyHead == this)
    {
        spEnemyHead = this->m_pEmnemyNext;
    }
    else
    {
        CEnemyPlane* temp = spEnemyHead;
        for(;temp->m_pEmnemyNext!=NULL;temp=temp->m_pEmnemyNext)
        {
            if(temp->m_pEmnemyNext==this)
            {
                temp->m_pEmnemyNext = this->m_pEmnemyNext;
                return;
            }
        }
    }
}

void CEnemyPlane::CreateEnemy()
{
    float tD = CGameControler::GetInstance()->GetElapsedTime();
    sfLastCreateTime += tD;
    if (sfLastCreateTime > 0.3f)//0.5�����һ�ܵл�
    {
        if (snEnemyCount < 10)
        {
            new CEnemyPlane((EnemyType)(snEnemyCount % 5));
        }
        sfLastCreateTime -= 0.5f;
    }
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
    float tD = CGameControler::GetInstance()->GetElapsedTime();
    float fDis = tD * m_nSpeed;

    m_nPosY += (int)fDis;

    m_fFireTime -= tD;
    if (m_fFireTime <= 0.0f)
    {
        m_fFireTime = 1.0f;
        new CBullet(
            m_nPosX + m_nWidth / 2 - 8, m_nPosY + m_nHeight,
            false, 5, 220,
            (BulletType)(m_nEnemyType % 4), 17.0 * PI / 36.0);
    }

    if (CPrincipalPlane::GetInstance()->CheckCollision(m_nPosX, m_nPosY, m_nWidth, m_nHeight, 20))
    {
        m_bIsVisible = false;
        new CExplosion(m_nPosX + m_nWidth / 2, m_nPosY + m_nHeight / 2, emBlastTypeBullet);
        return;
    }
}

void CEnemyPlane::Render(HDC hDC)
{
    CPicturePool::GetPicture(emPicTypePlane)[m_nEnemyType]->DrawBitmap(
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
            m_bIsVisible = false;
            new CExplosion(m_nPosX + m_nWidth / 2, m_nPosY + m_nHeight / 2, emBlastTypePlane);
        }
        return true;
    }
    return false;
}
