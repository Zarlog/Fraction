/*
 * FractionUnitTests.cpp
 *
 *  Created on: Mar 2, 2013
 *      Author: Zack
 */

#include <UnitTest++.h>
#include "Fraction.h"

class FractionTestFixture
{
    public:
        Fraction fract;
    private:
};


TEST_FIXTURE(FractionTestFixture, SetNumeratorAndDenomerator)
{
    fract.set(1, 2);

    CHECK_EQUAL(1, fract.get_num());
    CHECK_EQUAL(2, fract.get_den());
}

TEST_FIXTURE(FractionTestFixture, VerifyNormalize)
{
    fract.set(2, 8);

    CHECK_EQUAL(1, fract.get_num());
    CHECK_EQUAL(4, fract.get_den());
}

TEST_FIXTURE(FractionTestFixture, VerifyZeroDenomerator)
{
    fract.set(1, 0);

    CHECK_EQUAL(0, fract.get_num());
    CHECK_EQUAL(1, fract.get_den());
}

TEST_FIXTURE(FractionTestFixture, VerifyNegativeDenomerator)
{
    fract.set(1, -2);

    CHECK_EQUAL(-1, fract.get_num());
    CHECK_EQUAL(2, fract.get_den());
}

TEST_FIXTURE(FractionTestFixture, VerifynegativeNumerator)
{
    fract.set(-1, 2);

    CHECK_EQUAL(-1, fract.get_num());
    CHECK_EQUAL(2, fract.get_den());
}

TEST_FIXTURE(FractionTestFixture, AddFractionsWithSameDenom)
{
    fract.set(1, 2);

    Fraction fract2;
    fract2.set(1,2);

    Fraction result = fract.add(fract2);

    CHECK_EQUAL(1, result.get_num());
    CHECK_EQUAL(1, result.get_den());
}

TEST_FIXTURE(FractionTestFixture, AddFractionsWithDifferentDenom)
{
    fract.set(2, 3);

    Fraction fract2;
    fract2.set(1,5);

    Fraction result = fract.add(fract2);

    CHECK_EQUAL(13, result.get_num());
    CHECK_EQUAL(15, result.get_den());
}

TEST_FIXTURE(FractionTestFixture, MultFractions)
{
    fract.set(1, 2);

    Fraction fract2;
    fract2.set(1,2);

    Fraction result = fract.mult(fract2);

    CHECK_EQUAL(1, result.get_num());
    CHECK_EQUAL(4, result.get_den());
}

TEST_FIXTURE(FractionTestFixture, SubtractFractionsWithSameDenom)
{
    fract.set(1, 2);

    Fraction fract2;
    fract2.set(1, 2);

    Fraction result = fract.sub(fract2);

    CHECK_EQUAL(0, result.get_num());
    CHECK_EQUAL(1, result.get_den());
}

TEST_FIXTURE(FractionTestFixture, SubtractFractionsWithDifferentDenoms)
{
    fract.set(3, 4);

    Fraction fract2;
    fract2.set(1, 3);

    Fraction result = fract.sub(fract2);

    CHECK_EQUAL(5, result.get_num());
    CHECK_EQUAL(12, result.get_den());
}

TEST_FIXTURE(FractionTestFixture, SubtractFractionsWithNegativeResult)
{
    fract.set(1, 3);

    Fraction fract2;
    fract2.set(3, 4);

    Fraction result = fract.sub(fract2);

    CHECK_EQUAL(-5, result.get_num());
    CHECK_EQUAL(12, result.get_den());
}

TEST_FIXTURE(FractionTestFixture, DivideFractions)
{
    fract.set(2, 7);

    Fraction fract2;
    fract2.set(3, 4);

    Fraction result = fract.div(fract2);

    CHECK_EQUAL(8, result.get_num());
    CHECK_EQUAL(21, result.get_den());
}

TEST_FIXTURE(FractionTestFixture, CreateWithConstructor)
{
    Fraction fract(5, 8);
    CHECK_EQUAL(5, fract.get_num());
    CHECK_EQUAL(8, fract.get_den());
}

TEST_FIXTURE(FractionTestFixture, VerifyCopyConstructor)
{
    Fraction fract(5, 8);
    Fraction fract2(fract);

    fract2.set(1 ,2);

    CHECK_EQUAL(5, fract.get_num());
    CHECK_EQUAL(8, fract.get_den());

    CHECK_EQUAL(1, fract2.get_num());
    CHECK_EQUAL(2, fract2.get_den());
}
