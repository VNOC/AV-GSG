#pragma once

#include "IPlane.h"
#include "Picture.h"

///> ���طɻ���
class CPrincipalPlane : public PlaneBase
{
public:
    //�������ɵ���
    static CPrincipalPlane * GetInstance();
    virtual ~CPrincipalPlane();

    //��ʼ���ɻ�������Ѫ���ĸ���
    void InitPlane();

    //��ײ���
    virtual bool CheckCollision(int x, int y, int width, int height, int power);

    //��Ⱦ
    virtual void Render(HDC hDC);

    //���¾��麯����λ�ã��Ƕȵ����ԣ�
    virtual void Update();

    //���طɻ�ͼƬ��Ѫ��ͼƬ
    static void LoadBimap();
    static void FreeBitmap();

    BulletType GetBulletType(){ return m_nBulletType; }
    void SetBulletType(BulletType bulletType)
    {
        m_nBulletType = bulletType;
        if (m_nBulletType == emBulletTypeAMMO5 || m_nBulletType == emBulletTypeAMMO6)
        {
            SetAmmoCount(3);
        }
        if (m_nBulletType == emBulletTypeAmmoSB)
        {
            SetAmmoCount(5);
        }
    }

    void SetAmmoCount(int nAmmoCount){ m_nAmmoCount = nAmmoCount ;}

    void Control(ActionType actionType);

    static bool GetGameOver() { return m_emGameStatus == emGameStatusOver; }
    static bool GetGameReady() { return m_emGameStatus == emGameStatusReady; }
    static bool GetGameRuning() { return m_emGameStatus == emGameStatusRuning; }

    static void ClearGameStatus() { m_emGameStatus = emGameStatusNone; }
    static bool IsNeedUpdate() { return m_emGameStatus != emGameStatusNone; }
    static void StartGame() { m_emGameStatus = emGameStatusRuning; }
private:
    CPrincipalPlane(int x, int y);

    static CPrincipalPlane*     pCPrincipalPlane;
    static CPicture*            pPicturePlane;      //�ɻ�ͼƬ
    static CPicture*            pPictureLife;       //����ͼƬ
    static CPicture*            pPictureHP;
    static CPicture*            pPictureHPSide;
    BulletType                  m_nBulletType;
    int                         m_nHP;
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
    static GameStatus           m_emGameStatus;
};
