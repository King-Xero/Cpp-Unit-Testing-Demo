#include "CCalculator.h"
#include "CAddition.h"
#include <exception>


CCalculator::CCalculator(CAddition* addition, CSubtraction* subtraction)
{
	addition != nullptr ? m_pAddition = addition : throw std::exception("addition is nullptr");
	subtraction != nullptr ? m_pSubtraction = subtraction : throw std::exception("subtraction is nullptr");
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
	return m_pSubtraction->DoWork(iA, iB);
}
