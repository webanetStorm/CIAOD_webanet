#pragma once

#include <vector>
#include <string>

using namespace std;


struct Question
{
    static int _nextId;

    int Id;

    int ThemeId;

    string QuestionText;

    int Points;

    vector<string> AnswerOptions;

    int CorrectAnswerIndex;


    Question( int, string, int, vector<string>, int );

    Question();

    std::string ToFormatString();

};


struct Test
{

    std::vector<Question> Questions;

    Test();

    void Echo( vector<Question> );

    void InsertQuestion( Question );

    void RemoveQuestions( int );

    std::vector<Question> GenerateTest();

    void AutoFillTest();

};


Question InputQuestion( Question& );
