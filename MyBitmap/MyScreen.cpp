#include "pch.h"
#include "MyScreen.h"
#include "resource.h"
#include "MemoryDC.h"

MyScreen::MyScreen(void)
{
	m_ptCar = CPoint(30, 30);
	m_nCarStep = DEF_CAR_STEP;
	m_ptPerson = CPoint(60, 60);
	m_nPersonBack = IDB_WALK1_BACK;
	m_nPersonFore = IDB_WALK1_FORE;
}

void MyScreen::MoveCarDown(void)
{
	m_ptCar.y += m_nCarStep;
	Invalidate(TRUE);
}

void MyScreen::MoveCarUp(void)
{
	m_ptCar.y -= m_nCarStep;
	Invalidate(TRUE);
}

BEGIN_MESSAGE_MAP(MyScreen, BaseScreen)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void MyScreen::drawCar(CDC* pDC)
{
	drawBitmap(pDC, m_ptCar, 200, 99, IDB_CAR_BACK, IDB_CAR_FORE);
}

void MyScreen::drawPerson(CDC* pDC)
{
	drawBitmap(pDC, m_ptPerson, 110, 200, m_nPersonBack, m_nPersonFore);
}

void MyScreen::OnPaint()
{
	CPaintDC paintDc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� BaseScreen::OnPaint()��(��) ȣ������ ���ʽÿ�.

	// paintDc�� memoryDc ����
	MemoryDC dc(&paintDc);
	// ���Ŀ� dc�� �־��ִ� ��ü�� ��� memory DC�� �׷���
	// �� memory DC�� �Ҹ��� ���� paintDc�� ������ �׷���

	// ���� �׸���
	drawBack(&dc);

	//CDC memDc;
	//memDc.CreateCompatibleDC(&dc); // paint message�� ó���ϴ� dc�� memDc�� �����ؼ� ����

	//CBitmap bitmap;
	//// �״�� �׸���
	////bitmap.LoadBitmap(IDB_CAR);
	////CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	////// bit block transfer: ��� ������ ���� ��ɾ�
	////dc.BitBlt(m_ptCar.x, m_ptCar.y, 200, 99, &memDc, 0, 0, SRCCOPY); // ��Ʈ�� ������ ��Ʈ ���� ���� �״�� ����(copy)

	//// ����� �������� �׸���
	//bitmap.LoadBitmap(IDB_CAR_BACK); // �޸� �Ҵ�
	//CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	//dc.BitBlt(m_ptCar.x, m_ptCar.y, 200, 99, &memDc, 0, 0, SRCAND);
	//bitmap.DeleteObject(); // �޸� ����
	//bitmap.LoadBitmap(IDB_CAR_FORE); // �޸� �Ҵ�
	//memDc.SelectObject(&bitmap);
	//dc.BitBlt(m_ptCar.x, m_ptCar.y, 200, 99, &memDc, 0, 0, SRCPAINT);

	//memDc.SelectObject(pOldBitmap);

	// �ڵ��� �׸���
	drawCar(&dc);

	// ��� �׸���
	drawPerson(&dc);
}
