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
	CRC_DIV test;
	string S[2];
	int YES = 0;
	vector<int>in_test;
	vector<int>gen_test;
	if (argv[1] != NULL)
	{
		ifstream infile(argv[1]);
		if (!infile.bad())
		{
			while (getline(infile, S[YES]))
			{
				if (S[YES] == "\0")
					continue;
				YES++;
			}
			infile.close();
			if (YES < 0) cout << "The File is Corrupted";
			else
			{
				cout << "File read succeeded." << endl;
				for (int i = 0; i < S[0].length(); i++)
				{
					in_test.push_back((int)S[0][i]-'0');
				}
				for (int i = 0; i < S[1].length(); i++)
				{
					gen_test.push_back((int)S[1][i]-'0');
				}
				test.set_generator(gen_test);
				test = CRC(in_test, gen_test);
				vector<int>reminder_test = test.get_reminder();
				vector<int>output_test = test.get_output();
				cout << "reminder_test " << endl;
				for (std::vector<int>::iterator it = reminder_test.begin(); it != reminder_test.end(); ++it)
				{
					cout << *it;
				}
				cout << endl << "output_test " << endl;
				for (std::vector<int>::iterator it = output_test.begin(); it != output_test.end(); ++it)
				{
					cout << *it;
				}
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
	x.reminder.push_back(s.top());
	s.pop();
	while (s.size() > 0) {
		if (gen.size() - 1 <= x.reminder.size() - 1)
		{
			if (gen[0] == x.reminder[0] == 1)
			{
				x.output.push_back(1);
				for (int i = 0; i <= gen.size() - 1; i++)
				{
					x.reminder[i] = gen[i] ^ x.reminder[i];

				}
				x.reminder.push_back(s.top());
				s.pop();
				while ((x.reminder.size() != 0 && s.size() != 0) && (x.reminder[0] == 0))
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
			x.output.push_back(0);
		}
	}
	if (x.reminder.size() == 0)
	{
		x.output = { 0 };
		return x;
	}
	else
	{
		x.output.push_back(0);
		return x;
	}
}