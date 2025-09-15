
// MyInfoDlg.h: 헤더 파일
//

#pragma once


// CMyInfoDlg 대화 상자
class CMyInfoDlg : public CDialogEx
{
	// 생성입니다.
public:
	CMyInfoDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYINFO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


	// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_sName;
	CListBox m_ctListBox;
	afx_msg void OnBnClickedButton1();
	int m_nZipCode;
	CString m_sAddress;
	int m_nGender;
	BOOL m_bVip;
	CString m_sEI;
	CString m_sSN;
	CString m_sTF;
	CString m_sJP;
	int m_nPet;
	CStatic m_ctPet;
	CMonthCalCtrl m_ctMonthCal;
};
