#pragma once
#include "BaseCar.h"

class Player :
	public BaseCar
{
public:
	Player(void);

	void SetPtStart(const CRect& rect);

protected:
};

