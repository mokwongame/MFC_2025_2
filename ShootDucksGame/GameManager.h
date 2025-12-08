#pragma once

class GameManager
{
public:
	static int getScore(void) { return m_nScore; }
	static void incScore(void) { m_nScore++; }
	static void initScore(void) { m_nScore = 0; }

protected:
	static int m_nScore;
};

