#pragma once

#include "Sprite.h"
#include "IEmitter.h"

///> �ɻ������
class PlaneBase : public CSprite
{
public:
    PlaneBase(int x, int y)
        : CSprite(x, y)
        , m_nHP(0)
        , m_piEmitter(NULL)
    {
    }
    virtual ~PlaneBase() {}

    //��ײ���
    virtual bool CheckCollision(
        int x, int y,
        int width, int height,
        int power) = 0;

protected:
    int         m_nHP;      ///> Ѫ��
    IEmitter*   m_piEmitter; ///> �ӵ�������
};