///Rosalind exercise 2
///Michiel Herpers
///15 6 2017

#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <iterator>

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
	string letter;
	for (iter = line_info.begin(); iter < line_info.end(); ++iter)
	{
		stringstream iter_letter_ss;
		iter_letter_ss << *iter;
		string iter_letter = iter_letter_ss.str();
		switch (*iter)
		{
			case 'T':
				output << "U";
				break;
			default:
				output << iter_letter;
				break;
		}			
	}
	output << "\n";	

	//Close input/output files
	input.close();
	output.close();
}

