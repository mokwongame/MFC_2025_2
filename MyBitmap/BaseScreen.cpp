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

void BaseScreen::drawBack(CDC* pDC)
{
	CBrush brush;
	brush.CreateSolidBrush(m_nBackColor);
	CRect rect;
	GetClientRect(rect);
	pDC->FillRect(rect, &brush);
}

void BaseScreen::drawBitmap(CDC* pDC, const CPoint& pt, int nWid, int nHt, int nBackId, int nForeId)
{
	CDC memDc;
	memDc.CreateCompatibleDC(pDC);

	CBitmap bitmap;

	// ����� �������� �׸���
	bitmap.LoadBitmap(nBackId); // �޸� �Ҵ�
	CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	pDC->BitBlt(pt.x, pt.y, nWid, nHt, &memDc, 0, 0, SRCAND);
	bitmap.DeleteObject(); // �޸� ����
	bitmap.LoadBitmap(nForeId); // �޸� �Ҵ�
	memDc.SelectObject(&bitmap);
	pDC->BitBlt(pt.x, pt.y, nWid, nHt, &memDc, 0, 0, SRCPAINT);

	memDc.SelectObject(pOldBitmap);
}

BOOL BaseScreen::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	//CBrush brush;
	//brush.CreateSolidBrush(m_nBackColor);
	//CRect rect;
	//GetClientRect(rect);
	//pDC->FillRect(rect, &brush);
	//return CStatic::OnEraseBkgnd(pDC);
	return FALSE; // ����� ������ ����
}

void BaseScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
}
