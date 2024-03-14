#include <iostream>
#include <vector>
#include <string>
#include <format>


using namespace std;


const int MAX_QUESTION_LENGTH = 100;
const int MAX_NUM_QUESTIONS = 5;



struct Question
{

    int ThemeId;

    char QuestionText[MAX_QUESTION_LENGTH];

    int Points;

    char AnswerOptions[MAX_NUM_QUESTIONS];

    int CorrectAnswerIndex;



    Question ( 
        int themeId, 
        const char questionText[MAX_QUESTION_LENGTH],
        int points, 
        const char answerOptions[MAX_NUM_QUESTIONS], 
        int correctAnswerIndex 
    )
    {
        ThemeId = themeId;
        CorrectAnswerIndex = correctAnswerIndex;
        Points = points % 100;

        strncpy_s( QuestionText, questionText, _TRUNCATE );
        strncpy_s( AnswerOptions, answerOptions, _TRUNCATE );
    }

    Question() = default;



    string ToFormatString()
    {
        string options;

        for ( int i = 0; i < MAX_NUM_QUESTIONS; i++ )
            options += format( "\n\t{}. {}", i, AnswerOptions[i] );

        return format( "|{:^10}|{:<100s}|{:^6}|{}| Правильный ответ: {}",
            ThemeId,
            QuestionText,
            Points,
            AnswerOptions,
            CorrectAnswerIndex
        );
    }

};


struct QuestionTable
{

    vector<Question> Questions;


    QuestionTable() = default;

    void Echo()
    {
        cout << format( "|{:^10}|{:^100s}|{:^6}|\n{:=^118}\n",
            "Theme",
            "Question",
            "Points",
            "" 
        );

        for ( int i = 0; i < Questions.size(); i++ )
            cout << Questions.at( i ).ToFormatString() << endl;
    }

    void AddQuestion( const Question& question )
    {
        Questions.push_back( question );
    }

};



int main()
{
    setlocale( LC_ALL, "" );
    Question q( 1, "2 + 2 = ?", 10, { "1", "2", "3", "4" }, 4);
    cout << q.ToFormatString();


    return 0;
}
