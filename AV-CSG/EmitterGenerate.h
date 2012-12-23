#pragma once

#include "IEmitter.h"

///> ������������
class CEmitterGenerate
{
public:
    CEmitterGenerate(void);
    ~CEmitterGenerate(void);

    static IEmitter* Generate(
        int nType,
        bool bFriend,
        int nPower,
        int nSpeed,
        BulletType bulletType,
        float fAngle);
};

