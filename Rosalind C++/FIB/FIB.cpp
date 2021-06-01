///Rosalind FIB
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
	string number_new_pairs;
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
			number_new_pairs.append(symbol);
			//cout << "K: " << symbol << endl;
		}
		index = index + 1;
	}
	cout << "n: " << number_months << endl;
	cout << "k: " << number_new_pairs << endl;

	int n = stoi(number_months);
	int k = stoi(number_new_pairs);
	long int number_young_rabbit_pairs = 1;
	long int number_reproductive_age_pairs = 0;
	long int new_number_young_rabbit_pairs = 0;
	long int new_number_reproductive_age_pairs = 0;
	long int total_pairs;
	int month = 0;
	while(month < n)
	{
		if(month > 0)
		{
			number_young_rabbit_pairs = new_number_young_rabbit_pairs;
			number_reproductive_age_pairs = new_number_reproductive_age_pairs;
		}
		new_number_reproductive_age_pairs = number_reproductive_age_pairs + number_young_rabbit_pairs;
		new_number_young_rabbit_pairs = k*number_reproductive_age_pairs;
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

