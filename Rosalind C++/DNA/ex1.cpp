///Exercise 1 Rosalind
///Michiel Herpers
///12 6 2017

#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <random>
#include <fstream>
#include <cmath>
#include <iterator>

using namespace std;

int main(int argc, char* argv[])
{
	//Create counters
	int A_counter = 0;
	int T_counter = 0;
	int G_counter = 0;
	int C_counter = 0;

	//Define iterator
	string::iterator iter;
	string letter;

	//Open file
	string input_file_name;
	stringstream input_file_name_ss;
	stringstream line_info_ss;
	input_file_name_ss << argv[1];
	string line;
	input_file_name = input_file_name_ss.str();
	ifstream input_file;
	input_file.open(input_file_name);
	while (input_file.eof() != true) //For some reason runs this 3x
	{
		getline(input_file, line);
		cout << line << endl;
		//cout << typeid(line).name() << endl;

		//Convert char into string
		line_info_ss << line;
		string line_info;
		line_info = line_info_ss.str();
		//cout << line_info << endl;
		//Iterate through string
		for (iter = line_info.begin(); iter < line_info.end(); ++iter)
		{
			cout << *iter << endl;
			letter = *iter;
			switch (*iter)
			{
                case 'A':
                    A_counter += 1;
                    break;
                case 'T':
                    T_counter += 1;
                    break;
                case 'G':
                    G_counter += 1;
                    break;
                case 'C':
                    C_counter += 1;
                    break;
			}
		}
		//Empty stringstreams
		line_info_ss.str("");
		line_info_ss.clear();
	}

	//Print counts
	cout << "Counts: " << "\t" << A_counter << "\t" << C_counter << "\t" << G_counter << "\t" << T_counter << endl;

	//Create txt file with the answer
	string filename;
	stringstream filename_ss;
	fstream myfile;
	filename_ss << "answer.txt";
	filename = filename_ss.str();
	cout << filename << endl;
	myfile.open(filename, ios::out);
	myfile << A_counter << "\t" << C_counter << "\t" << G_counter << "\t" << T_counter << "\n";
	myfile.close();

	input_file.close();
	return 0;
}


