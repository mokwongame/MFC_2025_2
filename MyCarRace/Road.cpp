#include "pch.h"
#include "Road.h"

Road::Road(void)
{
	m_nCurbSize = 20;
	m_nCurbHatchCol = RGB(255, 0, 0);
	m_nCurbCol = RGB(200, 200, 200);

	m_nLaneSize = 150;
	m_nLineWid = 10;
	m_nLineHt = 50;
	m_nLineCol = RGB(255, 255, 255);
}

void Road::Draw(CDC* pDC) const
{
	DrawCurbs(pDC);
	DrawLines(pDC);
}

void Road::MoveDown(void)
{
}

void Road::DrawCurbs(CDC* pDC) const
{
	CBrush brush;
	brush.CreateHatchBrush(HS_DIAGCROSS, m_nCurbHatchCol);
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	COLORREF oldBkCol = pDC->SetBkColor(m_nCurbCol);
	CPen pen;
	pen.CreatePen(PS_NULL, 0, RGB(0, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&pen);
	pDC->Rectangle(CRect(0, 0, m_nCurbSize, m_rect.Height()));
	pDC->Rectangle(CRect(m_rect.Width() - m_nCurbSize, 0, m_rect.Width(), m_rect.Height()));
	pDC->SelectObject(pOldBrush);
	pDC->SetBkColor(oldBkCol);
	pDC->SelectObject(pOldPen);
}

void Road::DrawLines(CDC* pDC) const
{
	int nLine = (m_rect.Width() - 2 * m_nCurbSize) / m_nLaneSize;
	for (int i = 1; i <= nLine; i++)
	{
		int x = m_nCurbSize + i * m_nLaneSize;
		DrawOneLine(pDC, x);
	}
}

void Road::DrawOneLine(CDC* pDC, int x) const
{
	CBrush brush;
	brush.CreateSolidBrush(m_nLineCol);
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	int y = 0;
	while (y < m_rect.Height())
	{
		pDC->Rectangle(CRect(x, y, x + m_nLineWid, y + m_nLineHt));
		y += m_nLineHt * 2;
	}
	pDC->SelectObject(pOldBrush);
}
