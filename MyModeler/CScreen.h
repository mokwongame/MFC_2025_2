#pragma once
#include <afxwin.h>

#define DEF_RECT_LINE_WID	(2)
#define DEF_RECT_WID	(40)
#define DEF_RECT_HT	(40)

class CScreen :
	public CStatic
{
public:
	CScreen(void);

	void moveRectRight(void);
	void moveRectUp(void);

	COLORREF m_backCol; // 색깔: MFC에서는 color reference 사용
	COLORREF m_rectCol;
	COLORREF m_rectLineCol;
	CPoint m_ptRect; // 사각형의 중심점
	int m_nRectLineWid;	// 사각형 윤곽선의 두께
	int m_nRectWid; // 사각형의 너비
	int m_nRectHt;	// 사각형의 높이
	int m_nRectMoveStep;	// 사각형의 이동 간격

protected:
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

