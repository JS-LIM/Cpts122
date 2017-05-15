#include "Header.h"

int main()
{
	Complex a(5,2);
	cout << "Real: " << a.getReal() << endl << "Imaginary: " << a.getImag() << endl;

	a = a.add(a);
	cout << "Real: " << a.getReal() << endl << "Imaginary: " << a.getImag() << endl;

	a = add(a, a);
	cout << "Real: " << a.getReal() << endl << "Imaginary: " << a.getImag() << endl;

	a = a + a;
	cout << "Real: " << a.getReal() << endl << "Imaginary: " << a.getImag() << endl;




	return 0;
}