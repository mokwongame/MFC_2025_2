#include "pch.h"
#include "MyScreen.h"
#include "MemoryDC.h"
#include "resource.h"

#define FIELD_MIN	(-270)
#define FIELD_MAX	(0)
#define FIELD_SPEED	(3)

MyScreen::MyScreen(void)
{
	SetBackColor(RGB(0, 0, 255));
	m_ptField = CPoint((FIELD_MAX + FIELD_MIN) / 2, 100);
}

void MyScreen::MoveHunterLeft(void)
{
	m_ptField.x -= FIELD_SPEED;
	if (m_ptField.x < FIELD_MIN) m_ptField.x = FIELD_MIN;
}

void MyScreen::MoveHunterRight(void)
{
	m_ptField.x += FIELD_SPEED;
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
	ON_WM_CREATE()
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
	m_rifle.Draw(&dc);
}

int MyScreen::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (BaseScreen::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	GetClientRect(m_rtClient);
	m_rifle.SetPtStart(m_rtClient);

	return 0;
}
