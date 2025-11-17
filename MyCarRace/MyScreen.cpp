#include "pch.h"
#include "MyScreen.h"
#include "MemoryDC.h"

#define TIMERID_RENDER	(1)

MyScreen::MyScreen(void)
{
	m_fps = 100.;
	m_nDeltaTime = int(1000. / m_fps);

	m_nBackColor = RGB(63, 63, 63);

	m_pEnemy = nullptr; // null pointer
}

MyScreen::~MyScreen()
{
	if (m_pEnemy) delete m_pEnemy;
}

BEGIN_MESSAGE_MAP(MyScreen, BaseScreen)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

void MyScreen::CreateEnemy(void)
{
	if (m_pEnemy) delete m_pEnemy;
	m_pEnemy = new Enemy;
	m_pEnemy->SetPtStart(m_road.GetSafeRect());
}

void MyScreen::MoveEnemy(void)
{
	// 상대 속도: Player 속도 - Enemy 속도
	m_pEnemy->Move(0, m_road.GetSpeed() - m_pEnemy->GetSpeed());
}

void MyScreen::OnPaint()
{
	CPaintDC viewDc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 BaseScreen::OnPaint()을(를) 호출하지 마십시오.
	MemoryDC dc(&viewDc);
	DrawBack(&dc);
	m_road.Draw(&dc);
	m_player.Draw(&dc);
	if (m_pEnemy == nullptr) CreateEnemy();
	else MoveEnemy();
	m_pEnemy->Draw(&dc);
}

int MyScreen::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (BaseScreen::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	CRect rect;
	GetClientRect(rect);
	m_road.SetRect(rect);
	m_player.SetPtStart(rect);

	SetTimer(TIMERID_RENDER, m_nDeltaTime, NULL);

	return 0;
}

void MyScreen::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == TIMERID_RENDER)
	{
		m_road.MoveDown();
		Invalidate(FALSE);
	}

	BaseScreen::OnTimer(nIDEvent);
}
