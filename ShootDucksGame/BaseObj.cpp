#include "pch.h"
#include "BaseObj.h"
#include "BaseScreen.h"

BaseObj::BaseObj(void)
{
	m_nBmpWid = 0;
	m_nBmpHt = 0;
	m_nBackId = NULL;
	m_nForeId = NULL;
	m_nStep = 1;
}

void BaseObj::SetBitmap(int nWid, int nHt, int nBackId, int nForeId)
{
	m_nBmpWid = nWid;
	m_nBmpHt = nHt;
	m_nBackId = nBackId;
	m_nForeId = nForeId;
}

void BaseObj::Draw(CDC* pDC) const
{
	BaseScreen::DrawBitmap(pDC, TopLeft(), m_nBmpWid, m_nBmpHt, m_nBackId, m_nForeId);
}

CRect BaseObj::MakeRect(void) const
{
	// (l, t, r, b)
	return CRect(Left(), Top(), Right(), Bottom());
}
