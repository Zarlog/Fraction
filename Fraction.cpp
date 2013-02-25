/*
 * Fraction.cpp
 *
 *  Created on: Feb 24, 2013
 *      Author: Zack
 */
#include <stdlib.h>
#include "Fraction.h"

using namespace std;

void
Fraction::normalize()
{
	if (den == 0 || num == 0)
	{
		num = 0;
		den = 1;
	}

	if(den < 0)
	{
		num *= -1;
		den *= -1;
	}

	int n = gcf(num, den);
	num = num / n;
	den = den / n;
}

int
Fraction::gcf(int a, int b)
{
	if (b == 0)
		return abs(a);
	else
		return gcf(b, a%b);
}

int
Fraction::lcm(int a, int b)
{
	int n = gcf(a, b);
	return a / n * b;
}

Fraction
Fraction::add(Fraction other)
{
	Fraction fract;
	int lcd = lcm(den, other.den);
	int quot1 = lcd / den;
	int quot2 = lcd / other.den;
	fract.set(num * quot1 + other.num * quot2, lcd);
	return fract;
}

Fraction
Fraction::mult(Fraction other)
{
	Fraction fract;
	fract.set(num * other.num, den * other.den);
	return fract;
}

