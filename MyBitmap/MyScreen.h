#pragma once
#include "BaseScreen.h"

#define DEF_CAR_STEP	(1)

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);

	void MoveCarDown(void);

	CPoint m_ptCar; // �ڵ��� ��ġ (x, y)
	int m_nCarStep;	// �ڵ����� �����̴� ����

protected:

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

