#include "catch.hpp"
#include "../Calculator/CAddition.h"

class CAdditionTests
{
protected:
	CAddition CreateSut()
	{
		return CAddition();
	}
};

TEST_CASE_METHOD(CAdditionTests, "When DoWork is called with 2 and 3, will return 5", "[Add]")
{
	CAddition sut = CreateSut();

	REQUIRE(sut.DoWork(2, 3) == 5);
}

TEST_CASE_METHOD(CAdditionTests, "When DoWork is called with 7 and 6, will return 13", "[Add]")
{
	CAddition sut = CreateSut();

	REQUIRE(sut.DoWork(7, 6) == 13);
}