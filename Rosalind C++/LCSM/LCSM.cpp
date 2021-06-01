///Rosalind Exercise LCSM
///Michiel Herpers
///2/12/2017

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>

using namespace std;

int main(int argc, char* argv[])
{
	//Open input file
	string input_filename;
	stringstream ss_in; ss_in << argv[1]; input_filename = ss_in.str();
	ifstream input;
	input.open(input_filename);

	//Open output file "answer.txt" for writing output
	string output_filename;
	output_filename = "answer.txt";
	ofstream output;
	output.open(output_filename);

	//Determine the longest common substring (if multiple any solution OK)
	//Loop through text file and see if line is > or DNA string
	//Every member of the collection should have the same common substring
	//If DNA string check if string in a position is the same. How???
	


	//close files
	input.close();
	output.close();
	return 0;
}

