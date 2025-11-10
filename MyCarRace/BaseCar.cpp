#include "pch.h"
#include "BaseCar.h"
#include "BaseScreen.h"

BaseCar::BaseCar(void)
{
	m_nBmpWid = 0;
	m_nBmpHt = 0;
	m_nBackId = NULL;
	m_nForeId = NULL;
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
	BaseScreen::DrawBitmap(pDC, m_ptCtr, m_nBmpWid, m_nBmpHt, m_nForeId, m_nBackId);
}

