/*
 * Fraction.h
 *
 *  Created on: Feb 24, 2013
 *      Author: Zack
 */

#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>

class Fraction
{
    public:
        inline Fraction();
        inline Fraction(int num, int den);
        inline Fraction(Fraction const &src);
        inline void set(int n, int d);
        inline int get_num();
        inline int get_den();
        Fraction add(Fraction other);
        Fraction mult(Fraction other);
        Fraction sub(Fraction other);
        Fraction div(Fraction other);
    private:
        int num, den;
        void normalize();
        int gcf(int a, int b);
        int lcm(int a, int b);
};

Fraction::Fraction()
{
    set(0, 1);
}

Fraction::Fraction(int num, int den)
{
    set(num, den);
}

Fraction::Fraction(Fraction const &src)
{
    num = src.num;
    den = src.den;
}

void
Fraction::set(int n, int d)
{
	num=n;
	den=d;
	normalize();
}

int
Fraction::get_num()
{
	return num;
}

int
Fraction::get_den()
{
	return den;
}
#endif /* FRACTION_H_ */
