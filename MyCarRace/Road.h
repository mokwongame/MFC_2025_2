#pragma once

class Road
{
public:
	Road(void);

	void SetRect(const CRect& rect)
	{
		m_rect = rect;
	}
	void Draw(CDC* pDC) const;
	void MoveDown(void); // 도로를 아래로 움직이는 효과

protected:
	CRect m_rect;

	int m_nCurbSize;
	COLORREF m_nCurbHatchCol;
	COLORREF m_nCurbCol;

	int m_nLaneSize;
	int m_nLineWid;
	int m_nLineHt;
	COLORREF m_nLineCol;

	void DrawCurbs(CDC* pDC) const;
	void DrawLines(CDC* pDC) const;
	void DrawOneLine(CDC* pDC, int x) const;
};

