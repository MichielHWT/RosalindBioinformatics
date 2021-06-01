///Rosalind HAMM
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
	
	//Declare arrays
	string line_s;
	string line_t;

	//Read file and save line as array of strings for each character
	int linecounter = 0;
	for(string line; getline(input, line);) //Note ';' after getline command
	{
		cout << line << endl;
		if(linecounter == 0)
		{
			line_s = line;
		}	
		else if(linecounter == 1)
		{
			line_t = line;
		}
		linecounter = linecounter + 1;
	}
	
	//Loop through string index and compare symbols
	int hamm_distance = 0; //Number of symbols which are different in string
	for(int i = 0; i < line_s.length(); ++i)
	{
		if (line_s[i] != line_t[i])
		{
			hamm_distance = hamm_distance + 1;
		}
	}

	//Write hamm distance to answer file
	output << hamm_distance;	

	//Close input/output files
	input.close();
	output.close();
}

