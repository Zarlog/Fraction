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
Fraction::add(const Fraction &other)
{
	Fraction fract;
	int lcd = lcm(den, other.den);
	int quot1 = lcd / den;
	int quot2 = lcd / other.den;
	fract.set(num * quot1 + other.num * quot2, lcd);
	return fract;
}

Fraction
Fraction::mult(const Fraction &other)
{
	Fraction fract;
	fract.set(num * other.num, den * other.den);
	return fract;
}

Fraction
Fraction::sub(const Fraction &other)
{
    Fraction fract;
    int lcd = lcm(den, other.den);
    int quot1 = lcd / den;
    int quot2 = lcd / other.den;
    fract.set(num * quot1 - other.num * quot2, lcd);
    return fract;
}

Fraction
Fraction::div(const Fraction &other)
{
    Fraction fract;
    fract.set(num * other.den, den * other.num);
    return fract;
}

Fraction
Fraction::operator+(Fraction &other)
{
    return add(other);
}

Fraction
Fraction::operator-(Fraction &other)
{
    return sub(other);
}

Fraction
Fraction::operator*(Fraction &other)
{
    return mult(other);
}

Fraction
Fraction::operator/(Fraction &other)
{
    return div(other);
}

bool
Fraction::operator==(Fraction &other)
{
    return (num == other.num && den == other.den);
}

std::ostream
&operator<<(ostream &os, Fraction &fract)
{
    os << fract.num << "/" << fract.den;
    return os;
}
