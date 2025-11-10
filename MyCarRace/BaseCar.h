#pragma once

class BaseCar
{
public:
	BaseCar(void);

	void SetBitmap(int nWid, int nHt, int nBackId, int nForeId);
	void SetPtCtr(const CPoint& pt) { m_ptCtr = pt; }

	void Draw(CDC* pDC) const;

	void Move(int dx, int dy)
	{
		m_ptCtr += CPoint(dx, dy);
	}
	void MoveLeft(void)
	{
		Move(-m_nStep, 0);
	}
	void MoveRight(void)
	{
		Move(m_nStep, 0);
	}
	void MoveUp(void)
	{
		Move(0, -m_nStep);
	}
	void MoveDown(void)
	{
		Move(0, m_nStep);
	}

protected:
	CPoint m_ptCtr;
	int m_nBmpWid;
	int m_nBmpHt;
	int m_nBackId;
	int m_nForeId;
	int m_nStep;
};

