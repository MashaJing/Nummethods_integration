#include "Intervals.h"

std::vector<double> fragmentation::regular(double a, double b, unsigned int amount) //amount - количество участков на отрезке АВ
{
	if (b <= a || amount < 2 || (fabs(b - a) / amount == 0))
		throw std::exception("incorrect input parameters for regular fragmentation ");
	
	std::vector<double> res(amount, fabs(b - a) / amount); //res - массив с длинами шагов
	
	return res;
}


std::vector<double> fragmentation::adaptive(double a, double b, unsigned int amount, double ratio)
{
	if (b <= a || ratio < 1) throw std::exception("incorrect input parameters for adaptive fragmentation");
	if (ratio == 1) return fragmentation::regular(a, b, amount);

	std::vector<double> h(2, fabs(b - a) / pow(ratio, amount));
	
	for (int i = 1; i < amount ; i++)
	{
		h.push_back(h[i] * ratio);
	}
	
	return h;
}