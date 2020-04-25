#include <iostream>
#include "Integral.h"
#include "Intervals.h"

using namespace std;

void main()
{
	integral I1(integral::Rectangle);
	integral I2(integral::Trapeze);
	integral I3(integral::Gauss4);
	integral I4(integral::Gauss5);

	double a = 0, b = 4, I_Rectangle, I_Gauss4, I_Gauss5, I_NK, I_NL,
	I2_Rectangle, I2_Gauss4, I2_Gauss5, I2_NK;
	int steps = 10;

	auto f = [](double x){return exp(x);};
	auto F = [](double x){return exp(x);};


	try
	{
		//////////////////////h = 10////////////////////////
		I_Rectangle = I1.Count(f, a, b, steps);
		I_NK = I2.Count(f, a, b, steps);
		I_Gauss4 = I3.Count(f, a, b, steps);
		I_Gauss5 = I4.Count(f, a, b, steps);

		I_NL = fabs(F(b) - F(a));

		std::cout << std::scientific;
		
		for (rsize_t i = 0; i < 2; ++i)
		{
			
			cout << "////////////////////////////////////////////////////" << endl;
			cout << i << endl;
			
			cout << "H = " << fabs(a - b) / steps << endl;
			////////////////////// h*2 ////////////////////////
			steps *= 2;

			I2_Rectangle = I1.Count(f, a, b, steps);
			I2_NK = I2.Count(f, a, b, steps);
			I2_Gauss4 = I3.Count(f, a, b, steps);
			I2_Gauss5 = I4.Count(f, a, b, steps);

			//////////////////////RESULT OUTPUT, COUNTING "k"////////////////////////

			cout << "H*2 = " << fabs(a - b) / steps << endl;


			double k = log2(fabs(1 + (I2_Gauss5 - I_Gauss5) / (I_NL - I2_Gauss5))); 
			cout << "Gauss5 = " << I_Gauss5 << endl;
			cout << "|True - Gauss5| = " << fabs(I_NL - I_Gauss5) << endl;
			cout << "(I2_Gauss5 - I_Gauss5) / (I* - I2_Gauss5) =" << (I2_Gauss5 - I_Gauss5) / (I_NL - I2_Gauss5) << endl;
			cout << "(I2_Gauss5 - I_Gauss5) / (2^k - 1) =" << (I2_Gauss5 - I_Gauss5) / (pow(2, k) - 1) << endl;

			k = log2(fabs(1 + (I2_Gauss4 - I_Gauss4) / (I_NL - I2_Gauss4)));
			cout << endl << "Gauss4 = " << I_Gauss4 << endl;
			cout << "|True - Gauss4| = " << fabs(I_NL - I_Gauss4) << endl;
			cout << "(I2_Gauss4 - I_Gauss4) / (2^k - 1) =" << (I2_Gauss4 - I_Gauss4) / (pow(2, k) - 1) << endl;


			k = log2(fabs(1 + (I2_Rectangle - I_Rectangle) / (I_NL - I2_Rectangle)));
			cout << endl << "Rectangle = " << I_Rectangle << endl;
			cout << "|True - Rectangle| = " << fabs(I_NL - I_Rectangle) << endl;
			cout << "(I2_Rectangle - I_Rectangle) / (2^k - 1) =" << (I2_Rectangle - I_Rectangle) / (pow(2, k) - 1) << endl;


			k = log2(fabs(1 + (I2_NK - I_NK) / (I_NL - I2_NK)));
			cout << endl << "Trapeze = " << I_NK << endl;
			cout << "|True - Trapeze| = " << fabs(I_NL - I_NK) << endl;
			cout << "(I2_Trapeze - I_Trapeze) / (2^k - 1) =" << (I2_NK - I_NK) / (pow(2, k) - 1) << endl;

			cout << endl;

			I_Rectangle = I2_Rectangle;
			I_NK = I2_NK;
			I_Gauss4 = I2_Gauss4;
			I_Gauss5 = I2_Gauss5;
		}
		
		
	}
	catch (exception & ex)
	{
		cout << ex.what() << endl;
	}
}

//O//		///O//

   	 //..//

///ооооооооооо////