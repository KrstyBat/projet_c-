#include <iostream>

using namespace std;

class Case
{
	int value;
	bool merged = false;

	public:
		Case();

		bool setValue(int val, bool force);
		
		int getValue();

		void setMerged(bool merge);

		bool getMerged();

		int upgrade();

		void kill();
};