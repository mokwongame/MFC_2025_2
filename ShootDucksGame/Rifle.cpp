#include "pch.h"
#include "Rifle.h"
#include "resource.h"

Rifle::Rifle(void)
{
	SetBitmap(40, 150, IDB_RIFLE_BACK, IDB_RIFLE);
	SetSpeed(6);
}

void Rifle::SetPtStart(const CRect& rect)
{
	m_ptCtr.x = rect.CenterPoint().x;
	m_ptCtr.y = rect.bottom - 40;
}
