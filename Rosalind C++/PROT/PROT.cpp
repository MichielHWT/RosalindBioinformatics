///Rosalind Exercise PROT
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
	string DNA;
	getline(input, DNA);
	int DNA_length = DNA.length();
	int loop_length = DNA_length - 3;
	string input_codon;
	bool next_char = false;
	bool stop_codon = false;
	int string_position = 0;
	for(int i = 0; i < loop_length; /*empty*/)
	{
		string_position = i;
		//cout << string_position << endl;
		stringstream ss_input_codon;
		ss_input_codon << DNA[i] << DNA[i+1] << DNA[i+2];
		input_codon = ss_input_codon.str();
		//cout << input_codon << endl;
		ss_input_codon.clear();
		word.clear();
		//Read codon table and find match
		while(codon_table >> word)
		{
			cout << input_codon << endl;
			cout << word << endl;
			if(input_codon == word)
			{
				cout << word << endl;
				//Next word is right char or STOP
				next_char = true;
			}
			else if(next_char == true)
			{
				//Write char to output file
				//If stop codon break loop
				if(word == "Stop")
				{
					stop_codon == true;
					next_char = false;
					break;
				}
				else
				{
					output << word;
					next_char = false;
					break; //break from while loop
				}				
			}
			word.clear();
		}
		codon_table.clear();
		codon_table.seekg(0, ios::beg);
		if(stop_codon == true)
		{
			cout << "Stop codon at position " << string_position << endl;
			break;
		}
		++i;
		++i;
		++i;
	}

	//close files
	input.close();
	output.close();
	codon_table.close();
	return 0;
}

