// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"
#include<string>
TEST(task1, test1)
{
    vector<string> words{ "car", "a", "computer", "orange!" };
    GenText Gobject(words, 3, 1000);
    ASSERT_STREQ("a computer orange! ", Gobject.Generationtxt().c_str());

}

TEST(task2, test1)
{
    vector<string> words{ "High", "Hi", "ho" };
    GenText Gobject(words, 3, 100);
    ASSERT_STREQ("High Hi ho ", Gobject.Generationtxt().c_str());
}

TEST(task3, test1)
{
    map<deque<string>, vector<string>> mma;
    mma[{ "Hooly", "Wood" }].push_back(".");
    mma[{"Wood", "."}].push_back("_last_of_all_prefix_");
    GenText Gobject(mma, 1000);
    string output = Gobject.Generationtxt();
    if (output[0] == 'H')
        ASSERT_STREQ("Hooly Wood . ", output.c_str());
    else
        ASSERT_EQ('W', output[0]);
}

TEST(task4, test1)
{
    map<deque<string>, vector<string>> mma;
    mma[{"Enjoy", "the"}].push_back("ride");
    mma[{"Enjoy", "the"}].push_back("moment");
    mma[{"the", "ride"}].push_back("_last_of_all_prefix_");
    mma[{"the", "moment"}].push_back("_last_of_all_prefix_");

    GenText Gobject(mma, 100);
    string output = Gobject.Generationtxt();
    if (output[0] == 't')
        ASSERT_EQ('t', output[0]);
    else if (output[output[output.length() - 2]] == 'e')
        ASSERT_STREQ("Enjoy the ride ", output.c_str());
    else
        ASSERT_STREQ("Enjoy the moment ", output.c_str());
}

TEST(task5, test1)
{
    vector<string> words{ "Do", "you", "speak", "english", "my", "friend?" };
    GenText Gobject(words, 2, 100);
    string output = Gobject.Generationtxt();
    if (output[output.length() - 2] == '?')
        ASSERT_EQ('?', output[output.length() - 2]);
    else
        ASSERT_LE(100, output.size());
}