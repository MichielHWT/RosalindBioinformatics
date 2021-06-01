///Test Module 1000000
///Michiel Herpers
///2/12/2017

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int number = 1;
	int modulo;
	int count_millions = 0;
	for (int i = 0; i != 100; i++)
	{
		//Loop and multiply by 2 each time
		number = number*2;
		count_millions = count_millions*2;
		cout << number << endl;
		if (number > 1000000)
		{
			count_millions = count_millions + 1;
			number = number % 1000000;
		}
	}
	
	cout << "count_millions:" << count_millions << endl;
	cout << "number" << number << endl;
	return 0;
}