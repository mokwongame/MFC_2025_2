#pragma once

#include <afxstr.h>
#include <atltime.h>

// ���ӽ����̽�: ���� ������ �Լ��� ĸ��ȭ
// �̸�: camel case(ex: std)
namespace mokwonLib
{
	// �ð� ��� ����
	enum class ClockType
	{
		CLOCK = 0, KOR, ENG
	};

	inline CString getCurTimeStr(ClockType nType, bool bShowAmPm = false)
	{
		CTime curTime; // Ŭ������ ������ ���� == �ν��Ͻ� ����(��� ������ �Լ��� ��� ����)
		//CTime curTime2; // ���ο� �ν��Ͻ� ����(curTime�� �ٸ� ��� ������ �Լ��� ���Ӱ� ����)
		// Ŭ�������� ���������� ���� ������ �Լ��� static���� �����ؼ� �� ���� ���� --> static ����� class�� ����
		// �׷��� ȣ���� ���� "Ŭ������::�����"�� ���
		curTime = CTime::GetCurrentTime();
		int nHour = curTime.GetHour(); // �Լ� ���� �ڿ� �ִ� const �ǹ�: ���� �Լ�(�޼ҵ�)�� ��� ������ �������� �ʴ´�.
		int nMin = curTime.GetMinute();
		int nSec = curTime.GetSecond();
		CString sTime; // Unicode�� ó���ϴ� MFC�� ���ڿ�
		switch (nType)
		{
		case ClockType::CLOCK:
			if (bShowAmPm)
			{
				if (nHour > 12) // PM
					sTime.Format(_T("PM %02d:%02d:%02d"), nHour - 12, nMin, nSec);
				else sTime.Format(_T("AM %02d:%02d:%02d"), nHour, nMin, nSec); // AM
			}
			else sTime.Format(_T("%02d:%02d:%02d"), nHour, nMin, nSec); // %02d �ǹ�: ������(decimal) ��� -> 2�ڸ� Ȯ��, ��ĭ�� 0���� ä��
			break;
		case ClockType::KOR:
			sTime.Format(_T("%d�� %d�� %d��"), nHour, nMin, nSec); // _T �ǹ�: Text -> Unicode
			break;
		case ClockType::ENG:
			sTime.Format(_T("%d hr %d min %d sec"), nHour, nMin, nSec); // _T �ǹ�: Text -> Unicode
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
		sDate.Format(_T("%d�� %d�� %d��"), nYear, nMon, nDay);
		return sDate;
	}
}