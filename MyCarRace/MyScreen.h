#pragma once
#include "BaseScreen.h"
#include "Road.h"
#include "Player.h"
#include "Enemy.h"

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);
	~MyScreen();

	Road m_road;
	Player m_player;
	Enemy* m_pEnemy;

protected:
	double m_fps;	// frame per second
	int m_nDeltaTime;	// ¥‹¿ß: msec

	void CreateEnemy(void);
	void MoveEnemy(void);

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

