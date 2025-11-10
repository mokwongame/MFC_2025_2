#include "pch.h"
#include "BaseCar.h"
#include "BaseScreen.h"

BaseCar::BaseCar(void)
{
	m_nBmpWid = 0;
	m_nBmpHt = 0;
	m_nBackId = NULL;
	m_nForeId = NULL;
	m_nStep = 1;
}

void BaseCar::SetBitmap(int nWid, int nHt, int nBackId, int nForeId)
{
	m_nBmpWid = nWid;
	m_nBmpHt = nHt;
	m_nBackId = nBackId;
	m_nForeId = nForeId;
}

void BaseCar::Draw(CDC* pDC) const
{
	CPoint topLeft = m_ptCtr - CPoint(m_nBmpWid / 2, m_nBmpHt / 2);
	BaseScreen::DrawBitmap(pDC, topLeft, m_nBmpWid, m_nBmpHt, m_nBackId, m_nForeId);
}

