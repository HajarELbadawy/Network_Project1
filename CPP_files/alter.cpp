#include <iostream>
#include <vector>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;
//int main(int argc, char ** argv)
int main()
{
	string S[3];
	int YES = 0;
	vector<int>in_test;
	vector<int>gen_test;
	//if (argv[1] != NULL)
	{
		//ifstream infile(argv[1]);
		ifstream infile("transmitted_message.txt");
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
				//cout << "File read succeeded." << endl;
				for (int i = 0; i < S[0].length(); i++)
				{
					in_test.push_back((int)S[0][i] - '0');
				}
				for (int i = 0; i < S[1].length(); i++)
				{
					gen_test.push_back((int)S[1][i] - '0');
				}
				int bit_to_be_changed = 0;
				//cout << "please enter the noise on which bit ?" << endl;
				cin >> bit_to_be_changed;
				bit_to_be_changed = bit_to_be_changed - 1;
				for (int i = 0; i < in_test.size() - 1; i++)
				{
					if (i == bit_to_be_changed)
					{
						if (in_test[i] == 0)
						{
							in_test[i] = 1;
						}
						else
						{
							in_test[i] = 0;
						}
						break;
					}
				}
			}
		}
	}
	ofstream outfile("transmitted_message.txt");
	for (int i = 0; i < in_test.size(); i++)
	{
		outfile << (in_test[i]);
	}
	outfile << '\n';
	for (int i = 0; i < gen_test.size(); i++)
	{
		outfile << (gen_test[i]);
	}
	outfile.close();
	return 0;
}