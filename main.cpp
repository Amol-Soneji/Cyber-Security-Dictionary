#include "dictionary.h"
#include <iostream>

using std::cout;
using std::cin;


int main()
{
	int dictTypeOption = 0;
	while ((dictTypeOption < 1) || (dictTypeOption > 2))
	{
		cout << "Enter 1 for standard cybersecurity dictionary, or enter 2 to use a custom dictionary.  :  \n";
		cin >> dictTypeOption;
	}
	Dictionary dict();
	if (dictTypeOption == 2)
	{
		string flName = "";
		while ((flName.compare("")) == 0)
		{
			cout << "Please enter a valid file-path or name of the dictionary file youwould like to create or open.  :  \n";
			cin >> flName;
		}
		

	}

}