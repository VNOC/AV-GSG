#pragma once

#include "Sprite.h"

///> �ɻ������
class PlaneBase : public CSprite
{
public:
    PlaneBase(int x, int y) : CSprite(x, y) {}
    virtual ~PlaneBase() {}

    //��ײ���
    virtual bool CheckCollision(
        int x, int y,
        int width, int height,
        int power) = 0;

protected:
    int     m_nHP;
};