#pragma once

class CSelfPlane;

///> ��Ϸ�������࣬����������Ϸ�����й��̣��ṩ��Ϣ�Ա���¸�����
class CGameControler
{
public:
    static CGameControler* GetInstance();
    ~CGameControler(void);

    //������Ϸ����
    void UpdateScence();

    //��ȡʱ����
    float GetElapsedTime();

    //���̰�������
    void KeyDown(WPARAM nKeyCode);
    void KeyUp(WPARAM nKeyCode);

    void SetWndDC(HDC hDC);

    void StartGame();

    void Exit();
private:
    CGameControler(void);

    //��ͼѭ����ͼ
    void CirculationMap();

    void GameOver();
    void GameReady();

    static CGameControler* pGameControler;
    DWORD   m_dwLastTime;       //�ϴλ�ͼʱ��
    HDC     m_hMemDC;
    HBITMAP m_hBitmapMap;
    HBITMAP m_hMemBitmap;
    HDC     m_hWndDC;
    HDC     m_hMapDC; 
    int     m_nY;               //��¼��ͼ����ȡ�Ŀ��

    int     m_nPreKey;
    int     m_nCurKey;

    CSelfPlane *m_pSelfPlane;
};

