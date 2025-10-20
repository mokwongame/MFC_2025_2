#pragma once
#include <afxwin.h>

class BaseScreen :
	public CStatic
{
public:
	BaseScreen(void);
	~BaseScreen();

	void Create(int nId, CWnd* pParent);

protected:

};

