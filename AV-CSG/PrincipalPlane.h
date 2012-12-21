#pragma once
/*
*	add by hels	2012-5-12
*	���طɻ��࣬��¼�������ṩ��Ⱦ��������ײ��⣬��¼�ӵ����͵�.���طɻ�ֻ��һ�ܣ�����ʹ�õ���ģʽ����
*/
#include "Sprite.h"
#include "Picture.h"

class CPrincipalPlane : public CSprite
{
public:
	//�������ɵ���
	static CPrincipalPlane * GetInstance();
	virtual ~CPrincipalPlane();

	//��ʼ���ɻ�������Ѫ���ĸ���
	void InitPlane();

	//��ײ���
	bool CheckCollision(int x, int y, int width, int height, int power);

	//��Ⱦ
	void Render(HDC hDC);

	//���¾��麯����λ�ã��Ƕȵ����ԣ�
	void Update();

	//���طɻ�ͼƬ��Ѫ��ͼƬ
	static void LoadBimap();
	static void FreeBitmap();

	BulletType GetBulletType(){ return m_nBulletType; }
	void SetBulletType(BulletType bulletType){ m_nBulletType = bulletType; }

	void SetAmmoCount(int nAmmoCount){ m_nAmmoCount = nAmmoCount ;}

	void Control(ActionType actionType);

    static bool GetGameOver() { return m_emGameStatus == emGameStatusOver; }
    static bool GetGameReady() { return m_emGameStatus == emGameStatusReady; }

    static void ClearGameStatus() { m_emGameStatus = emGameStatusNone; }
    static bool IsNeedUpdate() { return m_emGameStatus != emGameStatusNone; }
    static void StartGame() { m_emGameStatus = emGameStatusPlaying; }
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

