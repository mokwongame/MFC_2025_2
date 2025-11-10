#include "pch.h"
#include "Enemy.h"
#include "resource.h"

Enemy::Enemy(void)
{
	SetBitmap(75, 152, IDB_ENEMY_BACK, IDB_ENEMY_FORE);
	m_nStep = 5;
}
