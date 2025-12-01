#include "pch.h"
#include "Duck.h"
#include "resource.h"
#include "BaseScreen.h"

Duck::Duck(void)
{
	SetBitmap(132, 125, IDB_DUCK_BACK, IDB_DUCK);
	SetSpeed(15);
}

void Duck::SetPtStart(const CRect& rect)
{
	m_ptCtr.x = -20;
	m_ptCtr.y = BaseScreen::RandRange(100, 300);
}
