#pragma once
#include "CSum.h"

class CSubtraction : CSum
{
public:
	CSubtraction();
	~CSubtraction() override;
	
	int DoWork(int iA, int iB) override;
};
