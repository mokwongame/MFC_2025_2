#pragma once
#include "BaseScreen.h"

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);

	CPoint m_ptCar; //  �ڵ��� ��ġ (x, y)

protected:

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

