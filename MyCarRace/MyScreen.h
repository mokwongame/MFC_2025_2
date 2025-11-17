#pragma once
#include "BaseScreen.h"
#include "Road.h"
#include "Player.h"
#include "Enemy.h"

class MyScreen :
	public BaseScreen
{
public:
	MyScreen(void);
	~MyScreen();

	Road m_road;
	Player m_player;
	Enemy* m_pEnemy;

protected:
	double m_fps;	// frame per second
	int m_nDeltaTime;	// 단위: msec
	int m_nEnemyDistMargin; // Enemy 기준으로 득점을 올린 거리 여유(distance margin)
	bool m_bGameOver;
	double m_score;

	void CreateEnemy(void);
	void MoveEnemy(void);
	void CheckEnemy(void);
	bool HitTest(void) const;

	void DrawScore(CDC* pDC) const;

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

