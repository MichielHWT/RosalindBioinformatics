///Rosalind GC
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

	//Count number of names in file
	int number_names = 0;
	string first_char;
	for(string line; getline(input, line);)
	{
		//cout << line << endl;
		first_char = line[0];
		//cout << first_char << endl;
		if(first_char == ">")
		{
			//cout << "New name: " << line << endl;
			number_names = number_names + 1;
		}
	}
	//Reset for getline
	input.clear();
	input.seekg(0, ios::beg); //https://stackoverflow.com/questions/5343173/returning-to-beginning-of-file-after-getline
	
	//Declare arrays
	string names[number_names] = {};
	string dna[number_names] = {};
	float GC_content_array[number_names] = {};

	//Read file and save line as array of strings for each character
	int linecounter = 0;
	bool new_name = false;
	int index = -1;
	string new_line;
	for(string line; getline(input, line);) //Note ';' after getline command
	{
		//Read file and save name of line and corresponding lines in seperate arrays 
		first_char = line[0];
		new_line = line;
		if(first_char == ">") //Create array with names
		{
			index = index + 1;
			string name = new_line; //remove ">" from name
			name.erase(0,1);
			names[index] = name;
			cout << name << endl;
			new_name = true;
		}
		else if(new_name == true) //Create array with symbols
		{
			dna[index] = new_line;
			new_name = false;
		}
		else //If there are multiple lines of symbols corresponding to one line
		{
			dna[index].append(new_line);
			//cout << new_line << endl;	
			//cout << dna[index] << endl;
		}
		linecounter = linecounter + 1;
	}

	//Calculate GC content per index number	
	string::iterator iter;
	for(int i = 0; i < number_names; ++i)
	{
		int GC_counts = 0;
		int length_symbols = dna[i].length();
		//for(int j = 0; j < length_symbols; ++j)
		for(iter = dna[i].begin(); iter < dna[i].end(); ++iter)
		{
			stringstream ss; ss << *iter; string symbol = ss.str();
			//cout << symbol << endl;
			if(symbol == "G" or symbol == "C")
			{
				GC_counts = GC_counts + 1;
			}
		}
		float GC_content = (float(GC_counts) / float(length_symbols)) * 100; //In percentage
		cout << "GC content: " << GC_content << endl;
		GC_content_array[i] = GC_content;
	}

	//Determine highest GC content
	int highest_index;
	float highest_GC_content;
	float GC_content;
	for(int i = 0; i < number_names; ++i)
	{
		if(i == 0)
		{
			GC_content = GC_content_array[0];
			highest_GC_content = GC_content;
			highest_index = 0;
		}
		else
		{
			GC_content = GC_content_array[i];
			if(GC_content > highest_GC_content)
			{
				highest_GC_content = GC_content;
				highest_index = i;
			}
		}
	}

	//Write hamm distance to answer file
	output << names[highest_index] << '\n' << GC_content_array[highest_index];	

	//Close input/output files
	input.close();
	output.close();
}

