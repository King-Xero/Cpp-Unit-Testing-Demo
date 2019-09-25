#pragma once
#include "CAddition.h"
#include "CSubtraction.h"

class CCalculator
{
private:
	CAddition*		m_pAddition = nullptr;
	CSubtraction*	m_pSubtraction = nullptr;
public:
	CCalculator() = delete;
	CCalculator(CAddition* addition, CSubtraction* subtraction);
	~CCalculator();

	int Add(int iA, int iB);
	int Subtract(int iA, int iB);
};

