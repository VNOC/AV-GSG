#pragma once

#include "StageXMLParser.h"

class CSelfPlane;

///> ��Ϸ�������࣬����������Ϸ�����й��̣��ṩ��Ϣ�Ա���¸�����
class CGameControler
{
public:
    static CGameControler* GetInstance();
    ~CGameControler(void);

    //������Ϸ����
    void UpdateScence();

    //���̰�������
    void KeyDown(WPARAM nKeyCode);
    void KeyUp(WPARAM nKeyCode);

    void SetWndDC(HDC hDC);
    void SetStageXML(const std::string& strPath);

    void StartGame();
    void PauseGame();
    void RecoveGame();

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

    int     m_PresentStage;

    CSelfPlane *m_pSelfPlane;
};

