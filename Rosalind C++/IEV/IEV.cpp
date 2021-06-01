///Rosalind IEV
///Michiel Herpers
///7 11 2019

/*
Given are six nonnegative integers representing the number of couples with a specific genotype
1. AA-AA
2. AA-Aa
3. AA-aa
4. Aa-Aa
5. Aa-aa
6. aa-aa
Return the expected number of offspring showing dominant phenotype when every couple gets two offspring
*/

#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <typeinfo>

int main(int argc, char* argv[])
{
	/*
	Open files
	*/
	//Open input file for reading
	std::string filename_input;
	std::stringstream filename_input_ss;
	std::ifstream input;
	filename_input_ss << argv[1];
	filename_input = filename_input_ss.str();
	input.open(filename_input);

	//Open output file for writing
	std::string filename_output;
	filename_output = "answer.txt";
	std::ofstream output;
	output.open(filename_output);

	/*
	Read input file and give integer values respresenting number of couples per genotype to right variable
	*/
	//Open file to vector
	std::string line_info;
	std::vector<std::string> gen_numbers;
	while (getline(input, line_info, ' '))
	{
		//Loop through file and put integer values as string in vector
		gen_numbers.push_back(line_info);
	}
    //Check if this works
	for (std::vector<std::string>::iterator iter = gen_numbers.begin(); iter < gen_numbers.end(); ++iter)
    {
        std::string gen_number;
        gen_number = *iter;
        std::cout << gen_number << std::endl;
    }

    /*
    Calculate the expected value using probabilities for dominant phenotype offspring per couple
    */
    //Declare variables
    double p1 = 1;
    double p2 = 1;
    double p3 = 1;
    double p4 = 0.75;
    double p5 = 0.5;
    double p6 = 0;
    double array_p [6] = {p1, p2, p3, p4, p5, p6};
    int counter = 0;
    std::string gen_number_str;
    int gen_number_int;
    double E_total = 0;
    double E_value_X;
    double E_value_Y;
    //Iterate through gen_numbers and calculate expected number of dominant phenotype per genotype and sum for total expected value E_total
    for (std::vector<std::string>::iterator iter = gen_numbers.begin(); iter < gen_numbers.end(); ++iter)
    {
        gen_number_str = *iter;
        std::cout << "type of gen_number_str: " << typeid(gen_number_str).name() << std::endl;
        gen_number_int = std::stoi(gen_number_str);
        E_value_X = gen_number_int*array_p[counter];
        E_value_Y = gen_number_int*array_p[counter];
        std::cout << "E_value_X: " << E_value_X << std::endl;
        E_total += (E_value_X + E_value_Y);
        std::cout << "E_total: " << E_total << std::endl;
        counter += 1;
    }

    /*
    Write total expected value to output file answer.txt
    */
    output << E_total;

	//Close files
	input.close();
	output.close();

	return 0;
}
