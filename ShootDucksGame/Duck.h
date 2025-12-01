#pragma once

#include "BaseObj.h"

class Duck :
	public BaseObj
{
public:
	Duck(void);

	virtual void SetPtStart(const CRect& rect);

protected:
};

