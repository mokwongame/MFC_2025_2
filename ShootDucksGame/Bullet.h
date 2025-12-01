#pragma once

#include "BaseObj.h"

class Bullet :
	public BaseObj
{
public:
	Bullet(void);
	virtual void SetPtStart(const CPoint& pt);

protected:
};

