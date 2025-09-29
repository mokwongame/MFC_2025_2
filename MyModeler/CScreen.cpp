#include "pch.h"
#include "CScreen.h"

CScreen::CScreen(void)
{
	m_backCol = RGB(0, 0, 0); // 검정색: 색깔은 0~255까지 변함
}

BEGIN_MESSAGE_MAP(CScreen, CStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

void CScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
	// 내가 그리고 싶은 그래픽을 코딩
}

// OnPaint() 전에 호출되는 메시지 핸들러
BOOL CScreen::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 배경색 선택: 배경색은 채우기(brush 필요)
	CBrush brush;
	brush.CreateSolidBrush(m_backCol);
	CRect rect;
	GetClientRect(rect); // 현재 클래스인 CScreen의 클라이언트(프레임 빼고 실제 서비스) 영역을 가져옴
	pDC->FillRect(rect, &brush);
	return CStatic::OnEraseBkgnd(pDC);
}
