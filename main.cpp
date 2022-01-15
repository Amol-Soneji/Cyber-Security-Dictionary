#include "dictionary.h"
#include <iostream>

using std::cout;
using std::cin;
using std::cerr;

Dictionary startDict(string param)
{
	if (param.compare("") == 0)
	{
		try
		{
			return Dictionary();
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
				return Dictionary(true, param);
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
		{
			try
			{
				return Dictionary(param);
			}
			catch (...)
			{
				cout << "Error:  Count not access file, or file not found.  \n";
				cout << "Program will close in 10 seconds.  \n";
				for (int ticks = 0; ticks < 10000; ticks++)
				{
					ticks = ticks; //Do nothing.  
				}
				exit(EXIT_FAILURE);
			}
		}
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
			cout << "Please enter a valid file-path or name of the dictionary file you would like to create or open.  :  \n";
			cin >> flName;
		}
	}
    Dictionary dict = startDict(flName);
	if (dictTypeOption == 2)
		dict.toggleCust();
	int option = 0;
	while ((option == 0) && (option != 5))
	{
		while ((option < 1) || (option > 5))
		{
			cout << "Please enter one of the following options.  :  \n"
				<< "1    -     To show entire dictionary.  \n"
				<< "2    -     Search for a term, but only show definition.  \n"
				<< "3    -     Search for a term, and show both term and definition.  \n"
				<< "4    -     Add a term and definition to the dictionary.  \n"
				<< "5    -     To exit program.  \n";
			cin >> option;
		}
		if (option == 1)
		{
			dict.displayEntireDict();
			option = 0;
		}
		else if (option == 2)
		{
			string term, def;
			cout << "Enter the term you wish to search for.  :  \n";
			cin >> term;
			def = dict.getJustDef(term);
			cout << "Definition:  \n"
				<< def << "\n";
			option = 0;
		}
		else if (option == 3)
		{
			string term;
			cout << "Enter the term you wish to search for.  :  \n";
			cin >> term;
			vector<string> termAndDef = dict.getDefAndTerm(term);
			cout << "----Term----------------------------------Definition-------------------\n"
				<< "  " << termAndDef[0] << "                  " << termAndDef[1] << "              \n";
			option = 0;
		}
		else if (option == 4)
		{
			vector<string> termAndDef;
			termAndDef.resize(2);
			vector<string>::iterator it = termAndDef.begin();
			cout << "Enter the term to add.  :  \n";
			cin >> *it;
			it = std::next(it, 1);
			cout << "Enter the definition to add.  :  \n";
			cin >> *it;
			if (dict.addTerm(termAndDef))
				cout << "Term and definition added successfuly.  \n";
			else
				cout << "Term not added, as it already exists in dectionary.  ";
			option = 0;
		}
	}
	dict.dictClose();
	return 0;
}
