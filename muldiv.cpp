#include <iostream>
#include <stdlib.h>
using namespace std;

struct muldiv_entry
{
	int mul;
	float div;
};

struct muldiv_entry** generate_tables(int n)
{
	struct muldiv_entry **array = new struct muldiv_entry*[n];
	for(int i = 0; i < n; i++)
	{
		array[i] = new struct muldiv_entry[n];
	}
	return array;
}

void get_val(muldiv_entry **table, int n)
{
	for(int i =0; i < n ; i++)
	{
		for(int j =0; j < n; j++)
		{
			table[i][j].mul =(j+1)*(i+1);
			table[i][j].div = (i+1.)/(j+1); 			
		}
	}
}

void print_tables(struct muldiv_entry** tables, int n)
{
	cout << endl;
	cout << "Multiplication Table: " << endl;	
	for(int i =0; i<n; i++)
	{
		cout << endl;
		for(int j = 0; j<n; j++)
		{
			cout << tables[i][j].mul << " \t";
		}
	}
	cout << endl;
	cout << endl;
	cout << "Division Table: " <<endl;
	for(int i =0; i<n; i++)
	{
		cout << endl;
		for(int j = 0; j<n; j++)
		{
			cout << tables[i][j].div << " \t";
		}
	}
	cout << endl;
	cout << endl;
}

void free_tables(struct muldiv_entry** tables, int n)
{
	for(int i = 0; i < n; i ++)
	{
		delete [] tables[i];
	}
		delete [] tables;
}

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
