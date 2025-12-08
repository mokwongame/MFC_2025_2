#include "pch.h"
#include "Bullet.h"
#include "resource.h"

Bullet::Bullet(void)
{
	m_nCollider = ColliderType::RECT;
	SetBitmap(20, 50, IDB_BULLET_BACK, IDB_BULLET);
	SetSpeed(10);
}

void Bullet::SetPtStart(const CPoint& pt)
{
	m_ptCtr.x = pt.x - 5;
	m_ptCtr.y = pt.y - 80;
}
