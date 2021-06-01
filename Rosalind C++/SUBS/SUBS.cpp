///Rosalind Exercise SUBS
///Michiel Herpers
///25 6 2017

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

	//Get strings "s" and "t" from input file
	//Only works in the right format
	//s will be in the first line
	string s;
	getline(input, s);
	cout << "s: " << s << endl;
	//t will be the second line
	string t;
	getline(input, t);
	cout << "t: " << t << endl;

	//Loop through string "s" and see if string "t" is in the string
	//Return all the starting positions at which t is in s
	int length_s = s.length();
	int length_t = t.length();
	string symbol;
	int position;
	int end_loop_s = (length_s - length_t) + 1;
	for(int i = 0; i < end_loop_s; ++i)
	{
		symbol = s[i]; 
		string code;
		stringstream ss_code;
		int end_code = i + length_t;
		for(int j = i; j < end_code; ++j)
		{
			//cout << s[j] << endl;
			ss_code << s[j];
		}
		code = ss_code.str();
		ss_code.clear();
		cout << "Code position " << i << ": " << code << endl;
		
		//Check if same as t and write to output if true
		if(code == t)
		{
			position = i + 1;
			output << position << ' ';
		}
	}

	output << '\n';
	
	//close files
	input.close();
	output.close();
	return 0;
}

