#include <iostream>

using namespace std;

class Case
{
	int value;

	public:
		Case();

		bool setValue(int val, bool force);
		
		int getValue();

		int upgrade();

		void kill();
};