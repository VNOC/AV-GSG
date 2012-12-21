#include "stdafx.h"
#include "GameFrame.h"

ISprite * g_pHead = NULL;

CGameFrame::CGameFrame(void)
{
}


CGameFrame::~CGameFrame(void)
{
}

void CGameFrame::FrameRender(HDC hDC)
{
    ISprite* pTemp = g_pHead;
    for( ; pTemp!=NULL; pTemp=pTemp->pNext )
    {
        pTemp->Render(hDC);
    }
}

void CGameFrame::FrameUpdate()
{
    //ѭ����������ÿһ��ͼ��
    ISprite *pTemp = g_pHead;
    for ( ; pTemp != NULL; )
    {
        if (!pTemp->IsVisible())
        {
            //���ɼ���ɾ��������������
            ISprite *p = pTemp;
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