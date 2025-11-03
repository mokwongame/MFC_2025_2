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

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

