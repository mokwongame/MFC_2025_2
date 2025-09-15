#pragma once

#include <afxstr.h>
#include <atltime.h>

// 네임스페이스: 전역 변수와 함수를 캡슐화
// 이름: camel case(ex: std)
namespace mokwonLib
{
	// 시계 출력 형식
	enum class ClockType
	{
		CLOCK = 0, KOR, ENG
	};

	inline CString getCurTimeStr(ClockType nType, bool bShowAmPm = false)
	{
		CTime curTime; // 클래스를 변수로 선언 == 인스턴스 생성(멤버 변수와 함수를 모두 생성)
		//CTime curTime2; // 새로운 인스턴스 생성(curTime과 다른 멤버 변수와 함수가 새롭게 생성)
		// 클래스에서 공통적으로 쓰는 변수와 함수는 static으로 선언해서 한 번만 생성 --> static 멤버는 class에 종속
		// 그래서 호출할 때는 "클래스명::멤버명"을 사용
		curTime = CTime::GetCurrentTime();
		int nHour = curTime.GetHour(); // 함수 정의 뒤에 있는 const 의미: 현재 함수(메소드)는 멤버 변수를 변경하지 않는다.
		int nMin = curTime.GetMinute();
		int nSec = curTime.GetSecond();
		CString sTime; // Unicode를 처리하는 MFC의 문자열
		switch (nType)
		{
		case ClockType::CLOCK:
			if (bShowAmPm)
			{
				if (nHour > 12) // PM
					sTime.Format(_T("PM %02d:%02d:%02d"), nHour - 12, nMin, nSec);
				else sTime.Format(_T("AM %02d:%02d:%02d"), nHour, nMin, nSec); // AM
			}
			else sTime.Format(_T("%02d:%02d:%02d"), nHour, nMin, nSec); // %02d 의미: 십진수(decimal) 출력 -> 2자리 확보, 빈칸은 0으로 채움
			break;
		case ClockType::KOR:
			sTime.Format(_T("%d시 %d분 %d초"), nHour, nMin, nSec); // _T 의미: Text -> Unicode
			break;
		case ClockType::ENG:
			sTime.Format(_T("%d hr %d min %d sec"), nHour, nMin, nSec); // _T 의미: Text -> Unicode
			break;
		}
		return sTime;
	}

	inline CString getCurDateStr(void)
	{
		CTime curTime = CTime::GetCurrentTime();
		int nYear = curTime.GetYear();
		int nMon = curTime.GetMonth();
		int nDay = curTime.GetDay();
		CString sDate;
		sDate.Format(_T("%d년 %d월 %d일"), nYear, nMon, nDay);
		return sDate;
	}
}