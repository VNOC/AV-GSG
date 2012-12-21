#pragma once

#include "Sprite.h"
#include "Picture.h"

// ��ըЧ���࣬��Ҫ�Ǹ��ݸ�������������ͣ���ʾ��ը��Ч���Ϳɡ�
class CExplosion : CSprite
{
public:
    CExplosion(int x, int y, BlastType blastType);
    virtual ~CExplosion(void);

    void Update();
    void Render(HDC hDC);
private:
    BlastType m_emBlastType;
};
