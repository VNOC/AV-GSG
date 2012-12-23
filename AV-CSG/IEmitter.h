#pragma once
#include "GameDef.h"

///> �ӵ�������
class IEmitter
{
public:
    IEmitter(void) {};
    virtual ~IEmitter(void) {};

public:
    virtual void Emit(int nPosX, int nPosY, BulletType bulletType) = 0;
};

