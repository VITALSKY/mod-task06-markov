#include "textgen.h"
Generatortxt::Generatortxt(vector<string> words, const int n_pref, const int max_gen)
{
	int i = 0;
	int j = 0;
	NPREF = n_pref;
	MAXGEN = max_gen;
	string str = "";
	while (i < words.size() + 1 - n_pref)
	{
		prefix pref;
		for (j = 0; j < n_pref; j++)
		{
			str = words[i + j];
			pref.push_back(str);
			str = "";
		}
		if ((words.size() - n_pref - i) == 0)
		{
			statetab[pref].push_back("last of all preffix");
		}
		else
		{
			statetab[pref].push_back(words[i + n_pref]);
		}
		i++;
	}
}
Generatortxt::Generatortxt(map<prefix, vector<string>> Gener, int pref, int m_gen)
{
	NPREF = pref;
	MAXGEN = m_gen;
	statetab = Gener;
}
string Generatortxt::Generationtxt()
{
	srand(time(0));
	string vihod;
	deque<string> words;


	for (int i = 0; i < NPREF; i++)
		words.push_back(statetab.begin()->first[i]);

	while (vihod.size() < MAXGEN)
	{
		prefix prefF;
		for (int i = 0; i < NPREF; i++)
			prefF.push_back(words[i]);
		int random = rand() % statetab.find(prefF)->second.size();
		if (statetab.find(prefF)->second[random] == "last of all preffix")
		{
			for (int i = 0; i < NPREF; i++)
				vihod += words[i] + ' ';
			break;
		}
		words.push_back(statetab.find(prefF)->second[random]);

		vihod += words[0] + ' ';

		words.pop_front();
	}
	return vihod;
}