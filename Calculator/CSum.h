#pragma once

class CSum
{
public:
	CSum();
	virtual ~CSum();
	virtual int DoWork(int iA, int iB) = 0;
};
