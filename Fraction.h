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
	inline void set(int n, int d);
	inline int get_num();
	inline int get_den();
	Fraction add(Fraction other);
	Fraction mult(Fraction other);
private:
	int num, den;
	void normalize();
	int gcf(int a, int b);
	int lcm(int a, int b);
};

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
