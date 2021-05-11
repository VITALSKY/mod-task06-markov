#include <deque>
#include <map>
#include <string>
#include <vector>

using namespace std;

class GenText
{
private:
    typedef deque<string> prefix;
    map<prefix, vector<string>> statelab;
    int NPREF = 2;
    int MAXGEN = 1000;

public:
    GenText(vector<string> all_of_words, int pref_counter, int gen_counter);
    GenText(map<prefix, vector<string>> Gener, int m_gen);
    string Generationtxt();
};
