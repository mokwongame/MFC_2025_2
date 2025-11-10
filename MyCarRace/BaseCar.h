#pragma once

class BaseCar
{
public:
	BaseCar(void);

	void SetBitmap(int nWid, int nHt, int nBackId, int nForeId);

	void Draw(CDC* pDC) const;

protected:
	CPoint m_ptCtr;
	int m_nBmpWid;
	int m_nBmpHt;
	int m_nBackId;
	int m_nForeId;
};

