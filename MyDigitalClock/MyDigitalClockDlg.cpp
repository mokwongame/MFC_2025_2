
// MyDigitalClockDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MyDigitalClock.h"
#include "MyDigitalClockDlg.h"
#include "afxdialogex.h"
#include "MokwonLib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define TIMER_CLOCK_ID	(1)
#define TIMER_PERIOD	(1000) // in msec
#define CLOCK_FONT_SIZE	(30)

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyDigitalClockDlg 대화 상자



CMyDigitalClockDlg::CMyDigitalClockDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYDIGITALCLOCK_DIALOG, pParent)
	, m_bShowAmPm(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nFontSize = CLOCK_FONT_SIZE;
}

void CMyDigitalClockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CLOCK, m_ctClock);
	DDX_Check(pDX, IDC_CHECK1, m_bShowAmPm);
	DDX_Control(pDX, IDC_DATE, m_ctDate);
}

BEGIN_MESSAGE_MAP(CMyDigitalClockDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDigitalClockDlg::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &CMyDigitalClockDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyDigitalClockDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMyDigitalClockDlg 메시지 처리기

BOOL CMyDigitalClockDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	// 타이머 설정하여 시작
	SetTimer(TIMER_CLOCK_ID, TIMER_PERIOD, NULL);
	// 시간과 날짜 갱신
	updateClock();
	// 폰트 초기화
	changeClockFontSize(m_nFontSize);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMyDigitalClockDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMyDigitalClockDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMyDigitalClockDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMyDigitalClockDlg::changeClockFontSize(int nSize)
{
	CFont* pFont = m_ctClock.GetFont();
	LOGFONT lf;
	pFont->GetLogFont(&lf);
	lf.lfHeight = nSize;
	lf.lfWeight = FW_BOLD; // 폰트 진하게
	lf.lfUnderline = TRUE; // 밑줄
	//CFont font; // font를 살릴려면 지역 변수 X; 전역 변수 or 클래스의 멤버 변수(필드, 프로퍼티)
	m_fontClock.DeleteObject(); // 폰트 생성 위해 먼저 파괴
	m_fontClock.CreateFontIndirect(&lf); // create: 생성
	m_ctClock.SetFont(&m_fontClock);
}

void CMyDigitalClockDlg::updateClock(void)
{
	using namespace mokwonLib;
	// 현재 시간을 표시
	CString sTime = getCurTimeStr(ClockType::CLOCK, m_bShowAmPm);
	m_ctClock.SetWindowText(sTime);
	// 오늘 날짜 표시
	CString sDate = getCurDateStr();
	m_ctDate.SetWindowText(sDate);
}

// 시간 확인
void CMyDigitalClockDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CString sTime = mokwonLib::getCurTimeStr(mokwonLib::ClockType::CLOCK);
	// 현재 메소드 안에서만 namespace 캡슐화 해제
	using namespace mokwonLib;
	UpdateData(TRUE);
	CString sTime = getCurTimeStr(ClockType::CLOCK, m_bShowAmPm);
	::AfxMessageBox(sTime); // :: 의미: 전역 함수란 뜻
}

void CMyDigitalClockDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	UpdateData(TRUE); // UI의 설정값을 현재 코드로 가져오기
	updateClock();
	CDialogEx::OnTimer(nIDEvent);
}

// 시계 글꼴 +
void CMyDigitalClockDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nFontSize++;
	changeClockFontSize(m_nFontSize);
}

// 시계 글꼴 -
void CMyDigitalClockDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_nFontSize--;
	changeClockFontSize(m_nFontSize);
}
