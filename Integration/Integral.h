#pragma once
#include <cmath>
#include <vector>

#define EPS 0.0001

using namespace std;

//класс схемы интегрирования
class integral 
{
	std::vector<double> alpha;
	std::vector<double> nodes;

	public:
	enum Integration_Scheme_Type
		{
			Rectangle,
			Trapeze,
			Gauss4 = 4, 
			Gauss5
		};
	integral(Integration_Scheme_Type type);
	integral();

	double Count(double f(double x), double& a, double& b, int ratio);
};
