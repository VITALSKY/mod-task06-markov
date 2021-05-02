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
	typedef deque<string> prefix;          // ������� ���������
	map<prefix, vector<string> > statetab; // �������-��������
	int NPREF ; // ���������� ���� � ��������
	int MAXGEN = 1000; //����� ������ �� ������
public:
	Generatortxt(vector<string> words, int n_pref ,int max_gen);
	Generatortxt(map<prefix, vector<string>> Gener, int pref,int m_gen);
	string Generationtxt();
};
