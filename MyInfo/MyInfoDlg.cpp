
// MyInfoDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MyInfo.h"
#include "MyInfoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CMyInfoDlg 대화 상자



CMyInfoDlg::CMyInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYINFO_DIALOG, pParent)
	, m_sName(_T(""))
	, m_nZipCode(0)
	, m_sAddress(_T(""))
	, m_nGender(1)
	, m_bVip(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_sName);
	DDX_Control(pDX, IDC_LIST1, m_ctListBox);
	DDX_Text(pDX, IDC_EDIT2, m_nZipCode);
	DDX_Text(pDX, IDC_EDIT3, m_sAddress);
	DDX_Radio(pDX, IDC_RADIO1, m_nGender);
	DDX_Check(pDX, IDC_CHECK1, m_bVip);
}

BEGIN_MESSAGE_MAP(CMyInfoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyInfoDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMyInfoDlg 메시지 처리기

BOOL CMyInfoDlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMyInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyInfoDlg::OnPaint()
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
HCURSOR CMyInfoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMyInfoDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ctListBox.ResetContent(); // ListBox 초기화
	UpdateData(TRUE); // UI 입력 -> 내 코드
	CString str;
	str = _T("이름 = ") + m_sName;
	m_ctListBox.AddString(str);
	// CString의 char *: GetBuffer(); 반드시 이후에  ReleaseBuffer() 호출
	str.Format(_T("주소 = (%d) %s"), m_nZipCode, m_sAddress.GetBuffer());
	m_sAddress.ReleaseBuffer();
	m_ctListBox.AddString(str);
	// 라디오 버튼
	// 1. 탭 오더 번호(Ctrl+D)는 인접하게 배치
	// 2. 첫번째 라디오 버튼 속성 > 그룹 = true, 나머지는 false로 유지
	// 3. 첫번째 라디오 버튼에만 변수 추가
	CString sGender = (m_nGender) ? _T("여성") : _T("남성");
	str = _T("성별 = ") + sGender;
	m_ctListBox.AddString(str);
	CString sVip = (m_bVip) ? _T("VIP") : _T("일반인");
	m_ctListBox.AddString(sVip);
}
