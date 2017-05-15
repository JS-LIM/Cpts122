// This example illustrates how to work with class templates.

// History: 10/24 - Completed the insert function for List.
//                  Started to develop a Stack template, which
//                  was composed of a List template. We wrapped
//                  the existing operations on the List inside of
//                  Stack operations!
//          10/21 - Started creating a List class template. We are making 
//                  the class as generic as possible, so that
//                  we could develop a Stack and Queue template
//                  from it as well!


#include "ListTemplate.h"
#include "StackTemplate.h"

int main(void)
{
	List<int> lInts(100);
	List<double> lDoubles(50);

	Stack<int> SInts(50);

	int number = 42;
	SInts.push(number);
	number = 50;
	SInts.push(number);
	SInts.printStack();

	/*int number = 42;
	lInts.insertPosN(0, number);

	double number2 = 42.7;
	lDoubles.insertPosN(0, number2);

	cout << "Template List of Ints: ";
	lInts.printItem(0);
	cout << "Template List of Doubles: ";
	lDoubles.printItem(0);
*/
	return 0;
}