#include "pch.h"
#include "MyScreen.h"
#include "MemoryDC.h"
#include "resource.h"
#include "GameManager.h"

#define FIELD_MIN	(-270)
#define FIELD_MAX	(0)
#define FIELD_SPEED	(2)
#define TIMERID_RENDER	(1)

MyScreen::MyScreen(void)
{
	SetBackColor(RGB(0, 0, 255));
	m_ptField = CPoint((FIELD_MAX + FIELD_MIN) / 2, 100);
	m_pBullet = nullptr; // null pointer
	m_pDuck = nullptr;

	m_fps = 100.;
	m_nDeltaTime = int(1000. / m_fps);

	GameManager::initScore();
}

MyScreen::~MyScreen()
{
	UnmakeBullet();
}

void MyScreen::MoveHunterLeft(void)
{
	m_ptField.x -= FIELD_SPEED;
	if (m_ptField.x < FIELD_MIN) m_ptField.x = FIELD_MIN;
	m_rifle.MoveLeft();
}

void MyScreen::MoveHunterRight(void)
{
	m_ptField.x += FIELD_SPEED;
	if (m_ptField.x > FIELD_MAX) m_ptField.x = FIELD_MAX;
	m_rifle.MoveRight();
}

void MyScreen::DrawMount(CDC* pDC) const
{
	BaseScreen::DrawBitmap(pDC, CPoint(-100, -200), 800, 800, IDB_MOUNT_BACK, IDB_MOUNT_FORE);
}

void MyScreen::DrawField(CDC* pDC) const
{
	BaseScreen::DrawBitmap(pDC, m_ptField, 900, 572, IDB_FIELD_BACK, IDB_FIELD_FORE);
}

void MyScreen::MakeBullet(void)
{
	if (m_pBullet) return; // 이미 메모리 할당
	m_pBullet = new Bullet;
	m_pBullet->SetPtStart(m_rifle.GetPtCtr());
}

void MyScreen::MoveBullet(void)
{
	if (m_pBullet == nullptr) return;
	m_pBullet->MoveUp();
	if (m_pBullet->Bottom() < -10) UnmakeBullet();
}

void MyScreen::MoveDuck(void)
{
	if (m_pDuck == nullptr) return;
	m_pDuck->MoveRight();
	if (m_pDuck->Left() > m_rtClient.right + 10) UnmakeDuck();
}

void MyScreen::MakeDuck(void)
{
	if (m_pDuck) return;
	m_pDuck = new Duck;
	m_pDuck->SetPtStart(m_rtClient);
}

void MyScreen::UnmakeBullet(void)
{
	if (m_pBullet)
	{
		delete m_pBullet;
		m_pBullet = nullptr;
	}
}

void MyScreen::UnmakeDuck(void)
{
	if (m_pDuck)
	{
		delete m_pDuck;
		m_pDuck = nullptr;
	}
}

void MyScreen::CheckDuck(void)
{
	if (m_pDuck == nullptr || m_pBullet == nullptr) return;
	if (m_pDuck->HitTest(*m_pBullet)) // 충돌 확인
	{
		GameManager::incScore();
		UnmakeDuck();
		UnmakeBullet();
	}
}

void MyScreen::DrawScore(CDC* pDC) const
{
	CFont font;
	font.CreatePointFont(300, _T("맑은 고딕"));
	CString str;
	str.Format(_T("Score = %d"), GameManager::getScore());
	CFont* pOldFont = pDC->SelectObject(&font);
	COLORREF nTextCol = pDC->SetTextColor(RGB(0, 0, 255));
	COLORREF nBkCol = pDC->SetBkColor(RGB(63, 63, 63));
	pDC->TextOut(50, 50, str);
	pDC->SelectObject(pOldFont);
	pDC->SetTextColor(nTextCol);
	pDC->SetBkColor(nBkCol);
}

BEGIN_MESSAGE_MAP(MyScreen, BaseScreen)
	ON_WM_PAINT()
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

void MyScreen::OnPaint()
{
	CPaintDC viewDc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 BaseScreen::OnPaint()을(를) 호출하지 마십시오.
	MemoryDC dc(&viewDc);
	DrawBack(&dc);
	DrawMount(&dc);
	if (m_pDuck) m_pDuck->Draw(&dc);
	DrawField(&dc);
	m_rifle.Draw(&dc);
	if (m_pBullet) m_pBullet->Draw(&dc);
	DrawScore(&dc);
}

int MyScreen::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (BaseScreen::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	GetClientRect(m_rtClient);
	m_rifle.SetPtStart(m_rtClient);

	SetTimer(TIMERID_RENDER, m_nDeltaTime, NULL);
	return 0;
}

void MyScreen::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == TIMERID_RENDER)
	{
		if (m_pDuck == nullptr) MakeDuck();
		else MoveDuck();
		MoveBullet();
		CheckDuck(); // bullet과 duck의 충돌 여부 판정
		Invalidate(FALSE);
	}

	BaseScreen::OnTimer(nIDEvent);
}
