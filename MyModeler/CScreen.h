#pragma once
#include <afxwin.h>
class CScreen :
	public CStatic
{
public:
	CScreen(void);

	COLORREF m_backCol; // 색깔: MFC에서는 color reference 사용

protected:
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

