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
	map<string, string>::iterator it = Dictionary::dictMap.find(term);
	if (it == Dictionary::dictMap.end())
	{
		return "Term not found.  \n";
	}
	return it -> second;
}

vector<string> Dictionary::getDefAndTerm(string term)
{
	vector<string> toReturn;
	map<string, string>::iterator it = Dictionary::dictMap.find(term);
	if (it == Dictionary::dictMap.end())
	{
		toReturn = { "N/A", "Term not found in dictionary.  \n" };
		return toReturn;
	}
	toReturn.resize(2);
	vector<string>::iterator itTwo = toReturn.begin();
	toReturn.insert(itTwo, it -> first);
	toReturn.insert(std::next(itTwo, 1), it -> second);
	return toReturn;
}

bool Dictionary::addTerm(vector<string> termToAdd)
{
	if(!Dictionary::isCustPathSet())
	{
		Dictionary::toggleCust();
		string toBePath;
		cout << "Please enter the name of file (if to store in program directory)\n or path, relative to this programs working directory.  \n";
		cin >> toBePath;
		Dictionary::setCustPath(toBePath);
	}
	if ((getDefAndTerm(termToAdd[0])[0].compare(termToAdd[0])) == 0)
	{
		return false;
	}
	Dictionary::dictMap.insert(pair<string, string>(termToAdd[0], termToAdd[1]));
	return true;

}

void Dictionary::displayEntireDict()
{
	cout << "---Term--------------------------------------------Definition------\n";
	for (map<string, string>::iterator it = Dictionary::dictMap.begin(); it != Dictionary::dictMap.end(); it++)
	{
		cout << "   " << it->first << "                   " << it->second << "      \n";
	}
}

void Dictionary::dictClose()
{
	if (Dictionary::isCustPathSet())
	{
		bool status = Dictionary::saveCustDict();
		if (status)
			cout << "Dictionary succesfully saved.  \n";
		else
			cout << "There was an error when trying to save dictionary.  \n";
	}
	cout << "Dictionary closed.  \n";
}
