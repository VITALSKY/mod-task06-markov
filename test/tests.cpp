// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
TEST(task1, test1)
{
    Markov Gen(vector<string> words{ "car", "a", "computer", "orange!" }, 3, 100);
    ASSERT_STREQ("a computer orange!".c_str(), Gen.TextGen().c_str());

}

TEST(task2, test1)
{
    Markov Gen(vector<string> words{ "High"," Hi" ,"ho"}, 3, 100);
    ASSERT_STREQ("High Hi ho".c_str(), Gen.TextGen().c_str());
}

TEST(task3, test1)
{
    map<deque<string>, vector<string>> mma;
    mma[{"everything", "throw"}].push_back("rain");
    mma[{"throw", "rain"}].push_back("houston");
    mma[{"rain", "houston"}].push_back("last of all preffix");
    Markov Gen(mma, 100);
    ASSERT_STREQ("everything throw rain houston".c_str(), Gen.TextGen().c_str());
}

TEST(task4, test1)
{
    map<deque<string>, vector<string>> dict;
    dict[{"everything", "throw"}].push_back("rain");
    dict[{"everything", "throw"}].push_back("move");
    dict[{"throw", "rain"}].push_back("last of all preffix");
    dict[{"throw", "move"}].push_back("last of all preffix");

    Markov Gen(dict, 100);
    string output = Gen.TextGen();
    if (output[output[output.length() - 1]] != 'e')
        ASSERT_STREQ("everything throw rain".c_str(), output.c_str());
    else
        ASSERT_STREQ("everything throw move".c_str(), output.c_str());
}

TEST(task5, test1)
{
    Markov Gen(vector<string> words{ "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "10)" }, 4, 100);
    string output = Gen.TextGen();
    if (output[output.length() - 1] == ')')
        ASSERT_EQ(')', output[output.length() - 1]);
    else
        ASSERT_LE(100, output.size());
}