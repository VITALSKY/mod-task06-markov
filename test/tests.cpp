// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"
#include<string>
TEST(task1, test1)
{
    vector<string> words{ "car", "a", "computer", "orange!" };
    Generatortxt G_object(words, 3, 1000);
    ASSERT_STREQ("a computer orange!".c_str(), G_object.Generationtxt().c_str());

}

TEST(task2, test1)
{
    vector<string> words{ "High", "Hi", "ho" };
    Generatortxt G_object(words, 3, 100);
    ASSERT_STREQ("High Hi ho".c_str(), G_object.Generationtxt().c_str());
}

TEST(task3, test1)
{
    map<deque<string>, vector<string>> mma;
    mma[{"everything", "throw"}].push_back("rain");
    mma[{"throw", "rain"}].push_back("houston");
    mma[{"rain", "houston"}].push_back("last of all preffix");
    Generatortxt G_object(mma, 100);
    ASSERT_STREQ("everything throw rain houston".c_str(), G_object.Generationtxt().c_str());
}

TEST(task4, test1)
{
    map<deque<string>, vector<string>> mma;
    mma[{"everything", "throw"}].push_back("rain");
    mma[{"everything", "throw"}].push_back("move");
    mma[{"throw", "rain"}].push_back("last of all preffix");
    mma[{"throw", "move"}].push_back("last of all preffix");
    Generatortxt G_object(mma, 100);
    string output = G_object.Generationtxt();
    if (output[output[output.length() - 2]] != 'e')
        ASSERT_STREQ("everything throw rain".c_str(), output.c_str());
    else
        ASSERT_STREQ("everything throw move".c_str(), output.c_str());
}

TEST(task5, test1)
{
    vector<string> words{ "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "10)" };
    Generatortxt G_object(words, 4, 100);
    string line = G_object.Generationtxt();
    if (line[line.length() - 2] == ')')
        ASSERT_EQ(')', line[line.length() - 2]);
    else
        ASSERT_LE(100, line.size());
}