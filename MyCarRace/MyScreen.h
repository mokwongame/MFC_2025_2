#pragma once
#include "BaseScreen.h"
#include "Road.h"

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);

protected:
	Road m_road;
	double m_fps;	// frame per second
	int m_nDeltaTime;	// ¥‹¿ß: msec

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

