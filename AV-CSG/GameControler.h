#pragma once
/*
*	add by hels	2012-5-12
*	��Ϸ�������࣬����������Ϸ�����й��̣��ṩ��Ϣ�Ա���¸����顣Ҳ��һ������ģʽ
*/

class CPrincipalPlane;

class CGameControler
{
public:
	static CGameControler * GetInstance();
	~CGameControler(void);

	//������Ϸ����
	void UpdateScence();
	
	//��ȡʱ����
	float GetElapsedTime(){ return m_fElapsedTime;}

	//���̰�������
	void KeyDown(WPARAM nKeyCode);
	void KeyUp(WPARAM nKeyCode);

	void SetLastTime(DWORD lastTime){ m_dwLastTime = lastTime; }
	void SetCurrentTime(DWORD currentTime){ m_dwCurrentTime = currentTime; }

	void SetWndDC(HDC hDC);

	void StartGame();

	void GameOver();

	void Exit();
private:
	CGameControler(void);

	//��ͼѭ����ͼ
	void CirculationMap();

	static CGameControler * pGameControler;
	DWORD m_dwLastTime;//�ϴλ�ͼʱ��
	DWORD m_dwCurrentTime;//��ǰʱ��
	HDC	  m_hMemDC;
	HBITMAP	m_hBitmapMap;
	HBITMAP m_hMemBitmap;
	HDC		m_hWndDC;
	HDC		m_hMapDC; 
	int		m_nY; //��¼��ͼ����ȡ�Ŀ��
	float	m_fElapsedTime;

	int		m_nPreKey;
	int		m_nCurKey;

	CPrincipalPlane *m_pPrincipalPlane;
};

