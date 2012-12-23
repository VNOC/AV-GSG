#pragma once

#include "IPlane.h"
#include "Picture.h"

///> ���طɻ���
class CPrincipalPlane : public PlaneBase
{
public:
    static CPrincipalPlane * GetInstance();
    virtual ~CPrincipalPlane();

    void InitPlane();

    virtual bool CheckCollision(int x, int y, int width, int height, int power);
    virtual void Render(HDC hDC);
    virtual void Update();

    void SetBulletType(BulletType bulletType);
    void SetAmmoCount(int nAmmoCount);

    void Control(ActionType actionType);
private:
    CPrincipalPlane(int x, int y);

    static CPrincipalPlane*     pCPrincipalPlane;
    BulletType                  m_nBulletType;
    int                         m_nLife;
    float                       m_fBulletFrequency;
    float                       m_fInvincibletime;  //�޵�ʱ��(��λ��)
    int                         m_nAmmoCount;       //ÿ�η����ӵ�����
    float                       m_fFrequencyTime;   //���������ӵ�ʱ��(��)
    bool                        m_bUnDead;
    bool                        m_bIsStopMove;
    bool                        m_bFire;
    int                         m_nWholeFired;      //ȫը����
    ActionType                  m_nAction;
};
