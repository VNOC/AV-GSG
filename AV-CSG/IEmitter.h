#pragma once

///> �ӵ�������
class IEmitter
{
public:
    IEmitter(void) {};
    virtual ~IEmitter(void) {};

public:
    virtual Emit() = 0;
};

