#pragma once
#include <afxwin.h>
class CScreen :
	public CStatic
{
public:
	CScreen(void);

	COLORREF m_backCol; // ����: MFC������ color reference ���

protected:
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

