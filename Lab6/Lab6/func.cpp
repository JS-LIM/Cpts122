#include "Header.h"

Complex::Complex(double newReal, double newImag)
{
	realDoub = newReal;
	imagDoub = newImag;
}

Complex::Complex(Complex &copy)
{
	setReal(copy.getReal());
	setImag(copy.getImag());
}

double Complex::getReal() const
{
	return realDoub;
}

double Complex::getImag() const
{
	return imagDoub;
}

void Complex::setReal(double newReal)
{
	realDoub = newReal;
}

void Complex::setImag(double newImag)
{
	imagDoub = newImag;
}

Complex Complex::add(Complex rhs)
{
	Complex result;

	result.setReal(rhs.getReal() + realDoub);
	result.setImag(rhs.getImag() + imagDoub);

	return result;
}

Complex add(const Complex &lhs, const Complex &rhs)
{
	Complex result;
	
	result.setReal(lhs.getReal() + rhs.getReal());
	result.setImag(lhs.getImag() + rhs.getImag());

	return result;
}

Complex & operator+(const Complex &lhs, const Complex &rhs)
{
	Complex result;

	result.setReal(lhs.getReal() + rhs.getReal());
	result.setImag(lhs.getImag() + rhs.getImag());

	return result;
}

Complex & operator-(const Complex &lhs, const Complex &rhs)
{
	Complex result;

	result.setReal(lhs.getReal() - rhs.getReal());
	result.setImag(lhs.getImag() - rhs.getImag());

	return result;
}

void Complex::read()
{
	cout << "Enter in a complex number in the form a + bi" << endl;

}
