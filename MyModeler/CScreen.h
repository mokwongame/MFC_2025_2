#pragma once
#include <afxwin.h>

#define DEF_RECT_LINE_WID	(2)

class CScreen :
	public CStatic
{
public:
	CScreen(void);

	COLORREF m_backCol; // ����: MFC������ color reference ���
	COLORREF m_rectCol;
	COLORREF m_rectLineCol;
	CPoint m_ptRect; // �簢���� �߽���
	int m_nRectLineWid;	// �簢�� �������� �β�
	int m_nRectWid; // �簢���� �ʺ�
	int m_nRectHt;	// �簢���� ����

protected:
public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

