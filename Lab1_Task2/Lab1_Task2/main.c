#include "Header.h"

int main()
{
	char str[20], rstr[20];
	int *max_size, count = 0;
	
	printf("Enter in a string\n");
	scanf("%s", str);

	find_max(&max_size, str);
	reverse_string(str, rstr, max_size, count);
	print_rstring(rstr, max_size);

	return 0;
}