///Rosalind Exercise MRNA
///Michiel Herpers
///26 6 2017

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

	//OPEN RNA codon table
	ifstream codon_table;
	codon_table.open("RNA_codon_table.txt");
	string word;

	//Read string from input data and match with codon in file
	string peptide;
	getline(input, peptide);
	int peptide_length = peptide.length();
	int loop_length = peptide_length;
	string input_AA;
	int string_position = 0;
	int modulo = 1000000;
	long long int number_RNA_strings = 1;
	for(int i = 0; i < loop_length; ++i)
	{
		string_position = i;
		input_AA = peptide[i];
		word.clear();
		//Read codon table and find match
		int appearance_counter = 0;
		while(codon_table >> word)
		{
			if(input_AA == word)
			{
				appearance_counter = appearance_counter + 1;
			}
			word.clear();
		}
		number_RNA_strings = number_RNA_strings * appearance_counter;
		
		//Take modulo 1000000 if number_RNA_strings is higher 
		number_RNA_strings = number_RNA_strings % 1000000;
		
		codon_table.clear();
		codon_table.seekg(0, ios::beg);
	}
	//Also take into account stop codon
	//3 Stop codons possible
	number_RNA_strings = number_RNA_strings * 3;
	number_RNA_strings = number_RNA_strings % 1000000;

	output << number_RNA_strings << endl;

	//close files
	input.close();
	output.close();
	codon_table.close();
	return 0;
}

