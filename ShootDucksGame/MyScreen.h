#pragma once

#include "BaseScreen.h"
#include "Rifle.h"
#include "Bullet.h"

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);
	~MyScreen();

	void MoveHunterLeft(void);
	void MoveHunterRight(void);
	void MakeBullet(void);

protected:
	CPoint m_ptField;
	CRect m_rtClient;
	Rifle m_rifle;
	Bullet* m_pBullet;

	double m_fps;	// frame per second
	int m_nDeltaTime;	// ¥‹¿ß: msec

	void DrawMount(CDC* pDC) const;
	void DrawField(CDC* pDC) const;

	void MoveBullet(void);
	void UnmakeBullet(void);

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

