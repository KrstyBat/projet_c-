#include <iostream>
#include "test.h"

Test::Test()
{
	num = 0;
};

int Test::add(int val)
{
	num += val;
	return num; 
};

int Test::getNumber()
{
	return num;
}