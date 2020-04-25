#pragma once
#include <vector>

class fragmentation
{
	public:
	static std::vector <double> regular(double a, double b, unsigned int amount);
	static std::vector <double> adaptive(double a, double b, unsigned int amount, double ratio);
};