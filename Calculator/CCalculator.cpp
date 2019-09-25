#include "CCalculator.h"
#include "CAddition.h"


CCalculator::CCalculator()
{
}

CCalculator::CCalculator(CAddition* addition, CSubtraction* subtraction)
{
	m_pAddition = addition;
	m_pSubtraction = subtraction;
}


CCalculator::~CCalculator()
{	
}

int CCalculator::Add(int iA, int iB)
{
	return m_pAddition->DoWork(iA, iB);
}

int CCalculator::Subtract(int iA, int iB)
{
	return iA - iB;
}
