#include "textgen.h"
#include <fstream>
#include <iostream>
#include <ostream>

using namespace std;

int main()
{
	setlocale(0,"");
	string path = "text2.txt";
	ifstream file;
	file.open(path);
	if (file.is_open())
	{
		vector<string> words;
		string temp;
		while (!file.eof())
		{
			file >> temp;
			words.push_back(temp);
		}
		file.close();
		Generatortxt G_object = Generatortxt(words, 2, 1000);
		string ex = G_object.Generationtxt();
		ofstream itog;
		itog.open("itog.txt");
		if (itog.is_open())
		{
			itog << ex;
		}
		else
		{
			cout << "itog.TXT не был открыт" << endl;
		}
		itog.close();
	}
	else
	{
		cout << "Не был открыт";
	}
	return 0;
}