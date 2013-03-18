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
    float GetElapsedTime(){ return m_fElapsedTime;}

    //���̰�������
    void KeyDown(WPARAM nKeyCode);
    void KeyUp(WPARAM nKeyCode);

    void SetLastTime(DWORD lastTime) { m_dwLastTime = lastTime; }
    void SetCurrentTime(DWORD currentTime) { m_dwCurrentTime = currentTime; }

    void SetWndDC(HDC hDC);

    void StartGame();
    void PauseGame();
    void RecoveGame();

    bool IsPause();

    void Exit();
private:
    CGameControler(void);

    //��ͼѭ����ͼ
    void CirculationMap();

    void GameOver();
    void GameReady();

    static CGameControler* pGameControler;
    DWORD   m_dwLastTime;       //�ϴλ�ͼʱ��
    DWORD   m_dwCurrentTime;    //��ǰʱ��
    HDC     m_hMemDC;
    HBITMAP m_hBitmapMap;
    HBITMAP m_hMemBitmap;
    HDC     m_hWndDC;
    HDC     m_hMapDC; 
    int     m_nY;               //��¼��ͼ����ȡ�Ŀ��
    float   m_fElapsedTime;

    int     m_nPreKey;
    int     m_nCurKey;

    bool    m_IsPause;

    CSelfPlane *m_pSelfPlane;
};

