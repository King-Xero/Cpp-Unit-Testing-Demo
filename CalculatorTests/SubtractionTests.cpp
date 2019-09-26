#include "catch.hpp"
#include "../Calculator/CSubtraction.h"

class CAdditionTests
{
protected:
	CSubtraction CreateSut()
	{
		return CSubtraction();
	}
};

TEST_CASE_METHOD(CAdditionTests, "When DoWork is called with 3 and 2, will return 1", "[Add]")
{
	CSubtraction sut = CreateSut();

	REQUIRE(sut.DoWork(3, 3) == 0);
}

TEST_CASE_METHOD(CAdditionTests, "When DoWork is called with 12 and 3, will return 9", "[Add]")
{
	CSubtraction sut = CreateSut();

	REQUIRE(sut.DoWork(7, 6) == 1);
}