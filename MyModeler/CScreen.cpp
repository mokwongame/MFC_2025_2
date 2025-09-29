#include "pch.h"
#include "CScreen.h"

CScreen::CScreen(void)
{
	m_backCol = RGB(0, 0, 0); // ������: ������ 0~255���� ����
	m_rectCol = RGB(0, 0, 0);
	m_rectLineCol = RGB(0, 0, 0);
	m_nRectWid = m_nRectHt = 0;
	m_nRectLineWid = DEF_RECT_LINE_WID;
}

BEGIN_MESSAGE_MAP(CScreen, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

void CScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
	// ���� �׸��� ���� �׷����� �ڵ�
	// �簢�� �׸���
	CBrush brush;
	brush.CreateSolidBrush(m_rectCol); // �簢���� ä��� ���� ����
	CPen pen;
	pen.CreatePen(PS_SOLID, m_nRectLineWid, m_rectLineCol);
	CBrush* pOldBrush = dc.SelectObject(&brush);
	CPen* pOldPen = dc.SelectObject(&pen);
	// �簢�� ����

	// ���� GDI ��ü�� ����
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldPen);
}

// OnPaint() ���� ȣ��Ǵ� �޽��� �ڵ鷯
BOOL CScreen::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	// ���� ����: ������ ä���(brush �ʿ�)
	CBrush brush;
	brush.CreateSolidBrush(m_backCol);
	CRect rect;
	GetClientRect(rect); // ���� Ŭ������ CScreen�� Ŭ���̾�Ʈ(������ ���� ���� ����) ������ ������
	pDC->FillRect(rect, &brush);
	return CStatic::OnEraseBkgnd(pDC);
}
