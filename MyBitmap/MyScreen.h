#pragma once
#include "BaseScreen.h"

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);

	CPoint m_ptCar; //  자동차 위치 (x, y)

protected:

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

