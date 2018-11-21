#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <fstream>
#include "BinaryDivision.h"
using namespace std;
CRC_DIV CRC(vector<int>in, vector<int>gen);

//int main(int argc, char ** argv)
int main()
{
	string S[3];//array of strings to store the lines in the input file
	int YES = 0;//just a counter
	//CRC class
	CRC_DIV test;
	vector<int>Data_Transmitted;
	vector<int>Generator_Function;
	//Read the input text file that is sent as an argument to this program.
	//if (argv[1] != NULL)
	{
		//ifstream infile(argv[1]);
		ifstream infile("transmitted_message.txt");
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
					Data_Transmitted.push_back((int)S[0][i] - '0');
				}
				for (unsigned int i = 0; i < S[1].length(); i++)
				{
					Generator_Function.push_back((int)S[1][i] - '0');
				}
				test.set_input(Data_Transmitted);
				test.set_generator(Generator_Function);
				//Binary Division
				test = CRC(Data_Transmitted, Generator_Function);
				//Get Remainder
				vector<int>remainder = test.get_remainder();
				//checking the remainder is equal to 0
				bool Zero_flag = true;
				for (std::vector<int>::iterator it = remainder.begin(); it != remainder.end(); ++it)
				{
					if (*it != 0)
					{
						Zero_flag = false;
						break;
					}
				}
				if (Zero_flag == true)
					cout << "message is correct"<<endl;
				else
					cout << "message is not correct"<<endl;

			}
		}
	}
	system("pause");
	return 0;
}

CRC_DIV CRC(vector<int>in, vector<int>gen)
{
	CRC_DIV x;
	stack<int> s;
	x.input = in;
	x.generator = gen;
	for (int i = in.size() - 1; i >= 0; i--)
	{
		int element = in[i];
		s.push(element);
	}
	//vector<int>output;
	//vector<int>reminder;//R
	x.remainder.push_back(s.top());
	s.pop();
	while (s.size() > 0) {
		if (gen.size() - 1 <= x.remainder.size() - 1)
		{
			if (s.size() != 0 && x.remainder.size() == 0) { x.remainder.push_back(0); }
			if (gen[0] == x.remainder[0] == 1)
			{
				x.quotient.push_back(1);
				for (unsigned int i = 0; i <= gen.size() - 1; i++)
				{
					x.remainder[i] = gen[i] ^ x.remainder[i];

				}
				x.remainder.push_back(s.top());
				s.pop();
				while ((x.remainder.size() != 0 && s.size() != 0) && (x.remainder[0] == 0))
				{
					//if(s.size()==0 && x.remainder.size() !=0 )
					x.remainder.erase(x.remainder.begin());
					//kol da 3ashan ashel al zero al 3ala al shemal 
				}

			}

		}
		else
		{
			x.remainder.push_back(s.top());
			s.pop();
			x.quotient.push_back(0);
		}
	}
	if ((s.size() == 0) && (x.remainder.size() == 0))
	{
		x.quotient = { 0 };
		return x;
	}
	else
	{
		x.quotient.push_back(0);
		return x;
	}
}