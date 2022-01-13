#include "dictionary.h"
#include <iostream>

using std::cout;
using std::cin;
using std::cerr;

Dictionary startDict(string param)
{
    if(param.compare(""))
		return Dictionary();
	else
	{
		int inputThree = 0;
		while ((inputThree < 1) || (inputThree > 2))
		{
			cout << "Enter 1 if this is a new dictionary and you want to start blank.  Enter 2 if dictionary file exists.  :  \n";
			cin >> inputThree;
		}
		if (inputThree == 1)
		{
			try
			{
				return Dictionary(true);
			}
			catch (InternalProgramException& e)
			{
				cerr << e.what();
				for (int ticks = 0; ticks < 10000; ticks++)
				{
					ticks = ticks; //Do nothing.  
				}
				exit(EXIT_FAILURE);
			}
		}
		else
			return Dictionary(param);
	}
}

int main()
{
	int dictTypeOption = 0;
	while ((dictTypeOption < 1) || (dictTypeOption > 2))
	{
		cout << "Enter 1 for standard cybersecurity dictionary, or enter 2 to use a custom dictionary.  :  \n";
		cin >> dictTypeOption;
	}
        string flName = "";
	if (dictTypeOption == 2)
	{
		while ((flName.compare("")) == 0)
		{
			cout << "Please enter a valid file-path or name of the dictionary file youwould like to create or open.  :  \n";
			cin >> flName;
		}
	}
    Dictionary dict = startDict(flName);
	if (dictTypeOption == 2)
		dict.toggleCust();
	int option = 0;
	
}
