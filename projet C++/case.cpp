#include "case.h"

Case::Case()
{
	value = 0;
}

void Case::setValue(int val)
{
	value = val;
}

int Case::getValue()
{
	return value;
}

int Case::upgrade()
{
	value *= 2;
	return value;
}

void Case::kill()
{
	value = 0;
}