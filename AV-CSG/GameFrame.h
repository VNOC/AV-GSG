#pragma once
#include "ISprite.h"

class CGameFrame
{
public:
    CGameFrame(void);
    ~CGameFrame(void);

    //ˢ��һ֡����
    static void FrameRender(HDC hDC);

    //ͳһ����֡����
    static void FrameUpdate();
};

