#include "pch.h"
#include "CScreen.h"

CScreen::CScreen(void)
{
	m_backCol = RGB(0, 0, 0); // ������: ������ 0~255���� ����
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
