#include <case.h>

Case::Case(int val)
{
	value = val;
}

int Case::getNextEvolution()
{
	return value*2;
}