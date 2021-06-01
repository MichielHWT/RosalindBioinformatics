///Rosalind LIA
///Michiel Herpers
///7 11 2019

/*
Given are two poritive integers k and N. k is the number of generations. N is the minimum number of offspring that has AaBb genotype.
The maximum number of generation is seven.

Return the probability that at least N organisms will have genotype AaBb at kth generation.
*/

#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iterator>
#include <typeinfo>
#include <map>

std::string genotypeSorter(std::string genotype_string)
{
    //Input is the genotype with A/a and B/b and is sorter to get capital A first and capital B first
    std::string new_genotype_string;
    std::string A_part_str = "";
    std::string B_part_str = "";
    std::string symbol;
    int counter = 0;
    for (std::string::iterator iter_str = genotype_string.begin(); iter_str < genotype_string.end(); ++iter_str)
    {
        symbol = *iter_str;
        if (counter == 0)
        {
            A_part_str += symbol;
        }
        else if (counter == 1)
        {
            if (A_part_str == "A")
            {
                A_part_str += symbol;
            }
            else if (A_part_str == "a")
            {
                A_part_str = symbol + A_part_str;
            }
        }
        if (counter == 2)
        {
            B_part_str += symbol;
        }
        else if (counter == 3)
        {
            if (B_part_str == "B")
            {
                B_part_str += symbol;
            }
            else if (B_part_str == "b")
            {
                B_part_str = symbol + B_part_str;
            }
        }
        counter += 1;
    }
    new_genotype_string = A_part_str + B_part_str;

    return new_genotype_string;
}

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
	std::string k_str; int k;
	std::string N_str; int N;
	int item_number = 0;
	while (getline(input, line_info, ' '))
	{
		//Loop through file get k and N
		if (item_number == 0)
		{
			k_str = line_info;
			k = std::stoi(k_str);
		}
		else if (item_number == 1)
		{
			N_str = line_info;
			N = std::stoi(N_str);
		}

		item_number += 1;
	}
	std::cout << "k: " << k << " N: " << N << std::endl;

    /*

    */
	//Declare all possible strings for genetype
	std::string genotype_str;
	std::string AABB = "AABB";
	std::string AaBB = "AaBB";
	std::string aaBB = "aaBB";
	std::string AABb = "AABb";
	std::string AaBb = "AaBb";
	std::string aaBb = "aaBb";
	std::string AAbb = "AAbb";
	std::string Aabb = "Aabb";
	std::string aabb = "aabb";
	//Create map contaning all genotype strings and probability each generation
	std::vector<std::string> genotype_name_vector;
	genotype_name_vector.push_back(AABB);
	genotype_name_vector.push_back(AaBB);
	genotype_name_vector.push_back(aaBB);
	genotype_name_vector.push_back(AABb);
	genotype_name_vector.push_back(AaBb);
	genotype_name_vector.push_back(aaBb);
	genotype_name_vector.push_back(AAbb);
	genotype_name_vector.push_back(Aabb);
	genotype_name_vector.push_back(aabb);
	for (std::vector<std::string>::iterator iter = genotype_name_vector.begin(); iter < genotype_name_vector.end(); ++iter)
	{
		//print vector
		std::cout << *iter << std::endl;
	}
    //Declare map for counting
	std::map<std::string, int> genotype_map;
	genotype_map[AABB] = 0;
	genotype_map[AaBB] = 0;
	genotype_map[aaBB] = 0;
	genotype_map[AABb] = 0;
	genotype_map[AaBb] = 0;
	genotype_map[aaBb] = 0;
	genotype_map[AAbb] = 0;
	genotype_map[Aabb] = 0;
	genotype_map[aabb] = 0;

	int generation = 0;
	int genotype_counter = 0;
	std::string genotype_child;
	std::string new_genotype_child;
	std::string A_str_1;
	std::string A_str_2;
	std::string B_str_1;
	std::string B_str_2;
    //Loop through generations to construct map with probabilities of genotype occuring when paring with AaBb
    for (std::vector<std::string>::iterator iter = genotype_name_vector.begin(); iter < genotype_name_vector.end(); ++iter)
    {
        //Loop through vector with genotype strings. For every genotype decide probability
        genotype_str = *iter;
        std::cout << "Genotype from vector working on now: " << genotype_str << std::endl;

        for (std::string::iterator it_str = genotype_str.begin(); it_str < genotype_str.begin() + 2; ++it_str)
        {
            //Get A/a from genotype string from child
            A_str_1 = *it_str;
            for (std::string::iterator it_str_2 = (genotype_str.begin() + 2); it_str_2 < genotype_str.end(); ++it_str_2)
            {
                //Get B/b from genotype string from child
                B_str_1 = *it_str_2;

                //Get combinations possible when mating with AaBb
                for (std::string::iterator it_str_3 = AaBb.begin(); it_str_3 < AaBb.begin() + 2; ++it_str_3)
                {
                    //Get A/a from mating partner with genotype AaBb
                    A_str_2 = *it_str_3;
                    for (std::string::iterator it_str_4 = (AaBb.begin() + 2); it_str_4 < AaBb.end(); ++it_str_4)
                    {
                        //Get B/b from mating partner with genotype AaBb
                        B_str_2 = *it_str_4;


                        //Get string of genotype from parents and count in map
                        genotype_child = A_str_1 + A_str_2 + B_str_1 + B_str_2;
                        std::cout << "Genotype child: " << genotype_child << std::endl;
                        new_genotype_child = genotypeSorter(genotype_child);
                        std::cout << "New Genotype child: " << new_genotype_child << std::endl;
                        genotype_map[new_genotype_child] += 1;
                        genotype_counter += 1;
                    }
                }
            }
        }
	}
	//Print probability of getting genotype from all genotypes with AaBb
    std::cout << "Genotypes counted: " << genotype_counter << std::endl;
    for (std::vector<std::string>::iterator iter = genotype_name_vector.begin(); iter < genotype_name_vector.end(); ++iter)
    {
        genotype_str = *iter;
        std::cout << "Genotype counted " << genotype_str << ": " << genotype_map[genotype_str] << std::endl;
    }

    /*
    Using the genotype map for probability and
    */
    //Declare map for probability first generation
	std::map<std::string, vector<double>> probability_map;
	probability_map[AABB].pushback(1/16);
	probability_map[AaBB].pushback(2/16);
	probability_map[aaBB].pushback(1/16);
	probability_map[AABb].pushback(2/16);
	probability_map[AaBb].pushback(4/16);
	probability_map[aaBb].pushback(2/16);
	probability_map[AAbb].pushback(1/16);
	probability_map[Aabb].pushback(2/16);
	probability_map[aabb].pushback(1/16);

	while (generation < k)
    {


        //Update generation
        generation += 1;
    }

    /*
    Write total expected value to output file answer.txt
    */
    //output << ;

	//Close files
	input.close();
	output.close();

	return 0;
}
