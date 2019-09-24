#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../Calculator/CCalculator.h"

TEST_CASE("When Add is called with 2 and 3, will return 5", "[Add]")
{
	CCalculator cCalculator;

	REQUIRE(cCalculator.Add(2, 3) == 5);
}

TEST_CASE("When Add is called with 7 and 6, will return 13", "[Add]")
{
	CCalculator cCalculator;

	REQUIRE(cCalculator.Add(7, 6) == 13);
}

TEST_CASE("When Subtract is called with 3 and 2, will return 1", "[Subtract]")
{
	CCalculator cCalculator;

	REQUIRE(cCalculator.Subtract(3, 2) == 1);
}

TEST_CASE("When Subtract is called with 12 and 3, will return 9", "[Subtract]")
{
	CCalculator cCalculator;

	REQUIRE(cCalculator.Subtract(12, 3) == 9);
}