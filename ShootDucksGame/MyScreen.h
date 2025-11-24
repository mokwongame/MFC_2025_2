#pragma once

#include "BaseScreen.h"

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);

	void MoveHunterLeft(void);
	void MoveHunterRight(void);

protected:
	CPoint m_ptField;

	void DrawMount(CDC* pDC) const;
	void DrawField(CDC* pDC) const;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

