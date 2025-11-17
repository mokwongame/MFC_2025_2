#include "pch.h"
#include "Enemy.h"
#include "resource.h"
#include "BaseScreen.h"

Enemy::Enemy(void)
{
	SetBitmap(75, 152, IDB_ENEMY_BACK, IDB_ENEMY_FORE);
	m_nStep = 5;
}

void Enemy::SetPtStart(const CRect& rect)
{
	int x = BaseScreen::RandRange(rect.left + m_nBmpWid / 2, rect.right - m_nBmpWid / 2);
	int y = -m_nBmpHt / 2;
	m_ptCtr = CPoint(x, y);
}
