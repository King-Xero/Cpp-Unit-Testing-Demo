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