#pragma once
#include <vector>
using namespace std;
class CRC_DIV {
public:
	vector<int>output;
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
