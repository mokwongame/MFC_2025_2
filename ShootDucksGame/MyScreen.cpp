#include "pch.h"
#include "MyScreen.h"
#include "MemoryDC.h"

MyScreen::MyScreen(void)
{
	SetBackColor(RGB(0, 0, 255));
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
}
