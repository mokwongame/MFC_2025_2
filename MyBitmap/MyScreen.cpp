#include "pch.h"
#include "MyScreen.h"
#include "resource.h"

MyScreen::MyScreen(void)
{
	m_ptCar = CPoint(30, 30);
	m_nCarStep = DEF_CAR_STEP;
}

void MyScreen::MoveCarDown(void)
{
	m_ptCar.y += m_nCarStep;
	Invalidate(TRUE);
}

BEGIN_MESSAGE_MAP(MyScreen, BaseScreen)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void MyScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 BaseScreen::OnPaint()을(를) 호출하지 마십시오.

	CDC memDc;
	memDc.CreateCompatibleDC(&dc); // paint message를 처리하는 dc와 memDc를 연동해서 생성

	CBitmap bitmap;
	// 그대로 그리기
	//bitmap.LoadBitmap(IDB_CAR);
	//CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	//// bit block transfer: 고속 데이터 전송 명령어
	//dc.BitBlt(m_ptCar.x, m_ptCar.y, 200, 99, &memDc, 0, 0, SRCCOPY); // 비트맵 정보를 비트 연산 없이 그대로 복사(copy)

	// 배경을 투명으로 그리기
	bitmap.LoadBitmap(IDB_CAR_BACK); // 메모리 할당
	CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	dc.BitBlt(m_ptCar.x, m_ptCar.y, 200, 99, &memDc, 0, 0, SRCAND);
	bitmap.DeleteObject(); // 메모리 해제
	bitmap.LoadBitmap(IDB_CAR_FORE); // 메모리 할당
	memDc.SelectObject(&bitmap);
	dc.BitBlt(m_ptCar.x, m_ptCar.y, 200, 99, &memDc, 0, 0, SRCPAINT);

	memDc.SelectObject(pOldBitmap);
}
