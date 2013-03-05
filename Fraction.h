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
        //constructors
        inline Fraction();
        inline Fraction(int num);
        inline Fraction(int num, int den);
        inline Fraction(Fraction const &src);

        //setters and getters
        inline void set(int n, int d);
        inline int get_num();
        inline int get_den();

        //mathmatical operations
        Fraction add(const Fraction &other);
        Fraction mult(const Fraction &other);
        Fraction sub(const Fraction &other);
        Fraction div(const Fraction &other);

        //operators
        //TODO these are inefficient it would be better to pass by reference
        Fraction operator+(Fraction &other);
        Fraction operator-(Fraction &other);
        Fraction operator*(Fraction &other);
        Fraction operator/(Fraction &other);
        bool operator==(Fraction &other);
        friend std::ostream &operator<<(std::ostream &os, Fraction &fract);

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

Fraction::Fraction(int num)
{
    set(num, 1);
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
