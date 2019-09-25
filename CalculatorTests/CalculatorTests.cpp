#include "catch.hpp"
#include "fakeit.hpp"
#include "../Calculator/CCalculator.h"

class CCalculatorTests
{
protected:
	fakeit::Mock<CAddition> additionMock;
	fakeit::Mock<CSubtraction> subtractionMock;

	CCalculator CreateSut()
	{
		return CCalculator(&additionMock.get(), &subtractionMock.get());
	}
public:
	CCalculatorTests() = default;
};

TEST_CASE_METHOD(CCalculatorTests, "When 'Ctor' is called with null CAddition, an exception is thrown", "[Ctor]")
{
	REQUIRE_THROWS(CCalculator(nullptr, &subtractionMock.get()));
}

TEST_CASE_METHOD(CCalculatorTests, "When 'Ctor' is called with null CSubtraction, an exception is thrown", "[Ctor]")
{
	REQUIRE_THROWS(CCalculator(&additionMock.get(), nullptr));
}

TEST_CASE_METHOD(CCalculatorTests, "When 'Add' is called, 'DoWork' is called on the underlying CAddition", "[Add]")
{
	fakeit::Fake(Method(additionMock, DoWork));

	CCalculator sut = CreateSut();
	
	sut.Add(2, 3);

	REQUIRE(fakeit::Verify(Method(additionMock, DoWork)));
}

TEST_CASE_METHOD(CCalculatorTests, "When 'Subtract' is called, 'DoWork' is called on the underlying CSubtraction", "[Subtract]")
{
	fakeit::Fake(Method(subtractionMock, DoWork));

	CCalculator sut = CreateSut();

	sut.Subtract(2, 3);

	REQUIRE(fakeit::Verify(Method(subtractionMock, DoWork)));
}

//ToDo Create test fixtures for CAddition and CSubtraction and move/refactor these tests there

//TEST_CASE("When Add is called with 2 and 3, will return 5", "[Add]")
//{
//	CCalculator cCalculator(new CAddition, new CSubtraction);
//
//	REQUIRE(cCalculator.Add(2, 3) == 5);
//}
//
//TEST_CASE("When Add is called with 7 and 6, will return 13", "[Add]")
//{
//	CCalculator cCalculator(new CAddition, new CSubtraction);
//
//	REQUIRE(cCalculator.Add(7, 6) == 13);
//}
//
//TEST_CASE("When Subtract is called with 3 and 2, will return 1", "[Subtract]")
//{
//	CCalculator cCalculator(new CAddition, new CSubtraction);
//
//	REQUIRE(cCalculator.Subtract(3, 2) == 1);
//}
//
//TEST_CASE("When Subtract is called with 12 and 3, will return 9", "[Subtract]")
//{
//	CCalculator cCalculator(new CAddition, new CSubtraction);
//
//	REQUIRE(cCalculator.Subtract(12, 3) == 9);
//}