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
        int num;
        int den;
    private:
};


TEST_FIXTURE(FractionTestFixture, SetNumeratorAndDenomerator)
{
    FractionTestFixture::num = 1;
    FractionTestFixture::den = 2;

    fract.set(num, den);

    CHECK_EQUAL(num, fract.get_num());
    CHECK_EQUAL(den, fract.get_den());
}

TEST_FIXTURE(FractionTestFixture, VerifyNormalize)
{
    FractionTestFixture::num = 2;
    FractionTestFixture::den = 8;

    fract.set(num, den);

    CHECK_EQUAL(1, fract.get_num());
    CHECK_EQUAL(4, fract.get_den());
}

TEST_FIXTURE(FractionTestFixture, VerifyZeroDenomerator)
{
    FractionTestFixture::num = 1;
    FractionTestFixture::den = 0;

    fract.set(num, den);

    CHECK_EQUAL(0, fract.get_num());
    CHECK_EQUAL(1, fract.get_den());
}

TEST_FIXTURE(FractionTestFixture, AddFractions)
{
    FractionTestFixture::num = 1;
    FractionTestFixture::den = 2;

    fract.set(num, den);

    Fraction fract2;
    fract2.set(1,2);

    Fraction result = fract.add(fract2);

    CHECK_EQUAL(1, result.get_num());
    CHECK_EQUAL(1, result.get_den());
}

TEST_FIXTURE(FractionTestFixture, MultFractions)
{
    FractionTestFixture::num = 1;
    FractionTestFixture::den = 2;

    fract.set(num, den);

    Fraction fract2;
    fract2.set(1,2);

    Fraction result = fract.mult(fract2);

    CHECK_EQUAL(1, result.get_num());
    CHECK_EQUAL(4, result.get_den());
}


