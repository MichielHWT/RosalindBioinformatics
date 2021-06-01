///Rosalind exercise 3
///Michiel Herpers
///16 6 2017

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
	
	//Read file and change T in U
	string line;
	getline(input, line);
	string line_info;
	stringstream ss;
	ss << line;
	line_info = ss.str();
	cout << line_info << endl;
	string::iterator iter;

	//stringstream before reverse
	stringstream DNA_ss;
	string letter;	
	string reverse_DNA;

	for (iter = line_info.begin(); iter < line_info.end(); ++iter)
	{
		stringstream iter_letter_ss;
		iter_letter_ss << *iter;
		string iter_letter = iter_letter_ss.str();

		switch (*iter)
		{
			case 'A':
				letter = 'T';
				break;
			case 'T':
				letter = 'A';
				break;
			case 'G':
				letter = 'C';
				break;
			case 'C':
				letter = 'G';
		}
		//Add to stringstream
		DNA_ss << letter;			
	}
	//Reverse 
	string DNA;
	DNA = DNA_ss.str();
	cout << "DNA: " << DNA << endl;
	reverse(begin(DNA), end(DNA)); //Important for std::reverse to not use operator ' = ' 
	//Write to output
	output << DNA << "\n";	

	//Close input/output files
	input.close();
	output.close();
}

