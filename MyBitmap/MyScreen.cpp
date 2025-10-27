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
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 BaseScreen::OnPaint()을(를) 호출하지 마십시오.

	// paintDc와 memoryDc 연결
	MemoryDC dc(&paintDc);
	// 이후에 dc에 넣어주는 객체는 모두 memory DC에 그려짐
	// 이 memory DC가 소멸할 때는 paintDc에 실제로 그려짐

	// 배경색 그리기
	drawBack(&dc);

	//CDC memDc;
	//memDc.CreateCompatibleDC(&dc); // paint message를 처리하는 dc와 memDc를 연동해서 생성

	//CBitmap bitmap;
	//// 그대로 그리기
	////bitmap.LoadBitmap(IDB_CAR);
	////CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	////// bit block transfer: 고속 데이터 전송 명령어
	////dc.BitBlt(m_ptCar.x, m_ptCar.y, 200, 99, &memDc, 0, 0, SRCCOPY); // 비트맵 정보를 비트 연산 없이 그대로 복사(copy)

	//// 배경을 투명으로 그리기
	//bitmap.LoadBitmap(IDB_CAR_BACK); // 메모리 할당
	//CBitmap* pOldBitmap = memDc.SelectObject(&bitmap);
	//dc.BitBlt(m_ptCar.x, m_ptCar.y, 200, 99, &memDc, 0, 0, SRCAND);
	//bitmap.DeleteObject(); // 메모리 해제
	//bitmap.LoadBitmap(IDB_CAR_FORE); // 메모리 할당
	//memDc.SelectObject(&bitmap);
	//dc.BitBlt(m_ptCar.x, m_ptCar.y, 200, 99, &memDc, 0, 0, SRCPAINT);

	//memDc.SelectObject(pOldBitmap);

	// 자동차 그리기
	drawCar(&dc);

	// 사람 그리기
	drawPerson(&dc);
}
