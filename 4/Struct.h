#pragma once

#include <vector>
#include <string>



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

    string ToFormatString();

};


struct Test
{

    vector<Question> Questions;


    Test();

    void Echo( vector<Question> );

    void InsertQuestion( Question );

    void RemoveQuestions( int );

    vector<Question> GenerateTest();

    void AutoFillTest();

};


Question InputQuestion( Question& );

