#include "case.h"

Case::Case()
{
	value = 0;
}

bool Case::setValue(int val, bool force)
{
	if (!force && value != 0)
		return false;
	value = val;
	return true;
}

int Case::getValue()
{
	return value;
}

void Case::setMerged(bool merge)
{
	merged = merge;
}

bool Case::getMerged()
{
	return merged;
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