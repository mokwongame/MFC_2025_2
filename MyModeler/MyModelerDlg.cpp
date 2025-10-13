
// MyModelerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MyModeler.h"
#include "MyModelerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define DEF_BACK_COL	RGB(255, 255, 255)

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


// CMyModelerDlg 대화 상자



CMyModelerDlg::CMyModelerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYMODELER_DIALOG, pParent)
	, m_nRectMoveStep(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyModelerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_btBackCol);
	DDX_Text(pDX, IDC_EDIT1, m_nRectMoveStep);
	DDX_Control(pDX, IDC_SLIDER_WID, m_slRectWid);
	DDX_Control(pDX, IDC_SLIDER_HT, m_slRectHt);
}

BEGIN_MESSAGE_MAP(CMyModelerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyModelerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyModelerDlg::OnBnClickedButton2)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BUTTON3, &CMyModelerDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CMyModelerDlg 메시지 처리기

BOOL CMyModelerDlg::OnInitDialog()
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
	// Screen 생성
	CWnd* pWnd = GetDlgItem(IDC_SCREEN);
	pWnd->ShowWindow(SW_HIDE); // 현재 static을 숨기기(hide)
	CRect rect; // 사각형(rectangle) 클래스
	pWnd->GetWindowRect(rect); // 스크린(문서) 좌표계 기준으로 rect를 반환
	ScreenToClient(rect); // 스크린 좌표계 -> 다이얼로그(지역) 좌표계

	m_screen.Create(NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, rect, this);
	m_screen.m_nRectMoveStep = m_nRectMoveStep;

	// 색깔 초기화
	m_btBackCol.SetColor(DEF_BACK_COL);
	m_screen.m_backCol = DEF_BACK_COL;

	// slider control 초기화
	m_slRectWid.SetRange(1, 200);
	m_slRectWid.SetPos(DEF_RECT_WID);
	m_slRectHt.SetRange(1, 200);
	m_slRectHt.SetPos(DEF_RECT_HT);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMyModelerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyModelerDlg::OnPaint()
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
HCURSOR CMyModelerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 그리기
void CMyModelerDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	COLORREF backCol = m_btBackCol.GetColor();
	m_screen.m_backCol = backCol;
	// OnPaint()를 위한 메시지 전달
	m_screen.Invalidate(TRUE); // 입력 역할: OnEraseBkgnd() 호출 여부; TRUE이면 OnEraseBkgnd() 호출
}

// right move
void CMyModelerDlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); // UI 데이터를 현재 코드로 저장(save = TRUE 뜻)
	// spin control 사용: buddy 선택(tab order = Ctrl+D로 인접한 순서가 되게 설정); 버디 정수 설정, 자동 버디, 맞춤을 각각 설정
	m_screen.m_nRectMoveStep = m_nRectMoveStep;
	m_screen.moveRectRight();
}

void CMyModelerDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (pScrollBar->GetDlgCtrlID() == IDC_SLIDER_WID) // slider control message인지 control ID로 확인
	{
		int nWid = m_slRectWid.GetPos();
		m_screen.m_nRectWid = nWid;
		m_screen.Invalidate(TRUE); // screen만 무효화(invalidate) -> WM_PAINT message 발생
	}
	else if (pScrollBar->GetDlgCtrlID() == IDC_SLIDER_HT)
	{
		int nHt = m_slRectHt.GetPos();
		m_screen.m_nRectHt = nHt;
		m_screen.Invalidate(TRUE);
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

// up move
void CMyModelerDlg::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_screen.m_nRectMoveStep = m_nRectMoveStep;
	m_screen.moveRectUp();
}
