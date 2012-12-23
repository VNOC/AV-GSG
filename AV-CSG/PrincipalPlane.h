#pragma once

#include "IPlane.h"
#include "Picture.h"

///> ���طɻ���
class CPrincipalPlane : public PlaneBase
{
public:
    static CPrincipalPlane * GetInstance();
    virtual ~CPrincipalPlane();

    void InitGame();

    virtual bool CheckCollision(int x, int y, int width, int height, int power);
    virtual void Render(HDC hDC);
    virtual void Update();

    void SetBulletType(BulletType bulletType);

    void Control(ActionType actionType);

private:
    CPrincipalPlane(int x, int y);
    void InitPlane();

private:
    static CPrincipalPlane*     pCPrincipalPlane;
    BulletType                  m_nBulletType;
    int                         m_nLife;
    float                       m_fBulletFrequency;
    float                       m_fInvincibletime;  //�޵�ʱ��(��λ��)
    float                       m_fFrequencyTime;   //���������ӵ�ʱ��(��)
    bool                        m_bUnDead;
    bool                        m_bIsStopMove;
    bool                        m_bFire;
    int                         m_nWholeFired;      //ȫը����
    ActionType                  m_nAction;
};
