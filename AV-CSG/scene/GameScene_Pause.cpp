#include "stdafx.h"
#include "GameScene_Pause.h"
#include "control\game\GameFrame.h"

GameScene_Parse::GameScene_Parse()
{

}

GameScene_Parse::~GameScene_Parse()
{

}

void GameScene_Parse::Update()
{
    ///> ��ͣ����ֻ����ȡ����ͣ����Ϣ
    if (InputEngine_->ClickPause())
    {
        SceneEngine_->Pop();
    }
}

void GameScene_Parse::Output()
{
    FrameRender(g_hMemDC);
    BitBlt(g_hWndDC, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, g_hMemDC, 0, 0, SRCCOPY);
}

