#include "pch.h"
#include "MyScreen.h"
#include "MemoryDC.h"
#include "resource.h"

#define FIELD_MIN	(-280)
#define FIELD_MAX	(0)

MyScreen::MyScreen(void)
{
	SetBackColor(RGB(0, 0, 255));
	m_ptField = CPoint((FIELD_MAX + FIELD_MIN) / 2, 100);
}

void MyScreen::MoveHunterLeft(void)
{
	m_ptField.x -= 5;
	if (m_ptField.x < FIELD_MIN) m_ptField.x = FIELD_MIN;
}

void MyScreen::MoveHunterRight(void)
{
	m_ptField.x += 5;
	if (m_ptField.x > FIELD_MAX) m_ptField.x = FIELD_MAX;
}

void MyScreen::DrawMount(CDC* pDC) const
{
	BaseScreen::DrawBitmap(pDC, CPoint(-100, -200), 800, 800, IDB_MOUNT_BACK, IDB_MOUNT_FORE);
}

void MyScreen::DrawField(CDC* pDC) const
{
	BaseScreen::DrawBitmap(pDC, m_ptField, 900, 572, IDB_FIELD_BACK, IDB_FIELD_FORE);
}

BEGIN_MESSAGE_MAP(MyScreen, BaseScreen)
	ON_WM_PAINT()
END_MESSAGE_MAP()

void MyScreen::OnPaint()
{
	CPaintDC viewDc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 BaseScreen::OnPaint()을(를) 호출하지 마십시오.
	MemoryDC dc(&viewDc);
	DrawBack(&dc);
	DrawMount(&dc);
	DrawField(&dc);
}
