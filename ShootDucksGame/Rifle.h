#pragma once

#include "BaseObj.h"

class Rifle :
	public BaseObj
{
public:
	Rifle(void);
	virtual void SetPtStart(const CRect& rect);

protected:
};

