#include "pch.h"
#include "BaseScreen.h"

BaseScreen::BaseScreen(void)
{
	m_nBackColor = DEF_BACK_COLOR;
}

BaseScreen::~BaseScreen()
{
}

void BaseScreen::Create(int nId, CWnd* pParent)
{
	CWnd* pWnd = pParent->GetDlgItem(nId);
	pWnd->ShowWindow(SW_HIDE);
	CRect rect;
	pWnd->GetWindowRect(rect);
	pParent->ScreenToClient(rect);

	CStatic::Create(NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, rect, pParent);
}
BEGIN_MESSAGE_MAP(BaseScreen, CStatic)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
END_MESSAGE_MAP()

BOOL BaseScreen::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CBrush brush;
	brush.CreateSolidBrush(m_nBackColor);
	CRect rect;
	GetClientRect(rect);
	pDC->FillRect(rect, &brush);
	return CStatic::OnEraseBkgnd(pDC);
}

void BaseScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
}
