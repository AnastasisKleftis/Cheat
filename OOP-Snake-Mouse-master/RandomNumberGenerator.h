// RandomNumberGenerator.h: UserInterface for the RandomNumberGenerator class
//////////////////////////////////////////////////////////////////////
//---------------------------------------------------------------------
// Date       Programmer    Amendments made and justification (if needed)
//---------------------------------------------------------------------
// 
//
//---------------------------------------------------------------------

#if !defined(RandomNumberGeneratorH)
#define RandomNumberGeneratorH

#include <stdlib.h>	//for srand and rand routines
#include <cassert>	//for assert
#include <ctime>	//for time used in RandomNumberGenerator::seed routines
using namespace std;

 class RandomNumberGenerator
{
	public:
			//constructors //assessors
			RandomNumberGenerator();
			int get_random_value(int) const;
	private:
};
#endif // !defined(RandomNumberGeneratorH)

