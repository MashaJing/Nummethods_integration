#include "integral.h"
#include "intervals.h"
#include <vector>
#include <list>

integral::integral(Integration_Scheme_Type type)
{
	switch (type)
	{
	case Trapeze:
		alpha = { 1, 1 };
		nodes = { 1, -1 };
		break;

	case Rectangle:
		alpha = { 2 };
		nodes = { 0 };
		break;

	case Gauss4:
		alpha = { (18 + sqrt(30)) / 36,
			 (18 + sqrt(30)) / 36,
			 (18 - sqrt(30)) / 36,
			 (18 - sqrt(30)) / 36 };

		nodes = { sqrt((3 - 2 * sqrt(6. / 5)) / 7) ,
		 -sqrt((3 - 2 * sqrt(6. / 5)) / 7),
		  sqrt((3 + 2 * sqrt(6. / 5)) / 7),
		 -sqrt((3 + 2 * sqrt(6. / 5)) / 7) };
		break;

	case Gauss5:
		alpha = { 128. / 225, 
			(322 + 13 * sqrt(70)) / 900, 
			(322 + 13 * sqrt(70)) / 900, 
			(322 - 13 * sqrt(70)) / 900, 
			(322 - 13 * sqrt(70)) / 900 };

		nodes = { 0,
		1. / 3 * sqrt(5 - 2 * sqrt(19. / 7)),
		-1. / 3 * sqrt(5 - 2 * sqrt(19. / 7)),
		1. / 3 * sqrt(5 + 2 * sqrt(19. / 7)),
		-1. / 3 * sqrt(5 + 2 * sqrt(19. / 7)) };
		break;
	};
}

integral::integral()
{

}

double integral::Count(double f(double x), double& a, double& b, int num_steps)
{
	if ( num_steps <= 1|| f == NULL || a == b ) throw exception("Incorrect parameters");
	if (a > b) 
	{
		double tmp = a;
		 a = b;
		 b = tmp;
	}
	double x = a, result = 0;
	
	std::vector<double> H = fragmentation::regular(a, b, num_steps);

	for (auto const &h : H)
	{
		for (int i = 0; i < nodes.size(); i++)
		{
			result+= h*alpha[i]*f(h*(nodes[i] + 1)/2 + x); //общая формула для всех методов численного интегрирования
		}
		x += h;
	}
	return result/ 2;
}