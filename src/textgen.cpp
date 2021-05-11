#include "textgen.h"
#include <time.h>

GenText::GenText(vector<string> all_of_words, int pref_counter, int gen_counter)
{
    NPREF = pref_counter;
    MAXGEN = gen_counter;

    int i = 0;
    while (i < all_of_words.size() - NPREF + 1)
    {
        prefix pref;
        for (int j = 0; j < NPREF; j++)
            pref.push_back(all_of_words.at(i + j));
        if (i == all_of_words.size() - NPREF)
            statelab[pref].push_back("_last_of_all_prefix_");
        else
            statelab[pref].push_back(all_of_words.at(i + NPREF));
        i++;
    }
}

GenText::GenText(map<prefix, vector<string>> Gener, int m_gen)
{
    statelab = Gener;
    NPREF = statelab.begin()->first.size();
    MAXGEN = m_gen;
}

string GenText::Generationtxt()
{
    srand(time(NULL));
    string vihod;
    deque<string> words;

    auto it = statelab.begin();
    advance(it, rand() % statelab.size());
    for (int i = 0; i < NPREF; i++)
        words.push_back(it->first.at(i));

    while (vihod.size() < MAXGEN)
    {
        prefix pref;
        for (int i = 0; i < NPREF; i++)
            pref.push_back(words.at(i));
        int random = rand() % statelab.find(pref)->second.size();
        if (statelab.find(pref)->second.at(random) == "_last_of_all_prefix_")
        {
            for (int i = 0; i < NPREF; i++)
                vihod += words.at(i) + ' ';
            break;
        }
        words.push_back(statelab.find(pref)->second.at(random));

        vihod += words.at(0) + ' ';
        words.pop_front();
    }

    return vihod;
}