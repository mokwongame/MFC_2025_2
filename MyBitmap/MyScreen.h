#pragma once
#include "BaseScreen.h"

#define DEF_CAR_STEP	(1)

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);

	void MoveCarDown(void);

	CPoint m_ptCar; // 자동차 위치 (x, y)
	int m_nCarStep;	// 자동차가 움직이는 간격

protected:

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

