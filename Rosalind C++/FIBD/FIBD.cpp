///Rosalind FIBD
///Michiel Herpers
///21 6 2017

#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	//Open input file for reading
	string filename_input;
	stringstream filename_input_ss;
	ifstream input;
	filename_input_ss << argv[1];
	filename_input = filename_input_ss.str();
	input.open(filename_input);

	//Open output file for writing
	string filename_output;
	filename_output = "answer.txt";
	ofstream output;
	output.open(filename_output);

	//From input file get n (number of months) and k
	string number_months;
	string number_max_age;
	string input_line;
	string line;
	getline(input, input_line);
	stringstream ss; ss << input_line; line = ss.str(); 
	ss.clear();
	string::iterator iter;
	int index = 0;
	bool n_ready = false;
	for(iter = line.begin(); iter < line.end(); ++iter)
	{
		//cout << *iter << endl;
		string symbol;
		stringstream ss; ss << *iter; symbol = ss.str(); ss.clear();
		if(symbol == " ")
		{
			n_ready = true;
			//cout << "N ready is true" << endl;
		}
		else if(n_ready == false)
		{
			number_months.append(symbol);
			//cout << "N: " << symbol << endl;
		}	
		else if(n_ready == true)
		{
			number_max_age.append(symbol);
			//cout << "K: " << symbol << endl;
		}
		index = index + 1;
	}
	cout << "n: " << number_months << endl;
	cout << "m: " << number_max_age << endl;

	int n = stoi(number_months);
	int m = stoi(number_max_age);
	int k = 1; //Number of pairs offspring per months per pair
	long long int number_young_rabbit_pairs = 1;
	long long int number_reproductive_age_pairs = 0;
	long long int new_number_young_rabbit_pairs = 0;
	long long int new_number_reproductive_age_pairs = 0;
	long long int total_pairs;
	vector<long long int> memory_population;
	long long int number_death_pairs;
	int month = 1;
	while(month < (n + 1))
	{
		//Reproduction (rabbits which will die this month also reproduce)
		if(month > 1)
		{
			number_young_rabbit_pairs = new_number_young_rabbit_pairs;
			number_reproductive_age_pairs = new_number_reproductive_age_pairs;
		}
		new_number_reproductive_age_pairs = number_reproductive_age_pairs + number_young_rabbit_pairs;
		new_number_young_rabbit_pairs = k*number_reproductive_age_pairs;
		//Death
		if(month < m)
		{
			memory_population.push_back(number_young_rabbit_pairs);
			number_death_pairs = 0;
			for(vector<long long int>::iterator iter = memory_population.begin(); iter != memory_population.end(); ++iter)
			{
				cout << *iter << endl;
			}
		}
		else
		{
			//On moment of death will be position index 0
			//number_death_pairs->*(memory_population.begin());
			number_death_pairs = memory_population.at(0);
			for(vector<long long int>::iterator iter = memory_population.begin(); iter != memory_population.end(); ++iter)
			{
				cout << *iter << endl;
			}
			cout << "Number death pairs: " << number_death_pairs << endl;
			new_number_reproductive_age_pairs = new_number_reproductive_age_pairs - number_death_pairs;
			cout << "vector size before: " << memory_population.size() << endl;
			memory_population.erase(memory_population.begin());
			cout << "vector size after: " << memory_population.size() << endl;
			memory_population.push_back(number_young_rabbit_pairs);
			cout << "vector size after pushback: " << memory_population.size() << endl;	
			//memory_population.push_back(new_number_young_rabbit_pairs);
		}
		total_pairs = number_young_rabbit_pairs + number_reproductive_age_pairs;
		cout << "Month: " << month << endl;
		month = month + 1;
		cout << "Total pairs: " << total_pairs << endl;
	}

	//Write output
	output << fixed << total_pairs;

	//Close input/output files
	input.close();
	output.close();
}

