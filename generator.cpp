#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <fstream>
#include "BinaryDivision.h"
using namespace std;
CRC_DIV CRC(vector<int>in, vector<int>gen);
int main(int argc, char ** argv)
{
	string S[3];//array of strings to store the lines in the input file
	int YES = 0;//just a counter
	//CRC class
	CRC_DIV test;
	vector<int>Data;
	vector<int>Generator_Function;
	//output file
	ofstream outfile("transmitted_message.txt");
	//Read the input text file that is sent as an argument to this program.
	if (argv[1] != NULL)
	{
		ifstream infile(argv[1]);
		if (!infile.bad())
		{//store what in the input text file (2 lines) in 2 strings
			while (getline(infile, S[YES]))
			{
				if (S[YES] == "\0")
					continue;
				YES++;
			}
			infile.close();
			if (YES < 0) std::cout << "The File is Corrupted";
			else
			{
				//cout << "File read succeeded." << endl;
				//store the 2 strings in 2 integer vectors. 1 char at a time
				for (unsigned int i = 0; i < S[0].length(); i++)
				{
					Data.push_back((int)S[0][i]-'0');
				}
				for (unsigned int i = 0; i < S[1].length(); i++)
				{
					Generator_Function.push_back((int)S[1][i]-'0');
					if (i == 0)
						continue;
					//add zeros to the data. The number of zeros is equal to the order of the generator function
					//So the number of 0s equals the number of characters in the 2nd line in the input text file - 1
					else
						Data.push_back(0);
				}
				test.set_input(Data);
				test.set_generator(Generator_Function);
				//Binary Division
				test = CRC(Data, Generator_Function);
				//Get Remainder
				vector<int>remainder = test.get_remainder();
				//erasing the zeros I added to the original Data
				for (unsigned int k = 1; k < Generator_Function.size(); k++)
				{
					Data.pop_back();
				}
				//outputing the original data
				for (unsigned int j = 0; j < Data.size(); j++)
				{
					outfile << Data[j];
				}
				//outputing the remainder
				for (std::vector<int>::iterator it = remainder.begin(); it != remainder.end(); ++it)
				{
					outfile << *it;
				}
				outfile << endl ;
				//outputing the generator function
				for (std::vector<int>::iterator it = Generator_Function.begin(); it != Generator_Function.end(); ++it)
				{
					outfile << *it;
				}
				outfile << endl;
			}
		}
	}
	return 0;
}
CRC_DIV CRC(vector<int>in, vector<int>gen)
{
	CRC_DIV x;
	stack<int> s;
	x.input = in;
	x.generator = gen;
	for (int i = in.size() - 1; i >=0 ; i--)
	{
		int element = in[i];
		s.push(element);
	}
	//vector<int>quotient;
	//vector<int>reminder;//R
	x.reminder.push_back(s.top());
	s.pop();
	while (s.size() > 0) {
		if (gen.size() - 1 <= x.reminder.size()-1)
		{
			if (s.size() != 0 && x.reminder.size() == 0) { x.reminder.push_back(0); }
			if (gen[0] == x.reminder[0] == 1)
			{
				x.quotient.push_back(1);
				for (int i = 0; i <= gen.size() - 1; i++)
				{
					x.reminder[i] = gen[i] ^ x.reminder[i];
					
				}
				x.reminder.push_back(s.top());
				s.pop();
					while ((x.reminder.size() != 0 && s.size()!=0)&&(x.reminder[0] == 0))
					{
//						if(s.size()==0 && x.reminder.size() !=0 )
							x.reminder.erase(x.reminder.begin());
						//kol da 3ashan ashel al zero al 3ala al shemal 
					}
				
			}
		
		}
		else
		{
			x.reminder.push_back(s.top());
			s.pop();
			x.quotient.push_back(0);
		}
	}
	if((s.size() == 0)&&(x.reminder.size()==0) )
	{
		x.quotient = {0};
		return x;
	}
	else 
	{
		x.quotient.push_back(0);
		return x;
	}
}