#include "StdAfx.h"
#include "Sprite.h"

CSprite * CSprite::g_pHead = NULL;

CSprite::CSprite(int x, int y):
    m_nPosX(x),
    m_nPosY(y),
    m_bIsVisible(true)
{
    this->pNext = g_pHead;
    g_pHead = this;
}


CSprite::~CSprite(void)
{
    //����ӻ�����ɾ��ʱ����Ҫ��������
    //��ɾ���ľ����Ǳ�ͷ����ʱ
    if (g_pHead == this)
    {
        g_pHead = pNext;
        return;
    }
    //��ɾ���ľ��鲻�Ǳ�ͷ����ʱ
    CSprite* pTemp = g_pHead;
    for ( ; pTemp->pNext != NULL; pTemp = pTemp->pNext )
    {
        if (pTemp->pNext == this)
        {
            pTemp->pNext = this->pNext;
            return;
        }
    }
}

bool CSprite::IsVisible()
{
    if(false == m_bIsVisible)
    {
        return m_bIsVisible;
    }
    //�����ɼ�����
    if(m_nPosX < - m_nWidth     ||
        m_nPosY < - m_nHeight   ||
        m_nPosX > SCREEN_WIDTH  ||
        m_nPosY > SCREEN_HEIGHT)
    {
        return false;
    }

    return true;
}

void CSprite::FrameRender(HDC hDC)
{
    CSprite* pTemp = g_pHead;
    for( ; pTemp!=NULL; pTemp=pTemp->pNext )
    {
        pTemp->Render(hDC);
    }
}

void CSprite::FrameUpdate()
{
    //ѭ����������ÿһ��ͼ��
    CSprite *pTemp = g_pHead;
    for ( ; pTemp != NULL; )
    {
        if (!pTemp->IsVisible())
        {
            //���ɼ���ɾ��������������
            CSprite *p = pTemp;
            p = p->pNext;
            delete pTemp;
            pTemp = p;
        } 
        else
        {
            pTemp->Update();
            pTemp = pTemp->pNext;
        }
    }
}