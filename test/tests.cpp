// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"
#include<string>
TEST(task1, test1)
{
    vector<string> words{ "car", "a", "computer", "orange!" };
    Generatortxt G_object(words, 3, 1000);
    ASSERT_STREQ("a computer orange! ", G_object.Generationtxt().c_str());

}

TEST(task2, test1)
{
    vector<string> words{ "High", "Hi", "ho" };
    Generatortxt G_object(words, 3, 100);
    ASSERT_STREQ("High Hi ho ", G_object.Generationtxt().c_str());
}

TEST(task3, test1)
{
    /////////////////////////////////////////////////////////////////////////////////
    map<deque<string>, vector<string>> mma;
    mma[{"Enjoy", "the"}].push_back("ride");
    mma[{"the", "ride"}].push_back("last of all preffix");
    Generatortxt G_object(mma, 100);
    string vihod = G_object.Generationtxt();
    if (vihod[0] == 'E')
        ASSERT_STREQ("Enjoy the ride ", vihod.c_str());
    else
        ASSERT_EQ('t', vihod[0]);
}

TEST(task4, test1)
{
    map<deque<string>, vector<string>> mma;
    mma[{"Enjoy", "the"}].push_back("ride");
    mma[{"Enjoy", "the"}].push_back("moment");
    mma[{"the", "ride"}].push_back("last of all preffix");
    mma[{"the", "moment"}].push_back("last of all preffix");

    Generatortxt G_object(mma, 100);
    string vihod = G_object.Generationtxt();
    if (vihod[0] == 't')
        ASSERT_EQ('t', vihod[0]);
    else if (vihod[vihod[vihod.length() - 2]] == 'e')
        ASSERT_STREQ("Enjoy the ride ", vihod.c_str());
    else
        ASSERT_STREQ("Enjoy the moment ", vihod.c_str());
}

TEST(task5, test1)
{
    vector<string> words{ "If", "you", "want", "to", "be", "somebody,", "somebody", "really", "special,", "be", "yourself." };
    Generatortxt G_object(words, 2, 100);
    string output = G_object.Generationtxt();
    if (output[output.length() - 2] == '.')
        ASSERT_EQ('.', output[output.length() - 2]);
    else
        ASSERT_LE(100, output.size());
}