#include "pch.h"
#include "BaseScreen.h"

BaseScreen::BaseScreen(void)
{
}

BaseScreen::~BaseScreen()
{
}

void BaseScreen::Create(int nId, CWnd* pParent)
{
	CWnd* pWnd = pParent->GetDlgItem(nId);
	pWnd->ShowWindow(SW_HIDE);
	CRect rect;
	pWnd->GetWindowRect(rect);
	pParent->ScreenToClient(rect);
}
