#pragma once

#include "Picture.h"

class CPicturePool
{
public:
    CPicturePool(void);
    ~CPicturePool(void);

    static void FreeImage();
    static void LoadImage();

    static void LoadBullet();
    static void FreeBullet();

    static CPicture** GetPicture(PictureType picType);
private:
    static CPicture* m_pPictureBlast[2];
    static CPicture* m_pPictureAmmo[8];

};
