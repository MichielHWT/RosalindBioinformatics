///Rosalind IPBR
///Michiel Herpers
///6 11 2019

#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <iterator>
#include <map>
#include <vector>


int main(int argc, char* argv[])
{
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

	///Open file to vector
	std::string line_info;
	std::getline(input, line_info);
	std::string line;
	std::stringstream ss; ss << line_info; line = ss.str(); ss.clear();
	int k = 0;
	int m = 0;
	int n = 0;
	std::string k_str = "";
	std::string m_str = "";
	std::string n_str = "";
	std::string::iterator iter;
	int counter = 0;
	std::string symbol;
	std::string symbol_1;
	std::string symbol_2;
	std::cout << "line: " << line << std::endl;
	std::cout << "type of line: " << typeid(line).name() << std::endl;

	for (iter = line.begin(); iter < line.end(); ++iter)
	{
	    std::stringstream ss; ss << *iter; symbol = ss.str(); ss.clear();
		if (symbol == " ")
		{
		    counter += 1;
		}
		else
		{
			if (counter == 0)
			{
			    k_str += symbol;
				k = std::stoi(k_str);
			}
			else if (counter == 1)
			{
			    m_str += symbol;
				m = std::stoi(m_str);
			}
			else if (counter == 2)
			{
			    n_str += symbol;
				n = std::stoi(n_str);
			}
		}
	}

	std::cout << "k: " << k << "m: " << m << "n: " << n << std::endl;
	std::map<std::string, int> map_kmn;
	map_kmn["k"] = k;
	map_kmn["m"] = m;
	map_kmn["n"] = n;
	int total;
	total = k+m+n;

	std::vector<std::string> v_kmn(3);
	v_kmn = {"k", "m", "n"};


	///Calculate the probability that the mating pair produces an individual with at least one dominant allele
	//Define dictionary contaning probability of pocessing dominant allele
	std::map<std::string, double> allele_map; //combination name, probability of dominant allele
	allele_map["kk"] = 1; //AA AA
	allele_map["km"] = 1; //AA Aa
	allele_map["kn"] = 1; //AA aa
	allele_map["mk"] = 1; //Aa AA
	allele_map["mm"] = 0.75; //Aa Aa
	allele_map["mn"] = 0.5; //Aa aa
	allele_map["nk"] = 1; //aa AA
	allele_map["nm"] = 0.5; //aa Aa
	allele_map["nn"] = 0; //aa aa

	double sum_of_probability = 0;
	double probability_dominant_allele;
	double probability_combination;
	double probability_combined;
	double p_1;
	double p_2;

	for (std::vector<std::string>::iterator it = v_kmn.begin(); it < v_kmn.end(); ++it)
	{
	    std::stringstream ss; ss << *it; symbol_1 = ss.str(); ss.clear();
		for (std::vector<std::string>::iterator it_2 = v_kmn.begin(); it_2 < v_kmn.end(); ++it_2)
		{
		    std::stringstream ss; ss << *it_2; symbol_2 = ss.str(); ss.clear();
			std::string allele_combination;
			allele_combination = symbol_1 + symbol_2;
			std::cout << "allele_combination: " << allele_combination << std::endl;
			probability_dominant_allele = allele_map[allele_combination];

            std::cout << map_kmn[symbol_1] << std::endl;
            std::cout << total << std::endl;
			p_1 = map_kmn[symbol_1]/(double)total;
			if (symbol_1 == symbol_2)
			{
				p_2 = (map_kmn[symbol_2] - 1)/(double)(total-1);
			}
			else
			{
				p_2 = (map_kmn[symbol_2])/(double)(total-1);
			}
            std::cout << "p_1: " << p_1 << " p_2: " << p_2 << std::endl;
			probability_combination = p_1*p_2;

			probability_combined = probability_dominant_allele*probability_combination;
			std::cout << probability_combined << std::endl;
			sum_of_probability += probability_combined;
		}
	}

	//Write output
	output << sum_of_probability;

	//Close input/output files
	input.close();
	output.close();

	return 0;
}

