#pragma once
#include <afxwin.h>

#define DEF_BACK_COLOR	RGB(255, 0, 0)

class BaseScreen :
	public CStatic
{
public:
	BaseScreen(void);
	~BaseScreen();

	void Create(int nId, CWnd* pParent);

	COLORREF m_nBackColor; // ����

protected:

public:
	DECLARE_MESSAGE_MAP()
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
};

