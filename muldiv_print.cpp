#include <iostream>
#include <stdlib.h>
#include "muldiv.hpp"
using namespace std;

int main (int argc, char *argv[])
{
	int n;

	if (argc > 2)
	{
		cout << "Too many arguments!\n";
		return 0;
	}
	n = atoi(argv[1]);
	cout << "The number is: " << n << "\n";
	muldiv_entry **table = generate_tables(n);
	get_val(table, n);
	print_tables(table,n);
	free_tables(table, n);
	return 0;
}