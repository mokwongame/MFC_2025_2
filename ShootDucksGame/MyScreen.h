#pragma once

#include "BaseScreen.h"
#include "Rifle.h"

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);

	void MoveHunterLeft(void);
	void MoveHunterRight(void);

protected:
	CPoint m_ptField;
	CRect m_rtClient;
	Rifle m_rifle;

	void DrawMount(CDC* pDC) const;
	void DrawField(CDC* pDC) const;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

