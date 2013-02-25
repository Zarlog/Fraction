/*
 * main.cpp
 *
 *  Created on: Feb 24, 2013
 *      Author: Zack
 */

#include <iostream>
#include <string>
#include "Fraction.h"

using namespace std;

int main()
{
	int a, b;
	string str;
	Fraction fract;

	while (true)
	{
		cout << "Enter numerator: ";
		cin >> a;
		cout << "Enter denominator: ";
		cin >> b;
		fract.set(a,b);
		cout << "Numerator is " << fract.get_num() << endl;
		cout << "Denomerator is " << fract.get_den() << endl;
		cout << "Do again? (Y or N) ";
		cin >> str;
		if (!(str[0] == 'Y' || str[0] == 'y'))
			break;
	}
	return 0;
}


