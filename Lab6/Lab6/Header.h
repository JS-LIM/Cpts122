#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

class Complex
{
public:
	Complex(double newReal = 0.0, double newImag = 0.0);
	Complex(Complex &copy);

	void setReal(double newReal);
	void setImag(double newImag);

	double getReal() const;
	double getImag() const;

	Complex add(Complex rhs);
	void read();

private:
	double realDoub;
	double imagDoub;
};

Complex add(const Complex &lhs, const Complex &rhs);
Complex & operator+(const Complex &lhs, const Complex &rhs);
Complex & operator-(const Complex &lhs, const Complex &rhs);



