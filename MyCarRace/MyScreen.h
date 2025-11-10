#pragma once
#include "BaseScreen.h"
#include "Road.h"
#include "Player.h"

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);

	Road m_road;
	Player m_player;

protected:
	double m_fps;	// frame per second
	int m_nDeltaTime;	// ¥‹¿ß: msec

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

