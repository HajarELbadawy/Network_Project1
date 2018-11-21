#include <iostream>
#include <vector>
#include <stack>
#include<cstdlib>
#include<string>
#include<fstream>
using namespace std;
class CRC_DIV {
public:
	vector<int>output ;
	vector<int>reminder;
	vector<int>input;
	vector<int>generator;
	CRC_DIV();
	friend CRC_DIV CRC(vector<int>in, vector<int>gen);
	void set_input(vector<int>in);
	void set_generator(vector<int>gene);

	vector<int>get_output();
	vector<int>get_reminder();

};
CRC_DIV ::CRC_DIV()
{
	vector<int>output = {0};
	vector<int>reminder={0};
	vector<int>input={0};
	vector<int>generator={0};
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
	//vector<int>output;
	//vector<int>reminder;//R
	x.reminder.push_back(s.top());
	s.pop();
	while (s.size() > 0) {
		if (gen.size() - 1 <= x.reminder.size()-1)
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
			x.output.push_back(0);
		}
	}
	if(x.reminder.size()==0)
	{
		x.output = {0};
		return x;
	}
	else 
	{
		x.output.push_back(0);
		return x;
	}
}
void CRC_DIV::set_input(vector<int>in)
{
	 input=in;
}
void CRC_DIV::set_generator(vector<int>gene)
{
	generator= gene;
}
vector<int>CRC_DIV::get_output()
{
	return output;
}
vector<int> CRC_DIV::get_reminder()
{
	return reminder;
}
int main() {
	CRC_DIV test;
	//vector<int>in_test = { 1,1,0,1,0,1 };
	vector<int>in_test = { 1,1,0,1,0,1,1,1,1,1,0,0,1,0 };
	//vector<int>in_test = { 1,0,0,1,1,1,0,1,0,0,0 };
	test.set_input(in_test);
	//vector<int>gen_test = { 1,0,1 };
	vector<int>gen_test = {1,0,0,1,1};
	//vector<int>gen_test = { 1,0,0,1 };
	test.set_generator(gen_test);

	test = CRC(in_test, gen_test);
	vector<int>reminder_test = test.get_reminder();
	vector<int>output_test = test.get_output();
	cout << "reminder_test " << endl;
	for (std::vector<int>::iterator it = reminder_test.begin(); it != reminder_test.end(); ++it)
	{
		std::cout  <<*it;
    }
	std::cout<<endl << "output_test " << endl;
	for (std::vector<int>::iterator it = output_test.begin(); it != output_test.end(); ++it)
	{
		std::cout <<  *it;
	}
	system("pause");
}

