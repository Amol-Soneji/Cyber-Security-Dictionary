#include "dictionary.h"
#include <algorithm>
#include <iostream>
#include <utility>

using std::sort;
using std::cout;
using std::cin;
using std::pair;

string Dictionary::getJustDef(string term)
{
	string first;
	string second;
	map<string, string>::iterator it = Dictionary::dictMap.find(term);
	*it->first;
	*it->second;
	return second;
}

vector<string> Dictionary::getDefAndTerm(string term)
{
	vector<string> toReturn;
	string first, second;
	map<string, string>::iterator it = Dictionary::dictMap.find(term);
	*it->first;
	*it->second;
	toReturn.reserve(2);
	vector<string>::iterator itTwo = toReturn.begin();
	toReturn.insert(itTwo, first);
	toReturn.insert(itTwo + 1, second);
	return toReturn;
}

bool Dictionary::addTerm(vector<string> termToAdd)
{
	if(!Dictionary::isCustPathSet)
	{
		Dictionary::toggleCust();
		string toBePath;
		cout << "Please enter the name of file (if to store in program directory)\n or path, relative to this programs working directory.  \n";
		cin >> toBePath;
		Dictionary::setCustPath(toBePath);
	}
	Dictionary::dictMap.insert(pair<string, string>(termToAdd[0], termToAdd[1]));
}

void Dictionary::displayEntireDict()
{
	cout << "---Term--------------------------------------------Definition------\n";
	string first, second;
	for (map<string, string>::iterator it = Dictionary::dictMap.begin(); it != Dictionary::dictMap.end(); it++)
	{
		cout << "   " << *it->first << "                   " << *it->second << "      \n";
	}
}

void Dictionary::dictClose()
{
	if (Dictionary::isCustPathSet)
	{
		bool status = Dictionary::saveCustDict();
		if (status)
			cout << "Dictionary succesfully saved.  \n";
		else
			cout << "There was an error when trying to save dictionary.  \n";
	}
	cout << "Dictionary closed.  \n";
}
