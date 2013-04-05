#include "stdafx.h"
#include "GameScene_Menu.h"
#include "control\stage_player\GameStagePlayer.h"
#include "GameScene_Play.h"
#include "control\generate\EnemyGenerate.h"
#include "gameobject\plane\SelfPlane.h"
#include "control\xml_parser\PlaneXMLParser.h"

GameScene_Menu::GameScene_Menu(CMenuBase* pMenu)
    : m_pMenu(pMenu)
    , m_PictureBackgroud(NULL)
{
    m_PictureBackgroud = CPicturePool::GetInstance()->GetPicture(pMenu->GetBackgroudImage());
    ///> Ĭ��ָ��˵���һ��
    m_nCurPos   = 0;
}

GameScene_Menu::~GameScene_Menu()
{

}

void GameScene_Menu::Update()
{
    ///> �ݶ�Ϊ���ϵ���һ�в˵�
    ///> �̽��� �ϡ��¡�ȷ������������������Ϣ
    if (InputEngine_->ClickUp())
    {
        Up();
    }
    else if (InputEngine_->ClickDown())
    {
        Down();
    }
    else if (InputEngine_->ClickOk())
    {
        Click();
    }
}

void GameScene_Menu::Output()
{
    ///> �Ȼ������������Ҫ�Ļ���
    if (m_PictureBackgroud)
    {
        m_PictureBackgroud->ImmediateDrawBitmap(g_hWndDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    }

    ///> �ٻ����в˵����������Ļ����ҳ/������������

    ///> ��������ǰ������ڲ˵���
}

void GameScene_Menu::Up()
{
    if (m_nCurPos > 0)
    {
        m_nCurPos--;
    }
}

void GameScene_Menu::Down()
{
    if (m_pMenu && m_nCurPos < m_pMenu->GetMenuSize() - 1)
    {
        m_nCurPos++;
    }
}

void GameScene_Menu::Click()
{
    if (m_pMenu && m_nCurPos < m_pMenu->GetMenuSize())
    {
        m_pMenu->OnClick(m_nCurPos);
    }
}
