#pragma once
/*
*	add by hels	2012-5-13
*	��ըЧ���࣬��Ҫ�Ǹ��ݸ�������������ͣ���ʾ��ը��Ч���Ϳɡ�
*/
#include "Sprite.h"
#include "Picture.h"

class CExplosion : CSprite
{
public:
	CExplosion(int x, int y, BlastType blastType);
	virtual ~CExplosion(void);
	static void LoadImage();
	static void FreeImage();

	void Update();
	void Render(HDC hDC);
private:
	static	CPicture *pPictureBlast[2];
	BlastType m_nBlastType;
};

