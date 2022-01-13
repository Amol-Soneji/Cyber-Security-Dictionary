#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "InternalProgramException.h"
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using std::map;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::istringstream;


class Dictionary
{
	public:
		Dictionary()
		{
			custPathSet = false;
			usingCust = false;
			ifstream stdDictFile;
			try
			{
				stdDictFile.open("./Dictionary.csv");
			}
			catch (...)
			{
				throw InternalProgramException();
			}
			string line;
			while (std::getline(stdDictFile, line))
			{
				istringstream iSStream(line);
				string term, def;
				std::getline(iSStream, term, ',');
				std::getline(iSStream, def, ',');
				dictMap.insert(term, def);
			}
			stdDictFile.close();
		}
		Dictionary(bool isNew, string path)
		{
			if (!isNew)
				throw InternalProgramException();
			customPath = path;
		}
		Dictionary(string path)
		{
			usingCust = true;
			customPath = path;
			custPathSet = true;
			ifstream dictFile;
			try
			{
				dictFile.open(customPath);
			}
			catch (...)
			{
				throw;
			}
			string line;
			while (std::getline(dictFile, line))
			{
				istringstream iSStream(line);
				string term, def;
				std::getline(iSStream, term, ',');
				std::getline(iSStream, def, ',');
				dictMap.insert(term, def);
			}
			dictFile.close();
		}
		void toggleCust()
		{
			usingCust = !usingCust;
		}
		bool isCustPathSet()
		{
			return custPathSet;
		}
		void setCustPath(string path)
		{
			customPath = path;
		}
		bool saveCustDict()
		{
			ofstream dictToWrite;
			dictToWrite.open(customPath);
			string first, second;
			bool toReturn = false;
			for (map<string, string>::iterator it = dictMap.begin(); it != dictMap.end(); it++)
			{
				dictToWrite << it->first << "," << it->second << "\n";
			}
			dictToWrite.close();
			bool toReturn = true;
			return toReturn;
		}
		string getJustDef(string term);
		vector<string> getDefAndTerm(string term);
		bool addTerm(vector<string> term);
		void displayEntireDict();
		void dictClose();
	private:
		string customPath;
		bool custPathSet;
		bool usingCust;
		map<string, string> dictMap;
};
#endif