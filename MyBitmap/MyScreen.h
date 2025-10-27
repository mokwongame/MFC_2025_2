#pragma once
#include "BaseScreen.h"

#define DEF_CAR_STEP	(1)

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);

	void MoveCarDown(void);
	void MoveCarUp(void);

	CPoint m_ptCar; // �ڵ��� ��ġ (x, y)
	int m_nCarStep;	// �ڵ����� �����̴� ����
	CPoint m_ptPerson;	// ��� ��ġ (x, y)
	int m_nPersonBack;
	int m_nPersonFore;

protected:
	void drawCar(CDC* pDC);
	void drawPerson(CDC* pDC);

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

