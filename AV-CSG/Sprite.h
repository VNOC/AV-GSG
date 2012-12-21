#pragma once
/*
*	add by hels	2012-5-10
*	�����ڳ����л��д�С��λ�á���Ҫ���л��ƣ���ײ��⣬��Ҫ֪���Ƿ�ɼ����Ƿ���Ļ���ˣ��ȵȡ�
*	����ῼ�ǽ����еľ����������ͳһ��static void FrameRender��������ˢ�£�����˵��������Ǿ������ꡣ
*	��������ǻ��࣬��ô��Щ����Ĺ��ܾ���Ҫ��������ȥʵ��һ��ʼ������ò�ȫ���������Բ���ӿ�
*/

#define PI	3.141592653f

//�����ӵ�����
enum BulletType
{
	AMMO0 = 0,
	AMMO1,
	AMMO2,
	AMMO3,
	AMMO4,
	AMMO5,
	AMMO6,
	WHOLEFRIED
};

//���嶯������
enum ActionType
{
	LEFT,
	DOWN,
	RIGHT,
	UP,
	LEFT_UP,
	LEFT_DOWN,
	RIGHT_UP,
	RIGHT_DOWN,
	STOP_MOVE,
	FIRE,
	STOP_FIRE,
	FIREALL
};

//�л�����
enum EnemyType
{
	ENEMY0 = 0,
	ENEMY1,
	ENEMY2,
	ENEMY3,
	ENEMY4
};

//��ըЧ������
enum BlastType
{
	BULLETBLAST,
	PLANEBLAST
};

class CSprite
{
public:
	//����λ�ã�����ΪͼƬ���Ͻ�
	CSprite(int	x, int y);
	virtual ~CSprite(void);

	//ˢ��һ֡����
	static void FrameRender(HDC hDC);

	//ͳһ����֡����
	static void FrameUpdate();
	
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
	int	m_nPosX;
	int m_nPosY;
	int m_nFrameStartX;//��ǰ֡��ͼƬ��ʼ��ͼ��X����
	int	m_nSpeed;//�����ٶ�
	int m_nFrameCount;//֡������һ���ӵ��м���ͼ��
	int m_nCurrentFrame;
	int	m_nWidth;
	int m_nHeight;
	float m_fAngle;
	bool	m_bIsVisible;
	static CSprite *pHead;
	CSprite *pNext;
};

