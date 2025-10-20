#include "pch.h"
#include "MyScreen.h"
#include "resource.h"

MyScreen::MyScreen(void)
{
	m_ptCar = CPoint(30, 30);
}

BEGIN_MESSAGE_MAP(MyScreen, BaseScreen)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void MyScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� BaseScreen::OnPaint()��(��) ȣ������ ���ʽÿ�.

	CDC memDc;
	memDc.CreateCompatibleDC(&dc); // paint message�� ó���ϴ� dc�� memDc�� �����ؼ� ����

	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_CAR);
	CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	// bit block transfer: ��� ������ ���� ��ɾ�
	dc.BitBlt(m_ptCar.x, m_ptCar.y, 200, 99, &memDc, 0, 0, SRCCOPY); // ��Ʈ�� ������ ��Ʈ ���� ���� �״�� ����(copy)

	memDc.SelectObject(pOldBitmap);
}
