#pragma once
#include<iostream>
#include<string>
#include<map>
#include<deque>
#include<vector>
using namespace std;

class Generatortxt
{
protected:
	typedef deque<string> prefix;          // очередь префиксов
	map<prefix, vector<string> > statetab; // префикс-суффиксы
	int NPREF ; // количество слов в префиксе
	int MAXGEN = 1000; //объем текста на выходе
public:
	Generatortxt(vector<string> words, int n_pref ,int max_gen);
	Generatortxt(map<prefix, vector<string>> Gener, int pref,int m_gen);
	string Generationtxt();
};
