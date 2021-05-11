#include "textgen.h"
#include <fstream>
#include <iostream>
#include<vector>

int main()
{
    setlocale(0, "");
    ifstream path;
    path.open("input.txt");
    vector<string> words;
    string word;
    while (!path.eof())
    {
        path >> word;
        words.push_back(word);
    }
    path.close();

    GenText Gobject(words, 2, 1000);
    string somthingtxt = Gobject.Generationtxt();

    ofstream file_itog;
    file_itog.open("output.txt");
    file_itog.clear();
    file_itog << somthingtxt;
    file_itog.close();

    return 0;
}