#pragma once

#include "IPlane.h"

///> ���طɻ���
class CSelfPlane : public PlaneBase
{
public:
    static CSelfPlane * GetInstance();
    virtual ~CSelfPlane();

    void InitGame();

    virtual bool CheckCollision(int x, int y, int width, int height, int power);
    virtual void Render(HDC hDC);
    virtual void Update();

    void SetBulletType(BulletType bulletType);

    void Control(ActionType actionType);

private:
    CSelfPlane(int x, int y);
    void InitPlane();

private:
    static CSelfPlane*     pCSelfPlane;
    BulletType                  m_nBulletType;
    int                         m_nLifes;
    float                       m_fBulletFrequency;
    float                       m_fInvincibletime;  //�޵�ʱ��(��λ��)
    float                       m_fFrequencyTime;   //���������ӵ�ʱ��(��)
    bool                        m_bUnDead;
    bool                        m_bIsStopMove;
    bool                        m_bFire;
    int                         m_nWholeFired;      //ȫը����
    ActionType                  m_nAction;
};
