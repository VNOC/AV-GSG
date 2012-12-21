#pragma once

#include "ISprite.h"

class CSprite : public ISprite
{
public:
    //����λ��
    CSprite(int	x, int y);
    virtual ~CSprite(void);

    //ˢ��һ֡����
    static void FrameRender(HDC hDC);

    //ͳһ����֡����
    static void FrameUpdate();

public:
    //�жϾ����Ƿ�ɼ�
    virtual bool IsVisible();

    //��Ⱦ�������ƺ���
    virtual void Render(HDC hDC) = 0;

    //���¾��麯����λ�ã��Ƕȵ����ԣ�
    virtual void Update() = 0;

    //����Ϊ���úͻ�ȡλ�ú���
    int GetX(){ return m_nPosX; }
    int GetY(){ return m_nPosY; }
    void SetX(int x){ m_nPosX = x; }
    void SetY(int y){ m_nPosY = y; }

protected:
    int     m_nPosX;
    int     m_nPosY;
    int     m_nFrameStartX;     //��ǰ֡��ͼƬ��ʼ��ͼ��X����
    int     m_nSpeed;           //�����ٶ�
    int     m_nFrameCount;      //֡������һ���ӵ��м���ͼ��
    int     m_nCurrentFrame;
    int     m_nWidth;
    int     m_nHeight;
    float   m_fAngle;
    bool    m_bIsVisible;
    static CSprite* g_pHead;
    CSprite* pNext;
};

