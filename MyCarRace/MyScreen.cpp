#include "pch.h"
#include "MyScreen.h"
#include "MemoryDC.h"

MyScreen::MyScreen(void)
{
	m_nBackColor = RGB(0, 0, 0);
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
	m_road.Draw(&dc);
}

int MyScreen::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (BaseScreen::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	CRect rect;
	GetClientRect(rect);
	m_road.SetRect(rect);
	return 0;
}
