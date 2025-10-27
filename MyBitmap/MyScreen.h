#pragma once
#include "BaseScreen.h"

#define DEF_CAR_STEP	(1)

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);

	void SetNextPersonId(void);

	void MoveCarDown(void);
	void MoveCarUp(void);

	void MovePersonLeft(void);

	CPoint m_ptCar; // 자동차 위치 (x, y)
	int m_nCarStep;	// 자동차가 움직이는 간격
	CPoint m_ptPerson;	// 사람 위치 (x, y)
	int m_nPersonBack;
	int m_nPersonFore;
	int m_nPersonCur;	// 현재 사람 비트맵
	int m_nPersonCount;	// 사람 비트맵 개수

protected:
	void DrawCar(CDC* pDC);
	void DrawPerson(CDC* pDC);

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

