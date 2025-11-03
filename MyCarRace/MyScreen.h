#pragma once
#include "BaseScreen.h"

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);

protected:
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};

