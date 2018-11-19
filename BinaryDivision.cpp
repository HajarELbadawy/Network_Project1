#include <vector>
#include <stack>
#include "BinaryDivision.h"
using namespace std;
CRC_DIV::CRC_DIV()
{
	vector<int>output = { 0 };
	vector<int>reminder = { 0 };
	vector<int>input = { 0 };
	vector<int>generator = { 0 };
}
void CRC_DIV::set_input(vector<int>in)
{
	input = in;
}
void CRC_DIV::set_generator(vector<int>gene)
{
	generator = gene;
}
vector<int>CRC_DIV::get_output()
{
	return output;
}
vector<int> CRC_DIV::get_reminder()
{
	return reminder;
}