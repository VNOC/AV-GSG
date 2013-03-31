#pragma once

#include "control/xml_parser/StageXMLParser.h"
#include "control/xml_parser/PlaneXMLParser.h"
#include "control/stage_player/GameStagePlayer.h"

class CSelfPlane;

///> ��Ϸ�������࣬����������Ϸ�����й��̣��ṩ��Ϣ�Ա���¸�����
class CGameControler
{
public:
    CGameControler();
    ~CGameControler();

    //������Ϸ����
    void UpdateScence();

    void SetWndDC(HDC hDC);
    void SetStageXML(const std::string& strPath);
    void SetPlaneXML(const std::string& strPath);
    void SetBulletXML(const std::string& strPath);

    void StartGame();

    void Exit();
private:
    //��ͼѭ����ͼ
    void CirculationMap();

    void GameOver();
    void GameReady();

    DWORD   m_dwLastTime;       //�ϴλ�ͼʱ��
    HBITMAP m_hBitmapMap;
    HBITMAP m_hMemBitmap;
    HDC     m_hMapDC; 
    int     m_nY;               //��¼��ͼ����ȡ�Ŀ��

    int     m_nPreKey;
    int     m_nCurKey;

    int     m_PresentStage;

    CSelfPlane *m_pSelfPlane;
};

