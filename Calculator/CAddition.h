#pragma once
#include "CSum.h"

class CAddition : CSum
{
public:
	CAddition();
	~CAddition() override;

	int DoWork(int iA, int iB) override;
};
